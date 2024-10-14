#include <iostream>
using namespace std;

int fibo(int n)
{
    if (n == 0 || n == 1)
    { // Base case
        return n;
    }
    return fibo(n - 1) + fibo(n - 2); // assumption and self work
}

int main()
{   
    int result = fibo(5);
    cout << result;

    return 0;
}