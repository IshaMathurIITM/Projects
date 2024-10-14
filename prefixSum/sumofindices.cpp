#include <iostream>
#include <vector>
using namespace std;

// index -> 0 1 2 3 4 5 6
// vector -> 0 x1 x2 

// 0 based indexing -> 0 ..... n-1
// 1 based indexing -> 0 ..... n



int main(){
    int n;
    cout << "Enter array size: ";
    cin >> n;
    vector<int> v(n+1,0);
    for(int i=1; i<=n; i++){
        
        cin >> v[i];
        
    }

    // calculate prefix sum array
    for(int i=1; i<=n; i++){
        v[i] += v[i-1];
    }

    int q;
    cout << "Enter number of queries: ";
    cin >> q;

    while(q--){
        int l,r;
        cout << "Enter left index: ";
        cin >> l;
        cout << "Enter right index: ";
        cin >> r;

        int ans = 0;
        // ans = prefixsum[r] - prefixsum[l-1]
        ans = v[r] - v[l-1];
        cout << ans << endl;

    }
    return 0;

}