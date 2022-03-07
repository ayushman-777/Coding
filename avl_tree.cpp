//
// Created by patha on 12-10-2021.
//

#include "bits/stdc++.h"

using namespace std;

struct AVLNode {
    int data;
    int height;
    AVLNode *left;
    AVLNode *right;
};

AVLNode *newNode(int data) {
    AVLNode *temp = new AVLNode;
    temp->data = data;
    temp->height = 1;
    temp->left = nullptr;
    temp->right = nullptr;
    return temp;
}

int getHeight(AVLNode *node) {
    if (node == nullptr) {
        return 0;
    }
    return node->height;
}

AVLNode *rightRotate(AVLNode *node) {
    AVLNode *x = node->left;
    AVLNode *t3 = x->right;

    node->left = t3;
    x->right = node;

    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

AVLNode *leftRotate(AVLNode *node) {
    AVLNode *x = node->right;
    AVLNode *t3 = x->left;

    node->right = t3;
    x->left = node;

    node->height = max(getHeight(node->right), getHeight(node->left)) + 1;
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;

    return x;
}

int getBalance(AVLNode *node) {
    if (node == nullptr) {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

AVLNode *insert(AVLNode *root, int data) {
    if (root == nullptr) {
        return newNode(data);
    } else if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    } else {
        return root;
    }

    root->height = max(getHeight(root->right), getHeight(root->left)) + 1;

    int balance = getBalance(root);

    if (balance > 1 && data < root->left->data) {
        return rightRotate(root);
    }

    if (balance < -1 && data > root->right->data) {
        return leftRotate(root);
    }

    if (balance > 1 && data > root->left->data) {
        root->left = leftRotate(root);
    }

    if (balance < -1 && data < root->right->data) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void levelOrder(AVLNode *root) {
    if (root == nullptr) {
        return;
    }
    queue<AVLNode *> que;
    que.push(root);
    while (!que.empty()) {
        AVLNode *current = que.front();
        cout << current->data << "   ";
        if (current->left != nullptr) que.push(current->left);
        if (current->right != nullptr) que.push(current->right);
        que.pop();
    }
}

bool isBSTFast(AVLNode *root, int minData, int maxData) {
    if (root == nullptr) {
        return true;
    }
    if (root->data > minData && root->data < maxData && isBSTFast(root->left, minData, root->data) &&
        isBSTFast(root->right, root->data, maxData)) {
        return true;
    }
    return false;
}

void preOrder(AVLNode *root) {
    if (root == nullptr) {
        return;
    }
    cout << root->data << "   ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(AVLNode *root) {
    if (root == nullptr) {
        return;
    }
    inOrder(root->left);
    cout << root->data << "   ";
    inOrder(root->right);
}

int main() {
    AVLNode *root = nullptr;
    int ans = 1;
    do {
        if (ans == 1) {
            int n;
            cout << endl << "Enter no. of nodes of tree  :   ";
            cin >> n;
            while (n--) {
                cout << endl << "Enter data :  ";
                int data;
                cin >> data;
                root = insert(root, data);
            }
        }
//        else if (ans == 2) {
//            int data;
//            cout << endl << "Enter element to search for";
//            cin >> data;
//            if (search(root, data)) {
//                cout << endl << "Element found";
//            } else {
//                cout << endl << "Element not found";
//            }
//        } else if (ans == 3) {
//            cout << endl << "Minimum Element is :" << minInBST(root);
//        } else if (ans == 4) {
//            cout << endl << "Maximum Element in BST is : " << maxInBST(root);
//        } else if (ans == 5) {
//            cout << endl << "Height of tree is :" << findHeight(root);
//        }
        else if (ans == 6) {
            cout << endl << "Level Order Traversal is   :";
            levelOrder(root);
        } else if (ans == 7) {
            cout << endl << "Pre-Order Traversal is   :";
            preOrder(root);
        }
        else if (ans == 8) {
            cout << endl << "In-Order Traversal is   :";
            inOrder(root);
        }
//        else if (ans == 9) {
//            cout << endl << "Post-Order Traversal is   :";
//            postOrder(root);
//        } else if (ans == 10) {
//            if (isBST(root)) {
//                cout << endl << "Tree is BST.  ";
//            } else {
//                cout << endl << "Tree is not BST";
//            }
//        }
        else if (ans == 11) {
            if (isBSTFast(root, INT_MIN, INT_MAX)) {
                cout << endl << "Tree is BST.  ";
            } else {
                cout << endl << "Tree is not BST";
            }
        }
//        else if (ans == 12) {
//            cout << endl << "Enter element to delete";
//            int data;
//            cin >> data;
//            root = deleteNode(root, data);
//        } else if (ans == 13) {
//            cout << endl << "Enter element data to find inorder Successor  :";
//            int data;
//            cin >> data;
//            cout << endl << "Inorder Successor is  :" << getInOrderSuccessor(root, data)->data;
//        }
        else {
            break;
        }
        cout << endl << "---------------------------------";
        cout << endl << "Enter choice : ";
        cin >> ans;
        cout << "---------------------------------";
    } while (true);
    return 0;
}