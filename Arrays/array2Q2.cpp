#include<iostream>
using namespace std;

int main(){
    int n=5, x;
    cin >> x;
    bool flag = false;
    int arr[5] = {-1,0,1,2,3};
    int i=0, j=n-1;
    while(i<j){
        if(arr[i] + arr[j] == x){
            flag = true;
            break;
        }
        else if(arr[i] + arr[j] > x){
            j--;
        }
        else{
            i++;
        }
    }
    if(flag == true){
        cout << "Yes";
    }
    else{
        cout << "No";
    }

    return 0;

}