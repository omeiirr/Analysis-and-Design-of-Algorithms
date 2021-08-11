#include<iostream>
using namespace std;

void displayArray(int *arr, int n){
    // cout<<endl;
    for(int i=0; i<n; ++i){
        cout<<arr[i]<<"\t";
    }
}

void insertionSort(int *arr, int n){
    int i, key, j;
    for (i=1; i<n; ++i, displayArray(arr, n), cout<<endl){
        key = arr[i];
        j = i -1;

        // If array is already sorted, don't enter while loop
        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    cout<<"\t INSERTION SORT";

    int n;
    cout<<"\n\nEnter number of elements \t : \t";
    cin>>n;

    int arr[n];
    cout<<"\nEnter numbers \t : ";
    for(int i = 0; i<n; ++i){
        cin >> arr[i];
    }

    cout<<"\n Initial Array \t : \t";
    displayArray(arr, n);

    cout<<"\n\n Sorting. . . \n";
    insertionSort(arr, n);

    cout<<"\n\n Sorted Array \t : \t";
    displayArray(arr, n);

    return 0;
}
