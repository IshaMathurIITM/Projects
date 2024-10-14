#include<iostream>
using namespace std;
int const N = 1e3;

void heapify(int arr[], int size, int curr){

    while((2*curr+1) < size){
        int leftchild = 2*curr+1;
        int rightchild = 2*curr+2;
        int minchild = leftchild;

        if(rightchild<size && arr[rightchild]<arr[minchild]){
            minchild = rightchild;
        }

        if(arr[minchild]>=arr[curr]){
            return;
        }

        swap(arr[minchild],arr[curr]);
        curr = minchild;
    }
}

void remove(int arr[], int &n){
    swap(arr[0],arr[n-1]);
    n--;
    heapify(arr, n, 0);
}

int main(){
    int arr[N] = {7,10,4,3,20,15};
    int size = 5;
    int k = 3;

    for(int i=size/2; i>=0; i--){
        heapify(arr, size, i);
    }

    for(int i=1; i<=k-1; i++){
        remove(arr, size);
    }

    cout << arr[0];

    return 0;
}