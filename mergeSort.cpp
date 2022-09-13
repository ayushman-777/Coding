// { Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


// } Driver Code Ends
class Solution
{
public:
    void merge(int arr[], int l, int m, int r)
    {
        int size = r - l + 1;
        int merged[size];

        int idx1 = l;
        int idx2 = m + 1;
        int ind = 0;

        while (idx1 <= m && idx2 <= r) {
            if (arr[idx1] < arr[idx2]) {
                merged[ind++] = arr[idx1++];
            } else {
                merged[ind++] = arr[idx2++];
            }
        }

        while (idx1 <= m) {
            merged[ind++] = arr[idx1++];
        }

        while (idx2 <= r) {
            merged[ind++] = arr[idx2++];
        }

        for (int i = 0, j = l; i < size; i++, j++) {
            arr[j] = merged[i];
        }
    }
public:
    void mergeSort(int arr[], int l, int r)
    {
        if (l < r) {
            int mid = l + (r - l) / 2;
            mergeSort(arr, l, mid);
            mergeSort(arr, mid + 1, r);
            merge(arr, l, mid, r);
        }
    }
}

// { Driver Code Starts.


int main()
{
    int n, T, i;

    scanf("%d", &T);

    while (T--) {

        scanf("%d", &n);
        int arr[n + 1];
        for (i = 0; i < n; i++)
            scanf("%d", &arr[i]);

        Solution ob;
        ob.mergeSort(arr, 0, n - 1);
        printArray(arr, n);
    }
    return 0;
}  // } Driver Code Ends