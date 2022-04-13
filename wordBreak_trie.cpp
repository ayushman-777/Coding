// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    // A : given string to search
    // B : vector of available strings

    struct Node {
        Node *arr[26];
        bool flag = false;

        bool contains(char ch) {
            return arr[ch - 'a'] != nullptr;
        }

        void put(char ch, Node *newNode) {
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
        for (int i = 0; i < word.size(); i++) {
            if (!root->contains(word[i])) {
                root->put(word[i], new Node());
            }
            root = root->getNext(word[i]);
        }
        root->setFlag();
    }

    bool search(Node *root, string word) {
        for (int i = 0; i < word.size(); i++) {
            if (!root->contains(word[i])) {
                return false;
            }
            root = root->getNext(word[i]);
        }
        return root != nullptr && root->isFlagSet();
    }

    bool wordBreakUtil(Node *node, string word) {
        if (word.size() == 0) return true;
        for (int i = 1; i <= word.size(); i++) {
            if (search(node, word.substr(0, i)) &&
                    wordBreakUtil(node, word.substr(i, word.size() - i))) {
                return true;
            }
        }
        return false;
    }

    int wordBreak(string A, vector<string> &B) {
        Node *root = new Node();
        for (auto ele : B) {
            insert(root, ele);
        }
        return wordBreakUtil(root, A);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string> dict;
        for (int i = 0; i < n; i++) {
            string S;
            cin >> S;
            dict.push_back(S);
        }
        string line;
        cin >> line;
        Solution ob;
        cout << ob.wordBreak(line, dict) << "\n";
    }
}
// } Driver Code Ends