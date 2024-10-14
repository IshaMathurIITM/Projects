#include<iostream>
#include<climits>
using namespace std;
int const N = 1e3;

void deleteMinHeap(int minHeap[], int &size, int value){
    minHeap[1] = minHeap[size];
    size--;
    int curr = 1;
    
    while(2*curr<=size){
        int left_child = 2*curr;
        int right_child = 2*curr + 1;
        int min_child = left_child;

        if(right_child<=size && minHeap[right_child]<=minHeap[left_child])
        {
            min_child = right_child;
        }

        if(minHeap[min_child]>=minHeap[curr]){
            return;
        }

        swap(minHeap[min_child],minHeap[curr]);
        curr = min_child;
        
    }
}

int main(){
    int minHeap[N] = {-1,5,20,10,40,50,30,60};
    int size = 7;
    int value = 5;
    deleteMinHeap(minHeap, size, value);
    for(int i=1; i<=size; i++){
        cout << minHeap[i] << " ";
    }



    return 0;
}