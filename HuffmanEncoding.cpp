// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
	struct MinHeapNode {
		int freq;
		MinHeapNode *left, *right;
		MinHeapNode(int f) {
			this->freq = f;
			this->left = nullptr;
			this->right = nullptr;
		}
	};
	class comp {
	public:
		bool operator()(MinHeapNode* m1, MinHeapNode* m2) {
			return m1->freq > m2->freq; // for extracting minimum
		}
	};

	void fillVector(MinHeapNode* root, string s, vector<string> &vec) {
		if (!root) return;

		if (root->left == nullptr && root->right == nullptr) {
			vec.push_back(s);
			return;
		}

		fillVector(root->left, s+'0', vec);
		fillVector(root->right, s+'1', vec);
	}

vector<string> huffmanCodes(string s, vector<int> f, int n) {
		priority_queue<MinHeapNode*, vector<MinHeapNode*>, comp> pq;
		for (auto ele : f) pq.push(new MinHeapNode(ele));
		while (pq.size() > 1) {
			MinHeapNode* left = pq.top();
			pq.pop();
			MinHeapNode* right = pq.top();
			pq.pop();
			MinHeapNode* top = new MinHeapNode(left->freq + right->freq);
			top->left = left;
			top->right = right;
			pq.push(top);
		}
		vector<string> ans;
		fillVector(pq.top(), "", ans);
		return ans;
	}
};

// { Driver Code Starts.
int main() {
	int T;
	cin >> T;
	while (T--)
	{
		string S;
		cin >> S;
		int N = S.length();
		vector<int> f(N);
		for (int i = 0; i < N; i++) {
			cin >> f[i];
		}
		Solution ob;
		vector<string> ans = ob.huffmanCodes(S, f, N);
		for (auto i : ans)
			cout << i << " ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends