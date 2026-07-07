#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<long long> Numbers;
    
    long long n;
    long long currentNumber;
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> currentNumber;
        Numbers.push_back(currentNumber);
    }
    
    long long current_sum = 0;
    long long current_max = 0;
    long long greatest_singleVal = -10000000000LL; // less than the maximum bounds
    
    for (long long x: Numbers) {
        if (current_sum >= 0) {
            current_sum += x;
        } else {
            current_sum = x;
        }
        
        if (current_sum > current_max) {
            current_max = current_sum;
        }
        if (x > greatest_singleVal) {
            greatest_singleVal = x;
        }
    }
    
    if (greatest_singleVal < 0) {
        cout << greatest_singleVal;
    } else {
        cout << current_max;
    }

    return 0;
}
