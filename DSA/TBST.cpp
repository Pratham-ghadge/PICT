#include <iostream>
using namespace std;

//  TBST Node


class TBSTNode {

    int data;
    TBSTNode* left;
    TBSTNode* right;
    bool leftThread, rightThread;
public:
    TBSTNode(int value) {
        data = value;
        left = right = nullptr;
        leftThread = rightThread = true;
    }

    friend class TBSTOperations;
};


//  TBST operations


class TBSTOperations {
private:
    TBSTNode* root;

public:
    // Constructor initializes TBST
    TBSTOperations() {
        root = nullptr;
    }

    // Function to insert a node
    void insert(int key) {
        TBSTNode* parent = nullptr;
        TBSTNode* current = root;

        // Search for the correct position
        while (current != nullptr) {
            if (key == current->data) {
                cout << "Duplicate keys not allowed!\n";
                return;
            }
            parent = current;
            if (key < current->data) {
                if (!current->leftThread)
                    current = current->left;
                else
                    break;
            } else {
                if (!current->rightThread)
                    current = current->right;
                else
                    break;
            }
        }

        TBSTNode* newNode = new TBSTNode(key);
        if (parent == nullptr) {
            root = newNode; // If tree is empty root node created
        } else if (key < parent->data) {
            newNode->left = parent->left;
            newNode->right = parent;
            parent->leftThread = false;
            parent->left = newNode;
        } else {
            newNode->right = parent->right;
            newNode->left = parent;
            parent->rightThread = false;
            parent->right = newNode;
        }
    }

    // Function to find the inorder successor
    TBSTNode* inorderSuccessor(TBSTNode* node) {
        if (node->rightThread)
            return node->right;
        node = node->right;
        while (!node->leftThread)
            node = node->left;
        return node;
    }

    // Function for inorder traversal
    void inorderTraversal() {
        if (root == nullptr) {
            cout << "Tree is empty!\n";
            return;
        }
        TBSTNode* current = root;
        while (!current->leftThread)
            current = current->left; // Move to leftmost node

        while (current != nullptr) {
            cout << current->data << " ";
            current = inorderSuccessor(current);
            if (current == root)
                break;
        }
        cout << endl;
    }

    // Function for preorder traversal
    void preorderTraversal() {
        if (root == nullptr) {
            cout << "Tree is empty!\n";
            return;
        }
        TBSTNode* current = root;
        while (current != nullptr) {
            cout << current->data << " ";
            if (!current->leftThread)
                current = current->left;
            else if (!current->rightThread)
                current = current->right;
            else {
                while (current != nullptr && current->rightThread)
                    current = current->right;
                if (current != nullptr)
                    current = current->right;
            }
        }
        cout << endl;
    }

    // Function to delete a node
    void deleteNode(int key) {
        TBSTNode* parent = nullptr;
        TBSTNode* current = root;

        // Search for the node to delete
        while (current != nullptr) {
            if (key == current->data)
                break;
            parent = current;
            if (key < current->data) {
                if (!current->leftThread)
                    current = current->left;
                else
                    return;
            } else {
                if (!current->rightThread)
                    current = current->right;
                else
                    return;
            }
        }

        if (current == nullptr) {
            cout << "Node not found!\n";
            return;
        }

        // Case 1: Leaf Node
        if (current->leftThread && current->rightThread) {
            if (parent == nullptr) {
                root = nullptr;
            } else if (parent->left == current) {
                parent->left = current->left;
                parent->leftThread = true;
            } else {
                parent->right = current->right;
                parent->rightThread = true;
            }
            delete current;
        }
        // Case 2: Node has one child
        else if (current->leftThread || current->rightThread) {
            TBSTNode* child = (!current->leftThread) ? current->left : current->right;

            if (parent == nullptr) {
                root = child;
            } else if (parent->left == current)
                parent->left = child;
            else
                parent->right = child;

            TBSTNode* succ = inorderSuccessor(current);
            TBSTNode* pred = (parent->left == current) ? parent : current->left;
            if (!current->leftThread)
                pred->right = succ;
            else
                succ->left = pred;

            delete current;
        }
        // Case 3: Node has two children
        else {
            TBSTNode* successor = inorderSuccessor(current);
            int val = successor->data;
            deleteNode(successor->data);
            current->data = val;
        }
    }
};
   

// Main function
int main() {

   TBSTOperations TBST;
     int choice, val;
        do {
            cout << "\nThreaded Binary Search Tree Menu\n";
            cout << "1. Insert\n2. Inorder Traversal\n3. Preorder Traversal\n4. Delete Node\n5. Exit\n";
            cout << "Enter choice: ";
            cin >> choice;
            switch (choice) {
                case 1:
                    cout << "Enter value to insert: ";
                    cin >> val;
                    TBST.insert(val);
                    break;
                case 2:
                    cout << "Inorder Traversal: ";
                    TBST.inorderTraversal();
                    break;
                case 3:
                    cout << "Preorder Traversal: ";
                    TBST.preorderTraversal();
                    break;
                case 4:
                    cout << "Enter value to delete: ";
                    cin >> val;
                   TBST.deleteNode(val);
                    break;
                case 5:
                    cout << "Exiting...\n";
                    break;
                default:
                    cout << "Invalid choice! Try again.\n";
            }
        } while (choice != 5);
    }



