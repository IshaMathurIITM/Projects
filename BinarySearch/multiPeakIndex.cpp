#include<iostream>
#include<vector>
using namespace std;

int multiPeakIndex(vector<int> &v){
    int n= v.size();
    int lo= 0, hi=n-1;
    while(lo<=hi){
        int mid = lo + (hi-lo)/2;
        if(mid==0){
            if(v[mid]>v[mid+1]){
                return 0;
            }else{
                return 1;
            }
        }
        else if(mid==n-1){
            if(v[mid]>v[mid-1]){
                return n-1;
            }else{
                return n-2;
            }
        }
        else{
            if(v[mid]>v[mid-1] and v[mid]>v[mid+1]){
                return mid;
            }
            else if(v[mid]>v[mid-1]){
                lo = mid+1;
            }else{
                hi = mid-1;
            }
        }
    }
}

int main(){

    int n; cin >> n;
    vector<int> v(n);
    while(n--){
        int x;
        cin >> x;
        v.push_back(x);
    }

    cout << multiPeakIndex(v) << endl;


    return 0;
}