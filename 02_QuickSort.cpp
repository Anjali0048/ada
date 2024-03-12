#include <iostream>
#include <vector>

using namespace std;

// Partition function for quicksort
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Quicksort function
void quicksort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    cout << "Enter the number of ele: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter the ele : ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // Perform quicksort
    quicksort(arr, 0, n - 1);

    // Display sorted list
    cout << "Quicksort Result: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }

    return 0;
}
