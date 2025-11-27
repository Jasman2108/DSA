#include <iostream>
using namespace std;

// SELECTION SORT 
void selectionSort(int arr[], int n) {
    for(int i = 0; i < n-1; i++) {
        int minIndex = i;
        for(int j = i+1; j < n; j++) {
            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // swap
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

// INSERTION SORT 
void insertionSort(int arr[], int n) {
    for(int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

// BUBBLE SORT 
void bubbleSort(int arr[], int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// MERGE FUNCTION 
void merge(int arr[], int l, int mid, int r) {
    int n1 = mid - l + 1;
    int n2 = r - mid;

    int A[n1], B[n2];

    for(int i = 0; i < n1; i++) A[i] = arr[l + i];
    for(int i = 0; i < n2; i++) B[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = l;

    while(i < n1 && j < n2) {
        if(A[i] <= B[j]) {
            arr[k++] = A[i++];
        } else {
            arr[k++] = B[j++];
        }
    }

    while(i < n1) arr[k++] = A[i++];
    while(j < n2) arr[k++] = B[j++];
}

//MERGE SORT
void mergeSort(int arr[], int l, int r) {
    if(l < r) {
        int mid = (l + r) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}

// PARTITION FOR QUICK SORT 
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; j++) {
        if(arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

// QUICK SORT 
void quickSort(int arr[], int low, int high) {
    if(low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// PRINT ARRAY 
void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// MAIN FUNCTION 
int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter array elements: ";
    for(int i = 0; i < n; i++) cin >> arr[i];

    int choice;
    cout << "\n1. Selection Sort\n2. Insertion Sort\n3. Bubble Sort\n4. Merge Sort\n5. Quick Sort\n";
    cout << "Enter choice: ";
    cin >> choice;

    switch(choice) {
        case 1: selectionSort(arr, n); break;
        case 2: insertionSort(arr, n); break;
        case 3: bubbleSort(arr, n); break;
        case 4: mergeSort(arr, 0, n-1); break;
        case 5: quickSort(arr, 0, n-1); break;
        default: cout << "Invalid choice"; return 0;
    }

    cout << "Sorted Array: ";
    printArray(arr, n);

    return 0;
}
