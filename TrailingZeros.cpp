#include <iostream>
using namespace std;

int main()
{
    long long n = 0;
    long long answer = 0;
    long long divisor = 5;
    cin >> n;
    
    while (divisor <= n) {
        answer += n / divisor;
        divisor *= 5;
    }

    cout << answer;
    
    return 0;
}
// Using Legendre's formula to find the trailing 0s of any factorial.
