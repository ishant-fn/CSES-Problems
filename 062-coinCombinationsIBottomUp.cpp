#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int target;
    int current_target;
    int current_number;
    int n;
    
    vector<long long> coins;
    
    cin >> n;
    cin >> target;

    vector<long long> previous_solutions(target + 1);
    
    previous_solutions[0] = 1;
    
    for (int i = 0; i < n; ++i) {
        cin >> current_number;
        coins.push_back(current_number);
    }
    
    sort(coins.begin(), coins.end());
    
    for (int i = 1; i <= target; ++i) {
        for (int current_coin = 0; current_coin < coins.size(); ++current_coin) {
            current_target = i - coins[current_coin];
            if (current_target < 0) {
                break;
            }
            previous_solutions[i] = (previous_solutions[i] + previous_solutions[current_target]) % 1000000007;
        }
    }
    cout << previous_solutions[target];
}
