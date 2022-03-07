// { Driver Code Starts
#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
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

void printInorder (struct Node* node)
{
	if (node == NULL)return;
	printInorder(node->left);
	printf("%d ", node->data);
	printInorder (node->right);
}

Node* constructTree(int n, int pre[], char preLN[]);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        Node* root = NULL;
        int n;
        cin>>n;
        int pre[n];
        char preLN[n];
        for(int i=0; i<n; i++)cin>>pre[i];
        for(int i=0; i<n; i++)cin>>preLN[i];
        root = constructTree (n, pre, preLN);
        printInorder(root);
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends


/*Structure of the Node of the binary tree is as
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
};
*/
// function should return the root of the new binary tree formed
struct Node *constructTreeUtil(int n, int pre[], char preLN[], int &ind)
{
	cout << ind << endl;
    if (ind < n) {
    	Node* node = new Node(pre[ind]);
    	if (preLN[ind]=='L') return node;
    	else {
    		ind++;
    		node->left = constructTreeUtil(n, pre, preLN, ind);
    		ind++;
    		node->right = constructTreeUtil(n, pre, preLN, ind);
    		return node;
    	}
    }
    return nullptr;
}

struct Node *constructTree(int n, int pre[], char preLN[]) {
	int i =0;
	return constructTreeUtil(n, pre, preLN, i);
}