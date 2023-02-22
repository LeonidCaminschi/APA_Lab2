#pragma once

#include <vector>

using namespace std;

int partition(vector<int>& arr, int start, int end) {

    int pivot = arr[start];

    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }

    int pivotIndex = start + count;
    std::swap(arr[pivotIndex], arr[start]);

    int i = start, j = end;

    while (i < pivotIndex && j > pivotIndex) {

        while (arr[i] <= pivot) i++;

        while (arr[j] > pivot) j--;

        if (i < pivotIndex && j > pivotIndex)
            std::swap(arr[i++], arr[j--]);
    }

    return pivotIndex;
}

void quick(vector<int>& arr, int start, int end) {
    if (start >= end) return;

    int p = partition(arr, start, end);
    quick(arr, start, p - 1);
    quick(arr, p + 1, end);
}

void quickSort(vector<int>& arr) {
    quick(arr, 0, arr.size());
}