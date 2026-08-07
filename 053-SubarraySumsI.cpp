#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long target;
    long long currentNumber;
    cin >> n >> target;
    vector<long long> numbers(n);
    vector<long long> sums(n + 1);
    sums[0] = 0;

    for (int i = 0; i < n; ++i) {
        cin >> currentNumber;
        numbers[i] = currentNumber;
        sums[i + 1] = sums[i] + currentNumber;
    }

    int ptr1 = 0;
    int ptr2 = 0;
    int sum = 0;
    int total = 0;

    while (ptr1 <= n) {
        sum = sums[ptr2] - sums[ptr1];
        if (sum < target && ptr2 <= n) {++ptr2;} else if (sum == target) {++total; ++ptr1;} else {++ptr1;}
    }

    cout << total;

    return 0;
}