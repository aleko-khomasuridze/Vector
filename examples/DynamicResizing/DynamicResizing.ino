/**
 * @file Example1_BasicOperations.ino
 * @brief Demonstrates basic operations of the vector class template.
 * 
 * This example shows how to add, edit, and remove elements from the vector.
 * 
 * @date 2024-06-23
 * @author Aleko Khomasuridze
 */

#include <Arduino.h>
#include <vector.h>

vector<int> myVector;

#define DEBUG_MODE

void setup() {
    Serial.begin(115200);

    // Adding elements to the vector
    myVector.PushBack(10);
    myVector.PushBack(20);
    myVector.PushBack(30);

    // Print all elements
    Serial.println("Initial vector:");
    #if defined(DEBUG_MODE)
    myVector.PrintAll(Serial);
    #endif

    // Edit an element
    myVector.Edit((size_t)1, 25); // Change element at index 1 from 20 to 25

    // Print all elements after editing
    Serial.println("After editing:");
    #if defined(DEBUG_MODE)
    myVector.PrintAll(Serial);
    #endif

    // Remove an element by value
    myVector.Remove(25); // Remove the element with value 25

    // Print all elements after removing by value
    Serial.println("After removing by value:");
    #if defined(DEBUG_MODE)
    myVector.PrintAll(Serial);
    #endif

    // Remove an element by index
    myVector.Remove((size_t)0); // Remove the element at index 1

    // Print all elements after removing by index
    Serial.println("After removing by index:");
    #if defined(DEBUG_MODE)
    myVector.PrintAll(Serial);
    #endif
}

void loop() {
    // Put your main code here, to run repeatedly:
}
