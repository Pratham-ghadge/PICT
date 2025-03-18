#include <iostream>
#include <stack>
#include <queue>
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

    // Function to create the root or insert a new node iteratively
    void create(int val) {
        if (root == nullptr) {
            root = new Node(val);
            cout << "Root node created with value " << val << endl;
        } else {
            cout << "Root already exists, inserting new node...\n";
            insert(val);
        }
    }

    // Iterative function to insert a node
    void insert(int val) {
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();

            char choice;
            cout << "Insert left or right of " << temp->data << " (l/r): ";
            cin >> choice;

            if (choice == 'l' || choice == 'L') {
                if (temp->left == nullptr) {
                    temp->left = new Node(val);
                    cout << "Inserted " << val << " to the left of " << temp->data << endl;
                    break;
                } else {
                    q.push(temp->left);
                }
            } else {
                if (temp->right == nullptr) {
                    temp->right = new Node(val);
                    cout << "Inserted " << val << " to the right of " << temp->data << endl;
                    break;
                } else {
                    q.push(temp->right);
                }
            }
        }
    }

    // Iterative in-order traversal
    void inorder() {
        stack<Node*> s;
        Node* temp = root;
        while (temp != nullptr || !s.empty()) {
            while (temp != nullptr) {
                s.push(temp);
                temp = temp->left;
            }
            temp = s.top();
            s.pop();
            cout << temp->data << " ";
            temp = temp->right;
        }
        cout << endl;
    }

    // Iterative pre-order traversal
    void preorder() {
        if (root == nullptr) return;
        stack<Node*> s;
        s.push(root);
        while (!s.empty()) {
            Node* temp = s.top();
            s.pop();
            cout << temp->data << " ";
            if (temp->right) s.push(temp->right);
            if (temp->left) s.push(temp->left);
        }
        cout << endl;
    }

    // Iterative post-order traversal using two stacks
    void postorder() {
        if (root == nullptr) return;
        stack<Node*> s1, s2;
        s1.push(root);
        while (!s1.empty()) {
            Node* temp = s1.top();
            s1.pop();
            s2.push(temp);
            if (temp->left) s1.push(temp->left);
            if (temp->right) s1.push(temp->right);
        }
        while (!s2.empty()) {
            cout << s2.top()->data << " ";
            s2.pop();
        }
        cout << endl;
    }

    // Iterative function to swap left and right child nodes
    void swapNodes() {
        if (root == nullptr) return;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();
            swap(temp->left, temp->right);
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
        cout << "Tree structure swapped.\n";
    }

    // Iterative function to calculate the height of the tree
    int height() {
        if (root == nullptr) return 0;
        queue<Node*> q;
        q.push(root);
        int height = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                Node* temp = q.front();
                q.pop();
                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }
            height++;
        }
        return height;
    }

    // Iterative function to count leaf and internal nodes
    void countNodes(int& internalCount, int& leafCount) {
        if (root == nullptr) return;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();
            if (temp->left == nullptr && temp->right == nullptr) {
                leafCount++;
            } else {
                internalCount++;
            }
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
    }

    // Iterative function to erase all nodes
    void erase() {
        if (root == nullptr) return;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
            delete temp;
        }
        root = nullptr;
        cout << "Tree erased.\n";
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
        cout << "7. Count Leaf and Internal Nodes\n";
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
                tree.inorder();
                break;
            case 3:
                cout << "Preorder Traversal: ";
                tree.preorder();
                break;
            case 4:
                cout << "Postorder Traversal: ";
                tree.postorder();
                break;
            case 5:
                tree.swapNodes();
                break;
            case 6:
                cout << "Height of tree: " << tree.height() << endl;
                break;
            case 7: {
                int internalCount = 0, leafCount = 0;
                tree.countNodes(internalCount, leafCount);
                cout << "Number of internal nodes: " << internalCount << endl;
                cout << "Number of leaf nodes: " << leafCount << endl;
                break;
            }
            case 8:
                tree.erase();
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
