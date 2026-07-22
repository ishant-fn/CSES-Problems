#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int target;
    int current_target;
    cin >> target;
    vector<long long> previous_solutions(target + 1);
    previous_solutions[0] = 1;
    previous_solutions[1] = 1;

    for (int i = 2; i <= target; ++i) {
        for (int current_face = 1; current_face <= 6; ++current_face) {
            current_target = i - current_face;
            if (current_target < 0) {
                break;
            }
            previous_solutions[i] = (previous_solutions[i] + previous_solutions[current_target]) % 1000000007;
        }
    }
    cout << previous_solutions[target];
}
