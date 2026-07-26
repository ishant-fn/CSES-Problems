#include <bits/stdc++.h>
using namespace std;

vector<int> toVector(int n) {
    vector<int> numbers;
    while (true) {
        if (n / 10 > 0) {
            numbers.push_back(n % 10);
            n /= 10;
        } else {
            numbers.push_back(n);
            break;
        }
    }
    return numbers;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int least;
    int currentNumber;
    cin >> n;

    vector<int> prev_solutions(n + 1, -1);
    prev_solutions[0] = 0;

    vector<int> NumberinVector;
    for (int i = 1; i <= n; i++) {
        least = 1e9;
        NumberinVector = toVector(i);
        for (int currentDigit : NumberinVector) {
            if (currentDigit == 0) {
                continue;
            }
            if (currentDigit < 0) {
                break;
            }
            currentNumber = i - currentDigit;
            least = min(least, prev_solutions[currentNumber] + 1);
        }
        prev_solutions[i] = least;
    }
    cout << prev_solutions[n] << "\n";
}
