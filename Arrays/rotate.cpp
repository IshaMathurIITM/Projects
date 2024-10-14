#include<iostream>
using namespace std;
int main(){
    int a[] = {1,2,3,4,5};
    int n = 5; // n is size
    int k;
    cout<<"Enter k: "; // array will be rotated k times
    cin>>k;
    // k can be greater than n
    k = k%n;
    int ansarray[5];
    int j=0;
    // inserting last k elements in array
    for(int i=n-k;i<n;i++){
        ansarray[j++] = a[i];
    }

    // inserting first n-k elements in ans array
    for(int i=0;i<n-k;i++){
        ansarray[j++] = a[i];
    }
    for(int i=0;i<n;i++){
        cout<<ansarray[i]<<" ";
    }
    cout<<endl;

}