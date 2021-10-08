#include <bits/stdc++.h>
using namespace std;

// A utility function that returns
// maximum of two integers
int max(int a, int b) { return (a > b) ? a : b; }

// Returns the maximum value that
// can be put in a knapsack of capacity W
int knapSack(int W, int wt[], int val[], int n)
{

    // Base Case
    if (n == 0 || W == 0)
        return 0;

    // If weight of the nth item is more
    // than Knapsack capacity W, then
    // this item cannot be included
    // in the optimal solution
    if (wt[n - 1] > W)
        return knapSack(W, wt, val, n - 1);

    // Return the maximum of two cases:
    // (1) nth item included
    // (2) not included
    else
        return max(
            val[n - 1]
                + knapSack(W - wt[n - 1],
                           wt, val, n - 1),
            knapSack(W, wt, val, n - 1));
}

// Driver code
int main()
{
    int n, capacity;
    cout<<"\nEnter number of items : ";
    cin>>n;

    int val[n];
    int wt[n];

    cout<<"\nEnter value and weight of each item : \n";
    for(int i=0; i<n; ++i){
        cin >> val[i];
        cin >> wt[i];
    }

    // int val[] = { 60, 100, 120 };
    // int wt[] = { 10, 20, 30 };

    cout<<"\nEnter capacity of knapsack : ";
    cin>> capacity;
    // int W = 50;
    // int n = sizeof(val) / sizeof(val[0]);
    cout << "\nMaximum profit earned = " << knapSack(capacity, wt, val, n);
    return 0;
}
