#include <iostream>
using namespace std;

void improvedSelectionSort(int arr[], int n) {
    int start = 0;
    int end = n - 1;

    while(start < end) {

        int minIndex = start;
        int maxIndex = start;

        // Find both min and max in the current range
        for(int i = start; i <= end; i++) {
            if(arr[i] < arr[minIndex]) {
                minIndex = i;
            }
            if(arr[i] > arr[maxIndex]) {
                maxIndex = i;
            }
        }

        // Swap the minimum element with the start
        int temp = arr[start];
        arr[start] = arr[minIndex];
        arr[minIndex] = temp;

        // If max element was at "start", we just moved it to minIndex
        if(maxIndex == start) {
            maxIndex = minIndex;
        }

        // Swap the maximum element with the end
        temp = arr[end];
        arr[end] = arr[maxIndex];
        arr[maxIndex] = temp;

        start++;
        end--;
    }
}

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) cin >> arr[i];

    improvedSelectionSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}
