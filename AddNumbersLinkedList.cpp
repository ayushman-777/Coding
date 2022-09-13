// { Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin >> val;

    Node* head = new Node(val);
    Node* tail = head;

    for (int i = 0; i < size - 1; i++)
    {
        cin >> val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node* n)
{
    while (n)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        int n = 0, m = 0;
        Node *temp = first, *ans = new Node(0);
        Node *lnn = ans;
        while (temp) {
            temp = temp->next;
            n++;
        }
        temp = second;
        while (temp) {
            m++;
            temp = temp->next;
        }
        temp = ans;
        while (n != 0 && m != 0) {
            if (n == m) {
                int add = first->data + second->data;
                if (add < 10) {
                    temp->next = new Node(add);
                    temp = temp->next;
                    if (add < 9) lnn = temp;
                } else {
                    temp->next = new Node(add % 10);
                    temp = temp->next;
                    lnn->data += 1;
                    lnn = lnn->next;
                    while (lnn != temp) {
                        lnn->data = 0;
                        lnn = lnn->next;
                    }
                }
                first = first->next;
                second = second->next;
                n--;
                m--;
            } else if (n > m) {
                while (n != m) {
                    n--;
                    temp->next = new Node(first->data);
                    first = first->next;
                    temp = temp->next;
                    if (temp->data < 9) {
                        lnn = temp;
                    }
                }
            } else {
                while (n != m) {
                    m--;
                    temp->next = new Node(second->data);
                    temp = temp->next;
                    second = second->next;
                    if (temp->data < 9) {
                        lnn = temp;
                    }
                }
            }
        }
        return ans->data == 0 ? ans->next : ans;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;

        cin >> n;
        Node* first = buildList(n);

        cin >> m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first, second);
        printList(res);
    }
    return 0;
}
// } Driver Code Ends