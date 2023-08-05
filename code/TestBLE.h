#pragma once

#include <chrono>

#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <WiFi.h>

#include "sleep.h"

namespace BLETest
{
    constexpr static const char* SERVICE_UUID = "4fafc201-1fb5-459e-8fcc-c5c9c331914b";
    constexpr static const char* CHARACTERISTIC_UUID = "beb5483e-36e1-4688-b7f5-ea07361b26a8";

    BLEServer* pServer;
    BLEService* pService;
    BLECharacteristic* pCharacteristic;

    std::chrono::system_clock::time_point start;

    inline void setup()
    {
        start = std::chrono::system_clock::now();
        Serial.begin(115200);
        Serial.print("MAC: ");
        Serial.println(WiFi.macAddress());
        Serial.println("Starting BLE Server!");

        BLEDevice::init("ESP32-BLE-Server");
        pServer = BLEDevice::createServer();
        pService = pServer->createService(SERVICE_UUID);
        pCharacteristic = pService->createCharacteristic(CHARACTERISTIC_UUID, BLECharacteristic::PROPERTY_READ);

        /* BLEServer *pServer = BLEDevice::createServer();
        BLEService *pService = pServer->createService(SERVICE_UUID);
        BLECharacteristic *pCharacteristic = pService->createCharacteristic(
                                               CHARACTERISTIC_UUID,
                                               BLECharacteristic::PROPERTY_READ |
                                               BLECharacteristic::PROPERTY_WRITE
                                             );*/

        pCharacteristic->setValue("Hello, World!");
        pService->start();
        // BLEAdvertising *pAdvertising = pServer->getAdvertising();
        BLEAdvertising* pAdvertising = BLEDevice::getAdvertising();
        pAdvertising->addServiceUUID(SERVICE_UUID);
        pAdvertising->setScanResponse(true);
        pAdvertising->setMinPreferred(0x06); // functions that help with iPhone connections issue
        pAdvertising->setMinPreferred(0x12);
        BLEDevice::startAdvertising();
        // pAdvertising->start();
        Serial.println("Characteristic defined! Now you can read it in the Client!");
    }

    inline void loop()
    {
        yield();
        const auto now = std::chrono::system_clock::now();
        if (now - start > std::chrono::seconds(10))
        {
            sleep(std::chrono::seconds(10));
        }
    }
} // namespace BLETest