#include <iostream>
using namespace std;

int main()
{
    long long n = 0;
    long long answer = 2;
    cin >> n;
    
    while (n > 1) {
        answer *= 2;
        answer %= 1000000007; // This is used to stop long longs from overflowing. The exact value will be given by CSES.
        --n;
    }
    
    cout << answer;
    
    return 0;
}
