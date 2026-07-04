/*
Project: WiFi Weather Web Server
Author: SATYAM KUMAR
Desc: esp32 connects to wifi and shows temperature and humidity on a web page with an led toggle
Date: 2026-07-04
*/

#include <WiFi.h>
#include <DHT.h>

int dhtPin=15;
int led=2;
int ledState=0;

DHT dht(dhtPin,DHT22);

WiFiServer server(80);

void setup(){
Serial.begin(115200);
dht.begin();
pinMode(led,OUTPUT);

WiFi.begin("Wokwi-GUEST","");
Serial.print("Connecting");
while(WiFi.status()!=WL_CONNECTED){
delay(500);
Serial.print(".");}

Serial.println("");
Serial.print("Connected. IP: ");
Serial.println(WiFi.localIP());
server.begin();}

void loop(){
WiFiClient client=server.available();

if(client){
String req=client.readStringUntil('\r');
client.flush();

if(req.indexOf("/led")!=-1){
ledState=!ledState;
digitalWrite(led,ledState);}

float temp=dht.readTemperature();
float hum=dht.readHumidity();
long up=millis()/1000;

client.println("HTTP/1.1 200 OK");
client.println("Content-type:text/html");
client.println("");
client.println("<html><head><meta http-equiv='refresh' content='10'></head><body>");
client.println("<h1>ESP32 Weather Station</h1>");
client.print("<p>Temperature: ");
client.print(temp);
client.println(" C</p>");
client.print("<p>Humidity: ");
client.print(hum);
client.println(" %</p>");
client.print("<p>Uptime: ");
client.print(up);
client.println(" seconds</p>");
client.println("<p><a href='/led'><button>Toggle LED</button></a></p>");
client.println("</body></html>");

client.stop();}}
