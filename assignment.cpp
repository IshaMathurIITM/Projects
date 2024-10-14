#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int secondLargestElement(int a[], int n){
    int max = 0;
    int second_max = 0;
    for(int i=0; i<n; i++){
        if(a[i] > max){
            max = a[i];
        }
    }
    for(int i=0; i<n; i++){
        if(a[i] > second_max && a[i]!=max){
            second_max = a[i];
        }
    }
    return second_max;
}

int main(){
    int a[] = {1,2,3,7,4,5,6,7};
    int n = 8;
    cout << secondLargestElement(a,n) << endl;
    
    return 0;
}



    
