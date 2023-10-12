#include <iostream>
using namespace std;

int main() {
    int n, temp, arr[50];
    cout << "Enter the number of elements: "<<endl;
    cin >> n;
    cout << "Enter the elements for the array: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for(int i = 0; i < n; i++) {
        for(int x = 0; x < n-i-1; x++) {
            if(arr[x] > arr[x+1]) {
                temp = arr[x];
                arr[x] = arr[x+1];
                arr[x+1] = temp;
            }
        }
    }
    cout << "The sorted array using bubble sort is: " << endl;
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
