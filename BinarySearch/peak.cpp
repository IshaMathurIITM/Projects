#include<iostream>
#include<vector>
using namespace std;

int findPeakIndex(vector<int> &a){
    int lo = 1, hi = a.size()-1;
    int ans = -1;
    while(lo<=hi){
        int mid = lo + (hi-lo)/2;
        if(a[mid]>a[mid-1]){
            ans = max(mid, ans);
            lo = mid+1;
        }
        else{
            
            hi = mid-1;
        }
    }
    return ans;
}

int main(){
    int n; cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }

    cout << findPeakIndex(v) << endl;


    return 0;
}