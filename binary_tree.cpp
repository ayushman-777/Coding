//
// Created by patha on 06-10-2021.
//

#include "bits/stdc++.h"

using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};

Node *newNode(int data) {
    Node *node = new Node(data);
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

Node *insert(Node *root, int data) {
    if (root == nullptr) {
        root = newNode(data);
    } else if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    } else {
        cout << endl << "Equal value cannot be inserted in BST";
    }
    return root;
}

bool search(Node *root, int data) {
    if (root == nullptr) {
        return false;
    }
    if (root->data == data) {
        return true;
    } else if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

Node *searchNode(Node *root, int data) {
    if (root == nullptr) {
        return nullptr;
    } else if (root->data == data) {
        return root;
    } else if (data < root->data) {
        return searchNode(root->left, data);
    } else {
        return searchNode(root->right, data);
    }
}

int minInBST(Node *root) {
    if (root == nullptr) {
        return -1;
    } else if (root->left == nullptr) {
        return root->data;
    }
    return minInBST(root->left);
}

int maxInBST(Node *root) {
    if (root == nullptr) {
        return -1;
    } else if (root->right == nullptr) {
        return root->data;
    }
    return maxInBST(root->right);
}

Node *findMinBST(Node *root) {
    if (root == nullptr) {
        return nullptr;
    } else if (root->left == nullptr) {
        return root;
    }
    return findMinBST(root->left);
}

Node *findMaxBST(Node *root) {
    if (root == nullptr) {
        return nullptr;
    } else if (root->right == nullptr) {
        return root;
    }
    return findMaxBST(root->right);
}

int findHeight(Node *root) {
    if (root == nullptr) {
        return -1;
    }
    return max(findHeight(root->left), findHeight(root->right)) + 1;
}

void levelOrder(Node *root) {
    if (root == nullptr) {
        return;
    }
    queue<Node *> que;
    que.push(root);
    while (!que.empty()) {
        Node *current = que.front();
        cout << current->data << "   ";
        if (current->left != nullptr) que.push(current->left);
        if (current->right != nullptr) que.push(current->right);
        que.pop();
    }
}

void preOrder(Node *root) {
    if (root == nullptr) {
        return;
    }
    cout << root->data << "   ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node *root) {
    if (root == nullptr) return;
    inOrder(root->left);
    cout << root->data << "   ";
    inOrder(root->right);
}

void postOrder(Node *root) {
    if (root == nullptr) {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << "   ";
}

bool isBTLesser(Node *root, int data) {
    if (root == nullptr) {
        return true;
    }
    if (root->data < data && isBTLesser(root->left, data) && isBTLesser(root->right, data)) {
        return true;
    }
    return false;
}

bool isBTGreater(Node *root, int data) {
    if (root == nullptr) {
        return true;
    }
    if (root->data > data && isBTGreater(root->left, data) && isBTGreater(root->right, data)) {
        return true;
    }
    return false;
}

bool isBST(Node *root) {
    if (root == nullptr) {
        return true;
    }
    if (isBTLesser(root->left, root->data) && isBTGreater(root->right, root->data) && isBST(root->left) &&
        isBST(root->right)) {
        return true;
    }
    return false;
}

bool isBSTFast(Node *root, int minData, int maxData) {
    if (root == nullptr) {
        return true;
    }
    if (root->data > minData && root->data < maxData && isBSTFast(root->left, minData, root->data) &&
        isBSTFast(root->right, root->data, maxData)) {
        return true;
    }
    return false;
}

Node *deleteNode(Node *root, int data) {
    if (root == nullptr) return root;
    if (root->data > data) root->left = deleteNode(root->left, data);
    else if (root->data < data) root->right = deleteNode(root->right, data);
    else {
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            root = nullptr;
        } else if (root->right == nullptr) {
            Node *temp = root;
            root = root->left;
            delete temp;
        } else if (root->left == nullptr) {
            Node *temp = root;
            root = root->right;
            delete temp;
        } else {
            Node *temp = findMinBST(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

Node *getInOrderSuccessor(Node *root, int data) {
    Node *current = searchNode(root, data);
    if (current == nullptr) {
        return nullptr;
    }
    if (current->right != nullptr) {
        return findMinBST(current->right);
    } else {
        Node *successor = nullptr;
        Node *ancestor = root;
        while (ancestor != current) {
            if (current->data < ancestor->data) {
                successor = ancestor;
                ancestor = ancestor->left;
            } else {
                ancestor = ancestor->right;
            }
        }
        return successor;
    }
}

vector<int> reverseLevelOrder(Node *node) {
    vector<int> ans;
    if (node == nullptr) return ans;
    queue<Node *> que;
    que.push(node);
    while (!que.empty()) {
        Node *current = que.front();
        ans.push_back(current->data);
        if (current->left != NULL) que.push(current->left);
        if (current->right != NULL) que.push(current->right);
        que.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int height(Node *node, int &ans) {
    if (node == NULL) return 0;
    int lHeight = height(node->left, ans);
    int rHeight = height(node->right, ans);
    ans = max(ans, 1 + lHeight + rHeight);
    return max(rHeight, lHeight) + 1;
}

int diameter(Node *root) {
    if (root == NULL) return 0;
    int ans = INT_MIN;
    height(root, ans);
    return ans;
}

Node *mirrorBT(Node *root) {
    if (root == nullptr) {
        return nullptr;
    }
    if (root->left == nullptr && root->right == nullptr) {
        return root;
    } else if (root->left == nullptr) {
        root->left = mirrorBT(root->right);
    } else if (root->right == nullptr) {
        root->right = mirrorBT(root->left);
    } else {
        Node *temp = root->left;
        root->left = mirrorBT(root->right);
        root->right = mirrorBT(temp);
    }
    return root;
}

void inorderIterative(Node *root) {
    if (root == nullptr) {
        return;
    }
    stack<Node *> s;
    Node *curr = root;
    while (!s.empty() || curr != nullptr) {
        if (curr != nullptr) {
            s.push(curr);
            curr = curr->left;
        } else {
            curr = s.top();
            cout << curr->data << "  ";
            s.pop();
            curr = curr->right;
        }
    }
}

void postorderIterative(Node *root) {
    if (root == nullptr) return;
    stack<Node *> s;
    stack<int> result;
    s.push(root);
    while (!s.empty()) {
        Node *cur = s.top();
        s.pop();
        result.push(cur->data);
        if (cur->left) s.push(cur->left);
        if (cur->right) s.push(cur->right);

    }
    while (!result.empty()) {
        cout << result.top() << "  ";
        result.pop();
    }
}

void preorderIterative(Node *root) {
    if (root == nullptr) return;
    stack<Node *> s;
    s.push(root);
    while (!s.empty()) {
        Node *cur = s.top();
        cout << cur->data << "  ";
        s.pop();
        if (cur->left) s.push(cur->left);
        if (cur->right) s.push(cur->right);
    }
}

void leftViewUtils(Node *root, int level, int &maxLevel) {
    if (root == nullptr) return;
    if (level > maxLevel) {
        cout << root->data << "  ";
        maxLevel++;
    }
    leftViewUtils(root->left, 1 + level, maxLevel);
    leftViewUtils(root->right, 1 + level, maxLevel);
}

void leftView(Node *root) {
    if (root == nullptr) return;
    int maxLevel = 0;
    leftViewUtils(root, 1, maxLevel);
}

void leftViewIterative(Node *root) {
    if (root == nullptr) {
        return;
    }
    queue<Node *> q;
    q.push(root);
    while (!q.empty()) {
        int n = q.size();
        for (int i = 1; i <= n; ++i) {
            Node *cur = q.front();
            q.pop();
            if (i == 1) {
                cout << cur->data << "  ";
            }
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
    }
}

vector<int> rightViewIterative(Node *root) {
    vector<int> ans;
    if (root == nullptr) return ans;
    queue<Node *> que;
    que.push(root);
    while (!que.empty()) {
        int n = que.size();
        for (int i = 1; i <= n; i++) {
            Node *cur = que.front();
            que.pop();
            if (i == n) {
                ans.push_back(cur->data);
            }
            if (cur->left) que.push(cur->left);
            if (cur->right) que.push(cur->right);
        }
    }
    return ans;
}

void topViewUtil(Node *root, int dist, int level, map<int, pair<int, int>> &m) {
    if (!root) return;
    if (m.find(dist) == m.end() || level < m[dist].second) {
        m[dist] = {root->data, level};
    }
    if (root->left) topViewUtil(root->left, dist - 1, level + 1, m);
    if (root->right) topViewUtil(root->right, dist + 1, level + 1, m);
}

vector<int> topView(Node *root) {
    vector<int> res;
    if (root == nullptr) return res;
    map<int, pair<int, int>> m;
    topViewUtil(root, 0, 0, m);
    for (auto f: m) {
        res.push_back(f.second.first);
    }
    return res;
}

void bottomViewUtil(Node *root, int dist, int level, map<int, pair<int, int>> &m) {
    if (!root) return;
    if (level >= m[dist].second) m[dist] = {root->data, level};
    if (root->left) bottomViewUtil(root->left, dist - 1, level + 1, m);
    if (root->right) bottomViewUtil(root->right, dist + 1, level + 1, m);
}

vector<int> bottomView(Node *root) {
    vector<int> res;
    if (root == nullptr) return res;
    map<int, pair<int, int>> map;
    bottomViewUtil(root, 0, 0, map);
    for (auto m: map) {
        res.push_back(m.second.first);
    }
    return res;
}

vector<int> zigZagTraversal(Node *root) {
    vector<int> res;
    if (!root) return res;
    deque<Node *> dq;
    int level = 1;
    Node *cur;
    dq.push_back(root);
    res.push_back(root->data);
    while (!dq.empty()) {
        int n = dq.size();
        for (int i = 0; i < n; i++) {
            if (level % 2 == 0) {
                cur = dq.back();
                dq.pop_back();
                if (cur->left) {
                    dq.push_front(cur->left);
                    res.push_back(cur->left->data);
                }
                if (cur->right) {
                    dq.push_front(cur->right);
                    res.push_back(cur->right->data);
                }
            } else {
                cur = dq.front();
                dq.pop_front();
                if (cur->right) {
                    dq.push_back(cur->right);
                    res.push_back(cur->right->data);
                }
                if (cur->left) {
                    dq.push_back(cur->left);
                    res.push_back(cur->left->data);
                }
            }
        }
        level++;
    }
    return res;
}

bool isBalanced(Node *root) {
    if (root == nullptr) return true;
    if (abs(findHeight(root->left) - findHeight(root->right)) > 1) {
        return false;
    }
    if (root->right) isBalanced(root->right);
    if (root->left) isBalanced(root->left);
    return true;
}

bool isBalanced(Node *root, int *height) {
    if (root == nullptr) {
        *height = 0;
        return true;
    }
    int lh = 0, rh = 0;
    bool l, r;
    l = isBalanced(root->left, &lh);
    r = isBalanced(root->right, &rh);
    *height = (lh > rh ? lh : rh) + 1;
    if (abs(lh - rh) >= 2) return false;
    else return l && r;
}

void diagonalUtils(Node *root, int dist, map<int, vector<int>> &vec) {
    if (root == nullptr) return;
    vec[dist].push_back(root->data);
    if (root->left) diagonalUtils(root->left, dist + 1, vec);
    if (root->right) diagonalUtils(root->right, dist, vec);
}

vector<int> diagonal(Node *root) {
    vector<int> res;
    if (root == nullptr) return res;
    map<int, vector<int>> mv;
    diagonalUtils(root, 0, mv);
    for (auto item1: mv) {
        for (auto item2: item1.second) {
            res.push_back(item2);
        }
    }
    return res;
}

Node *constructTree(string s, int &start) {
    // Assuming there is/are no negative
    // character/characters in the string
    if (s.empty() || start >= s.size())
        return nullptr;

    // constructing a number from the continuous digits
    int num = 0;
    while (start < s.size() && s[start] != '(' && s[start] != ')') {
        int num_here = (int) (s[start] - '0');
        num = num * 10 + num_here;
        start++;
    }

    // creating a node from the constructed number from
    // above loop
    struct Node *root = newNode(num);

    // check if start has reached the end of the string
    if (start >= s.size())
        return root;

    // As soon as we see first right parenthesis from the
    // current node we start to construct the tree in the
    // left
    if (start < s.size() && s[start] == '(') root->left = constructTree(s, ++start);
    if (start < s.size() && s[start] == ')') start++;

    // As soon as we see second right parenthesis from the
    // current node we start to construct the tree in the
    // right
    if (start < s.size() && s[start] == '(') root->right = constructTree(s, ++start);
    if (start < s.size() && s[start] == ')') start++;

    return root;
}

void bToDLL(Node *root, Node **dlNode) {
    if (root == nullptr) return;
    if (root->right) bToDLL(root->right, dlNode);
    (*dlNode)->data = root->data;
    Node *temp1 = newNode(0);
    (*dlNode)->left = temp1;
    temp1->right = *dlNode;
    *dlNode = temp1;
    if (root->left) bToDLL(root->left, dlNode);
}

void printList(Node *node) {
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->right;
    }
}

void *bToDLL(Node *root) {
    Node *res = newNode(0);
    bToDLL(root, &res);
    res = res->right;
    res->left = nullptr;
    printList(res);
    return nullptr;
}

int toSumTreeUtil(Node *root) {
    int temp = root->data;
    if (!root->left && !root->right) {
        root->data = 0;
        return temp;
    }
    root->data = (root->left ? toSumTreeUtil(root->left) : 0) + (root->right ? toSumTreeUtil(root->right) : 0);
    return temp + root->data;
}

void toSumTree(Node *node) {
    toSumTreeUtil(node);
}

Node *buildTreeUtil(int in[], int pre[], int start, int end, unordered_map<int, int> mp) {
    static int preIndex = 0;

    if (start > end) return nullptr;

    int data = pre[preIndex++];
    Node *temp = newNode(data);

    if (start == end) return temp;

    int inIndex = mp[data];

    temp->left = buildTreeUtil(in, pre, start, inIndex - 1, mp);
    temp->right = buildTreeUtil(in, pre, inIndex + 1, end, mp);

    return temp;
}

Node *buildTree(int in[], int pre[], int n) {
    unordered_map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        mp[in[i]] = i;
    }
    return buildTreeUtil(in, pre, 0, n - 1, mp);
}

int minSwaps(std::vector<int> &v) {
    vector<pair<int, int>> vec(v.size());
    int ans = 0;
    for (int i = 0; i < v.size(); ++i)
        vec[i].second = i, vec[i].first = v[i];

    sort(vec.begin(), vec.end());
    for (int i = 0; i < vec.size(); ++i) {
        if (vec[i].first == i) continue;
        else {
            swap(vec[i].first, vec[vec[i].second].first);
            swap(vec[i].second, vec[vec[i].second].second);
        }

        if (i != vec[i].second)
            --i;

        ans++;
    }
    return ans;
}

int sumSubTree(Node *root) {
    if (root == nullptr) return 0;
    if (root->left == nullptr && root->right == nullptr) return root->data;
    return root->data + sumSubTree(root->right) + sumSubTree(root->left);
}

bool isSumTree(Node *root) {
    if (root == nullptr || (root->right == nullptr && root->left == nullptr)) return true;
    if (root->right == nullptr && (root->left->data == root->data)) return true;
    if (root->left == nullptr && (root->right->data == root->data)) return true;
    if ((root->data == sumSubTree(root->left) + sumSubTree(root->right)) && isSumTree(root->left)
        && isSumTree(root->right))
        return true;
    return false;
}

int findMinDepth(Node *root) {
    if (root->left == nullptr && root->right == nullptr) return 1;
    if (root->left == nullptr) {
        return min(INT_MAX, findMinDepth(root->right)) + 1;
    } else if (root->right == nullptr) {
        return min(findMinDepth(root->left), INT_MAX) + 1;
    } else {
        return min(findMinDepth(root->left), findMinDepth(root->right)) + 1;
    }
}

bool check(Node *root) {
    if (root == nullptr) return true;
    int height = findHeight(root); // return 0;if root = nullptr
    int minDepth = findMinDepth(root);
    if (minDepth != height) return false;
    return true;
}

string dupSubUtil(Node *root, unordered_map<string, int> &mp, bool &found) {
    if (root == nullptr) return "";
    string str = "(";
    str += dupSubUtil(root->left, mp, found);
    str += to_string(root->data);
    str += dupSubUtil(root->right, mp, found);
    str += ")";

    if (mp.find(str) != mp.end()) {
        if (str.size() > 3) found = true;
    }

    mp[str]++;

    return str;
}

int dupSub(Node *root) {
    bool found;
    unordered_map<string, int> mp;
    dupSubUtil(root, mp, found);
    return found;
}

void fillSet(Node *root, set<int> &ele) {
    if (root == nullptr) return;
    ele.insert(root->data);
    if (root->left) fillSet(root->left, ele);
    if (root->right) fillSet(root->right, ele);
}

void findPreSuc(Node *root, Node *&pre, Node *&suc, int key) {
    set<int> ele;
    fillSet(root, ele);
    int sucVal = *ele.upper_bound(key);
    int preVal = *(--ele.lower_bound(key));
    pre = searchNode(root, preVal);
    suc = searchNode(root, sucVal);
}

void populateNextRecur(Node *p, Node **next_ref) {
    if (p) {
        populateNextRecur(p->right, next_ref);
        // p->next = *next_ref;
        *next_ref = p;
        populateNextRecur(p->left, next_ref);
    }
}

void populateNext(Node *root) {
    Node *next = nullptr;
    populateNextRecur(root, &next);
}

Node *LCA(Node *root, int n1, int n2) {
    if (root == nullptr) return nullptr;
    if (root->data < n1 && root->data < n2) return LCA(root->right, n1, n2);
    if (root->data > n1 && root->data > n2) return LCA(root->left, n1, n2);
    return root;
}

void BTtoVECTOR(Node *root, vector<int> &vec) {
    if (root == nullptr) return;
    vec.push_back(root->data);
    if (root->left) BTtoVECTOR(root->left, vec);
    if (root->right) BTtoVECTOR(root->right, vec);
}

void binaryTreeToBSTUtil(Node *root, vector<int> &vec, int &preIndex) {
    if (root == nullptr) return;
    binaryTreeToBSTUtil(root->left, vec, preIndex);
    root->data = vec[preIndex];
    preIndex++;
    binaryTreeToBSTUtil(root->right, vec, preIndex);
}

Node *binaryTreeToBST(Node *root) {
    vector<int> vec;
    BTtoVECTOR(root, vec);
    sort(vec.begin(), vec.end());
    int i = 0;
    binaryTreeToBSTUtil(root, vec, i);
    return root;
}

void kthLargestUtil(Node *root, int &k, int &i, int &ans) {
    if (root == nullptr) return;
    kthLargestUtil(root->right, k, i, ans);
    i++;
    if (i == k) {
        ans = root->data;
        return;
    }
    kthLargestUtil(root->left, k, i, ans);
}

int kthLargest(Node *root, int K) {
    int ans;
    int i = 0;
    kthLargestUtil(root, K, i, ans);
    return ans;
}

void KthSmallestElementUtil(Node *root, int &k, int &i, int &ans) {
    if (root == nullptr) return;
    KthSmallestElementUtil(root->left, k, i, ans);
    i++;
    if (i == k) {
        ans = root->data;
        return;
    }
    KthSmallestElementUtil(root->right, k, i, ans);
}

int KthSmallestElement(Node *root, int K) {
    int ans;
    int i = 0;
    KthSmallestElementUtil(root, K, i, ans);
    return ans;
}

void BSTToMap(Node *root, map<int, int> &map) {
    if (root == nullptr) return;
    BSTToMap(root->left, map);
    map[root->data]++;
    BSTToMap(root->right, map);
}

void countPairsUtil(Node *root, map<int, int> &map, int x, int &ans) {
    if (root == nullptr) return;
    if (map[(x - root->data)]) {
        ans++;
    }
    countPairsUtil(root->left, map, x, ans);
    countPairsUtil(root->right, map, x, ans);
}

int countPairs(Node *root1, Node *root2, int x) {
    map<int, int> map2;
    BSTToMap(root2, map2);
    int ans = 0;
    countPairsUtil(root1, map2, x, ans);
    return ans;
}

void MorisInorder(Node *root) {
    Node *current = root;
    while (current != nullptr) {
        if (current->left == nullptr) {
            cout << current->data << "  ";
            current = current->right;
        } else {
            Node *predecessor = current->left;
            while (predecessor->right != current && predecessor->right != nullptr) {
                predecessor = predecessor->right;
            }

            if (predecessor->right == nullptr) {
                predecessor->right = current;
                current = current->left;
            } else {
                predecessor->right = nullptr;
                cout << current->data << "  ";
                current = current->right;
            }
        }
    }
}

class MinHeap {
    int *harr; // pointer to array of elements in heap
    int capacity; // maximum possible size of min heap
    int heap_size;
public:
    MinHeap(int cap) {
        harr = new int[cap];
        capacity = cap;
        heap_size = 0;
    }

    void minHeapify(int i) {
        int l = left(i);
        int r = right(i);
        int smallest = i;
        if (harr[l] < harr[i] && l < heap_size) smallest = l;
        if (harr[r] < harr[smallest] && r < heap_size) smallest = r;
        if (smallest != i) {
            swap(harr[smallest], harr[i]);
            minHeapify(smallest);
        }
    }

    int parent(int i) { return (i - 1) / 2; }

    int left(int i) { return 2 * i + 1; }

    int right(int i) { return 2 * i + 2; }

    void insertKey(int key) {
        if (heap_size == capacity) {
            cout << endl << "Cannot Insert more, Overflow!";
            return;
        }
        int i = heap_size++;
        harr[i] = key;
        while (i != 0 && harr[i] < harr[parent(i)]) {
            swap(harr[parent(i)], harr[i]);
            i = parent(i);
        }
    }

    int extractMin() {
        if (heap_size <= 0) return INT_MAX;
        heap_size--;
        if (heap_size == 1) {
            return harr[0];
        }
        int root = harr[0];
        harr[0] = harr[heap_size];
        minHeapify(0);
        return root;
    }

    void decreaseKey(int i, int newKey) {
        harr[i] = newKey;
        while (i != 0 && harr[i] < harr[parent(i)]) {
            swap(harr[i], harr[parent(i)]);
            i = parent(i);
        }
    }

    void deleteKey(int i) {
        decreaseKey(i, INT_MIN);
        extractMin();
    }

};

class minHeap {
    int *arr;
    int capacity;
    int heapSize;
public:
    minHeap(int cap) {
        capacity = cap;
        arr = new int[cap];
        heapSize = 0;
    }
    int parent(int i) { return (i - 1) / 2; }

    int left(int i) { return 2 * i + 1; }

    int right(int i) { return 2 * i + 2; }

    void insert(int key) {
        if (heapSize == capacity) {
            return;
        }
        int i = heapSize++;
        arr[i] = key;
        while (i != 0 && arr[i] < arr[parent(i)]) {
            swap(arr[parent(i)], arr[i]);
            i = parent(i);
        }
    }

    void minHeapify(int i) {
        int l = left(i);
        int r = right(i);
        int smallest = i;
        if (l < heapSize && arr[l] < arr[i]) smallest = l;
        if (r < heapSize && arr[r] < arr[smallest]) smallest = r;
        if (smallest != i) {
            swap(arr[smallest], arr[i]);
            minHeapify(smallest);
        }
    }

    void decreaseKey(int i, int new_val) {
        arr[i] = new_val;
        while (i != 0 && arr[i] < arr[parent(i)]) {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    int extractMin() {
        if (heapSize <= 0) {
            return INT_MAX;
        }
        if (heapSize == 1) {
            heapSize--;
            return arr[0];
        }
        int min = arr[0];
        arr[0] = arr[heapSize - 1];
        minHeapify(0);
        heapSize--;
        return min;
    }
};

int main() {
    Node *root = nullptr;
    int ans = 1;
    do {
        if (ans == 1) {
            int n;
            cout << endl << "Enter no. of nodes of tree to insert  :";
            cin >> n;
            while (n--) {
                cout << endl << "Enter data   :";
                int data;
                cin >> data;
                root = insert(root, data);
            }
        } else if (ans == 2) {
            int data;
            cout << endl << "Enter element to search for   :";
            cin >> data;
            if (search(root, data)) {
                cout << endl << "Element found.";
            } else {
                cout << endl << "Element not found.";
            }
        } else if (ans == 3) {
            cout << endl << "Minimum Element is   :" << minInBST(root);
        } else if (ans == 4) {
            cout << endl << "Maximum Element in BST is   :" << maxInBST(root);
        } else if (ans == 5) {
            cout << endl << "Height of tree is :" << findHeight(root);
        } else if (ans == 6) {
            cout << endl << "Level Order Traversal is   :";
            levelOrder(root);
        } else if (ans == 7) {
            cout << endl << "Pre-Order Traversal is   :";
            preorderIterative(root);
        } else if (ans == 8) {
            cout << endl << "In-Order Traversal is   :";
            inorderIterative(root);
        } else if (ans == 9) {
            cout << endl << "Post-Order Traversal is   :";
            postorderIterative(root);
        } else if (ans == 10) {
            if (isBST(root)) {
                cout << endl << "Tree is BST.";
            } else {
                cout << endl << "Tree is not BST";
            }
        } else if (ans == 11) {
            if (isBSTFast(root, INT_MIN, INT_MAX)) {
                cout << endl << "Tree is BST.";
            } else {
                cout << endl << "Tree is not BST.";
            }
        } else if (ans == 12) {
            cout << endl << "Enter element to delete   :";
            int data;
            cin >> data;
            root = deleteNode(root, data);
        } else if (ans == 13) {
            cout << endl << "Enter element data to find inorder Successor   :";
            int data;
            cin >> data;
            cout << endl << "Inorder Successor is   :" << getInOrderSuccessor(root, data)->data;
        } else if (ans == 14) {
            Node *temp = mirrorBT(root);
            cout << endl << "Mirrored Binary Tree Inorder is   :";
            inOrder(temp);
        } else if (ans == 15) {
            cout << endl << "Left View of Binary Tree is   :";
            leftViewIterative(root);
        } else if (ans == 16) {
            cout << endl << "Top View of Binary Tree is   :";
            vector<int> temp = topView(root);
            for (int i: temp) {
                cout << i << "  ";
            }
        } else if (ans == 17) {
            cout << endl << "Doubly Linked list is   :";
            bToDLL(root);
            break;
        } else {
            break;
        }
        cout << endl << "---------------------------------";
        cout << endl << "Enter choice   :";
        cin >> ans;
        cout << "---------------------------------";
    } while (true);
    return 0;
}