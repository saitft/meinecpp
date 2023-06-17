// Bu program, bir bağlı listeyi oluşturur ve ekrana yazdırır recursive fonksiyon kullanarak.
#include <iostream>

using namespace std;

// Node yapısı
struct Node {
    int data;
    Node* next;
};

// Bağlı listeyi ekrana yazdıran fonksiyon  
void dumplist(Node* node) {
    if (node == nullptr) {
        return;
    }
    cout << node->data << " ";
    dumplist(node->next);
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

    // Listeyi ekrana yazdırma
    cout << "The linked list is: ";
    dumplist(head);

    return 0;
}
