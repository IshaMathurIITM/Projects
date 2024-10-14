#include<iostream>
#include<vector>
using namespace std;

void insertionSort(vector<int> &v){
    for(int i=1; i<v.size(); i++){
        int current = v[i];
        int j = i-1;
        while(j>=0 && v[j]>current){
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = current;
    }
    return;
}

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    insertionSort(v);
    for(int i=0; i<n; i++){
        cout << v[i] << " ";
    }



    return 0;
}