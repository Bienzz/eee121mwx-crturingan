#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Function to allocate memory for the array
int *intArray(int size){ 
    int *arr = new int[size];
    return arr;
}

// Function to partition the array
int partition(int A[], int l, int h){
    int p = A[h]; // O(1) - Assigning pivot element
    int i = l - 1; // O(1) - Initializing index variable

    // Iterating through the array
    for(int j = l; j <= h; j++){ // O(n) - 'n' is the size of the array
        if(A[j] < p){ // O(1) - Comparison
            i++; // O(1) - Incrementing index
            swap(A[i], A[j]); // O(1) - Swapping elements
        }
    }
    swap(A[i + 1], A[h]); // O(1) - Swapping elements
    return (i + 1); // O(1) - Returning pivot index
}
 
// Recursive function for quicksort
void quick_sort(int A[], int l, int h){
    if(l < h){
        int p = partition(A, l, h); // O(n) - Partitioning the array
        quick_sort(A, l, p - 1); // Recursively sorting left subarray
        quick_sort(A, p + 1, h); // Recursively sorting right subarray
    }
}

// Main function
int main(){
    int size;
    cin >> size;

    int *intArr = intArray(size);
    
    // Input elements into the array
    for (int i = 0; i < size; i++){
        cin >> intArr[i];
    }

    // Sorting the array using quicksort algorithm
    quick_sort(intArr, 0, size - 1); // O(n log n) - Time complexity of quicksort
    cout << "Quicksorted Array" << endl;
    
    // Printing the sorted array
    for(int i = 0; i < size; i++){
        cout << intArr[i] << endl;
    }
    
    delete[] intArr;
    return 0;
}

/*
WORSE CASE SCENARIO 

T(n)=T(n−1)+T(1)+O(n)
T(n)=T(n−1)+c+O(n)
T(n)=(T(n−2)+c+O(n−1))+c+O(n)
T(n) = (T(n-2)+c+O(n-1))+c+O(n)
=T(n−2)+2c+O(n−1)+O(n)
T(n)=T(n−k)+kc+O(n−(k−1))+O(n−(k−2))+…+O(n−1)+O(n)
T(n-k) -> T(1) when k = n-1
T(n)=T(1)+nc+O(1)+O(2)+…+O(n−1)+O(n)
WORSE CASE SCENARIO TIME COMPLEXITY: O(n^2)

WORSE CASE TIME COMPLEXITY IS O(n) DUE TO RECURSIVE CALL OF QUICKSORT FUNCTION TWICE
*/

/*
AVERAGE CASE SCENARIO

n*T(n)–(n–1)*T(n–1) = 2*T(n–1)+n2*c–(n–1)2*c
n*T(n) = T(n–1)*(2+n–1)+c+2*n*c–c
= (n+1)*T(n–1)+2*n*c
T(n)/(n+1) = T(1)/2+2*c*[1/2 + 1/3 + . . . + 1/(n–1)+1/n + 1/(n+1)]
T(n) = 2 * c * log2n * (n + 1)
AVERAGE CASE SCENARIO TIME COMPLEXITY: O(n log n)

AVERAGE CASE TIME COMPLEXITY IS O(n) DUE TO RECURSIVE CALL OF QUICKSORT FUNCTION TWICE
*/