#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class TreeNode {
public:
    int data;
    vector<TreeNode*> children;

    TreeNode(int value) : data(value) {}

    ~TreeNode() {
        for (TreeNode* child : children) {
            delete child;
        }
    }
};

class Tree {
private:
    TreeNode* root;

    void printLabels(TreeNode* node) {
        if (node) {
            cout << node->data << " ";
            for (TreeNode* child : node->children) {
                printLabels(child);
            }
        }
    }

public:
    Tree() : root(nullptr) {}

    ~Tree() {
        delete root;
    }

    void insert(int parentData, int childData) {
        if (!root) {
            root = new TreeNode(parentData);
        }
        TreeNode* parentNode = findNode(root, parentData);
        if (parentNode) {
            parentNode->children.push_back(new TreeNode(childData));
        }
    }

    TreeNode* findNode(TreeNode* node, int data) {
        if (!node) {
            return nullptr;
        }
        if (node->data == data) {
            return node;
        }
        for (TreeNode* child : node->children) {
            TreeNode* found = findNode(child, data);
            if (found) {
                return found;
            }
        }
        return nullptr;
    }

    bool hasDescendants(int data) {
        TreeNode* node = findNode(root, data);
        return node && !node->children.empty();
    }

    void printLabels() {
        printLabels(root);
        cout << endl;
    }
};

int main() {
    Tree tree;

    ifstream inputFile("graph.txt");
    if (!inputFile) {
        cerr << "Unable to open input file." << endl;
        return 1;
    }

    int parent, child;
    while (inputFile >> parent >> child) {
        tree.insert(parent, child);
    }

    inputFile.close();

    cout << "Labels of all nodes: ";
    tree.printLabels();

    int nodeToCheck;
    cout << "Enter the node to check for descendants: ";
    cin >> nodeToCheck;

    if (tree.hasDescendants(nodeToCheck)) {
        cout << "The node has descendants." << endl;
    } else {
        cout << "The node does not have descendants." << endl;
    }

    return 0;
}
