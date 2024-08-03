//
// Created by patha on 06-08-2020.
//

#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *next;
};

void insertEnd(int dataEnd, Node *head);

void insertBeg(int dataBeg, Node *head);

void deleteEnd(Node *head);

void deleteN(Node *head, int pos);

void deleteBeg(Node *head);

void insertN(int data, Node *head, int pos);

void Display(Node *np) {
    if (np == nullptr) { cout << "No Element in the List!" << endl; }
    else {
        while (np != nullptr) {
            cout << np->data << "  --->  ";
            np = np->next;
        }
        cout << endl << "List ended here !!! " << endl;
    }
}

int main() {

    int t;
    cout << "Enter number of elements of linked list (>0) :";
    cin >> t;
    Node *head = new Node, *temp = new Node;
    Node *nw = new Node;
    cout << "Enter data  :";
    cin >> nw->data;
    nw->next = nullptr;
    head->next = nw;
    head->data = -1;
    temp->next = nw;
    while (t - 1) {
        Node *nw1 = new Node;
        cout << "Enter data  :";
        cin >> nw1->data;
        nw->next = nw1;
        nw1->next = nullptr;
        nw = nw1;
        t--;
    }
    Display(head);

    while (true) {
        int ans;
        cout << "\nEnter 0 to Exit.\n";
        cout << "Enter 1 to insert at beginning.\n";
        cout << "Enter 2 to insert at end.\n";
        cout << "Enter 3 to insert at nth position.\n";
        cout << "Enter 4 to delete at beginning.\n";
        cout << "Enter 5 to delete at end.\n";
        cout << "Enter 6 to delete at nth position.\n";

        cin >> ans;
        switch (ans) {
            case 0:
                exit(0);
            case 1:
                int dataBeg;
                cout << "Enter data :";
                cin >> dataBeg;
                insertBeg(dataBeg, head);
                Display(head);
                break;
            case 2:
                int dataEnd;
                cout << "Enter data :";
                cin >> dataEnd;
                insertEnd(dataEnd, head);
                Display(head);
                break;
            case 3:
                int dataN, insertPos;
                cout << "Enter position to insert on :";
                cin >> insertPos;
                cout << "\nEnter data :";
                cin >> dataN;
                insertN(dataN, head, insertPos);
                Display(head);
                break;
            case 4:
                deleteBeg(head);
                Display(head);
                break;
            case 5:
                deleteEnd(head);
                Display(head);
                break;
            case 6:
                int deletePos;
                cout << "Enter position to delete :";
                cin >> deletePos;
                deleteN(head, deletePos);
                Display(head);
                break;
            default:
                cout << "Wrong choice. Enter choice again.\n";
                break;
        }
    }
}

void insertBeg(int data, Node *head) {
    Node *nw = new Node;
    nw->data = data;
    nw->next = head->next;
    head->next = nw;
}

void insertEnd(int data, Node *head) {
    Node *temp, *nw = new Node;
    nw->data = data;
    nw->next = nullptr;
    temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = nw;
}

void insertN(int data, Node *head, int pos) {
    Node *temp, *nw = new Node;
    nw->data = data;
    temp = head;
    while (pos - 1) {
        temp = temp->next;
        pos--;
    }
    nw->next = temp->next;
    temp->next = nw;
}

void deleteBeg(Node *head) {
    Node *temp;
    temp = head->next;
    head->next = temp->next;
    free(temp);
}

void deleteEnd(Node *head) {
    Node *temp1, *temp2;
    temp1 = head->next;
    temp2 = head;
    while (temp1->next != nullptr) {
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    temp2->next = nullptr;
    free(temp1);
}

void deleteN(Node *head, int pos) {
    bool ck = false;

    Node *temp1, *temp2;
    temp1 = head;
    temp2 = head->next;

    while (pos - 1) {
        if (ck) {
            cout<<"UNDERFLOW! \n";
            return;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
        if (temp2->next == nullptr) {
            ck = true;
        }
        pos--;

    }
    temp1->next = temp2->next;
    free(temp2);
}


