#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int knapsack(int wt[], int val[], int W, int n){
    if(n==0 || W==0) return 0;
    
    if(wt[n-1]<=W){
        return max(val[n-1] + knapsack(wt,val,W-wt[n-1],n-1), knapsack(wt,val,W,n-1));
    }
    else{
        return (knapsack(wt,val,W,n-1));
    }
}

int main(){
    int wt[4] = {1,3,4,5};
    int val[4] = {1,4,5,7};
    int W = 7;
    int n = 4;

    cout << knapsack(wt,val,W,n) << endl;

    return 0;
}