/*

Módulo para configurar en un dispositivo ARDUINO UNO R3
una segunda UART para comunicación serie.
De esta manera no se pierde la uart estandar para 
funciones de programación y depuración serie.

*/

#include <SoftwareSerial.h>

// Define los pines para la UART virtual
// Pin 10 -> RX (Conectar al TX del ESP32)
// Pin 11 -> TX (Conectar al RX del ESP32 mediante divisor de voltaje)
const int rxPin = 12;
const int txPin = 13;

// Crea el objeto para la UART virtual
SoftwareSerial vSerial2(rxPin, txPin);

void setup() {
  // Inicializa la comunicación con la computadora (Monitor Serie)
  Serial.begin(115200);
  Serial.println("Arduino Uno listo. Esperando datos del ESP32...");

  // Inicializar UART virtual .
  // Nota: SoftwareSerial no funciona de forma estable por encima de 57600 bps. 
  // 9600 bps es el valor ideal y más seguro.
  vSerial2.begin(9600);
  vSerial2.setTimeout(50); // Acorta el tiempo de espera a 50ms. (Por defecto es 1seg)

}

void loop() {
  
  if (vSerial2.available()) { // Si hay datos disponibles

    // --- Lectura de datos en UART
    // --- 3 opciones : byte , string + "\n" , o buffer string
    char datoRecibido = vSerial2.read();                  // Lee el byte entrante
    String data_rc = vSerial2.readStringUntil('\n');      // Lee buffer hasta encontrar \n
    data_rc.trim();                                       // Elimina retornos de carro

    String data_raw = vSerial2.readString();              // Lee todo el buffer y espera timeOut establecido
    // Lo reenvía al Monitor Serie de la computadora
    Serial.print(datoRecibido);
    Serial.print(data_rc);
    Serial.print(data_raw);
  }

    // Escribir en la UART
    String data_raw = "Mensaje para enviar";
    vSerial2.print(data_raw);
}
