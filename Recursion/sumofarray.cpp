#include<iostream>
using namespace std;

int f(int *arr, int idx, int n){
    if(idx == n-1){
        return arr[idx];
    }
    return arr[idx]+f(arr, idx+1, n);
}

int main(){
    int n=5;
    int arr[5] = {2,3,5,20,1};
    cout << f(arr,0,n);
    return 0;
}