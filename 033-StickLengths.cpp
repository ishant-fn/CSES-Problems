#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<long long> Numbers;
    
    long long n;
    long long currentNumber;
    cin >> n;

    for (long long i = 1; i <= n; ++i) {
        cin >> currentNumber;
        Numbers.push_back(currentNumber);
    }
    
    sort(Numbers.begin(), Numbers.end());
    long long targetNumber = Numbers[n/2];
    long long total = 0;
    
    for (long long x:Numbers) {
        if (x > targetNumber) {
            total += (x - targetNumber);
        } else {
            total += (targetNumber - x);
        }
    }
    
    cout << total << "\n";

    return 0;
}
