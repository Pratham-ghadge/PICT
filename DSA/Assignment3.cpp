#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;
    bool lbit, rbit;

    Node(int val) {
        data = val;
        left = right = nullptr;
        lbit = rbit = false;
    }
};

class TBST {
    Node *head;  // Dummy head node

public:
    TBST() {
        head = new Node(-1); // Head node
        head->left = head->right = head;
        head->lbit = false;
        head->rbit = false;
    }

    void insert(int val) {
        Node* newNode = new Node(val);
        if (head->left == head) {
            // First node (root) insertion
            newNode->left = newNode->right = head;
            newNode->lbit = newNode->rbit = false;
            head->left = newNode;
            head->lbit = true;
            return;
        }

        Node* temp = head->left;
        while (true) {
            if (val < temp->data) {
                if (temp->lbit == false) {
                    // Insert as left child
                    newNode->left = temp->left;
                    newNode->right = temp;
                    newNode->lbit = false;
                    newNode->rbit = false;
                    temp->left = newNode;
                    temp->lbit = true;
                    return;
                }
                temp = temp->left;
            } 
            else if (val > temp->data) {
                if (temp->rbit == false) {
                    // Insert as right child
                    newNode->right = temp->right;
                    newNode->left = temp;
                    newNode->rbit = false;
                    newNode->lbit = false;
                    temp->right = newNode;
                    temp->rbit = true;
                    return;
                }
                temp = temp->right;
            } 
            else {
                cout << "Duplicate values are not allowed.\n";
                return;
            }
        }
    }

    void inorder() {
        Node* temp = head->left;
        while (temp->lbit) temp = temp->left; // Move to leftmost node

        cout << "Inorder Traversal: ";
        while (temp != head) {
            cout << temp->data << " ";
            if (temp->rbit) {
                temp = temp->right;
                while (temp->lbit) temp = temp->left;
            } else {
                temp = temp->right;
            }
        }
        cout << endl;
    }

    void preorder() {
        Node* temp = head->left;
        cout << "Preorder Traversal: ";
        while (temp != head) {
            cout << temp->data << " ";
            if (temp->lbit) {
                temp = temp->left;
            } else {
                while (!temp->rbit && temp != head)
                    temp = temp->right;
                temp = temp->right;
            }
        }
        cout << endl;
    }

    void deleteNode(int val) {
        Node* parent = head;
        Node* temp = head->left;

        while (temp != head) {
            if (val == temp->data) break;
            parent = temp;
            if (val < temp->data) {
                if (temp->lbit) temp = temp->left;
                else return void(cout << "Value not found!\n");
            } else {
                if (temp->rbit) temp = temp->right;
                else return void(cout << "Value not found!\n");
            }
        }

        if (temp->lbit && temp->rbit) {
            // Node with two children
            Node* succ = temp->right;
            Node* succParent = temp;
            while (succ->lbit) {
                succParent = succ;
                succ = succ->left;
            }
            temp->data = succ->data;
            temp = succ;
            parent = succParent;
        }

        Node* child = (temp->lbit) ? temp->left : temp->right;
        if (parent->left == temp) {
            parent->left = child;
            parent->lbit = temp->lbit;
        } else {
            parent->right = child;
            parent->rbit = temp->rbit;
        }
        delete temp;
        cout << "Node deleted successfully.\n";
    }
};

int main() {
    TBST tree;
    int choice, val;

    while (true) {
        cout << "\n1. Insert Node\n2. Delete Node\n3. Inorder Traversal\n4. Preorder Traversal\n0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> val;
                tree.insert(val);
                break;
            case 2:
                cout << "Enter value to delete: ";
                cin >> val;
                tree.deleteNode(val);
                break;
            case 3:
                tree.inorder();
                break;
            case 4:
                tree.preorder();
                break;
            case 0:
                return 0;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
}
