#include <iostream>
using namespace std;

int main() {
    int x, y, z, i, j, arr[100], first, mid, last;
    cout << "Enter size of array: ";
    cin >> x;
    cout << "Enter " << x << " Elements: ";
    for(i=0; i<x; i++) {
        cin >> arr[i];
    }
    for(i=0; i<(x-i-1); i++) {
        for(j=0; j<(x-i-1); j++) {
            if(arr[j]>arr[j+1]) {
                x = arr[j];
                arr[j] = arr[j+1];
                arr[j+1];
            }
        }
    }
    cout << "The sorted array is: \n";
    for(i=0; i<x; i++) {
        cout << arr[i] << " ";
    }
    cout << "\nEnter elements to be searched: ";
    cin >> z;
    first = 0;
    last = (x-1);
    mid = (first+last)/2;
    
    while(first <= last) {
        if(arr[mid]<z) {
            first = mid + 1;
        } else if(arr[mid] == z) {
            cout << z << " found at position " << mid + 1;
            break;
        } else {
            last = mid - 1;
            mid = (first+last)/2;
        }
    if(first>last) {
            cout << "Entered number not found in array!";
            cout << endl;
        }
    }

    return 0;
}
