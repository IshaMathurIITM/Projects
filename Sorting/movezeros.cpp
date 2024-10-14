#include<iostream>
#include<vector>
#include<climits>
using namespace std;

void moveZeros(vector<int> &arr){
    for(int i=arr.size()-1; i>=0; i--){
        bool flag = 0; //this flag indicates when we can stop our process and that will happen only when all the zeroes have been shifted to the end
        int j=0;
        while(j!=i){
            if(arr[j]==0 && arr[j+1]!=0){ // if any zero is found in between before 'i' that indicates some of the zero is in between therefore we need to turn the flag=1
                swap(arr[j],arr[j+1]);
                flag = 1;
            }
            j++;
        }
        if(flag==0){
            break;
        }
    }
    return;
}
    
int main(){
    int n;
    cout << "Enter the size of array : ";
    cin >> n;

    vector<int> arr(n);

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    moveZeros(arr);

    cout << "After moving zeroes to the end :" << endl;

    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }


    return 0;
}