// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    struct Node {
        Node *arr[26];
        bool flag = false;
        int count = 0;

        bool contains(char ch) {
            return (arr[ch - 'a'] != nullptr);
        }

        void put(char ch, Node *newNode) {
            newNode->count = 1;
            arr[ch - 'a'] = newNode;
        }

        Node *getNext(char ch) {
            return arr[ch - 'a'];
        }

        void setFlag() {
            flag = true;
        }

        bool isFlagSet() {
            return flag;
        }
    };

    void insert(Node *root, string word) {
        Node *temp = root;
        for (char ch : word) {
            if (!temp->contains(ch)) {
                Node *newNode = new Node();
                temp->put(ch, newNode);
                temp = temp->getNext(ch);
            } else {
                temp = temp->getNext(ch);
                temp->count++;
            }
        }
        temp->setFlag();
    }
    void shortestPrefix(Node *root, string word, vector<string> &ans) {
        string temp;
        for (char ch : word) {
            temp += ch;
            // cout << ch << "  555  " << temp << "  666  " << root->count << endl;
            root = root->getNext(ch);
            if (root->count == 1) {
                ans.push_back(temp);
                return;
            }
        }
        ans.push_back(temp);
    }
    vector<string> findPrefixes(string arr[], int n)
    {
        Node *root = new Node();
        for (int i = 0; i < n; i++) {
            insert(root, arr[i]);
        }
        vector<string> ans;
        for (int i = 0; i < n; i++) {
            shortestPrefix(root, arr[i], ans);
        }
        return ans;
    }

};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        string arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        Solution ob;
        vector<string> ans = ob.findPrefixes(arr, n);

        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";


        cout << "\n";

    }

    return 0;
}
// } Driver Code Ends