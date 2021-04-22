//
// Created by Abdul Aziz Ibrahim on 4/20/21.
//

#include "BinaryTree.h"

void BinaryTree::insertNode(int num)
{
    TreeNode *newNode = nullptr; // Pointer to a new node.

    // Create a new node and store num in it.
    newNode = new TreeNode;
    newNode->value = num;
    newNode->left = newNode->right = nullptr;

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
