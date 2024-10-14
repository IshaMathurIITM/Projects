#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

string longestCommonPrefix(vector<string> &str){
    // sorting the input strings
    sort(str.begin(), str.end());

    string s1 = str[0]; //first string
    int i=0;
    string s2 = str[str.size()-1]; // last string
    int j=0;

    string ans="";
    while(i<s1.size() && j<s2.size()){
        if(s1[i]==s2[i]){
            ans+=s1[i];
            i++; j++;
        }
        else{
            break;
        }
    }

    return ans;
}

int main(){
    int n;
    cout << "Enter number of elements in the string: ";
    cin >> n;
    vector<string> str(n);
    cout << "Enter elements of string: ";
    for(int i=0; i<n; i++){
        cin >> str[i];
    }

    cout << "Longest Common Prefix: " << longestCommonPrefix(str) << endl;







    return 0;
}