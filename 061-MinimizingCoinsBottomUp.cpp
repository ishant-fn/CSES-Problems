#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int target;
    int current_target;
    int current_number;
    int min_val = 1e9;
    int current_val = 0;
    int n;
    
    vector<long long> coins;
    
    cin >> n;
    cin >> target;

    vector<long long> previous_solutions(target + 1);
    
    previous_solutions[0] = 0;
    
    for (int i = 0; i < n; ++i) {
        cin >> current_number;
        coins.push_back(current_number);
    }
    
    sort(coins.begin(), coins.end());
    
    for (int i = 1; i <= target; ++i) {
        min_val = 1e9;
        for (int current_coin = 0; current_coin < coins.size(); ++current_coin) {
            current_target = i - coins[current_coin];
            if (current_target < 0) {
                break;
            }
            current_val = previous_solutions[current_target]+1;
            if (min_val > current_val) {
                min_val = current_val;
            }
        }
        previous_solutions[i] = min_val;
    }
    if (previous_solutions[target] == 1e9) {
        cout << -1;
    } else {
        cout << previous_solutions[target];
    }
}
