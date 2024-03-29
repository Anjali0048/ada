#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex] ) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && key < arr[j]) {
            arr[j + 1] = arr[j];
            --j;
        }

        arr[j + 1] = key;
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int* arr1 = new int[n];
    int* arr2 = new int[n];

    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr1[i];
    }
    
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr2[i];
    }

    insertionSort(arr1, n);
    cout << "Insertion Sort (Ascending): ";
    printArray(arr1,n);
    cout << endl;

    selectionSort(arr2, n);
    cout << "Selection Sort (Ascending): ";
    printArray(arr2,n);
    
    cout << endl;

    delete[] arr1;
    delete[] arr2;

    return 0;
}
