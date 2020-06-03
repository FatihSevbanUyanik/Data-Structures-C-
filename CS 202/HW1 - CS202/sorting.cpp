/**
* Title : Sorting Object
* Author : Fatih Sevban Uyanık
* ID: 21602486
* Section : 1
* Assignment : 1
* Description : Contains all sorting methods.
*/

#include "sorting.h"

void sorting::printArray(int *arr, int size) {
    cout << "--------------------------------------------------------" << endl;
    cout << "[ ";
    for (int i = 0; i < size; i++) {
        cout << arr[i];
        if (i != size - 1) {
            cout << ", ";
        }
    }
    cout << " ]" << endl;
    cout << "--------------------------------------------------------" << endl;
}

void sorting::insertionSort(int *arr, int size, int &compCount, int &moveCount) {
    for (int unsorted = 1; unsorted < size; unsorted++) {
        int value = arr[unsorted];
        int index = unsorted-1;
        moveCount++;

        while (index > -1 && arr[index] > value) {
            compCount++;
            moveCount++;
            arr[index+1] = arr[index];
            index--;
        }

        arr[index+1] = value;
        moveCount++;
    }
};

int sorting::partition(int *arr, int f ,int l, int &compCount, int &moveCount) {
    // choosing pivot index
    // from the middle
    int p = (f + l) / 2;
    moveCount = moveCount + 3;
    int temp = arr[p];
    arr[p] = arr[f];
    arr[f] = temp;

    p = f;
    int lastS1 = f;
    int index = lastS1+1;

    while (index <= l) {
        if (arr[p] > arr[index]) {
            lastS1++;
            moveCount = moveCount + 3;
            int temp1 = arr[index];
            arr[index] = arr[lastS1];
            arr[lastS1] = temp1;
        }
        compCount++;
        index++;
    }

    int temp2 = arr[lastS1];
    arr[lastS1] = arr[p];
    arr[p] = temp2;
    moveCount = moveCount + 3;
    return lastS1;
}


void sorting::quickSort(int *arr, int f ,int l, int &compCount, int &moveCount) {
    if (f < l) {
        int p = partition(arr, f, l, compCount, moveCount);
        quickSort(arr, f, p-1, compCount, moveCount);
        quickSort(arr, p+1, l, compCount, moveCount);
    }
};

void sorting::hybridSort(int *arr, int f ,int l, int &compCount, int &moveCount) {
    if (l - f <= 10) {
        // insertion sort
        for (int unsorted = f+1; unsorted <= l; unsorted++) {
            int value = arr[unsorted];
            int index = unsorted-1;
            moveCount++;

            while (index > (f-1) && arr[index] > value) {
                compCount++;
                moveCount++;
                arr[index+1] = arr[index];
                index--;
            }

            arr[index+1] = value;
            moveCount++;
        }
    } else {
        // quickSort
        int p = partition(arr, f, l, compCount, moveCount);
        hybridSort(arr, f, p-1, compCount, moveCount);
        hybridSort(arr, p+1, l, compCount, moveCount);
    }
};

void sorting::hybridSort(int *arr, int size, int &compCount, int &moveCount) {
    hybridSort(arr, 0, size-1, compCount,moveCount);
};

void sorting::performanceAnalysis() {
    int sizes[] = { 3000, 4500, 6000, 7500, 9000, 10500, 12000, 13500, 15000 };
    int **arrays = new int*[9];

    for (int l = 0; l < 9; l++) {
        arrays[l] = new int[sizes[l]];
        for(int k=0; k<sizes[l]; k++){
            arrays[l][k] = rand()+1;
        }
    }

    cout << endl;
    cout << "-----------------------------------------------------------------" << endl;
    cout << "---------------------------QUICK SORT----------------------------" << endl;
    cout << "-----------------------------------------------------------------" << endl;
    cout << endl;

    for (int i = 0; i < 9; i++) {
        double duration = 0;
        int compCount = 0;
        int moveCount = 0;

        for (int j = 0; j < 10000; j++) {
            compCount = 0;
            moveCount = 0;
            int *array = new int[sizes[i]];

            for(int k=0; k<sizes[i]; k++){
                array[k] = arrays[i][k];
            }

            clock_t startTime = clock();
            quickSort(array, 0,sizes[i]-1,compCount, moveCount);
            duration += 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
            delete [] array;
        }

        duration = duration / 10000;

        cout << "*********************************************" << endl;
        cout << "Array Size      : " << sizes[i] << endl;
        cout << "Time Elapsed    : " << duration << endl;
        cout << "Comparison Count: " << compCount << endl;
        cout << "Move Count      : " << moveCount << endl;
        cout << "*********************************************" << endl;
    }


    cout << endl;
    cout << "-----------------------------------------------------------------" << endl;
    cout << "---------------------------HYBRID SORT---------------------------" << endl;
    cout << "-----------------------------------------------------------------" << endl;
    cout << endl;

    for (int i = 0; i < 9; i++) {
        double duration = 0;
        int compCount = 0;
        int moveCount = 0;

        for (int j = 0; j < 10000; j++) {
            compCount = 0;
            moveCount = 0;
            int *array = new int[sizes[i]];

            for(int k=0; k<sizes[i]; k++){
                array[k] = arrays[i][k];
            }

            clock_t startTime = clock();
            hybridSort(array, sizes[i], compCount, moveCount);
            duration += 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
            delete [] array;
        }

        duration = duration / 10000;
        cout << "*********************************************" << endl;
        cout << "Array Size      : " << sizes[i] << endl;
        cout << "Time Elapsed    : " << duration << endl;
        cout << "Comparison Count: " << compCount << endl;
        cout << "Move Count      : " << moveCount << endl;
        cout << "*********************************************" << endl;
    }


    cout << endl;
    cout << "-----------------------------------------------------------------" << endl;
    cout << "--------------------------INSERTION SORT-------------------------" << endl;
    cout << "-----------------------------------------------------------------" << endl;
    cout << endl;

    for (int i = 0; i < 9; i++) {
        int *array = new int[sizes[i]];

        for(int k=0; k<sizes[i]; k++){
            array[k] = arrays[i][k];
        }

        double duration;
        clock_t startTime = clock();

        int compCount = 0;
        int moveCount = 0;
        insertionSort(array, sizes[i], compCount, moveCount);
        //Compute the number of seconds that passed since the starting time
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

        cout << "*********************************************" << endl;
        cout << "Array Size      : " << sizes[i] << endl;
        cout << "Time Elapsed    : " << duration << endl;
        cout << "Comparison Count: " << compCount << endl;
        cout << "Move Count      : " << moveCount << endl;
        cout << "*********************************************" << endl;

        delete [] array;
    }

    for (int m = 0; m < 9; ++m) {
        delete [] arrays[m];
    }

}