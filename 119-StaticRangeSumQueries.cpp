#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int q;
    long long currentNumber;
    int currentQueryStart;
    int currentQueryEnd;
    vector<long long> previous_sums = {0};

    cin >> n >> q;

    for (int i = 0; i < n; ++i) {
        cin >> currentNumber;
        previous_sums.push_back(previous_sums.back() + currentNumber);
    }

    for (int i = 0; i < q; ++i) {
        cin >> currentQueryStart;
        cin >> currentQueryEnd;
        cout << previous_sums[currentQueryEnd] - previous_sums[currentQueryStart - 1] << "\n";
    }
}