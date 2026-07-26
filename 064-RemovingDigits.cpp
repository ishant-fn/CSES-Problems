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

int removeDigits(vector<int> &numbers, int NumberinInt, vector<int> &prev_numbers) {
    int total = 0;
    int least = 1e9;
    int currentNumber;
    if (NumberinInt == 0) {
        return 0;
    }

    if (NumberinInt < 0) {
        return 1e9;
    }

    if (prev_numbers[NumberinInt] != -1) {
        return prev_numbers[NumberinInt];
    }

    vector<int> NumberinVector;
    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] == 0) {
            continue;
        }
        currentNumber = NumberinInt - numbers[i];
        NumberinVector = toVector(currentNumber);
        total = removeDigits(NumberinVector, currentNumber, prev_numbers) + 1;
        if (total > 1e9) {
            return 1e9;
        }
        least = min(least, total);
    }
    prev_numbers[NumberinInt] = least;
    return least;
}

int main() {
    int n;
    cin >> n;
    vector<int> numbers = toVector(n);
    vector<int> prev_numbers(n + 1, -1);

    removeDigits(numbers, n, prev_numbers);
    cout << prev_numbers[n] << "\n";

    return 0;
}