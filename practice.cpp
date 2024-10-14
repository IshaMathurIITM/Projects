#include<iostream>
#include<vector>
#include<cmath>
#include<climits>
#include<algorithm>
using namespace std;

void bucketSort(float arr[], int size){
    vector<vector<float>> bucket(size,vector<float> ());

    int min_ele = arr[0];
    int max_ele = arr[0];
    for(int i=0; i<size; i++){
        max_ele = max(max_ele,arr[i]);
        min_ele = min(min_ele,arr[i]);
    }

    float range = (max_ele - min_ele)/size;
    for(int i=0; i<size; i++){
        int index = (arr[i] - min_ele)/range;

        int diff = (arr[i] - min_ele)/range - index;

        if(diff==0 && arr[i]!=min_ele){
            bucket[index-1].push_back(arr[i]);
        }else{
            bucket[index].push_back(arr[i]);
        }
    }




    int k=0;
    for(int i=0; i<size; i++){
        for(int j=0; j<bucket[i].size(); j++){
            arr[k++] = bucket[i][j];
        }
    }
}

int main(){
    float arr[] = {0.45,0.68,0.35,0.78,0.95,0.12,0.67};
    int size = sizeof(arr)/sizeof(arr[0]);

    bucketSort(arr,size);

    for(int i=0; i<size; i++){
        cout << arr[i] << " ";
    }


    return 0;
}