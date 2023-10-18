#include <iostream>
using namespace std;

int n = 50;
void merge(int arr[], int beg, int mid, int end) {
    int i=beg, j=mid+1, k=beg, temp[n], x;
    while((i <= mid) && (j <= end))
    {
        if(arr[i] < arr[j]) {
            temp[k] = arr[i];
            i++;
        } else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }
    if(i > mid) {
        while(j <= end){
            temp[k] = arr[j];
            j++;
            k++;
        }
    } else {
        while(i <= mid) {
            temp[k] = arr[i];
            i++;
            k++;
        }
    }
    for(x = beg;x < k;x++)
    arr[x] = temp[x];
}

void merge_sort(int arr[], int beg, int end) {
    int mid;
    if(beg<end) {
        mid = (beg+end)/2;
        merge_sort(arr, beg, mid);
        merge_sort(arr, mid+1, end);
        merge(arr, beg, mid, end);
    }
}

int main() {
    int arr[n], i, a;
    cout << "Enter the number of elements for array: " << endl;
    cin >> a;
    cout << "Enter the elements: ";
    for(i = 0;i < a;i++) {
        cin >> arr[i];
    }
    merge_sort(arr, 0, a-1);
    cout << "Sorted array is: " << endl;
    for(i = 0;i < a; i++) {
        cout << arr[i] << " ";
    }
}
