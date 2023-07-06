#include <iostream>
#include <conio.h>

using namespace std;

struct Node {
    int data;
    Node *prev, *next;
};

void cutlast(Node **head) {
    if (*head == nullptr) {
        return;
    }
    Node *last = (*head)->prev;
    Node *second_last = last->prev;
    second_last->next = *head;
    (*head)->prev = second_last;
    cout << "Kesilen eleman: " << last->data << endl;
    delete last;
}

int main() {
    // İlk bağlı liste oluşturulur
    Node *head1 = nullptr;
    Node *n1 = new Node{1, nullptr, nullptr};
    Node *n2 = new Node{2, nullptr, nullptr};
    Node *n3 = new Node{3, nullptr, nullptr};

    n1->prev = n3;
    n1->next = n2;
    n2->prev = n1;
    n2->next = n3;
    n3->prev = n2;
    n3->next = n1;
    head1 = n1;

    // İkinci bağlı liste oluşturulur
    Node *head2 = nullptr;
    Node *n4 = new Node{4, nullptr, nullptr};
    Node *n5 = new Node{5, nullptr, nullptr};
    Node *n6 = new Node{6, nullptr, nullptr};

    n4->prev = n6;
    n4->next = n5;
    n5->prev = n4;
    n5->next = n6;
    n6->prev = n5;
    n6->next = n4;
    head2 = n4;

    // İlk bağlı listenin son elemanı kesilir ve ekrana yazdırılır
    cutlast(&head1);

    // İkinci bağlı listenin son elemanı kesilir ve ekrana yazdırılır
    cutlast(&head2);

    return 0;
}
