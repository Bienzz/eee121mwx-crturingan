#include <iostream>
using namespace std;

int *intArray(int size){ // func to allocate memory for the array
    int *arr = new int[size]; // create the array with the specified size
    return arr; // return the created array
}

int main(){
    int size;
    cout << "Size: "; 
    cin >> size; // get the size of the array
    int *intArr = intArray(size); //create a pointer pointing to the address of the array


    for (int i = 0; i < size; i++){ // for my input, I just store numbers from 1 to size of the array in the array
        intArr[i] = i+1;
    }

    for (int i = 0; i < size; i++){ // loop to print the elements of the array
        cout << intArr[i] << ' '; 
    } 

    delete[] intArr; // deallocate the array in the memory

    return 0;
}