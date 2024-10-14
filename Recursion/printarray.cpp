#include<iostream>
using namespace std;

void f(int *arr, int idx, int n){
    // base case
    if(idx==n) return;
    // self work
    cout << arr[idx] << endl;
    // assume that
    f(arr, idx+1, n);
}

int main(){
    int n=5;
    int arr[] = {6,1,9,4,3};
    f(arr,0,n);
    return 0;
}