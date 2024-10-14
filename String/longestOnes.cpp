#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

// time complexity = O(n) n is the length of input string
// space complexity = O(1)

int longestOnes(string str, int k){
    int start = 0;
    int end = 0;
    int zero_count = 0;
    int max_length = 0;

    for(; end<str.length(); end++){
        if(str[end]=='0'){
            zero_count++;
        }

        while(zero_count>k){
            if(str[start]=='0') zero_count--;
            start++; // contracting window
        }

        //if zero_count>=k
        max_length = max(max_length, end-start+1);
    }

    return max_length;
}

int main(){
    string str;
    cout << "Enter binary string: ";
    cin >> str;

    int k;
    cout << "Enter maximum flips: ";
    cin >> k;

    cout << longestOnes(str, k) << endl;


    return 0;
}