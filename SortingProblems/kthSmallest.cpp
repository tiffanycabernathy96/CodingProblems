//Tiffany Abernathy Implementation of nth Smallest Number in an Array Solution

//Problem::Given an array arr[] and an integer K where K is smaller than size of array, the task is to find the Kth smallest element in the given array. 
//It is given that all array elements are distinct.

//Solution::Modify Quick Sort to only sort the sides of the array that contain the desired nth smallest number. 

#include <iostream>
using namespace std;

//Simple function to swap two numbers in an array
void swap(int* left, int* right) {
    int temp = *left;
    *left = *right;
    *right = temp;
}

int partition(int *arr, int start, int end) {
    //Let the pivot be the last element of the array
    int pivot = arr[end];
    //Set the idx to start
    int idx = start;

    //Place the items less than the pivot to the left of them
    for (int i = start; i < end; i++) {
        if (arr[i] <= pivot) {
            swap(&arr[i], &arr[idx]);
            //Increment the index as another value has been found less than the pivot
            idx++;
        }
    }
    //Finally swap the last value with the index value. Now all values to the left of the index are less than the pivot and all the ones to the right are greater
    swap(&arr[idx], &arr[end]);
    return idx;
}
int kthSmallest(int *arr, int l, int r, int k)
{
    //Find the partition index
    int partI = partition(arr, l, r);
    //If the index is equal to k return arr at the value
    if ((partI - l) == k - 1)
        return arr[partI];
    //Else if the index is greater than the k, run quick sort on the left side of the index
    else if ((partI - l) > k - 1)
        return kthSmallest(arr, l, partI - 1, k);
    //Otherwise the index is less than the k, run quick sort on the right side of the index
    else
        return kthSmallest(arr, partI + 1, r, k - partI + l - 1);
}

int main()
{
    int arr[] = { 11, 31, 9, 23, 29, 15, 27, 21, 1, 19, 7, 13, 25, 17, 3, 5 };
                //1 3 5 7 9 11 13 15 17 19 21 23 25 27 29 31
    int k = 9;
    cout << kthSmallest(arr, 0, 15, k) << endl;
}
