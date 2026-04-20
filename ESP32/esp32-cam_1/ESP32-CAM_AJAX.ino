#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <PubSubClient.h>
#include "cfg.h"    // Configuración del proyecto

float pepe=0.0;
AsyncWebServer server(80);
WiFiClient espClient;
PubSubClient client(espClient);

void callback(char* topic, byte* payload, unsigned int length) {
    String message = "";
    for (int i = 0; i < length; i++) {
      message += (char)payload[i];
    }
    pepe = message.toFloat(); // lo guardo en una variable
    Serial.println(message);    // Muestra en monitor serie
}

void reconnect() {
  while (!client.connected()) {
    if (client.connect("ESP32client")) {
      client.subscribe("sensor/dato");
    }
  }
}

const int ledPin = 4;

String pagina() {

  String html = R"rawliteral(
  <!DOCTYPE html><html><head>
  <meta name="viewport" content="width=device-width, initial-scale=1">
 <style>
body{
  font-family: Arial;
  text-align: center;
  margin-top: 50px;
  background-color: cyan;
}

.container{
  background: white;
  padding: 30px;
  border-radius: 15px;
  width: 90%;
  max-width: 400px;
  margin: auto;
  box-shadow: 0px 4px 15px rgba(0,0,0,0.2);
}

button{
  font-size: 20px;
  padding: 15px 40px;
  margin: 10px;
  border: none;
  border-radius: 10px;
  cursor: pointer;
  background-color: #007BFF;
  color: white;
  transition: 0.3s;
}

button:hover{
  background-color: #0056b3;
}

img{
  width: 200px; 
  margin-top: 20px;
}

#temperatura{
  font-weight: bold;
  font-size: 18px;
}

footer{
  margin-top: 30px;
  font-size: 14px;
  color: #333;
}
  </style></head><body>
<div class="container">
  <h2>ESP32 Control</h2>
  <button onclick="ledOn()">ENCENDER</button>
  <button onclick="ledOff()">APAGAR</button>
  <button onclick="getTemp()">LEER</button>
  <p id="estado">Estado: desconocido</p>
  <p id="temperatura"> -- .C</p>
  <!-- Imagen de ejemplo 
  <img src="https://images.squarespace-cdn.com/content/v1/50f14d35e4b0d70ab5fc4f24/1409224741340-S9NNFVR0X8SX10796E9K/image-asset.jpeg?format=2500w" alt="Imagen ejemplo">
  -->
</div>
<footer>  Ies Juan de la Cierva -2026</footer>
<script>

  function ledOn(){
    fetch('/on')
    .then(response => response.text())
    .then(data => {
      document.getElementById('estado').innerHTML = data;
    });
  }

  function ledOff(){
    fetch('/off')
    .then(response => response.text())
    .then(data => {
      document.getElementById('estado').innerHTML = data;
    });
  }

  function getTemp(){
        fetch('/upd')
          .then(response => response.text())
          .then(data => {
          actualizarTemperatura(parseFloat(data));
    });
    }
  //setInterval(actualizarTemperatura, 3000);
  function actualizarTemperatura(valor){
    let tempElem = document.getElementById("temperatura");
    tempElem.innerText = " " + valor + " .C";
    if(valor > 26.0)      { tempElem.style.color = "red";}
    else if(valor < 21.5) { tempElem.style.color = "blue";}
    else                  { tempElem.style.color = "green";}
  }
  </script>
  </body>
  </html>
  )rawliteral";
  
  return html;
}

void setup() {

//------------ configuración serie y pins
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  pepe = 0.0;
  digitalWrite(ledPin, LOW);
//------------ configuración wifi  
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.print("Conectando ");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("Conectado!");
  Serial.println(WiFi.localIP());
  // ----------- configuración MQTT
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);
  // --------------- configuración servidor Web
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(200, "text/html", pagina());
  });
  server.on("/on", HTTP_GET, [](AsyncWebServerRequest *request){
    digitalWrite(ledPin, HIGH);
    request->send(200, "text/plain", "LED ENCENDIDO");
  });
  server.on("/off", HTTP_GET, [](AsyncWebServerRequest *request){
    digitalWrite(ledPin, LOW);
    request->send(200, "text/plain", "LED APAGADO");
  });
  server.on("/upd", HTTP_GET, [](AsyncWebServerRequest *request){
    //digitalWrite(ledPin, LOW);
    request->send(200, "text/plain", String(pepe,2));
  });
  server.begin();
}

void loop() {
      if (!client.connected()) {
        reconnect();
      }
      client.loop();
  
  }
