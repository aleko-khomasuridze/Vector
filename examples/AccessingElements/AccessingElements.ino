/**
 * @file AccessingElements.ino
 * 
 * @brief This example demonstrates how to access and modify elements using the subscript operator.
 * 
 * @date: 2024-06-23
 * @author: Aleko Khomasuridze
 */

#include <Arduino.h>
#include "vector.h"

vector<int> myVector;

void setup() {
    Serial.begin(115200);

    // Adding elements to the vector
    for (int i = 0; i < 5; ++i) {
        myVector.PushBack(i * 5);
    }

    // Accessing and modifying elements using the subscript operator
    Serial.println("Accessing elements:");
    for (size_t i = 0; i < myVector.size(); ++i) {
        Serial.println(myVector[i]);
    }

    // Modifying elements
    myVector[2] = 100;

    // Print all elements after modification
    Serial.println("After modifying element at index 2:");
    #if defined(DEBUG_MODE)
    myVector.PrintAll(Serial);
    #endif
}

void loop() {
    // Put your main code here, to run repeatedly:
}
