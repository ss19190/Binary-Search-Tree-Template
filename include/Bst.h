/**
 * @file Bst.h
 * @brief Declaration of the Bst template
 *
 * @author Sara Sobstyl
 * @version 1.1
 *
 */

#ifndef __BST_H__
#define __BST_H__

#include <iostream>
#include <memory>
#include <fstream>
#include <functional>
#include <type_traits>
#include <string>

/**
 * @brief Template class for a binary search tree.
 *
 * @param T The type of elements stored in the tree.
 */
template <typename T>
class BST
{

public:
    struct Node;
    using NodePtr = std::shared_ptr<Node>; ///< Pointer to a tree node.

    /**
     * @brief Represents a node in a binary search tree.
     */
    struct Node
    {

        T value;       ///< The value stored in the node.
        NodePtr left;  ///< Pointer to the left child node.
        NodePtr right; ///< Pointer to the right child node.

        /**
         * @brief Constructor for a Node.
         * @param val The value to be stored in the node.
         */
        Node(const T &val) : value(val), left(nullptr), right(nullptr) { std::cout << "Node constructed\n"; }
        ~Node() { std::cout << "Node destructed\n"; }
    };

    /**
     * @brief Pointer to the root node of the BST.
     */
    NodePtr root;

    /**
     * @brief Default constructor.
     */
    BST();

    /**
     * @brief Copy constructor for BST.
     * @param other The BST to be copied.
     */
    BST(const BST &other);

    /**
     * @brief Helper method for copying a BST tree
     * @param node The node to be copied.
     * @return NodePtr A pointer to the new node.
     */
    NodePtr copyNodes(NodePtr node);

    /**
     * @brief Move constructor for BST.
     * @param other The BST to be moved from.
     */
    BST(BST&& other);

    /**
     * @brief Destructor.
     */
    ~BST();

    /**
     * @brief Copy assignment operator.
     *
     * @param other The BST to assign from.
     * @return Reference to this BST.
     */
    BST& operator=(const BST &other);

    /**
     * @brief Move assignment operator.
     *
     * @param other The BST to move from.
     * @return Reference to this BST.
     */
    BST &operator=(BST &&other);

    /**
     * @brief Helper method for inserting an element into the BST.
     *
     * @param value The value to insert.
     */
    void insert(const T &value);

    /**
     * @brief Method for inserting an element into the BST.
     *
     * @param value The value to insert.
     * @param node Pointer to the current node.
     */
    void insert(const T &value, NodePtr &node);

    /**
     * @brief Serialize the BST to a stream of bytes.
     *
     * @param output The output stream.
     * @param traversalType The type of tree traversal to use during serialization. Valid options are "in-order" and "pre-order".
     */
    void serialize(std::ostream &output, std::string traversalType) const;

    /**
     * @brief Deserialize the BST from a stream of bytes.
     *
     * @param inputFile The input file.
     */
    void deserialize(std::ifstream &inputFile);

    /**
     * @brief Helper method to search for an element in the BST.
     *
     * @param value The value to search for.
     * @return True if the value exists in the BST, false otherwise.
     */
    bool search(const T &value) const;

    /**
     * @brief Method to search for an element in the BST.
     *
     * @param node Pointer to the current node.
     * @param value The value to search for.
     * @return True if the value exists in the BST, false otherwise.
     */
    bool search(NodePtr node, const T &value) const;

    /**
     * @brief Helper method for traversing the BST in preorder.
     *
     * @param output Output stream to write the traversed values to.
     */
    void preorderTraversal(std::ostream &output) const;

    /**
     * @brief Method for traversing the BST in preorder.
     *
     * @param node Pointer to the current node.
     * @param output Output stream to write the traversed values to.
     */
    void preorderTraversal(NodePtr node, std::ostream &output) const;

    /**
     * @brief Helper method to perform an in-order traversal of the Binary Search Tree (BST).
     *
     * @param output The output stream where the traversed elements will be written.
     *
     * @note In an in-order traversal, the left subtree is visited first, followed by the current node,
     * and then the right subtree.
     */
    void inorderTraversal(std::ostream &output) const;

    /**
     * @brief Method to perform an in-order traversal of the Binary Search Tree (BST).
     *
     * @param node Pointer to the current node.
     * @param output The output stream where the traversed elements will be written.
     *
     * @note In an in-order traversal, the left subtree is visited first, followed by the current node,
     * and then the right subtree.
     */
    void inorderTraversal(const NodePtr &node, std::ostream &output) const;

    /**
     * @brief Delete an element from the BST.
     *
     * @param value The value to delete.
     */
    void deleteElement(const T &value);
};

#endif // __BST_H__