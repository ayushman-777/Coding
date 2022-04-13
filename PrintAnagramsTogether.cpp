// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


// } Driver Code Ends
//User function Template for C++

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

    bool search(Node *root, string word) {
        for (int i = 0; i < word.size(); i++) {
            if (!root->contains(word[i])) {
                return false;
            }
            root = root->getNext(word[i]);
        }
        return root != nullptr && root->isFlagSet();
    }
    vector<vector<string>> Anagrams(vector<string> &string_list) {
        map<string, vector<string>> mp;
        vector<vector<string>> ans;
        string temp;
        Node *root = new Node();
        for (auto s : string_list) {
            temp = s;
            sort(temp.begin(), temp.end());
            mp[temp].push_back(s);
        }
        for (auto ele : mp) {
            ans.push_back(ele.second);
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
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin >> string_list[i];
        Solution ob;
        vector<vector<string> > result = ob.Anagrams(string_list);
        sort(result.begin(), result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for (int j = 0; j < result[i].size(); j++)
            {
                cout << result[i][j] << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}
// } Driver Code Ends