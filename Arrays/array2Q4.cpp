#include<iostream>
#include<cmath>
using namespace std;

void square(int arr[], int n){
    for(int i=0; i<n; i++){
        arr[i] = arr[i]* arr[i];
    }
    for(int i=0; i<n; i++){
        for(int j=1; j<n-1; j++){
            if(arr[i] > arr[j]){
            arr[i], arr[j] = arr[j], arr[i];
        }
        }
    }
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
}

int main(){
    int n=5;
    int arr[5] = {-5,-4,-3,-2,-1};
    square(arr, n);
}