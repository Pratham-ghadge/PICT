#include <iostream>
using namespace std;

class Node {
    int data;
    Node* next;

public:
    Node(int val) { 
        data = val; 
        next = nullptr; 
    }

    int getData() { return data; }
    Node* getNext() { return next; }
    void setNext(Node* nxt) { next = nxt; }

    friend class Graph;  // Allows Graph to access private members
};

class Graph {
    Node* head[20];  // Array of adjacency lists
    bool visited[20]; // Visited array for traversal

public:
    Graph(int vertices) {
        for (int i = 1; i <= vertices; i++) {
            head[i] = new Node(i); // Create a dummy head node for each vertex
            visited[i] = false;
        }
    }

    void addEdge(int source, int dest) {
        // Adding edge from source to destination
        Node* temp = head[source];
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->setNext(new Node(dest));

        // Adding edge from destination to source (for an undirected graph)
        temp = head[dest];
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->setNext(new Node(source));
    }

    void createGraph(int edges) {
        int source, dest;
        for (int i = 1; i <= edges; i++) {
            cout << "Enter edge " << i << " (source destination): ";
            cin >> source >> dest;
            addEdge(source, dest);
        }
    }

    void BFS(int start) {
        int queue[20], front = 0, rear = 0;
        queue[rear++] = start;
        visited[start] = true;

        cout << "BFS Traversal: ";
        while (front < rear) {
            int current = queue[front++];
            cout << current << " ";

            Node* temp = head[current]->getNext();
            while (temp) {
                if (!visited[temp->getData()]) {
                    queue[rear++] = temp->getData();
                    visited[temp->getData()] = true;
                }
                temp = temp->getNext();
            }
        }
        cout << endl;
    }

    void DFS(int vertex, bool visited[]) {
        cout << vertex << " ";
        visited[vertex] = true;

        Node* temp = head[vertex]->getNext();
        while (temp) {
            if (!visited[temp->getData()]) {
                DFS(temp->getData(), visited);
            }
            temp = temp->getNext();
        }
    }

    void displayGraph(int vertices) {
        cout << "\nGraph Representation (Adjacency List):\n";
        for (int i = 1; i <= vertices; i++) {
            cout << "Vertex " << i << " ->";
            Node* temp = head[i]->getNext();
            while (temp) {
                cout << " " << temp->getData();
                temp = temp->getNext();
            }
            cout << endl;
        }
    }
};

int main() {
    int vertices, edges;

    cout << "Enter number of vertices: ";
    cin >> vertices;

    Graph g(vertices);

    cout << "Enter number of edges: ";
    cin >> edges;
    g.createGraph(edges);

    g.displayGraph(vertices);

    int startVertex;
    cout << "\nEnter starting vertex for BFS: ";
    cin >> startVertex;
    g.BFS(startVertex);

    bool visited[vertices + 1] = {false};
    cout << "\nEnter starting vertex for DFS: ";
    cin >> startVertex;
    cout << "DFS Traversal: ";
    g.DFS(startVertex, visited);
    cout << endl;

    return 0;
}
