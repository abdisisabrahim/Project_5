#include <iostream>
#include "BinaryTree.h"
#include <string>
#include <fstream>
using namespace std;

int main() {
    ifstream inFile;
    string fileName;
    string string1;


    cout << "Enter file name with extension: ";   // asking the user for fileName
    cin >> fileName;   // input from user

    inFile.open (fileName);    // opening file

    if(!inFile){

        cout << "Error. Could not open file";
    }
    else {
        cout << "Opening file......\n\n";

        while (inFile >> string1) {    // using the while loop to execute the following
            cout << string1 << endl;

        }
    }
    BinaryTree tree;
    tree.insertNode("a");
    tree.insertNode("cat");
    tree.insertNode("b");
    tree.displayInOrder();
    return 0;
}
