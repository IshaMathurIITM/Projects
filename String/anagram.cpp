#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool isanagram(string s1, string s2){
    vector<int> freq(26, 0);
    
    //if the strings are not equal in size then they cannot be anagrams
    if(s1.length()!=s2.length()){
        return false;
    }

    for(int i=0; i<s1.length(); i++){
        freq[s1[i]-'a']++; // If it is a character from string s1 we increment the frequency
        freq[s2[i]-'a']--; // If it is a character from string s2 we decrement the frequency
    }

    for(int i=0; i<26; i++){
        if(freq[i]!=0){  // If any character's frequency is not zero that means either that character was more in string t or in string s, hence imbalance was found, therefore strings are not anagrams.
            return false; 
        }
    }

    return true;
}

int main(){
    string s1, s2;
    cin >> s1 >> s2;
    if(isanagram(s1,s2)){
        cout << "Yes, strings are anagram";
    }
    else{
        cout << "No, string are not anagram";
    }




    return 0;
}