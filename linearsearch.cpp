#include<iostream>
using namespace std;
int main()
{
    int arr[100], x, i, num, arrTemp[50], j=0, k=0;
    cout<<"Enter the size for the Array: " << endl;
    cin>>x;
    cout<<"Enter "<< x <<" array elements: ";
    for(i=0; i<x; i++) {
        cin>>arr[i];
    }
    cout<<"Enter the number to be searched: ";
    cin>>num;
    for(i=0; i<x; i++) {
        if(arr[i]==num)
        {
            arrTemp[j] = i;
            j++;
            k++;
        }
    }
    if(k>0) {
        cout<<"Number found at index No. " << endl;
        x = k;
        for(i=0; i<x; i++)
            cout<<arrTemp[i]<<" ";
    }
    else {
        cout<<"Number is not found!";
    }
    cout<<endl;
    return 0;
}
