#include <iostream>
#include <algorithm>
using namespace std;

// f represents whether the x is present in the range [i, n-1] or not
int f(int *arr, int n, int i, int x){
    if(i==n)  return false; // array is exhausted
    return ((arr[i]==x)  || f(arr,n,i+1,x));
}

int main(){
    int arr[] = {1,2,3,4,5,6};
    int x = 8;
    int n = 6;
    cout << f(arr, n, 0, x);

    return 0;
}