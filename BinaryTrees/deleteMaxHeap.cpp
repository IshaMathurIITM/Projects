#include<iostream>
using namespace std;
int const N = 1e3;

void insertMaxHeap(int maxHeap[], int &size, int value){
    maxHeap[1] = maxHeap[size];
    size--;
    int curr = 1;

    while(2*curr<=size){
        int leftchild = 2*curr;
        int rightchild = 2*curr + 1;
        int maxchild = leftchild;

        if(rightchild<=size && maxHeap[leftchild]<=maxHeap[rightchild]){
            maxchild = rightchild;
        }

        if(maxHeap[maxchild]<=maxHeap[curr]){
            return;
        }

        swap(maxHeap[maxchild],maxHeap[curr]);
        curr = maxchild;
    }
}

int main(){

    int maxHeap[N] = {-1,90,80,70,20,10,50,60};
    int size = 7;
    int value = 90;

    insertMaxHeap(maxHeap, size, value);
    for(int i=1; i<=size; i++){
        cout << maxHeap[i] << " ";
    }

    return 0;
}