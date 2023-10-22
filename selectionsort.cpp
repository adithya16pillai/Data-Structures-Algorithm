#include <iostream>
using namespace std;

int smallest(int arr[], int k, int n) {
    int pos = k;
    int small = arr[k];
    for(int i = k + 1; i < n; i++) {
        if(arr[i] < small) {
            small = arr[i];
            pos = i;
        }
    }
    return pos;
}

void selection_sort(int arr[], int n) {
    for(int k = 0; k < n; k++) {
        int pos = smallest(arr, k, n);
        int temp = arr[k];
        arr[k] = arr[pos];
        arr[pos] = temp;
    }
}

int main() {
    int arr[50], n;
    cout << "Enter number of elements for array: " << endl;
    cin >> n;
    cout << "Enter the elements: " << endl;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    selection_sort(arr, n);
    cout << "Sorted array is: " << endl;
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}
