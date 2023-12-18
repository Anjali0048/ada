#include <iostream>
using namespace std;

void selectionSort(int arr[], int n, bool ascending = true) {
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if ((ascending && arr[j] < arr[minIndex]) || (!ascending && arr[j] > arr[minIndex])) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

void insertionSort(int arr[], int n, bool ascending = true) {
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && ((ascending && key < arr[j]) || (!ascending && key > arr[j]))) {
            arr[j + 1] = arr[j];
            --j;
        }

        arr[j + 1] = key;
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

    insertionSort(arr1, n, true);
    cout << "Insertion Sort (Ascending): ";
    for (int i = 0; i < n; ++i) {
        cout << arr1[i] << " ";
    }
    cout << endl;

    selectionSort(arr2, n, true);
    cout << "Selection Sort (Ascending): ";
    for (int i = 0; i < n; ++i) {
        cout << arr2[i] << " ";
    }
    cout << endl;

    delete[] arr1;
    delete[] arr2;

    return 0;
}
