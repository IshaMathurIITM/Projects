#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void bucketSort(float arr[], int size){
    // step-1: Creating bucket
    vector<vector<float> > bucket(size, vector<float> ());

    // finding range
    float max_ele = arr[0];
    float min_ele = arr[0];
    for(int i=0; i<size; i++){
        max_ele = max(max_ele,arr[i]);
        min_ele = min(min_ele,arr[i]);
    }
    float range = (max_ele - min_ele)/size;
    // step-2: inserting elements into the bucket
    for(int i=0; i<size; i++){
        int index = (arr[i]-min_ele)/range;
        // boundary element
        float diff = (arr[i]-min_ele)/range - index;
        if(diff==0 && arr[i]!=min_ele){
            bucket[index-1].push_back(arr[i]);
        }
        
        else{
            bucket[index].push_back(arr[i]);
        }
    }

    // step-3: sorting individual buckets
    for(int i=0; i<size; i++){
        if(!bucket.empty()){
            sort(bucket[i].begin(), bucket[i].end());
        }
    }

    // step-4: combining elements from buckets
    int k=0;
    for(int i=0; i<size; i++){
        for(int j=0; j<bucket[i].size(); j++){
            arr[k++] = bucket[i][j];
        }
    }


}

int main(){
    float arr[] = {6.13, 8.45, 0.12, 1.89, 4.75, 2.63, 7.85, 10.39};
    int size = sizeof(arr)/sizeof(arr[0]);
    bucketSort(arr, size);
    for(int i=0; i<size; i++){
        cout << arr[i] << " ";
    }



    return 0;
}