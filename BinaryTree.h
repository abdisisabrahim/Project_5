//
// Created by Abdul Aziz Ibrahim on 4/20/21.
//

#ifndef PROJECT_5_BINARYTREE_H
#define PROJECT_5_BINARYTREE_H
using namespace std;

class BinaryTree {
    private:
        struct TreeNode{
            string value;
            int count;
            TreeNode* left;
            TreeNode* right;
        };

        TreeNode* root;

        void insert(TreeNode *&, TreeNode*&);
        void destroySubTree(TreeNode *);
        void deleteNode(int, TreeNode *&);
        void makeDeletion(TreeNode *&);
        void displayInOrder(TreeNode* ) const;
        void displayPreOrder(TreeNode *) const;
        void displayPostOrder(TreeNode *) const;

    public:
        //Constructor
        BinaryTree()
        { root = nullptr; }

        // Destructor
        ~BinaryTree()
        { destroySubTree(root); }

        // Binary tree operations
        void insertNode(int);
        bool searchNode(int);
        void remove(int);


        void displayInOrder() const
        { displayInOrder(root); }

        void displayPreOrder() const
        { displayPreOrder(root); }

        void displayPostOrder() const
        { displayPostOrder(root); }
};


#endif //PROJECT_5_BINARYTREE_H
