#include<iostream>
using namespace std;
int main(){
    // int n; // n is the number of elements in the array
    // cin>>n;
    // int array[n];
    // int sum = 0;
    // for(int idx=0;idx<n;idx++){
    //     sum = sum + (idx+1);
    // }
    // cout<<sum;

    int array[] = {3,4,10,11};
    int length = sizeof(array)/sizeof(array[0]);
    int sum = 0;
    for(int idx=0;idx<length;idx++){
        sum = sum + array[idx];
    }
    cout<<sum;



    return 0;
}