#include<iostream>
#include<vector>
using namespace std;


int main(){
    int m=3, n=3;
    int arr[m+n];
    int arr1[3] = {1,2,3};
    int arr2[3] = {4,5,6};
    int i=m-1, j=n-1, k=m+n-1;
    while(i>=0 && j>=0){
        if(arr1[i] < arr2[j]){
            arr[k--] = arr2[j--];
        }
        else{
            arr[k--] = arr1[i--];
        }
    }
    while(i>=0){
        arr[k--] = arr1[i--];
    }
    while(j>=0){
        arr[k--] = arr2[j--];
    }
    for(int k=0; k<(m+n); k++){
        cout << arr[k] << " ";
    }



    return 0;
}
