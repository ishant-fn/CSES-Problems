#include <bits/stdc++.h>
using namespace std;

long long HowManySubarrays (vector<long long> &sum, long long max_val) {
    long long totalSubarrays = 1;
    long long current_position = 0;
    for (int i = 1; i < sum.size(); ++i) {
        if (sum[i] - sum[current_position] > max_val) {
            current_position = i - 1;
            ++totalSubarrays;
        }
    }

    return totalSubarrays;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long target;
    long long currentNumber;
    long long min_sum = -1;
    cin >> n >> target;
    vector<long long> array(n);
    vector<long long> sum(n + 1);
    sum[0] = 0;

    for (int i = 0; i < n; ++i) {
        cin >> currentNumber;
        array[i] = currentNumber;
        sum[i + 1] = sum[i] + currentNumber;
        min_sum = max(min_sum, currentNumber);
    }

    long long max_sum = sum[n];
    long long avg_sum;
    long long correctAnswer = 0;

    while (max_sum >= min_sum) {
        avg_sum = min_sum + (max_sum - min_sum) / 2;
        if (HowManySubarrays(sum, avg_sum) <= target) {
            max_sum = avg_sum - 1;
            correctAnswer = avg_sum;
        } else {
            min_sum = avg_sum + 1;
        }
    }

    cout << correctAnswer;

    return 0;
}