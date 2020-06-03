#include <iostream>
using namespace std;

void displayArray(int *arr, int size) {
    cout << "----------------------------------------" << endl;
    cout << "[ ";
    for (int i = 0; i < size; i++) {
        cout << arr[i];
        if (i != size - 1) {
            cout << ", ";
        }
    }
    cout << " ]" << endl;
    cout << "----------------------------------------" << endl;
}

void insertionSort(int *arr, int size) {
    for (int i = 1; i < size; ++i) {
        int value = arr[i];
        int j = i - 1;

        while(j > -1 && arr[j] > value) {
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = value;
    }
}

void selectionSort(int *arr, int size) {
    for (int i = 0; i < size; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j) {
            if (arr[minIndex] > arr[j]) {
                minIndex = j;
            }
        }

        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

void bubbleSort(int *arr, int size) {
    bool isSorted = false;
    for (int i = 0; i < size && !isSorted; i++) {
        isSorted = true;
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j+1] < arr[j]) {
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
                isSorted = false;
            }
        }
    }
}

int partition(int *arr, int first, int last) {
    int pivotIndex = (first + last) / 2;
    int temp1 = arr[pivotIndex];
    arr[pivotIndex] = arr[first];
    arr[first] = temp1;
    pivotIndex = first;

    int lastS1 = first;
    int unsorted = lastS1+1;
    int pivotValue = arr[pivotIndex];

    while(unsorted <= last) {

        if (pivotValue > arr[unsorted]) {
            lastS1++;
            int temp2 = arr[unsorted];
            arr[unsorted] = arr[lastS1];
            arr[lastS1] = temp2;
        }
        unsorted++;
    }

    int temp3 = arr[pivotIndex];
    arr[pivotIndex] = arr[lastS1];
    arr[lastS1] = temp3;
    pivotIndex = lastS1;
    return pivotIndex;
}

void quickSort(int *arr, int first, int last) {
    if (first < last) {
        int pivotIndex = partition(arr, first, last);
        quickSort(arr, first, pivotIndex-1);
        quickSort(arr, pivotIndex+1, last);
    }
}

void quickSort(int *arr, int size) {
    quickSort(arr, 0, size-1);
}

void merge(int *arr, int arrSize, int low, int middle, int high) {
    int *temp = new int[arrSize];
    int first1 = low;
    int last1 = middle;
    int first2 = middle+1;
    int last2 = high;
    int index = first1;

    for ( ; first1 <= last1 && first2 <= last2; index++) {
        if (arr[first1] > arr[first2]) {
            temp[index] = arr[first2++];
        } else {
            temp[index] = arr[first1++];
        }
    }

    for ( ; first1 <= last1; first1++, index++) {
        temp[index] = arr[first1];
    }

    for ( ; first2 <= last2; first2++, index++) {
        temp[index] = arr[first2];
    }

    for (index = low; index <= high; index++) {
        arr[index] = temp[index];
    }

    delete [] temp;
}

void mergeSortIterative(int *arr, int arrSize) {
    int i;
    for (i = 2; i <= arrSize; i = i * 2) {
        int size = arrSize;
        if (arrSize % 2 == 1) {
            size--;
        }
        for (int j = 0; j < size; j = j + i) {
            int low = j;
            int high = j + i - 1;
            int middle = (low + high) / 2;
            merge(arr, arrSize, low, middle, high);
        }
    }
    if (arrSize % 2 == 1) {
        merge(arr, arrSize, 0, arrSize-2, arrSize-1);
    }
}

void mergeSortRecursive(int *arr, int arrSize, int first, int last) {
    if (first < last) {
        int middle = (first + last) / 2;
        mergeSortRecursive(arr, arrSize, first, middle);
        mergeSortRecursive(arr, arrSize, middle+1, last);
        merge(arr, arrSize, first, middle, last);
    }
}

void mergeSortRecursive(int *arr, int arrSize) {
    mergeSortRecursive(arr, arrSize, 0, arrSize-1);
}

int main() {

    int arr1[] = { 20, 10, 25, 5, 30, 40, 15 };
    int arrSize1 = 7;

    cout << "SELECTION SORT" << endl;
    displayArray(arr1, arrSize1);
    selectionSort(arr1, arrSize1);
    displayArray(arr1, arrSize1);

    int arr2[] = { 20, 10, 25, 5, 30, 40, 15 };
    int arrSize2 = 7;

    cout << "INSERTION SORT" << endl;
    displayArray(arr2, arrSize2);
    insertionSort(arr2, arrSize2);
    displayArray(arr2, arrSize2);

    int arr3[] = { 20, 10, 25, 5, 30, 40, 15 };
    int arrSize3 = 7;

    cout << "BUBBLE SORT" << endl;
    displayArray(arr3, arrSize3);
    bubbleSort(arr3, arrSize3);
    displayArray(arr3, arrSize3);

    int arr4[] = { 20, 10, 25, 5, 30, 40, 15 };
    int arrSize4 = 7;

    cout << "QUICK SORT" << endl;
    displayArray(arr4, arrSize4);
    quickSort(arr4, arrSize4);
    displayArray(arr4, arrSize4);

    cout << "MERGE SORT ITERATIVE" << endl;
    int arr5[] = { 90, 70, 10, 25, 5, 30, 40, 15, 1 };
    int arrSize5 = 9;

    displayArray(arr5, arrSize5);
    mergeSortIterative(arr5, arrSize5);
    displayArray(arr5, arrSize5);

    cout << "MERGE SORT RECURSIVE" << endl;
    int arr6[] = { 90, 70, 10, 25, 5, 30, 40, 15, 1 };
    int arrSize6 = 9;

    displayArray(arr6, arrSize6);
    mergeSortRecursive(arr6, arrSize6);
    displayArray(arr6, arrSize6);

    return 0;
}