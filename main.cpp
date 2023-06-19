#include <iostream>
using namespace std;
const int MAX_KEYS = 3;
struct node {
    int keys[MAX_KEYS];
    node* children[MAX_KEYS + 1];
    int key_count;
    bool leaf;
};
node* newnode() {
    node* new_node = new node;
    new_node->key_count = 0;
    new_node->leaf = true;
    for (int i = 0; i < MAX_KEYS; i++) {
        new_node->keys[i] = 0;
        new_node->children[i] = nullptr;
    }
    new_node->children[MAX_KEYS] = nullptr;
    return new_node;
}
void inserttree(node*& tree, node* new_node) {
    if (tree == nullptr) {
        tree = new_node;
        new_node->leaf = false;
        return;
    }
    int key = new_node->keys[0];
    int pos = tree->key_count;
    if (tree->leaf) {
        while (pos > 0 && tree->keys[pos - 1] > key) {
            tree->keys[pos] = tree->keys[pos - 1];
            pos--;
        }
        tree->keys[pos] = key;
        tree->key_count++;
    } else {
        while (pos > 0 && tree->keys[pos - 1] > key) 
            pos--;
        if (tree->children[pos] != nullptr && tree->children[pos]->key_count == MAX_KEYS) {
            node* split_node = newnode();
            node* child_node = tree->children[pos];
            int mid = child_node->keys[MAX_KEYS / 2];
            split_node->leaf = child_node->leaf;
            split_node->key_count = MAX_KEYS / 2;
            for (int i = 0; i < MAX_KEYS / 2; i++) {
                split_node->keys[i] = child_node->keys[i + MAX_KEYS / 2 + 1];
                split_node->children[i] = child_node->children[i + MAX_KEYS / 2 + 1];
            }
            split_node->children[MAX_KEYS / 2] = child_node->children[MAX_KEYS];
            child_node->key_count = MAX_KEYS / 2;
            for (int i = tree->key_count; i > pos; i--) 
                tree->keys[i] = tree->keys[i - 1];
            for (int i = tree->key_count + 1; i > pos + 1; i--) 
                tree->children[i] = tree->children[i - 1];
            tree->keys[pos] = mid;
            tree->children[pos] = child_node;
            tree->children[pos + 1] = split_node;
            tree->key_count++;
            if (key > mid) 
                inserttree(tree->children[pos + 1], new_node);
            else 
                inserttree(tree->children[pos], new_node);
        } else 
            inserttree(tree->children[pos], new_node);
        
    }
}
void printtree(node* tree) {
    if (tree != nullptr) {
        for (int i = 0; i < tree->key_count; i++) {
            printtree(tree->children[i]);
            cout << tree->keys[i] << " ";
        }
        printtree(tree->children[tree->key_count]);
    }
}
int main() {
    node* tree = nullptr;
    int keys[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100}; 
    int n = sizeof(keys) / sizeof(keys[0]);
    for (int i = 0; i < n; i++) {
        node* new_node = newnode();
        new_node->keys[0] = keys[i];
        new_node->key_count++;
        inserttree(tree, new_node);
    }
    cout << "B-Tree: ";
    printtree(tree);
    cout << endl;
    return 0;
}
