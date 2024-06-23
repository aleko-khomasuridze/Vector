/**
 * @file UsingIterators.ino
 * 
 * @brief Example demonstrates how to use iterators to traverse the vector.
 * 
 * @date 2024-06-23
 * @author Aleko Khomasuridze
 */

#include <Arduino.h>
#include "vector.h"

vector<String> myVector;

void setup() {
    Serial.begin(115200);

    // Adding elements to the vector
    myVector.PushBack("Hello");
    myVector.PushBack("World");
    myVector.PushBack("Arduino");

    // Using iterators to traverse the vector
    Serial.println("Traversing vector with iterators:");
    for (vector<String>::iterator it = myVector.begin(); it != myVector.end(); ++it) {
        Serial.println(*it);
    }

    // Using const iterators to traverse the vector
    Serial.println("Traversing vector with const iterators:");
    for (vector<String>::const_iterator it = myVector.begin(); it != myVector.end(); ++it) {
        Serial.println(*it);
    }

    // Using range-based for loop to traverse the vector
    Serial.println("Traversing vector with range-based for loop:");
    for (const String& item : myVector) {
        Serial.println(item);
    }
}

void loop() {
    // Put your main code here, to run repeatedly:
}
