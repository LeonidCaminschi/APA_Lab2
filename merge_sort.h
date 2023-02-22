#pragma once

#include <vector>

using namespace std;

void merge(vector<int>& arr, int const left, int const mid, int const right) {
    int const subArrayOne = mid - left + 1;
    int const subArrayTwo = right - mid;

    int *leftArray = new int[subArrayOne],
    *rightArray = new int[subArrayTwo];

    for (auto i = 0; i < subArrayOne; i++) leftArray[i] = arr[left + i];
    for (auto j = 0; j < subArrayTwo; j++) rightArray[j] = arr[mid + 1 + j];

    auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;

    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            arr[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            arr[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }

    while (indexOfSubArrayOne < subArrayOne) {
        arr[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }

    while (indexOfSubArrayTwo < subArrayTwo) {
        arr[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }

    delete[] leftArray;
    delete[] rightArray;
}

void mergeLOL(vector<int>& arr, int start, int end) {
    if (start >= end) return;

    auto mid = start + (end - start) / 2;
    mergeLOL(arr, start, mid);
    mergeLOL(arr, mid + 1, end);
    merge(arr, start, mid, end);
}

void mergeSort(vector<int>& arr) {
    mergeLOL(arr, 0, arr.size());
}