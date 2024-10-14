#include<iostream>
#include<vector>
using namespace std;

void selectionSort(vector<int> &v){
    int n = v.size();
    for(int i=0; i<n-1; i++){
        // finding min element in unsorted array
        int min_idx = i;
        for(int j=i+1; j<n; j++){
            if(v[j]<v[min_idx]){
                min_idx=j;
            }
        }
        // placing min element at the beginning
        if(min_idx != i) swap(v[i],v[min_idx]);

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
    for(int i=0; i<n; i++){
        cout << v[i] << " ";
    }
    cout << endl;

    selectionSort(v);
    for(int i=0; i<n; i++){
        cout << v[i] << " ";
    }


    return 0;
}