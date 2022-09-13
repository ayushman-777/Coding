#include "bits/stdc++.h"
using namespace std;
template<typename T1, typename T2> // cin >> pair<T1, T2>
istream& operator>>(istream &istream, pair<T1, T2> &p) { return (istream >> p.first >> p.second); }
template<typename T> // cin >> vector<T>
istream& operator>>(istream &istream, vector<T> &v) {for (auto &it : v)cin >> it; return istream;}
template<typename T1, typename T2> // cout << pair<T1, T2>
ostream& operator<<(ostream &ostream, const pair<T1, T2> &p) { return (ostream << p.first << " " << p.second); }
template<typename T> // cout << vector<T>
ostream& operator<<(ostream &ostream, const vector<T> &c) { for (auto &it : c) cout << it << " "; return ostream; }

class minHeap {
    vector<int> heap;
    int parent(int i) {return ((i - 1) / 2);}
    int left(int i) {return ((2 * i) + 1);}
    int right(int i) {return ((2 * i) + 2);}
    void heapifyUp(int i) {
        while (i != 0 && heap[i] < heap[parent(i)]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }
    void heapifyDown(int i) {
        int l = left(i), r = right(i);
        int smallest = i;
        if (l < size() && heap[l] < heap[smallest]) smallest = l;
        if (r < size() && heap[r] < heap[smallest]) smallest = r;
        if (smallest != i) {
            swap(heap[smallest], heap[i]);
            heapifyDown(smallest);
        }
    }
public:
    minHeap() {}
    int size() {
        return heap.size();
    }
    void push(int element) { // insert
        heap.push_back(element);
        heapifyUp(size() - 1);
    }
    void display() {
        cout << endl << "heap ->   ";
        for (auto &ele : heap) {
            cout << ele << " ";
        }
        cout << endl;
    }
    void top() { // extractMin
        cout << "Top Element  ->  " << heap[0] << endl;
    }
    void pop() { // deleteMin
        if (size() == 1) {heap.pop_back(); return;}
        heap[0] = heap[size() - 1];
        heap.pop_back();
        heapifyDown(0);
    }

};

class maxHeap {
private:
    vector<int> heap;
    int left(int i) {return ((2 * i) + 1);}
    int right(int i) {return ((2 * i) + 2);}
    int parent(int i) {return (i - 1) / 2;}
    void heapifyUp(int i) {
        while (i != 0 && heap[i] > heap[parent(i)]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }
    void heapifyDown(int i) {
        int biggest = i, l = left(i), r = right(i);
        if (l < size() && heap[l] > heap[biggest]) biggest = l;
        if (r < size() && heap[r] > heap[biggest]) biggest = r;
        if (biggest != i) {
            swap(heap[i], heap[biggest]);
            heapifyDown(biggest);
        }
    }
public:
    int size() {return heap.size();}
    void push(int element) {
        heap.push_back(element);
        heapifyUp(size() - 1);
    }
    void top() {
        cout << "Top Element -> " << heap[0] << endl;
    }
    void pop() {
        if (size() == 1) {heap.pop_back(); return;}
        heap[0] = heap[size() - 1];
        heap.pop_back();
        heapifyDown(0);
    }

};

void heapify(vector<int> &arr, int n, int i) {
    int largest = i;
    int l = (2 * i) + 1;
    int r = (2 * i) + 2;
    if (l < n and arr[l] > arr[largest]) largest = l;
    if (r < n and arr[r] > arr[largest]) largest = r;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int> &arr) {
    for (int i = ((arr.size() / 2) - 1); i >= 0; i--) {
        heapify(arr, arr.size(), i);
    }
    cout << arr << endl;
    for (int i = (arr.size() - 1); i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void solve() {
    // minHeap pq;
    // maxHeap pq;
    // pq.push(12);
    // pq.push(14);
    // pq.push(11);
    // pq.push(20);
    // pq.push(1);
    // pq.push(2);
    // pq.push(92);
    // pq.top();
    // pq.pop();
    // pq.top();
    // pq.pop();
    // pq.top();
    // pq.pop();
    // pq.top();
    // pq.pop();
    // pq.top();
    // pq.pop();
    // pq.top();
    // pq.pop();
    // pq.top();
    // pq.pop();

    vector<int> arr = {10,  5,  6,  2,  12,  7,  9};
    heapSort(arr);
    cout << arr;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    cout.tie(0);

    solve();

    return 0;
}
