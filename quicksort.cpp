#include <iostream>
using namespace std;

int n = 50;
int partition(int arr[], int beg, int end) {
    int left, right, temp, loc, x;
    loc = left = beg;
    right = end;
    x = 0;
    while(x != 1) {
        while((arr[loc] <= arr[right]) && (loc != right)) 
        right--;
        if(loc == right) 
        x = 1;
        else if(arr[loc] > arr[right]) {
            temp = arr[loc];
            arr[loc] = arr[right];
            arr[right] = temp;
            loc = right;
        }
        if(x != 1) {
            while((arr[loc] >= arr[left]) && (loc != left)) 
            left++;
            if(loc == left) 
            x = 1;
            else if(arr[loc] < arr[left]) {
                temp = arr[loc];
                arr[loc] = arr[left];
                arr[left] = temp;
                loc = left;
            }
        }
    }
    return loc;
}

void quick_sort(int arr[], int beg, int end) {
    if(beg<end) {
        int loc = partition(arr, beg, end);
        quick_sort(arr, beg, loc - 1);
        quick_sort(arr, loc + 1, end);
    }
}

int main() {
    int arr[n], i, a;
    cout << "Enter number of elements for array: " << endl;
    cin >> a;
    cout << "Enter elements for array: " << endl;
    for(i = 0; i < a; i++) {
        cin >> arr[i];
    }
    quick_sort(arr, 0, a - 1);
    cout << "Sorted array is: " << endl;
    for(i = 0; i < a; i++) {
        cout << arr[i] << " ";
    }
}
