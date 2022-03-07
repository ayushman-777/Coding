//
// Created by patha on 21-12-2021.
//

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low;
    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            swap(arr[j], arr[i]);
            i++;
        }
    }
    swap(arr[i], arr[high]);
    return i;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void merge(int arr[], int left, int mid, int right) {
    int subArrayLeft = mid - left + 1;
    int subArrayRight = right - mid;

    int leftArray[subArrayLeft];
    int rightArray[subArrayRight];

    int indexOfLeftArray = 0;
    int indexOfRightArray = 0;
    int indexOfMergedArray = left;

    for (int i = 0; i < subArrayLeft; ++i) {
        leftArray[i] = arr[left + i];
    }

    for (int i = 0; i < subArrayRight; ++i) {
        rightArray[i] = arr[mid + 1 + i];
    }

    while (indexOfLeftArray < subArrayLeft && indexOfRightArray < subArrayRight) {
        if (leftArray[indexOfLeftArray] <= rightArray[indexOfRightArray]) {
            arr[indexOfMergedArray] = leftArray[indexOfLeftArray];
            indexOfLeftArray++;
        } else {
            arr[indexOfMergedArray] = rightArray[indexOfRightArray];
            indexOfRightArray++;
        }
        indexOfMergedArray++;
    }

    while (indexOfLeftArray < subArrayLeft) {
        arr[indexOfMergedArray] = leftArray[indexOfLeftArray];
        indexOfLeftArray++;
        indexOfMergedArray++;
    }

    while (indexOfRightArray < subArrayRight) {
        arr[indexOfMergedArray] = rightArray[indexOfRightArray];
        indexOfRightArray++;
        indexOfMergedArray++;
    }
}

void mergeSort(int arr[], int begin, int end) {
    if (begin < end) {
        int mid = begin + (end - begin) / 2;
        mergeSort(arr, begin, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, begin, mid, end);
    }
}

void insertionSort(int arr[], int n) {
    int j, key;
    for (int i = 1; i < n; ++i) {
        j = i - 1;
        key = arr[i];
        while (j >= 0 && key < arr[j]) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

long long maxSubarraySum(int arr[], int n) {
    long long max_so_far = LONG_LONG_MIN, max_ending_here = 0;
    for (int i = 0; i < n; ++i) {
        max_ending_here += arr[i];
        if (max_so_far < max_ending_here) {
            max_so_far = max_ending_here;
        }
        if (max_ending_here < 0) {
            max_ending_here = 0;
        }
    }
    return max_so_far;
}

int multiply(int x, int res[], int res_size) {
    int carry = 0;
    for (int i = 0; i < res_size; ++i) {
        int prod = res[i] * x + carry;

        res[i] = prod % 10;

        carry = prod / 10;
    }
    while (carry) {
        res[res_size] = carry%10;
        res_size++;
        carry /= 10;
    }
    return res_size;
}



int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    insertionSort(arr, n);
    return 0;
}
