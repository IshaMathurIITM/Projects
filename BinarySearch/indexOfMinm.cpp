#include<iostream>
#include<vector>
using namespace std;

int indexOfMin(vector<int> &a){
    int lo =  0, hi = a.size()-1;
    if(a.size()==1) return 0;
    if(a[lo]<a[hi]){ // sorted array
        return lo; 
    }
    while(lo<=hi){
        int mid = lo + (hi-lo)/2;
        if(a[mid]>a[mid+1]){
            return mid+1;
        }
        if(a[mid]<a[mid-1]){
            return mid;
        }
        if(a[mid]>a[lo]){
            lo = mid+1;
        }
        else{
            hi = mid-1;
        }
    }
    return -1;
}

int main(){

    int n; cin >> n;
    vector<int> v(n);
    for(int i=0; i< n; i++){
        cin >> v[i];
    }

    cout << indexOfMin(v) << endl;

    return 0;
}