#include <iostream>
using namespace std;

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

// function to print the array
void displayArray(int *arr, int n){
    // cout<<endl;
    for(int i=0; i<n; ++i){
        cout<<arr[i]<<"\t";
    }
}

// function to rearrange array (find the partition point)
int partition(int array[], int low, int high) {
  // select the rightmost element as pivot
  int pivot = array[high];
  // pointer for greater element
  int i = (low - 1);
  // traverse each element of the array
  // compare them with the pivot
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
      // if element smaller than pivot is found
      // swap it with the greater element pointed by i
      i++;
      // swap element at i with element at j
      swap(&array[i], &array[j]);
    }
  }

  // swap pivot with the greater element at i
  swap(&array[i + 1], &array[high]);

  // return the partition point
  return (i + 1);
}

void quickSort(int array[], int low, int high) {
  if (low < high) {

    // find the pivot element such that
    // elements smaller than pivot are on left of pivot
    // elements greater than pivot are on righ of pivot
    int pi = partition(array, low, high);

    // recursive call on the left of pivot
    quickSort(array, low, pi - 1);

    // recursive call on the right of pivot
    quickSort(array, pi + 1, high);
  }
}

// Driver code
int main() {
    cout<<"\t QUICK SORT";

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
    quickSort(arr, 0, n-1);

    cout<<"\n\n Sorted Array \t : \t";
    displayArray(arr, n);

    return 0;
}
