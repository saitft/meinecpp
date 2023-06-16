// Bu program, bir bağlı listenin son elemanını bulur recursive fonksiyon kullanarak .
#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* last(Node* node) {
    if (node == nullptr || node->next == nullptr) {
        return node;
    }
    return last(node->next);
}

int main() {
    system("cls"); // terminali temizleme 
    system("echo off"); // terminalde komutları gizleme
    // Bir bağlı liste oluşturma 
    Node* head = new Node();
    head->data = 5;
    Node* second = new Node();
    second->data = 12;
    head->next = second;
    Node* third = new Node();
    third->data = 13;
    second->next = third;

    // Listedeki son node'u bulma
    Node* lastNode = last(head);

    // Son node'un data'sını yazdırma
    cout << "The last node in the linked list has data " << lastNode->data << endl;

    return 0;
}
