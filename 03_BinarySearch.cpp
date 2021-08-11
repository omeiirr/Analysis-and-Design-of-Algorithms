#include<iostream>
#include<vector>
using namespace std;

void displayArray(vector<int> arr, int n){
    // cout<<endl;
    for(int i=0; i<n; ++i){
        // cout<<arr[i]<<"  ";
        cout<<arr.at(i)<<"  ";
    }
}

int iterativeBinarySearch(vector<int> arr, int search){
    int low=0, high=arr.size(), mid;

    while(low<=high){
        mid=(low+high)/2;
        if(arr[mid] == search)
            return mid;
        if(arr[mid] > search)
            high = mid-1;
        if(arr[mid] < search)
            low = mid+1;
    }
    return -1;
}

int recursiveBinarySearch(vector<int> arr, int search, int low, int high){
    if(low > high)
        return -1;
    int mid=(low+high)/2;

    if(arr[mid] == search)
        return mid;
    if(arr[mid] > search)
        return recursiveBinarySearch(arr, search, low, mid-1);
    if(arr[mid] < search)
        return recursiveBinarySearch(arr, search, mid+1, high);
}

int main() {
    cout<<"\t BINARY SEARCH RECURSIVE";

    int n;
    cout<<"\n\nEnter number of elements \t : \t";
    cin>>n;

    // int arr[n];
    vector<int> arr;
    cout<<"\nEnter numbers \t\t\t : \t";
    for(int i = 0; i<n; ++i){
        int x;
        cin >> x;
        arr.push_back(x);
    }

    cout<<"\nArray \t : \t";
    displayArray(arr, n);

    int search;
    cout<<"\n\nEnter element to search \t : \t ";
    cin>>search;

    cout<<"\nIterative version \t : "<<iterativeBinarySearch(arr, search);
    cout<<"\nRecursive version \t : "<<recursiveBinarySearch(arr, search, arr[0], arr[n]);

    return 0;
}
