#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

string longestCommonPrefix(vector<string> &str){
    // comparing first string as const and comparing it with all other other strings
    string s1 = str[0];
    int ans_length = s1.size();

    for(int i=1; i<str.size(); i++){
        int j=0;
        while(j<s1.size() && j<str[i].size() && s1[j]==str[i][j]){ // finding the common prefix
            j++;
        }

        ans_length = min(ans_length, j); //ipdating length of ans string
    }

    string ans = s1.substr(0, ans_length);
    return ans;
}

int main(){
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements: ";
    vector<string> str(n);
    for(int i=0; i<n; i++){
        cin >> str[i];
    }
    
    cout << "Longest Common Prefix: " << longestCommonPrefix(str);


    return 0;
}