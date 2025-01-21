#include <iostream>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Binary tree class
class BinaryTree {
public:
    Node* root;

    BinaryTree() : root(nullptr) {}

    // Function to create the root or insert a new node
    void create(int val) {
        if (root == nullptr) {
            root = new Node(val);
            cout << "Root node created with value " << val << endl;
        } else {
            cout << "Root already exists, inserting new node...\n";
            insert(root, val);
        }
    }

    // Function to insert a node
    void insert(Node* temp, int val) {
        char choice;
        cout << "Insert left or right of " << temp->data << " (l/r): ";
        cin >> choice;

        if (choice == 'l' || choice == 'L') {
            if (temp->left == nullptr) {
                temp->left = new Node(val);
                cout << "Inserted " << val << " to the left of " << temp->data << endl;
            } else {
                insert(temp->left, val);
            }
        } else {
            if (temp->right == nullptr) {
                temp->right = new Node(val);
                cout << "Inserted " << val << " to the right of " << temp->data << endl;
            } else {
                insert(temp->right, val);
            }
        }
    }

    // Recursive function for in-order traversal
    void inorder(Node* temp) {
        if (temp == nullptr) return;
        inorder(temp->left);
        cout << temp->data << " ";
        inorder(temp->right);
    }

    // Recursive function for pre-order traversal
    void preorder(Node* temp) {
        if (temp == nullptr) return;
        cout << temp->data << " ";
        preorder(temp->left);
        preorder(temp->right);
    }

    // Recursive function for post-order traversal
    void postorder(Node* temp) {
        if (temp == nullptr) return;
        postorder(temp->left);
        postorder(temp->right);
        cout << temp->data << " ";
    }

    // Function to swap left and right child nodes
    void swapNodes(Node* temp) {
        if (temp == nullptr) return;
        swap(temp->left, temp->right);
        swapNodes(temp->left);
        swapNodes(temp->right);
    }

    // Function to calculate the height of the tree
    int height(Node* temp) {
        if (temp == nullptr) return 0;
        return 1 + max(height(temp->left), height(temp->right));
    }

    // function to count Leaf and internal node
    void countNodes(Node* temp, int& internalCount, int& leafCount) {
    if (temp == nullptr) {
        return;
    }

    if (temp->left == nullptr && temp->right == nullptr) {
        leafCount++;
    } else {
        internalCount++;
    }

    countNodes(temp->left, internalCount, leafCount);
    countNodes(temp->right, internalCount, leafCount);
}


    // Function to erase all nodes
    void erase(Node*& temp) {
        if (temp == nullptr) return;
        erase(temp->left);
        erase(temp->right);
        delete temp;
        temp = nullptr;
    }
};

// Main function
int main() {
    BinaryTree tree;
    int choice, value;

    while (true) {
        cout << "\nBinary Tree Operations:\n";
        cout << "1. Create/Insert Node\n";
        cout << "2. Inorder Traversal\n";
        cout << "3. Preorder Traversal\n";
        cout << "4. Postorder Traversal\n";
        cout << "5. Swap Tree\n";
        cout << "6. Get Tree Height\n";
        cout << "7. Count Leaf And Internal Nodes\n";
        cout << "8. Erase Tree\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                tree.create(value);
                break;
            case 2:
                cout << "Inorder Traversal: ";
                tree.inorder(tree.root);
                cout << endl;
                break;
            case 3:
                cout << "Preorder Traversal: ";
                tree.preorder(tree.root);
                cout << endl;
                break;
            case 4:
                cout << "Postorder Traversal: ";
                tree.postorder(tree.root);
                cout << endl;
                break;
            case 5:
                tree.swapNodes(tree.root);
                cout << "Tree structure swapped.\n";
                break;
            case 6:
                cout << "Height of tree: " << tree.height(tree.root) << endl;
                break;
            case 7:{
                int internalCount = 0, leafCount = 0;
                tree.countNodes(tree.root, internalCount, leafCount);
                cout << "Number of internal nodes: " << internalCount << endl;
                cout << "Number of leaf nodes: " << leafCount << endl;
                break;
            }
            case 8:
                tree.erase(tree.root);
                cout << "Tree erased.\n";
                break;
            case 9:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice, try again.\n";
        }
    }

    return 0;
}
