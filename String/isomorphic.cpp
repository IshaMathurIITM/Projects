#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool isisomorphic(string s1, string s2){
    vector<int> freq1(128, -1);
    vector<int> freq2(128, -1);

    if(s1.length()!=s2.length()){  //if size is not equal strings cannot be isomorphic
        return false;
    }

    for(int i=0; i<s1.length(); i++){
        if(freq1[s1[i]]!=freq2[s2[i]]){  //if at any instant the same index is mapped with a different numeric value
            return false;
        }
        freq1[s1[i]] = freq2[s2[i]] = i; //storing string positions in vectors for characters at index i
    }

    return true;

}

int main(){
    string s1, s2;
    cin >> s1 >> s2;

    if(isisomorphic(s1,s2)){
        cout << "Yes";
    }
    else{
        cout << "No";
    }




    return 0;
}