#include<iostream>
#include<vector>
using namespace std;

int partition(int arr[], int first, int last){
    int pivot = arr[last];
    int i = first - 1; // for inserting element less than pivot
    for(int j=first; j<last; j++){ // to find element less than pivot
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[last]);
    return i+1;
}

void quickSort(int arr[], int first, int last){
    // base case
    if(first>=last) return;
    // recursive case
    int pi = partition(arr, first, last);
    quickSort(arr,first,pi-1);
    quickSort(arr,pi+1,last);
}

int main(){
    int arr[6] = {18,12,30,16,35,20};
    quickSort(arr,0,5);
    for(int i=0; i<6; i++){
        cout << arr[i] << " ";
    }



    return 0;
}