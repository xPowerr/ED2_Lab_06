/*
  Author: Gabriel Carrera 21216
  
  Electrónica Digital 2 - Laboratorio 6 
*/

#include <SPI.h> //Incluir Librería de comunicación SPI
#include <SD.h> //Incluir librería para la memoria microSD

int sel; //Variable para controlar el modo en el que encuentra el programa
char var; //Variable para validar cambio de modos
String dibujo; // Variable para recibir la imagen creada
int draw;

File myFile; //Se define myFile como tipo archivo

void setup() {

  dibujo = "\n";
  // put your setup code here, to run once:
  Serial.begin(115200); //Inicializar comunicación serial
  SPI.setModule(0); //Utilizar el SPI Module 0
  
  Serial.print("Initializing SD card..."); //Indicar que se está inicializando la memoria
  pinMode(PA_3, OUTPUT); //Se define PA_3 como salida y se convierte en slave select

  if (!SD.begin(PA_3)){ //Verificar que el slave select este en 0, y se responda un 1
    Serial.println("initialization failed!"); //Si no falló la inicialización
    return;
  }
  Serial.println("initialization done."); //Se inició la comunicación
}

void loop() {
  // put your main code here, to run repeatedly: 
  Serial.println("Presione 1 para desplegar imagen1"); //Desplegar las opciones
  Serial.println("Presione 2 para desplegar imagen2");
  Serial.println("Presione 3 para desplegar imagen3");
  Serial.println("Presione 4 para desplegar imagen creada");
  Serial.println("Presione 5 para crear una imagen");
  
  sel = 0; //Inicializar loop
  
  while (sel == 0){
    var = Serial.read(); //Leer la respuesta del usuario
    if (var == '1'){ //Chequear respuesta
      sel = 1; //Si elegió imagen 1, elegir la imagen1
    }
    else if (var == '2'){ //Chequear respuesta
      sel = 2; //Si elegió imagen 2, elegir la imagen2
    }
    else if (var == '3'){ //Chequear respuesta
      sel = 3; //Si elegió imagen 3, elegir la imagen3
    }
    else if (var == '4'){ //Chequear respuesta
      sel = 4; //Si elegió imagen 3, elegir la imagen creada
    }
    else if (var == '5'){ //Chequear respuesta
      sel = 5; //Si elegió imagen 5, elegir crear imagen
    }
  }

  if (sel == 1){ //Si se eligió imagen 1
    myFile = SD.open("image1.txt"); //Se busca el archivo con nombre 'image1'
    if (myFile) { //Si sí hay un archivo llamado así ejecutar
      Serial.println("image1.txt:"); 
      // read from the file until there's nothing else in it:
      while (myFile.available()) { //Leer el archivo hasta que no haya nada
        Serial.write(myFile.read()); //Mostrar en la terminal lo que se está leyendo
      }
      // close the file:
      myFile.close(); //Cerrar el archivo
      Serial.println('\n'); //Imprimir un enter
    } else {
      // if the file didn't open, print an error:
      Serial.println("error opening image.txt"); //Si no hay archivo con ese nombre, hay error
    }
    sel = 0; //Regresar al menu
  }

  else if (sel == 2){ //Si se eligió imagen 2
    myFile = SD.open("image2.txt"); //Se busca el archivo con nombre 'image2'
    if (myFile) { //Si sí hay un archivo llamado así ejecutar
      Serial.print("image2.txt:"); 
      // read from the file until there's nothing else in it:
      while (myFile.available()) { //Leer el archivo hasta que no haya nada
        Serial.write(myFile.read()); //Mostrar en la terminal lo que se está leyendo
      }
      // close the file:
      myFile.close(); //Cerrar el archivo
      Serial.println('\n'); //Imprimir un enter
    } else {
      // if the file didn't open, print an error:
      Serial.println("error opening image.txt"); //Si no hay archivo con ese nombre, hay error
    }
    sel = 0; //Regresar al menú
  }

  else if (sel == 3){ //Si se eligió imagen 3
    myFile = SD.open("image3.txt"); //Se busca el archivo con nombre 'image3'
    if (myFile) { //Si sí hay un archivo llamado así ejecutar
      Serial.println("image3.txt:");
      // read from the file until there's nothing else in it:
      while (myFile.available()) { //Leer el archivo hasta que no haya nada
        Serial.write(myFile.read()); //Mostrar en la terminal lo que se está leyendo
      }
      // close the file:
      myFile.close(); //Cerrar el archivo
      Serial.print('\n'); //Imprimir un enter
    } else {
      // if the file didn't open, print an error:
      Serial.println("error opening image.txt"); //Si no hay archivo con ese nombre, hay error
    }
    sel = 0; //Regresar al menú
  }

  else if (sel == 4){ //Si se eligió imagen creada 
    myFile = SD.open("image4.txt"); //Se busca el archivo con nombre 'image5'
    if (myFile) { //Si sí hay un archivo llamado así ejecutar
      Serial.println("image4.txt:");
      // read from the file until there's nothing else in it:
      while (myFile.available()) { //Leer el archivo hasta que no haya nada
        Serial.write(myFile.read()); //Mostrar en la terminal lo que se está leyendo
      }
      // close the file:
      myFile.close(); //Cerrar el archivo
      Serial.print('\n'); //Imprimir un enter
    } else {
      // if the file didn't open, print an error:
      Serial.println("error opening image.txt"); //Si no hay archivo con ese nombre, hay error
    }
    sel = 0; //Regresar al menú
  }

// Si el usuario seleccionó la opción 5 del menú
    while (sel == 5) {
        myFile = SD.open("image4.txt", FILE_WRITE); // Abrir el archivo en modo escritura
        if (myFile) { //Si sí hay un archivo llamado así ejecutar
          Serial.println("Dibuje la imagen a crear...");
          Serial.println("Presione 7 para salir al haber terminado.");
          while (Serial.read() != '7') {
            dibujo = Serial.read(); //Leer la respuesta del usuario
          }
          myFile.println(dibujo);
          // close the file:
          myFile.close(); //Cerrar el archivo
          Serial.println("Contenido guardado en imagen4.txt.");
          Serial.print('\n'); //Imprimir un enter
        } else {
         // if the file didn't open, print an error:
          Serial.println("error opening image.txt"); //Si no hay archivo con ese nombre, hay error
       }
          sel = 0; //Regresar al menú
        
      }

}
