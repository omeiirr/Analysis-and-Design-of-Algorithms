#include<iostream>

using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a= b;
    b=temp;
}

void displayArray(int *arr, int n){
    // cout<<endl;
    for(int i=0; i<n; ++i){
        cout<<arr[i]<<" ";
    }
}

void bubbleSort (int *arr, int n) {
    for(int i=0; i<n;++i){
        bool isSwapped = false;

        for(int j = 0; j<n - i -1; ++j){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                isSwapped = true;
            }
        }

        if(!isSwapped){
            cout<<"\n\n No swap in this pass, array is sorted";
            break;
        }

        cout<<"\n\n Pass "<<i+1<<" \t : \t";
        displayArray(arr, n);
    }
}

int main() {

    cout<<"\t BUBBLE SORT";

    int n;
    cout<<"\nEnter number of elements \t : \t";
    cin>>n;

    int arr[n];
    cout<<"Enter numbers \t : \n";
    for(int i = 0; i<n; ++i){
        cin >> arr[i];
    }

    cout<<"\n Initial Array \t : \t";
    displayArray(arr, n);

    cout<<"\n\n Sorting. . .";
    bubbleSort(arr, n);

    cout<<"\n\n Sorted Array \t : \t";
    displayArray(arr, n);

    return 0;
}
