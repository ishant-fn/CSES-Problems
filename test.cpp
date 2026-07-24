#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long currentNumber;
    cin >> n;
    vector<long long> values;
    map<long long, long long> currentWindow;
    
    for (int i = 0; i < n; ++i) {
        cin >> currentNumber;
        values.push_back(currentNumber);
    }
    
    int ptr1 = 0;
    int ptr2 = 0;
    long long subarrays = 0;
    
    while (ptr2 < n && ptr1 < n) {
        ++currentWindow[values[ptr2]];
        while (currentWindow[values[ptr2]] > 1) {
            --currentWindow[values[ptr1]];
            ++ptr1;
        }
        subarrays += ptr2-ptr1+1;
        ++ptr2;
    }
    
    cout << subarrays;
    
    return 0;
}
