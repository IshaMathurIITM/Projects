#include<iostream>
using namespace std;

int binarySearch(int arr[], int n, int target){
    int lo = 0;
    int hi = n-1;
    while(hi>=lo){
        int mid = lo + (hi-lo)/2;
        if(arr[mid]==target) return mid;
        else if(arr[mid]<target){
            lo = mid+1;
        }
        else{
            hi = mid-1;
        }
    }
    return -1;
}

int main(){
    int arr[] = {2,2,5,5,5,6,6,8,9,9,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << binarySearch(arr, n, 6);



    return 0;
}