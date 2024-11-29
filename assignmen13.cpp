#include <iostream>
#include <string>
using namespace std;

// Cấu trúc node đại diện cho một giỏ hàng của một khách hàng
struct Node {
    string customerName; // Tên khách hàng
    int totalAmount;     // Tổng tiền của giỏ hàng
    int productACount;   // Số lượng sản phẩm A
    Node* next;          // Con trỏ tới node tiếp theo
};

// Cấu trúc hàng đợi
struct Queue {
    Node* front; // Con trỏ tới phần tử đầu tiên
    Node* rear;  // Con trỏ tới phần tử cuối cùng
};

// Khởi tạo hàng đợi
void Queue_Init(Queue &q) {
    q.front = nullptr;
    q.rear = nullptr;
}

// Kiểm tra hàng đợi có rỗng hay không
bool isEmpty(Queue &q) {
    return q.front == nullptr;
}

// Thêm một khách hàng vào hàng đợi
void enqueue(Queue &q, string name, int amount, int countA) {
    Node* newNode = new Node{name, amount, countA, nullptr};
    if (isEmpty(q)) {
        q.front = q.rear = newNode;
    } else {
        q.rear->next = newNode;
        q.rear = newNode;
    }
}

// Xóa khách hàng đầu tiên khỏi hàng đợi sau khi thanh toán
void dequeue(Queue &q) {
    if (isEmpty(q)) {
        cout << "Hang doi rong, khong co khach hang de xoa!" << endl;
        return;
    }
    Node* temp = q.front;
    q.front = q.front->next;
    if (q.front == nullptr) {
        q.rear = nullptr;
    }
    delete temp;
}

// Tính tổng số tiền thu ngân thu được
int calculateTotalRevenue(Queue &q) {
    int totalRevenue = 0;
    Node* current = q.front;
    while (current != nullptr) {
        totalRevenue += current->totalAmount;
        current = current->next;
    }
    return totalRevenue;
}

// Đếm số lượng sản phẩm A đã bán
int countProductA(Queue &q) {
    int totalProductA = 0;
    Node* current = q.front;
    while (current != nullptr) {
        totalProductA += current->productACount;
        current = current->next;
    }
    return totalProductA;
}

int main() {
    Queue q;
    Queue_Init(q);

    // Thêm khách hàng vào hàng đợi
    enqueue(q, "Alice", 500, 2);
    enqueue(q, "Bob", 300, 1);
    enqueue(q, "Charlie", 700, 3);

    // Hiển thị tổng số tiền thu được
    cout << "Tong so tien thu ngan thu duoc: " << calculateTotalRevenue(q) << " VND" << endl;

    // Hiển thị số lượng sản phẩm A đã bán
    cout << "Tong so luong san pham A da ban: " << countProductA(q) << endl;

    // Xóa khách hàng đầu tiên
    dequeue(q);

    // Hiển thị tổng số tiền và số lượng sản phẩm sau khi xóa 1 khách hàng
    cout << "Sau khi xoa khach hang dau tien:" << endl;
    cout << "Tong so tien thu ngan thu duoc: " << calculateTotalRevenue(q) << " VND" << endl;
    cout << "Tong so luong san pham A da ban: " << countProductA(q) << endl;

    return 0;
}
