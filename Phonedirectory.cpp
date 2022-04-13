/*// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
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

    void storeAll(Node *node, string prefix, vector<string> &ans) {
        if (node == nullptr) return;
        if (node->isFlagSet()) {
            ans.push_back(prefix);
            return;
        }
        for (int i = 0; i < 26; i++) {
            if (node->arr[i] != nullptr) {
                char ch = 'a' + i;
                storeAll(node->arr[i], prefix + ch, ans);
            }
        }
    }

    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        Node *root = new Node();
        for (int i = 0; i < n; i++) {
            insert(root, contact[i]);
        }
        vector<vector<string>> ans;
        Node *node = root;
        string prefix;
        for (auto ch : s) {
            vector<string> temp;
            prefix += ch;
            if (node != nullptr && node->contains(ch)) {
                storeAll(node->getNext(ch), prefix, temp);
                if (temp.empty()) {
                    temp.push_back("0");
                }
                node = node->getNext(ch);
            } else {
                temp.push_back("0");
                node = nullptr;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string contact[n], s;
        for (int i = 0; i < n; i++)
            cin >> contact[i];
        cin >> s;

        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for (int i = 0; i < s.size(); i++) {
            for (auto u : ans[i])
                cout << u << " ";
            cout << "\n";
        }
    }
    return 0;
}  // } Driver Code Ends*/


// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

struct Node {
    Node* links[26];
    bool flag = false;

    bool containsKey(char ch) {
        return links[ch - 'a'];
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    bool isEnd() {
        return flag;
    }

    void setEnd() {
        flag = true;
    }
};

class Trie {
private:
    Node* root;
public:

    vector<string> arr;
    vector<vector<string>> result;

    Trie() {
        root = new Node();
    }


    void insert(string word) {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->containsKey(word[i])) {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }

        node->setEnd();
    }


    void search(Node* root, string &str) {
        if (!root) return;
        if (root->isEnd()) arr.push_back(str);

        for (int k = 0; k < 26; k++) {
            char ch = k + 'a';
            str.push_back(ch);
            search(root->get(ch), str);
            str.pop_back();
        }
    }

    void search(string &str) {
        Node* node = root;
        for (char &ch : str) {
            if (!node->containsKey(ch)) {
                result.push_back({"0"});
                return;
            }
            node = node->get(ch);
        }
        arr.clear();
        search(node, str);

        result.push_back(arr);
    }
};


class Solution {
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
        Trie trie;
        for (int i = 0; i < n; i++) {
            trie.insert(contact[i]);
        }

        string _str = "";
        for (char &ch : s) {
            _str += ch;
            trie.search(_str);
        }

        return trie.result;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string contact[n], s;
        for (int i = 0; i < n; i++)
            cin >> contact[i];
        cin >> s;

        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for (int i = 0; i < s.size(); i++) {
            for (auto u : ans[i])
                cout << u << " ";
            cout << "\n";
        }
    }
    return 0;
}  // } Driver Code Ends