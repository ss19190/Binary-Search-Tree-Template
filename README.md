# Binary Search Tree (BST) Implementation

## Overview

This project provides a C++ implementation of a Binary Search Tree (BST) as a class template. A Binary Search Tree is a data structure that allows for efficient insertion, deletion, and search operations on a collection of elements.

## Features

- **Generic Design:** The BST is implemented as a class template, allowing it to store elements of any data type. ([For classes and structs information see here](#note))
- **Tree Traversal:** Support for in-order and pre-order tree traversals, providing flexibility in accessing elements.
- **Serialization and Deserialization:** Serialize the BST to a stream of bytes and deserialize it back, enabling easy storage and retrieval.
- **Search and Deletion:** Efficient methods to search for and delete elements from the BST.
- **Inputting:** Efficient methods to input values into the BST.

## Usage

### Initialization

```cpp
// Example usage of BST with integers
BST<int> bst;
```

### Insertion

```cpp
bst.insert(42);
```

### Serialization

```cpp
std::ofstream outputFile("output.txt");
bst.serialize(outputFile, "in-order");
```

### Deserialization

```cpp
std::ifstream inputFile("input.txt");
bst.deserialize(inputFile);
```

### Search

```cpp
if (bst.search(42)) {
    std::cout << "Element 42 found in the BST." << std::endl;
} else {
    std::cout << "Element 42 not found in the BST." << std::endl;
}
```

### Deletion

```cpp
bst.deleteElement(42);
```

## Building and Running

### Using <i>make</i>

1. Open your terminal.
2. Navigate to the project <i>folder</i>.
3. Run the following commands:
```shell
make
./main
```

### Using <i>g++</i> directly

1. Open terminal
2. Navigate to the project <i>folder</i>.
3. Run the following commands:
```shell
g++ -o main.exe src/car.cpp src/person.cpp src/bst.cpp src/main.cpp
.\main
```
## Important Note for User-defined Types <a name = "note"></a>

To use the Binary Search Tree (BST) template for your custom classes or structs, please ensure the following:

1. **Comparison Operators Overloading:** Overload the `<`, `==`, and `!=` operators for your class or struct to enable proper comparison. For example:
```cpp
bool Car::operator<(const Car &other) const
{
    if (make < other.make)
        return true;
    else if (make > other.make)
        return false;

    if (model < other.model)
        return true;
    else if (model > other.model)
        return false;

    return year < other.year;
}

bool Car::operator==(const Car &other) const
{
    return make == other.make && model == other.model && year == other.year;
}

bool Car::operator!=(const Car &other) const
{
    return !operator==(other);
}
```

2. **Input and Output Stream Operators Overloading (Optional):** Overload the `>>` and `<<` operators for your class or struct if you want to support serialization and deserialization. For example:
```cpp
std::istream &operator>>(std::istream &inputStream, Car &car)
{
    inputStream >> car.make >> car.model >> car.year;
    return inputStream;
}

std::ostream &operator<<(std::ostream &outputStream, const Car &car)
{
    outputStream << car.make << " " << car.model << " " << car.year << std::endl;
    return outputStream;
}
```

Ensure that your custom types conform to these requirements for errorless integration with the BST template.

### Used language:
<a href="https://www.w3schools.com/cpp/" target="_blank" rel="noreferrer"> <img src="https://raw.githubusercontent.com/devicons/devicon/master/icons/cplusplus/cplusplus-original.svg" alt="cplusplus" width="40" height="40"/> </a>
