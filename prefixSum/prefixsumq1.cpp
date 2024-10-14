#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void runningSum (vector<int> &v){
    for(int i=0; i<v.size(); i++){
        v[i+1] += v[i];
    }
    return;
}
int main(){
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    runningSum(v);
    for(int i=0; i<n; i++){
        cout << v[i] << " ";
    }
    

    
    return 0;
}
