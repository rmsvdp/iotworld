/*
Módulo para configurar en un dispositivo ESP32-CAM
la segunda UART para comunicación serie.
Los pines por defecto no se pueden utilizar ya
que este módulo incorpora cámara y SD y gasta alguno
de los pines
*/

#include <HardwareSerial.h>

// Asingar pines para la UART en la ESP32-CAM
// ¡¡ATENCIÓN!!: Los pines 16 y 17 NO se pueden usar en ESP32-CAM porque controlan la memoria PSRAM de la cámara.
// En  ESP32-CAM: GPIO 14 (TX) y GPIO 15 (RX) se usan para la SD, cambiar si se va a usar.
#define RX2 15         
#define TX2 14          

// SOLUCIÓN AL ERROR: Creamos nuestro propio objeto UART de hardware usando el puerto 1 o 2.
HardwareSerial Uart2(2); 

void setup()
{
  Serial.begin(115200);                         // UART-0 , serial por defecto (para monitorear en PC)
  
  // Inicializamos nuestra UART personalizada con los pines remapeados
  Uart2.begin(115200, SERIAL_8N1, RX2, TX2);   
  Uart2.setTimeout(20);                       // Fijar time-out para operaciones readString 
}

void loop()
{
  // Recibir datos desde el Arduino Uno
  if (Uart2.available()){                             
      
      // String datos = Uart2.readStrin();          // lee todo el buffer y espera timeOut 
      String datos = Uart2.readStringUntil('\n');   // Sólo lee hasta encontrar \n  
      datos.trim();                                     // Limpia espacios y el \r oculto
      
      // --- Procesar información -------------
      Serial.print("Recibido de Arduino: ");
      Serial.println(datos);
      // --------------------------------------

      // --- Preparar información -------------
      // CORREGIDO: Declaramos una variable nueva "datos2" para no causar conflictos en C++
      String datos2 = "Mensaje para enviar";             
      
      Serial.print("Enviando a Arduino: ");
      Serial.println(datos2);
      
      Uart2.println(datos2);               // Enviamos el mensaje con \n al final
      Uart2.write(0x41);                           // Escribir un byte extra ('A')
      // --------------------------------------
  }
}
