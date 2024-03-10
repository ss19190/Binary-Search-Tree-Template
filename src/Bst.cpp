#include "../include/Bst.h"
#include "../include/Car.h"
#include "../include/Person.h"

template class BST<int>;
template class BST<Car>;
template class BST<Person>;

template <typename T>
BST<T>::BST() { std::cout << "BST constructed\n"; }

template <typename T>
BST<T>::BST(const BST &other)
{
    root = copyNodes(other.root);
    std::cout << "Copy constructor used\n";
}

template <typename T>
typename BST<T>::NodePtr BST<T>::copyNodes(NodePtr node)
{
    if (node == nullptr)
        return nullptr;
    NodePtr newNode = std::make_shared<Node>(node->value);
    newNode->left = copyNodes(node->left);
    newNode->right = copyNodes(node->right);
    return newNode;
}

template <typename T>
BST<T>::BST(BST &&other) : root(std::move(other.root))
{
    root = copyNodes(other.root);
    std::cout << "Move constructor used\n";
}

template <typename T>
typename BST<T>::NodePtr BST<T>::copyNodes(NodePtr node)
{
    if (node == nullptr)
        return nullptr;
    NodePtr newNode = std::make_shared<Node>(node->value);
    newNode->left = copyNodes(node->left);
    newNode->right = copyNodes(node->right);
    node ->
    return newNode;
}

template <typename T>
BST<T>& BST<T>::operator=(const BST &other)
{
    if (this != &other) {
        BST<T> temp(other); // Use the copy constructor to create a temporary object
        std::swap(root, temp.root); // Swap the contents of the temporary object with the current object
    }
    std::cout << "Copy assignment operator used\n";
    return *this;
}

// Overloaded move assignment operator
template <typename T>
BST<T>& BST<T>::operator=(BST<T>&& other)
{
    if (this != &other) {
        root = std::move(other.root);
        other.root = nullptr; // Reset the moved from tree
    }
    std::cout << "Move assignment operator used\n";
    return *this;
}


template <typename T>
BST<T>::~BST() { std::cout << "BST destroyed\n"; }

template <typename T>
void BST<T>::insert(const T &value) { insert(value, root); }

template <typename T>
void BST<T>::insert(const T &value, NodePtr &node)
{
    if (!node)
    {
        node = std::make_shared<Node>(value);
        return;
    }

    if (value < node->value)
        insert(value, node->left);
    else
        insert(value, node->right);
}

template <typename T>
void BST<T>::serialize(std::ostream &output, std::string traversal) const
{
    if (traversal == "preorder")
        preorderTraversal(root, output);
    else if (traversal == "inorder")
        inorderTraversal(root, output);
    else
        output << "Invalid type of traversal";
}

template <typename T>
void BST<T>::deserialize(std::ifstream &inputFile)
{
    T value;
    while (inputFile >> value)
        insert(value);
}

template <typename T>
bool BST<T>::search(const T &value) const
{
    search(root, value);
    return false;
}

template <typename T>
bool BST<T>::search(NodePtr node, const T &value) const
{
    if (!node)
        return false;

    if (value == node->value)
        return true;
    else
        return search(node->left, value) || search(node->right, value);
}

template <typename T>
void BST<T>::preorderTraversal(std::ostream &output) const { preorderTraversal(root, output); }

template <typename T>
void BST<T>::preorderTraversal(NodePtr node, std::ostream &output) const
{
    if (!node)
        return;

    output << node->value << " ";

    preorderTraversal(node->left, output);
    preorderTraversal(node->right, output);
}

template <typename T>
void BST<T>::deleteElement(const T &value)
{
    // Find the node to delete
    NodePtr node = root;
    NodePtr parent = nullptr;

    while (node && node->value != value)
    {
        parent = node;

        if (value < node->value)
            node = node->left;
        else
            node = node->right;
    }

    // If the node is not found, return
    if (!node)
        return;

    // Determine the type of node to delete
    bool isLeaf = !node->left && !node->right;
    bool hasSingleChild = node->left || node->right;

    // If the node is a leaf node or has only one child, handle it accordingly
    if (isLeaf || hasSingleChild)
    {
        NodePtr child = (node->left) ? node->left : node->right;

        if (parent)
        {
            if (parent->left == node)
                parent->left = std::move(child);
            else
                parent->right = std::move(child);
        }
        else
            root = std::move(child);

        return;
    }

    // If the node has two children, find its in-order successor
    NodePtr successorParent = node;
    NodePtr successor = node->right;

    while (successor->left)
    {
        successorParent = successor;
        successor = successor->left;
    }

    // Replace the node's value with the successor's value
    node->value = successor->value;

    // Delete the successor node
    successor = nullptr;
}

template <typename T>
void BST<T>::inorderTraversal(std::ostream &output) const { inorderTraversal(root, output); }

template <typename T>
void BST<T>::inorderTraversal(const NodePtr &node, std::ostream &output) const
{
    if (node)
    {
        inorderTraversal(node->left, output);
        output << node->value << " ";
        inorderTraversal(node->right, output);
    }
}
