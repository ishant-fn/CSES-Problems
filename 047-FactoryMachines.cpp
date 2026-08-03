#include <bits/stdc++.h>
using namespace std;

bool InTime(vector<long long> &machine_speeds, long long time, long long target) {
    long long total = 0;
    for (int machine_speed : machine_speeds) {
        total += time / machine_speed;
        if (total >= target) {
            return true;
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long target;
    long long currentNumber;
    cin >> n >> target;
    vector<long long> machine_speeds(n);

    for (int i = 0; i < n; ++i) {
        cin >> currentNumber;
        machine_speeds[i] = currentNumber;
    }

    sort(machine_speeds.begin(), machine_speeds.end());
    
    long long max_time = target * machine_speeds.front();
    long long avg_time;
    long long min_time = 0;
    long long correct_answer = -1;

    while (min_time <= max_time) {
        avg_time = (min_time + max_time) / 2;
        if (InTime(machine_speeds, avg_time, target)) {
            max_time = avg_time - 1;
            correct_answer = avg_time;
        } else {
            min_time = avg_time + 1;
        }
    }
    cout << correct_answer;
}