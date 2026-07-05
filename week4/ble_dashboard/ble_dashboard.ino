/*
Project: BLE Sensor Dashboard
Author: SATYAM KUMAR
Desc: esp32 broadcasts temperature and humidity over BLE to view on a phone app
Date: 2026-07-05
*/

#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>
#include <DHT.h>

int dhtPin=25;
DHT dht(dhtPin,DHT11);

BLECharacteristic *pChar;

void setup(){
Serial.begin(115200);
dht.begin();

BLEDevice::init("ESP32-SATYAM-BLE");
BLEServer *pServer=BLEDevice::createServer();
BLEService *pService=pServer->createService("12345678-1234-1234-1234-123456789abc");
pChar=pService->createCharacteristic(
"abcd1234-1234-1234-1234-123456789abc",
BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_NOTIFY);
pChar->addDescriptor(new BLE2902());
pService->start();

BLEAdvertising *pAdvertising=BLEDevice::getAdvertising();
pAdvertising->addServiceUUID("12345678-1234-1234-1234-123456789abc");
pAdvertising->start();
Serial.println("BLE started. Scan with nRF Connect for ESP32-SATYAM-BLE");}

void loop(){
float temp=dht.readTemperature();
float hum=dht.readHumidity();

String data="Temp: "+String(temp)+" C, Humidity: "+String(hum)+" %";
pChar->setValue(data.c_str());
pChar->notify();

Serial.println(data);
delay(3000);}
