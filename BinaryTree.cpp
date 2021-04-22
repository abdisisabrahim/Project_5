//
// Created by Abdul Aziz Ibrahim on 4/20/21.
//

#include "BinaryTree.h"
#include <iostream>
#include <string>

using namespace std;

void BinaryTree::insertNode(string seq)
{
    TreeNode *newNode = nullptr; // Pointer to a new node.

    // Create a new node and store num in it.
    newNode = new TreeNode;
    newNode->value = seq;
    newNode->left = newNode->right = nullptr;
    newNode->count = 1;
    // Insert the node.
    insert(root, newNode);
}

void BinaryTree::insert(TreeNode *&nodePtr, TreeNode *&newNode)
{
    if (nodePtr == nullptr)
        nodePtr = newNode; // Insert the node.
    else if (newNode->value < nodePtr->value)
        insert(nodePtr->left, newNode); // Search the left branch.
    else
        insert(nodePtr->right, newNode); // Search the right branch.
}

void BinaryTree::displayInOrder(TreeNode *nodePtr) const
{
    if (nodePtr)
    {
        displayInOrder(nodePtr->left);
        cout << nodePtr->value << " " << nodePtr->count << endl;
        displayInOrder(nodePtr->right);
    }
}

void BinaryTree::displayPreOrder(TreeNode *nodePtr) const
{
    if (nodePtr)
    {
        cout << nodePtr->value << endl;
        displayPreOrder(nodePtr->left);
        displayPreOrder(nodePtr->right);
    }
}

void BinaryTree::displayPostOrder(TreeNode *nodePtr) const
{
    if (nodePtr)
    {
        displayPostOrder(nodePtr->left);
        displayPostOrder(nodePtr->right);
        cout << nodePtr->value << endl;
    }
}

bool BinaryTree::searchNode(string seq)
{
    TreeNode *nodePtr = root;

    while (nodePtr)
    {
        if (nodePtr->value == seq)
            return true;
        else if (seq < nodePtr->value)
            nodePtr = nodePtr->left;
        else
            nodePtr = nodePtr->right;
    }

    return false;
}

void BinaryTree::remove(string seq)
{
    deleteNode(seq, root);
}

void BinaryTree::deleteNode(string seq, TreeNode *&nodePtr)
{
    if (seq < nodePtr->value)
        deleteNode(seq, nodePtr->left);
    else if (seq > nodePtr->value)
        deleteNode(seq, nodePtr->right);
    else
        makeDeletion(nodePtr);
}

void BinaryTree::makeDeletion(TreeNode *&nodePtr)
{
    // Define a temporary pointer to use in reattaching
    // the left subtree.
    TreeNode *tempNodePtr = nullptr;

    if (nodePtr == nullptr)
        cout << "Cannot delete empty node.\n";
    else if (nodePtr->right == nullptr)
    {
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->left; // Reattach the left child.
        delete tempNodePtr;
    }
    else if (nodePtr->left == nullptr)
    {
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->right; // Reattach the right child.
        delete tempNodePtr;
    }
    // If the node has two children.
    else
    {
        // Move one node to the right.
        tempNodePtr = nodePtr->right;
        // Go to the end left node.
        while (tempNodePtr->left)
            tempNodePtr = tempNodePtr->left;
        // Reattach the left subtree.
        tempNodePtr->left = nodePtr->left;
        tempNodePtr = nodePtr;
        // Reattach the right subtree.
        nodePtr = nodePtr->right;
        delete tempNodePtr;
    }
}
void BinaryTree::destroySubTree(TreeNode *nodePtr)
{
    if (nodePtr)
    {
        if (nodePtr->left)
            destroySubTree(nodePtr->left);

        if (nodePtr->right)
            destroySubTree(nodePtr->right);

        delete nodePtr;
    }
}