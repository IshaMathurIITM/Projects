#include<iostream>
using namespace std;
int const N = 1e3;

void heapifyMinHeap(int minHeap[], int size, int &curr){
    
    while(2*curr<=size){
        int leftchild = 2*curr;
        int rightchild = 2*curr + 1;
        int minchild = leftchild;

        if(rightchild<=size && minHeap[rightchild]<minHeap[minchild]){
            minchild = rightchild;
        }

        if(minHeap[minchild]>=minHeap[curr]){
            return;
        }

        swap(minHeap[minchild],minHeap[curr]);
        curr = minchild;
    }
}

int main(){
    int minHeap[N] = {-1,60,10,80,50,5,20,70};
    int size = 7;

    for(int i=size/2; i>0; i--){
        // i-> parent node
        heapifyMinHeap(minHeap, size, i);
    }

    for(int i=1;i <=size; i++){
        cout << minHeap[i] << " ";
    }


    return 0;
}