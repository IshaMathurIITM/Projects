#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int> &input, int target){
    // define search space
    int lo = 0; // start of the search space 
    int hi = input.size() - 1; // end of the search space
    while(lo <= hi){
        // calculate mid point of the search space
        int mid = (lo+hi) / 2;
        if (input[mid] == target) return mid;
        else if(input[mid]<target){
            lo = mid+1; // discard the left of the mid
        }
        else{
            hi = mid-1; // discard the right of the mid
        }
    }
    return -1;
}

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    int target; cin >> target;
    cout << binarySearch(v, target);



    return 0;
}