# Caso 2 Estructuras de Datos

Estudiante: Dayana Xie Li
Curso: Estructuras de Datos
Carnet: 2022097967

## Descripción del caso

La compañía 4home es un proveedor de domótica para todo latinoamérica, los consumidores pueden comprar sus productos que van desde tomacorrientes, bombillos, tiras de led, cámaras y gran variedad de sensores de movimiento, humo y apertura de puertas entre otros muchos tipos de dispositivos. Sus clientes luego de instalar dichos dispositivos en casa, usando el app 4home pueden configurarlos para acceder a los mismos y así controlarlos desde la aplicación, haciendo así su casa inteligente. cada tipo de dispositivo tiene sus diferentes parámetros configurables y las acciones propias del tipo de dispositivo.

Cómo diseñaría e implementaría usted en C++ las diversas classes para el app 4home de tal forma que permita realizar las siguientes tareas:

1.  Agregar K dispositivos de T tipos diferentes a las H habitaciones de la casa de un consumidor
2.  Que el usuario pueda crear tareas con un nombre, que al accionarlas ejecute acciones y cambie parámetros de un subconjunto seleccionado de los dispositivos de la casa, siendo dichas acciones y parámetros configurables en la tarea
3.  Ejecutar una tarea en particular

## Diseño y Estrategia

El formato establecido para agregar dispositivos, tareas, acciones y parámetros es harcoded y además el programa posee un struct para cada elemento mencionado anteriormente.

La idea principal del programa es que desde una tarea, se le pueda asignar dispositivos que la realicen. En donde dentro de esos dispositivos van a tener acciones específicas correspondientes a la tarea asignada, que muestran parámetros.

En donde se hace uso de las listas enlazadas es a lal hora de agregar dispositivos y tareas a sus listas correspondientes ya que estas van cambiando conforme el usuario vaya creando nuevas tareas y agregando nuevos dispositivos a su casa.
Por ejemplo:
Si se quiere crear una tarea llamada "Buenos días", de dispositivo el bombillo y queremos que se encienda con el color amarillo.

Primero creamos las acciones y sus parámetros para asignarlas a un dispositivo, para luego encargarle a ese dispositivo la tarea respectiva, que en este caso es "Buenos días".
