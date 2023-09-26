/*
  Author: Gabriel Carrera 21216
  
  Electrónica Digital 2 - Laboratorio 6 
*/

#include <SPI.h> //Incluir Librería de comunicación SPI
#include <SD.h> //Incluir librería para la memoria microSD

int sel = 0; //Variable selector para controlar el modo en el que encuentra el programa
char var; //Variable para validar cambio de modos


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200); //Inicializar comunicación serial
  
  Serial.print("Initializing SD card..."); //Indicar que se está inicializando la memoria
  Serial.println('\n'); //Imprimir un enter
  
}

void loop() {
  // put your main code here, to run repeatedly: 
  Serial.println("Presione 1 para desplegar imagen1"); //Desplegar las opciones
  Serial.println("Presione 2 para desplegar imagen2");
  Serial.println("Presione 3 para desplegar imagen3");
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
  }

  if (sel == 1){ //Si se eligió imagen 1
    Serial.println("Elegida la Imagen 1:"); 
    Serial.println('\n'); //Imprimir un enter
    sel = 0; //Regresar al menu
  }

  else if (sel == 2){ //Si se eligió imagen 2
    Serial.print("Elegida la Imagen 2:"); 
    Serial.println('\n'); //Imprimir un enter
    sel = 0; //Regresar al menú
  }

  else if (sel == 3){ //Si se eligió imagen 3
    Serial.println("Elegida la Imagen 3:");
    Serial.print('\n'); //Imprimir un enter
    sel = 0; //Regresar al menú
  }
}
