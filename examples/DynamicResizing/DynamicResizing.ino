/**
 * @file DynamicResizing.ino
 * 
 * @brief This example demonstrates the dynamic resizing feature of the vector.
 * 
 * @date: 2024-06-23
 * @author: Aleko Khomasuridze
 */

#include <Arduino.h>
#include "vector.h"

vector<int> myVector;

void setup() {
    Serial.begin(115200);

    // Adding elements to the vector to trigger dynamic resizing
    for (int i = 0; i < 20; ++i) {
        myVector.PushBack(i * 10);
    }

    // Print all elements after adding
    Serial.println("Vector after adding elements:");
    #if defined(DEBUG_MODE)
    myVector.PrintAll(Serial);
    #endif
}

void loop() {
    // Put your main code here, to run repeatedly:
}


#include <Arduino.h>
#include "vector.h"

vector<int> myVector;

void setup() {
    Serial.begin(115200);

    // Adding elements to the vector to trigger dynamic resizing
    for (int i = 0; i < 20; ++i) {
        myVector.PushBack(i * 10);
    }

    // Print all elements after adding
    Serial.println("Vector after adding elements:");
    #if defined(DEBUG_MODE)
    myVector.PrintAll(Serial);
    #endif
}

void loop() {
    // Put your main code here, to run repeatedly:
}
