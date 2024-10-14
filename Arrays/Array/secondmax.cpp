#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;

int main(){
    int ans = INT_MIN;
    int arr[6] = {2,6,4,3,8,5};
    for(int i=0; i<6; i++){
        if(arr[i]>ans){
            ans = arr[i];
        }
    }
    cout << ans << endl;
    int second = INT_MIN;
    for(int i=0; i<6; i++){
        if(ans != arr[i]){
            second = max(second, arr[i]);
        }
    }
    cout << second;


    return 0;

}