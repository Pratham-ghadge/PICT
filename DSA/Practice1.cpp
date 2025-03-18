#include <iostream>
#include <queue>
#include <stack>
using namespace std;
class Node
{
    int data;
    Node *left;
    Node *right;

public:
    friend class BToperation;

    Node(int Val)
    {
        data = Val;
        left = nullptr;
        right = nullptr;
    }
};

class BToperation
{
    Node *root;

public:
    BToperation()
    {
        root = nullptr;
    }

    void create(int val)
    {
        if (root == nullptr)
        {
            root = new Node(val);
            cout << "Root is Created With Root " << val << "! " << endl;
        }
        else
        {
            cout << "Root is Alerady created" << endl;
            insert(val);
        }
    }

    void insert(int val)
    {
        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();

            char choice;
            cout << "Insert left or right of" << temp->data << "(L/R) : ";
            cin >> choice;

            if (choice == 'l' || choice == 'L')
            {
                if (temp->left == nullptr)
                {
                    temp->left = new Node(val);
                    cout << "inserted " << val << "to the " << temp->data << "left" << endl;
                }
                else
                {
                    q.push(temp->left);
                }
            }
            else
            {
                if (temp->right == nullptr)
                {
                    temp->right = new Node(val);
                    cout << "inserted " << val << " to the " << temp->data << " right" << endl;
                }
                else
                {
                    q.push(temp->right);
                }
            }
        }
    }

    void preorder()
    {
        if (root == nullptr)
        {
            return;
        }
        stack<Node *> s;
        s.push(root);

        while (!s.empty())
        {
            Node *temp = s.top();
            s.pop();
            cout << " " << temp->data << " ";

            if (temp->left)
                s.push(temp->left);
            if (temp->right)
                s.push(temp->right);
        }
        cout << endl;
    }
};

int main()
{
    BToperation BT;
    int choice, value;

    while (true)
    {
        cout << "----------------------Binary Tree Operation-----------------" << endl;
        cout << "1.Insert the value" << endl;
        cout << "2.Preorder" << endl;
        cout << "3. End the Program.." << endl;
        cout << "Enter Your Choice :";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the Value You want TO insert :";
            cin>>value;
            BT.create(value);
            break;
        case 2:
            BT.preorder();
            break;
        case 3:
            return 0;
            break;
        default:
            cout << "please select the Valid Choice !" << endl;
            break;
        }
    }

    return 0;
}