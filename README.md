
# Vector Class Template for Arduino

## Overview

This `vector` class template provides a simple implementation of a dynamic array for Arduino. It supports basic functionalities such as adding, removing, editing elements, and iterating over the elements. The class also includes debugging features that can be enabled with the `DEBUG_MODE` macro.

## Features

- Dynamic resizing of the array
- Add elements to the end of the array
- Remove elements by value or index
- Edit elements by value or index
- Access elements using the subscript operator
- Iterate over the elements using iterators
- Debugging support to print all elements to a specified stream

## Installation

1. Download the `vector` repo as zip file.
2. Place the zip files in your Arduino through library manager.
3. Include the `vector.h` file in your Arduino sketch.

## Usage

### Initialization

Include the `vector` class in your sketch:

```cpp
#include "vector.h"
```

### Basic Operations

#### Adding Elements

```cpp
vector<int> myVector;
myVector.PushBack(10);
myVector.PushBack(20);
myVector.PushBack(30);
```

#### Removing Elements

```cpp
myVector.Remove(20); // Remove by value
myVector.Remove(1);  // Remove by index
```

#### Editing Elements

```cpp
myVector.Edit(0, 100);     // Edit element at index 0
myVector.Edit(30, 200);    // Edit element with value 30
```

#### Accessing Elements

```cpp
int value = myVector[0];   // Access element at index 0
```

### Iterating Over Elements

#### Using Iterators

```cpp
for (vector<int>::iterator it = myVector.begin(); it != myVector.end(); ++it) {
    Serial.println(*it);
}
```

#### Using Const Iterators

```cpp
for (vector<int>::const_iterator it = myVector.begin(); it != myVector.end(); ++it) {
    Serial.println(*it);
}
```

#### Using ForEach Itirator
```cpp
vector<String> items;
// assume that vector had Strings pushed in it 

for (const String& item : items) {
    Serial.println(item);
}
```

### Debugging

Enable the `DEBUG_MODE` macro to use debugging features:

```cpp
#define DEBUG_MODE
```

Print all elements to the serial console:

```cpp
myVector.PrintAll(Serial);
```

## Example Sketch

```cpp
#include <Arduino.h>
#include "vector.h"

vector<int> myVector;

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
    myVector.Edit(1, 25); // Change element at index 1 from 20 to 25

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
    myVector.Remove(1); // Remove the element at index 1

    // Print all elements after removing by index
    Serial.println("After removing by index:");
    #if defined(DEBUG_MODE)
    myVector.PrintAll(Serial);
    #endif
}

void loop() {
    // Put your main code here, to run repeatedly:
}
```

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Author

 - Aleko khomasuridze - 2024-06-23
