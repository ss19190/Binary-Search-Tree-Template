#include "../include/Bst.h"
#include "../include/Car.h"
#include "../include/Person.h"

#include <iostream>

int main()
{

    // Create a BST of integers
    BST<int> bst;

    // Insert some elements into the BST
    bst.insert(10);
    bst.insert(15);
    bst.insert(9);
    bst.insert(25);
    bst.insert(8);
    bst.insert(12);

    // Traverse the BST in order
    std::cout << "In-order traversal: ";
    bst.inorderTraversal(std::cout);
    std::cout << std::endl;

    // Traverse the BST in pre-order
    std::cout << "Pre-order traversal: ";
    bst.preorderTraversal(std::cout);
    std::cout << std::endl;

    // Search for an element in the BST
    int key = 32;
    bool found = bst.search(key);
    if (found)
    {
        std::cout << "Element found: " << key << std::endl;
    }
    else
    {
        std::cout << "Element not found: " << key << std::endl;
    }

    key = 12;
    found = bst.search(key);

    if (found)
    {
        std::cout << "Element found: " << key << std::endl;
    }
    else
    {
        std::cout << "Element not found: " << key << std::endl;
    }

    // Delete an element from the BST
    key = 12;
    bst.deleteElement(key);

    // Traverse the BST in order again
    std::cout << "In-order traversal after deleting " << key << ": ";
    bst.inorderTraversal(std::cout);
    std::cout << std::endl;

    //use of copy constructor by copy assingment operator
    BST<int> copiedTree = bst;
    std::cout << "Copy tree:\n";
    copiedTree.inorderTraversal(std::cout);

    //use of move constructor
    BST<int> movedTree(std::move(bst));

    std::cout << "Display of original tree after move:\n";
    bst.preorderTraversal(std::cout);
    std::cout << "Display of tree in a new location:\n";
    movedTree.preorderTraversal(std::cout);

    std::cout << std::endl;
    std::ofstream outputFile("test/output.txt");

    if (!outputFile.is_open())
    {
        std::cerr << "Failed to open file: output.txt" << std::endl;
        return 1; // Return an error code
    }

    copiedTree.serialize(outputFile, "preorder");
    outputFile.close();

    BST<Car> carBST;
    std::ifstream inputFile("test/structTest.txt"); // Open the file before passing it to deserialize

    if (!inputFile.is_open())
    {
        std::cerr << "Failed to open file: structTest.txt" << std::endl;
        return 1; // Return an error code
    }

    carBST.deserialize(inputFile); // Pass the file stream;

    inputFile.close(); // Close the file after using it

    std::cout << "All Cars in BST: \n";
    carBST.inorderTraversal(std::cout);
    std::cout << std::endl;

    Car targetCar = {"Audi", "Yukon", 2026};
    found = carBST.search(targetCar);

    if (found)
    {
        std::cout << "this " << targetCar.make << " was found!" << std::endl;
    }
    else
    {
        std::cout << "this " << targetCar.make << " was not found." << std::endl;
    }

    targetCar = {"GMC", "Yukon", 2026};
    found = carBST.search(targetCar);

    if (found)
    {
        std::cout << "this " << targetCar.make << " was found!" << std::endl;
    }
    else
    {
        std::cout << "this " << targetCar.make << " was not found." << std::endl;
    }

    carBST.deleteElement(targetCar);

    std::cout << "Deletion of " << targetCar.make << std::endl;

    std::cout << "All Cars in BST after deletion: \n";
    carBST.inorderTraversal(std::cout);
    std::cout << std::endl;

    found = carBST.search(targetCar);

    if (found)
    {
        std::cout << "Car found!" << std::endl;
    }
    else
    {
        std::cout << "Car not found." << std::endl;
    }

    // Create a BST for storing Person objects
    BST<Person> PersonBST;

    // Create some Person objects to insert into the BST
    Person person1("Alice", 30);
    Person person2("Bob", 32);
    Person person3("Charlie", 25);
    Person person4("David", 27);
    Person person5("Eve", 29);

    // Insert the Person objects into the BST
    PersonBST.insert(person1);
    PersonBST.insert(person2);
    PersonBST.insert(person3);
    PersonBST.insert(person4);
    PersonBST.insert(person5);

    // Serialize the BST
    std::ofstream testFile("test/twoWaysTest.txt");
    if (!testFile.is_open())
    {
        std::cerr << "Failed to open file: testFile.txt" << std::endl;
        return 1; // Return an error code
    }

    PersonBST.serialize(testFile, "preorder");
    std::cout << std::endl;
    testFile.close();

    //test for deserialization after serialization
    BST<Person> PersonTest;
    std::ifstream inTestFile("test/twoWaysTest.txt");

    if (!inTestFile.is_open())
    {
        std::cerr << "Failed to open file: inTestFile.txt" << std::endl;
        return 1; // Return an error code
    }

    PersonTest.deserialize(inTestFile);
    inTestFile.close();

    std::cout << "Two direction test:\n";
    PersonTest.preorderTraversal(std::cout);

    // Search for a specific Person object in the BST
    Person targetPerson("David", 27);
    bool personFound = PersonBST.search(targetPerson);

    if (personFound)
    {
        std::cout << "This person was found: " << targetPerson;
    }
    else
    {
        std::cout << "This person wasn't found: " << targetPerson;
    }

    Person targetPerson2("Anna", 67);
    personFound = PersonBST.search(targetPerson2);

    if (personFound)
    {
        std::cout << "This person was found: " << targetPerson2;
    }
    else
    {
        std::cout << "This person wasn't found: " << targetPerson2;
    }

    // Delete a Person object from the BST
    Person deletePerson("Charlie", 25);
    PersonBST.deleteElement(deletePerson);

    // Serialize the BST to an output stream in inorder traversal

    std::ofstream fileToTest("test/classTest.txt"); // Open the file before passing it to deserialize

    if (!fileToTest.is_open())
    {
        std::cerr << "Failed to open file: classTest.txt" << std::endl;
        return 1; // Return an error code
    }

    PersonBST.serialize(fileToTest, "inorder");

    return 0;
}
