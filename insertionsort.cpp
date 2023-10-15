#include <iostream>
using namespace std;

int size = 50;
void insertion_sort(int arr[], int n) {
    for(int i = 1; i < n; i++) {
        int temp = arr[i];
        int j = i - 1;
        while((temp < arr[j]) && (j >= 0)) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

int main() {
    int arr[size], n;
    cout << "Enter number of elements for array: " << endl;
    cin >> n;
    cout << "Enter elements for array: " << endl;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    insertion_sort(arr, n);
    cout << "Sorted array is: " << endl;
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}
