#include<iostream>
using namespace std;
int const N = 1e3;

void heapify(int arr[], int size, int curr){

    while(2*curr<=size){
        int leftchild = 2*curr;
        int rightchild = 2*curr + 1;
        int maxchild = leftchild;

        if(rightchild<=size && arr[rightchild]>arr[maxchild]){
            maxchild = rightchild;
        }

        if(arr[maxchild]<=arr[curr]){
            return;
        }

        swap(arr[maxchild],arr[curr]);
        curr = maxchild;
    }
}

void remove(int arr[], int &size){
    swap(arr[1],arr[size]);
    size--;
    heapify(arr, size, 1);

}

void heapSort(int arr[], int n){

    // 1. heapify all parent nodes into max heap
    for(int i=n/2; i>0; i--){
        heapify(arr, n, i);
    }

    //2. keep deleting elements from max heap until size becomes zero
    while(n>0){
        remove(arr, n);
    }
}

int main(){
    int n = 7;
    int arr[N]  = {-1,60,10,80,50,5,20,70};

    heapSort(arr, n);

    for(int i=1; i<=n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}
