#include <iostream>
using namespace std;

class Node {
private:
    int coeff, expo;
    Node* prev, * next;

    friend class ddl;

public:
    Node(int c, int e) : coeff(c), expo(e), next(nullptr), prev(nullptr) {}
};

class ddl {
private:
    Node* head;
    Node* tail;

public:
    ddl() : head(nullptr), tail(nullptr) {}

    void insert(int coeff, int expo) {
        Node* newnode = new Node(coeff, expo);

        if (!head) {
            head = tail = newnode;
            return;
        }

        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }

    void display() const {
        if (!head) {
            cout << "Polynomial is empty!" << endl;
            return;
        }

        Node* temp = head;
        while (temp) {
            cout << temp->coeff << "x^" << temp->expo;
            temp = temp->next;

            if (temp) cout << " + ";
        }
        cout << endl;
    }

    void add(ddl& result, ddl& poly1, ddl& poly2) {
        Node* temp1 = poly1.head;
        Node* temp2 = poly2.head;

        while (temp1 || temp2) {
            if (!temp2 || (temp1 && temp1->expo > temp2->expo)) {
                result.insert(temp1->coeff, temp1->expo);
                temp1 = temp1->next;
            }
            else if (!temp1 || (temp1 && temp1->expo < temp2->expo)) {
                result.insert(temp2->coeff, temp2->expo);
                temp2 = temp2->next;
            }
            else {
                int sum = temp1->coeff + temp2->coeff;
                if (sum != 0) {
                    result.insert(sum, temp1->expo);
                }
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
        }
    }
};

int main() {
    ddl poly1, poly2, result;

    poly1.insert(10, 3);
    poly1.insert(20, 2);
    poly1.insert(30, 1);
    poly1.insert(40, 0);

    poly2.insert(5, 3);
    poly2.insert(15, 2);
    poly2.insert(30, 1);
    poly2.insert(50, 0);

    cout << "Polynomial 1: ";
    poly1.display();

    cout << "Polynomial 2: ";
    poly2.display();

    result.add(result, poly1, poly2);

    cout << "Sum of Polynomials: ";
    result.display();

    return 0;
}
