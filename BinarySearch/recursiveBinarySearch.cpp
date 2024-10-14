#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int> &input, int target, int lo, int hi){
    if(lo > hi) return -1;
    int mid = (lo+hi)/2;
    if(input[mid]==target) return mid;
    else if(input[mid]<target){
        return binarySearch(input, target, mid+1, hi);
    }
    else{
        return binarySearch(input, target, lo, mid-1);
    }

}

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    int target; cin >> target;
    cout << binarySearch(v, target, 0, n-1 );



    return 0;
}