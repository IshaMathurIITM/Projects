#include <iostream>
using namespace std;
int main()
{
    int n; // print nth fibonacci number
    cout << "Enter a number: ";
    cin >> n;
    int fib1 = 1;
    int fib2 = 1;
    int sum = 1;
    for (int i = 1; i <= n-2; i++)
    {
        sum = fib1 + fib2;
        fib1 = fib2;
        fib2 = sum;
    }
    cout <<n<<"th fabonacci number is: " << sum;
    

    return 0;
}