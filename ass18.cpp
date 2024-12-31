#include <iostream>
using namespace std;

#define MAX 100
/*
Đồ thị hình thứ 2 cô gửi (không có trọng số)

Ma trận kề:
1
7
0 1 1 1 0 0 0
0 0 0 0 1 0 0
0 0 0 0 1 0 0
0 0 0 0 0 1 0
0 0 0 0 0 1 1
0 0 0 0 0 0 1
0 0 0 0 0 0 0

Danh sách kề:
0: 1 2 3
1: 4
2: 4
3: 5
4: 5 6
5: 6
6:
*/

struct Queue {
    int data[MAX];
    int front, rear;

    void init() {
        front = rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    void push(int x) {
        if (front == -1) front = 0;
        data[++rear] = x;
    }

    int pop() {
        int x = data[front];
        if (front == rear)
            front = rear = -1;
        else
            front++;
        return x;
    }
};

struct Stack {
    int data[MAX];
    int top;

    void init() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    void push(int x) {
        data[++top] = x;
    }

    int pop() {
        return data[top--];
    }
};

class GraphMatrix {
    int n;
    int adj[MAX][MAX];

public:
    void input() {
        cin >> n;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> adj[i][j];
    }

    void BFS(int start) {
        bool visited[MAX] = {false};
        Queue q;
        q.init();
        visited[start] = true;
        q.push(start);
        while (!q.isEmpty()) {
            int u = q.pop();
            cout << u << " ";
            for (int v = 0; v < n; v++) {
                if (adj[u][v] && !visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        cout << endl;
    }

    void DFS(int start) {
        bool visited[MAX] = {false};
        Stack s;
        s.init();
        s.push(start);
        while (!s.isEmpty()) {
            int u = s.pop();
            if (!visited[u]) {
                visited[u] = true;
                cout << u << " ";
            }
            for (int v = n - 1; v >= 0; v--) {
                if (adj[u][v] && !visited[v]) {
                    s.push(v);
                }
            }
        }
        cout << endl;
    }
};

struct Node {
    int vertex;
    Node* next;
};

struct AdjList {
    Node* head;
};

class GraphList {
    int n;
    AdjList list[MAX];

public:
    void init() {
        for (int i = 0; i < MAX; i++)
            list[i].head = nullptr;
    }

    void input() {
        cin >> n;
        for (int i = 0; i < n; i++) {
            int v;
            while (true) {
                cin >> v;
                if (v == -1) break;
                Node* newNode = new Node{v, list[i].head};
                list[i].head = newNode;
            }
        }
    }

    void BFS(int start) {
        bool visited[MAX] = {false};
        Queue q;
        q.init();
        visited[start] = true;
        q.push(start);
        while (!q.isEmpty()) {
            int u = q.pop();
            cout << u << " ";
            for (Node* p = list[u].head; p != nullptr; p = p->next) {
                if (!visited[p->vertex]) {
                    visited[p->vertex] = true;
                    q.push(p->vertex);
                }
            }
        }
        cout << endl;
    }

    void DFS(int start) {
        bool visited[MAX] = {false};
        Stack s;
        s.init();
        s.push(start);
        while (!s.isEmpty()) {
            int u = s.pop();
            if (!visited[u]) {
                visited[u] = true;
                cout << u << " ";
            }
            for (Node* p = list[u].head; p != nullptr; p = p->next) {
                if (!visited[p->vertex]) {
                    s.push(p->vertex);
                }
            }
        }
        cout << endl;
    }
};

int main() {
    GraphMatrix gm;
    GraphList gl;
    int choice;
    cin >> choice;
    if (choice == 1) {
        gm.input();
        gm.BFS(0);
        gm.DFS(0);
    } else if (choice == 2) {
        gl.init();
        gl.input();
        gl.BFS(0);
        gl.DFS(0);
    }
    return 0;
}