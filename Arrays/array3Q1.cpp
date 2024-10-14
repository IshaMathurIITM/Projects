#include<iostream>
#include<vector>
using namespace std;

int main(){
    
    int n, l, r, sum=0;
    cin >> n;
    vector <int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    cout << "Enter left index: ";
    cin >> l;
    cout << "Enter right index: ";
    cin >> r;
    for(int i=l; i<=r; i++){
        sum += v[i];
    }
    cout << sum;





    return 0;
}