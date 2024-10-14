#include <iostream>
#include <vector>
using namespace std;

bool checkPrefixSuffixSum(vector<int> &v){
    int totalSum = 0;
    for(int i=0; i<v.size(); i++){
        totalSum += v[i];
    }

    int prefix_sum = 0;
    for(int i=0; i<v.size(); i++){
        prefix_sum += v[i];
        int suffix_sum = totalSum - prefix_sum;

        if(suffix_sum == prefix_sum){
            return true;
        }
    }
    return false;
}
int main(){
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        int ele;
        cin >> ele;
        v.push_back(ele);
    }
    
    cout << checkPrefixSuffixSum(v) << endl;


    return 0;
}