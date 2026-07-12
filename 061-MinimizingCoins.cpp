#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long Coins(int target, vector<int> &values, vector<int> &prev_solutions) {
    int answer = 0;
    int least_value = 1e9;
    int current_value = 0;
    if (target == 0) {
        return 0;
    }
    if (target < 0) {
        return 1e9;
    }
    if (prev_solutions[target] != -1) {
        return prev_solutions[target];
    }
    for (int i = 0; i < values.size(); ++i) {
        current_value = Coins(target - values[i], values, prev_solutions);
        if (current_value < 1e9 && current_value < least_value) {
            answer = current_value + 1;
            least_value = current_value;
        }
        
        if (least_value == 1e9) {
            answer = 1e9;
        }
    }
    prev_solutions[target] = answer;
    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> prev_solutions;
    vector<int> values;
    int n;
    int target;
    int currentNumber;
    int ans = 0;
    cin >> n;
    cin >> target;
    
    for (int i = 0; i < n; ++i) {
        cin >> currentNumber;
        values.push_back(currentNumber);
    }
    
    prev_solutions.resize(target + 1, -1);
    
    ans = Coins(target, values, prev_solutions);
    
    if (ans >= 1e9) {
        cout << -1;
    } else {
        cout << ans;
    }

    return 0;
}
