// { Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

 // } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    Node* construct(int in[], int pre[], int inStart, int inEnd, 
    								int preStart, int preEnd, 
    								unordered_map<int, int> &mp) {
    	if (inStart > inEnd || preStart > preEnd) return nullptr;

    	Node *temp = new Node(pre[preStart]);

    	int inRoot = mp[temp->data];
    	int numsLeft = inRoot - inStart;

    	temp->left = construct(in, pre, inStart, inRoot - 1, 
    												 preStart + 1, preStart + numsLeft, mp);

    	temp->right = construct(in, pre, inRoot + 1, inEnd, 
    													preStart + numsLeft + 1, preEnd, mp);

    }

    Node* buildTree(int in[],int pre[], int n)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i<n; i++) mp[in[i]] = i;

        Node *res = construct(in, pre, 0, n-1, 0, n-1, mp);

      	return res;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}
  // } Driver Code Ends