#include <iostream>
using namespace std;

// -------------------------
// Basic singly linked list
// -------------------------
struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

// Utility to print the list (for testing)
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// -------------------------
// Split a list into two halves
// (using fast/slow pointer technique)
// -------------------------
void splitList(Node* source, Node*& front, Node*& back) {
    if (source == nullptr || source->next == nullptr) {
        front = source;
        back = nullptr;
        return;
    }

    Node* slow = source;
    Node* fast = source->next;

    // Advance fast two nodes, slow one node
    while (fast != nullptr) {
        fast = fast->next;
        if (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    front = source;
    back = slow->next;
    slow->next = nullptr;
}

// -------------------------
// Merge two sorted lists
// -------------------------
Node* mergeLists(Node* left, Node* right) {
    if (left == nullptr) return right;
    if (right == nullptr) return left;

    Node* result = nullptr;

    if (left->data <= right->data) {
        result = left;
        result->next = mergeLists(left->next, right);
    }
    else {
        result = right;
        result->next = mergeLists(left, right->next);
    }

    return result;
}

// -------------------------
// The main recursive merge sort
// -------------------------
void mergeSort(Node*& head) {
    if (head == nullptr || head->next == nullptr)
        return; // Base case: already sorted or empty

    Node* left = nullptr;
    Node* right = nullptr;

    // Step 1: split the list
    splitList(head, left, right);

    // Step 2: recursively sort both halves
    mergeSort(left);
    mergeSort(right);

    // Step 3: merge final sorted halves
    head = mergeLists(left, right);
}

// -------------------------
// Example test driver
// -------------------------
int main() {
    Node* head = new Node(34);
    head->next = new Node(12);
    head->next->next = new Node(87);
    head->next->next->next = new Node(23);
    head->next->next->next->next = new Node(5);

    cout << "Original list: ";
    printList(head);

    mergeSort(head);

    cout << "Sorted list:   ";
    printList(head);

    return 0;
}
