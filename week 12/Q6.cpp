#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

class LinkedList {
    Node *head;

public:
    LinkedList() {
        head = NULL;
    }

    ~LinkedList() {
        while (head != NULL) {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    void insertAtBeginning(int value) {
        Node *node = new Node;
        node->data = value;
        node->next = head;
        head = node;
    }

    void insertAtEnd(int value) {
        Node *node = new Node;
        node->data = value;
        node->next = NULL;
        if (head == NULL) {
            head = node;
            return;
        }
        Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = node;
    }

    void insertAtPosition(int value, int pos) {
        if (pos < 1) {
            cout << "Invalid position" << endl;
            return;
        }
        if (pos == 1) {
            insertAtBeginning(value);
            return;
        }
        Node *temp = head;
        for (int i = 1; i < pos - 1 && temp != NULL; i++)
            temp = temp->next;
        if (temp == NULL) {
            cout << "Position out of range" << endl;
            return;
        }
        Node *node = new Node;
        node->data = value;
        node->next = temp->next;
        temp->next = node;
    }

    void deleteAtBeginning() {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        Node *temp = head;
        head = head->next;
        cout << "Deleted " << temp->data << endl;
        delete temp;
    }

    void deleteAtEnd() {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        if (head->next == NULL) {
            cout << "Deleted " << head->data << endl;
            delete head;
            head = NULL;
            return;
        }
        Node *temp = head;
        while (temp->next->next != NULL)
            temp = temp->next;
        cout << "Deleted " << temp->next->data << endl;
        delete temp->next;
        temp->next = NULL;
    }

    void deleteAtPosition(int pos) {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        if (pos < 1) {
            cout << "Invalid position" << endl;
            return;
        }
        if (pos == 1) {
            deleteAtBeginning();
            return;
        }
        Node *temp = head;
        for (int i = 1; i < pos - 1 && temp->next != NULL; i++)
            temp = temp->next;
        if (temp->next == NULL) {
            cout << "Position out of range" << endl;
            return;
        }
        Node *target = temp->next;
        temp->next = target->next;
        cout << "Deleted " << target->data << endl;
        delete target;
    }

    void display() {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        Node *temp = head;
        while (temp != NULL) {
            cout << temp->data;
            if (temp->next != NULL)
                cout << " -> ";
            temp = temp->next;
        }
        cout << " -> NULL" << endl;
    }
};

int main() {
    LinkedList list;
    int choice, value, pos;

    do {
        cout << endl;
        cout << "1. Insert at beginning" << endl;
        cout << "2. Insert at end" << endl;
        cout << "3. Insert at position" << endl;
        cout << "4. Delete at beginning" << endl;
        cout << "5. Delete at end" << endl;
        cout << "6. Delete at position" << endl;
        cout << "7. Display" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            list.insertAtBeginning(value);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> value;
            list.insertAtEnd(value);
            break;
        case 3:
            cout << "Enter value: ";
            cin >> value;
            cout << "Enter position (1-based): ";
            cin >> pos;
            list.insertAtPosition(value, pos);
            break;
        case 4:
            list.deleteAtBeginning();
            break;
        case 5:
            list.deleteAtEnd();
            break;
        case 6:
            cout << "Enter position (1-based): ";
            cin >> pos;
            list.deleteAtPosition(pos);
            break;
        case 7:
            list.display();
            break;
        case 8:
            break;
        default:
            cout << "Invalid choice" << endl;
        }
    } while (choice != 8);

    return 0;
}
