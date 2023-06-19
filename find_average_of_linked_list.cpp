// Bu program bir bağlı listenin ortalamasını bulur recuirsive fonksiyon kullanarak .
#include <iostream>

using namespace std;

// Node yapısı
struct Node {
    int data;
    Node* next;
};

// Bağlı listedeki elemanların ortalamasını bulan fonksiyon
double ortalama(Node* node, int toplam, int sayac) {
    if (node == nullptr) {
        if (sayac == 0) {
            return 0.0; // Eğer listede düğüm yoksa, ortalama 0 olarak kabul edilir.
        } else {
            return static_cast<double>(toplam) / sayac; // Toplamı sayaca bölerek ortalama hesaplanır.
        }
    }

    toplam += node->data;
    sayac++;

    return ortalama(node->next, toplam, sayac);
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

    // Listedeki dataların ortalamsını bulma
    double average = ortalama(head, 0, 0);

    // Ortalamayı ekrana yazdırma 
    cout << "The average of the linked list is: " << average << endl;

    return 0;
}
