#include <list>
#include <string>
#include <iostream>

using namespace std;

// tipo de dispositivos posibles
enum typeDevice {
	bombillo = 0,
	sensorHumo = 1,
	sensorPuertas = 2,
	camara = 3,
    impresora = 4
};

// valores de los parametros
struct ActionParameters {
    string key;
    string value;
};


struct Action {
	string name;
    // lista de parametros de la accion
    list<ActionParameters> params;
};

// struct del dispositivo
typedef struct Device
{
	string name;			// nombre de un dispositivo
	typeDevice type;		// tipo del dispositivo
	string room;			// nombre de la habitacion en el que se ubica
	
	list<Action> actions;   // lista de las acciones que puede realizar
	Device* NextDevice;		// Puntero hacia el siguiente dispositivo

}*PtrDevice;  			    //Puntero para poder acceder al struct de TDispositivos

typedef struct Task 
{
	string name;			  // nombre de la tarea
	list<PtrDevice> devices;  // lista de dispositivos

	Task* NextTask;		      //puntero a la siguiente tarea en la lista

}*PtrTasks;

PtrDevice listDevices;      // puntero de lista de dispotivos
list<PtrTasks> listTasks;   // lista de todas las tareas


// agregar dispositivo
PtrDevice addDevice(string pName, typeDevice pDevideType, string pRoom, PtrDevice& pListDevices){
    PtrDevice newDevice = new(Device);
	newDevice->name = pName;
	newDevice->type = pDevideType;
	newDevice->room = pRoom;
    // hacemos que el ultimo apunte a null
	newDevice->NextDevice = NULL;
    // se actualiza la lista
    newDevice->NextDevice = pListDevices;
	pListDevices = newDevice;
    return newDevice;
}


void createTask(list<PtrTasks>& pTaskList, string pTaskName, PtrDevice& pDevice){

    PtrTasks newTask = new(Task);
    newTask->name = pTaskName;
    newTask->devices.push_back(pDevice);
    newTask->NextTask = NULL;
	pTaskList.push_back(newTask);
}

void executeTask(string pTaskName, list<PtrTasks>& plistTasks){
    bool founded = false;
    // se recorre cada tarea en la lista de tareas
    for(PtrTasks task : plistTasks){
        // se encuentra la tarea que se desea ejecutar
        if(task->name ==  pTaskName){
            founded = true;
            cout << "Tarea: " << task->name << endl;
            // se busca el dispositivo
            for(PtrDevice device : task->devices){
                // se busca la accion
                for(Action action :  device->actions){
                    cout << action.name << " , ";
                    for(ActionParameters parameter : action.params){
                        cout << parameter.key << " " << parameter.value << endl;
                    }
                }
            }
            // si ya lo encontro termina
            break;
        }
    }
    // si no se encontro ninguna tarea con ese nombre
    if (founded == false){
        cout << "No existe la tarea" << endl;
    }
} 

// eliminar una accion de un dispositivo
PtrDevice deleteAction(PtrDevice& pDevice, Action pAction, list<PtrTasks>& plistTasks){
    // se recorre la lista
    for(list<Action>::iterator actionItr = pDevice->actions.begin(); actionItr != pDevice->actions.end(); ++actionItr){
        if (actionItr->name == pAction.name){
            // se elimina
            pDevice->actions.erase(actionItr);
            break;
        }
    }
    return pDevice;    
}

int main(){
    PtrDevice device;
    Action actions1;
    ActionParameters parameters1;
    parameters1 = {"color", "amarillo"};
    actions1 = {"Encender bombillo", {parameters1}};
    device = addDevice("bombillo de sala", bombillo, "Sala", listDevices);
    device->actions.push_back(actions1);
    createTask(listTasks, "Buenos dias", device);
    executeTask("Buenos dias", listTasks);

    device = deleteAction(device, actions1, listTasks);
    actions1 = {"Parpadear luz del bombillo", {parameters1}};
    device->actions.push_back(actions1);
    executeTask("Buenos dias", listTasks);

    PtrDevice device2;
    Action actions2;
    ActionParameters parameters2;
    parameters2 = {"color", "blanco"};
    actions2 = {"Apagar bombillo", {parameters2}};
    device2 = addDevice("bombillo de cocina", bombillo, "Sala", listDevices);
    device2->actions.push_back(actions2);
    createTask(listTasks, "Buenas noches", device2);
    executeTask("Buenas noches", listTasks);

    return 0;
}