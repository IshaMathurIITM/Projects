#include<iostream>
#include<vector>
using namespace std;

int indexOfTarget(vector<int> &a, int target){
    int lo = 0, hi = a.size()-1;

    while(lo<=hi){
        int mid = lo + (hi-lo)/2;
        if(a[mid]==target) return mid;
        if(a[mid]>=a[lo]){
            if(target>=a[lo] and target<=a[mid]){
                hi = mid-1;
            }
            else{
                lo = mid+1;
            }
        }
        else{
            if(target<=a[hi] and target>=a[mid]){
                lo = mid+1;
            }
            else{
                hi = mid-1;
            }
        }
    }
    return -1;
}

    

int main(){
    int n; cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }

    int target; cin >> target;

    cout << indexOfTarget(v,target);



    return 0;
}