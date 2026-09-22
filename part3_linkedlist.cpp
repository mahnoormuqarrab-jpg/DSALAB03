#include <iostream>
using namespace std;

// A node in the linked list
struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

// 1. Insert a new node at the head
void insertAtHead(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    cout << "Inserted " << value << " at head." << endl;
}

// 2. Insert a new node at the 3rd position
void insertAtThird(int value) {
    Node* newNode = new Node();
    newNode->data = value;

    if (head == NULL || head->next == NULL) {
        cout << "List has fewer than 2 nodes. Inserting at head instead." << endl;
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;
    // move to the 2nd node, so we can insert after it (making new node 3rd)
    temp = temp->next;
    newNode->next = temp->next;
    temp->next = newNode;
    cout << "Inserted " << value << " at 3rd position." << endl;
}
// 3. Display the list
void displayList() {
    Node* temp = head;
    if (temp == NULL) {
        cout << "List is empty." << endl;
        return;
    }
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// 4. Delete the last node
void deleteLast() {
    if (head == NULL) {
        cout << "List is empty, nothing to delete." << endl;
        return;
    }
    if (head->next == NULL) {
        delete head;
        head = NULL;
        cout << "Deleted the only node." << endl;
        return;
    }
    Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
    cout << "Deleted last node." << endl;
}

// 5. Count nodes
int countNodes() {
    int count = 0;
    Node* temp = head;
    while (temp != NULL) {
        count = count + 1;
        temp = temp->next;
    }
    return count;
}

// 6. Reverse the list iteratively
void reverseList() {
    Node* prev = NULL;
    Node* current = head;
    Node* nextNode = NULL;

    while (current != NULL) {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }
    head = prev;
    cout << "List reversed." << endl;
}

// 7. Search for a value
void searchValue(int value) {
    Node* temp = head;
    int position = 0;
    while (temp != NULL) {
        if (temp->data == value) {
            cout << "Value " << value << " found at position " << position << endl;
            return;
        }
        temp = temp->next;
        position = position + 1;
    }
    cout << "Value " << value << " not found in the list." << endl;
}

// 8. Menu-driven main function
int main() {
    int choice;
    int value;

    do {
        cout << "\n----- Linked List Menu -----" << endl;
        cout << "1. Insert at head" << endl;
        cout << "2. Insert at 3rd position" << endl;
        cout << "3. Display list" << endl;
        cout << "4. Delete last node" << endl;
        cout << "5. Count nodes" << endl;
        cout << "6. Reverse list" << endl;
        cout << "7. Search for a value" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                insertAtHead(value);
                break;
            case 2:
                cout << "Enter value to insert: ";
                cin >> value;
                insertAtThird(value);
                break;
            case 3:
                displayList();
                break;
            case 4:
                deleteLast();
                displayList();
                break;
            case 5:
                cout << "Number of nodes: " << countNodes() << endl;
                break;
            case 6:
                reverseList();
                displayList();
                break;
            case 7:
                cout << "Enter value to search: ";
                cin >> value;
                searchValue(value);
                break;
            case 8:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice, try again." << endl;
        }
    } while (choice != 8);

    return 0;
}
