#include<iostream> 
#include<vector>
#include<climits>
using namespace std;

int firstoccurence(vector<int> &arr, int target){
    int n = arr.size()-1;
    int lo = 0, hi = n-1;
    int first = -1;
    while(lo<=hi){
        int mid = (lo+hi)/2;
        if(arr[mid]==target){
            first = mid;
            hi = mid-1;
        }
        else if(arr[mid]<target){
            lo = mid+1;
        }
        else{
            hi = mid-1;
        }
    }
    return first;
}

int main(){
    int n; cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    int target; cin >> target;

    cout << firstoccurence(v, target) << endl;



    return 0;
}
