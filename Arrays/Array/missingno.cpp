#include<iostream>
using namespace std;

int main(){
    int n = 6;
    int sum = n*(n+1) / 2;
    
    int arr[5] = {1,3,4,5,6};
    int sum_arr = 0;
    for(int i=0; i<n-1; i++){
        sum_arr += arr[i];
    }
    
    int missing_number = sum - sum_arr;
    cout << "The missing number in the array is: " << missing_number;


    return 0;
}