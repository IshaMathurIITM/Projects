#include<bits/stdc++.h>
#include <climits>
#include<iostream>
using namespace std;
	void swapElements(int *input, int i, int j){
		int temp=input[i];
		input[i]=input[j];
		input[j]=temp;
	}
	
	void reverse(int *input, int start, int end){
		int i=start, j=end;
		while(i<j){
			swapElements(input, i, j);
			i++;
			j--;
		}
	}

	void rotate(int *input, int d, int n){
		if(d>=n && n!=0){
			d=d%n;
		}
		else if(n==0){
			return;
		}
		reverse(input,0,n-1);                 // Here we reverse the array
		reverse(input,0,n-d-1);               // Here we re-reverse the array till the position after which the shifted elements are placed
		reverse(input,n-d,n-1);               // Here we re-reverse the array from the position of shift till the last index
    }
    int main()
{
	int t;
    cout<<"Number of arrays: ";
	cin >> t;
	
	while (t--)
	{
		int size;
        cout<<"Enter array size: ";
		cin >> size;

		int *input = new int[size];
        cout<<"Enter elements of array separated by space: ";
		for (int i = 0; i < size; ++i)
		{
			cin >> input[i];
		}

		int d;
        cout<<"Enter number of elements after which array is rotated: ";
		cin >> d;

		rotate(input, d, size);

		for (int i = 0; i < size; ++i)
		{
			cout << input[i] << " ";
		}
		
		delete[] input;
		cout << endl;
	}

	return 0;
}