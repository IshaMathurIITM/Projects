#include<iostream>
#include<vector>
using namespace std;


int lowerbound(vector<int> &input, int target){
    int lo = 0;
    int hi = input.size()-1;
    int lower = -1;
    while(lo<=hi){
        int mid = (lo+hi)/2;
        if(input[mid]>=target){
            lower = mid;
            hi = mid-1;
        }
        else{
            lo = mid+1;
        }
    }
    return lower;
}

int upperbound(vector<int> &input, int target){
    int lo = 0;
    int hi = input.size()-1;
    int upper = -1;
    while(lo<=hi){
        int mid = (lo+hi)/2;
        if(input[mid]>target){
            upper = mid;
            hi = mid-1;
        }
        else{
            lo = mid+1;
        }
    }
    return upper;
}



int main(){
    int n; cin >> n;
    vector<int> input(n);
    for(int i=0; i<n; i++){
        cin >> input[i];
    }
    int target; 
    cin >> target;

    int lb = lowerbound(input, target);


    vector<int> result;
    if(input[lb]!=target){
        result.push_back(-1);
        result.push_back(-1);
    }
    else{
        int ub = upperbound(input, target);
        result.push_back(lb);
        result.push_back(ub-1);
    }

    cout << result[0] << " " << result[1] << endl;

    

    




    return 0;
}