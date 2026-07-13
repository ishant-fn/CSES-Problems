#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long Coins(int target, vector<int> &values, int currentCoin, vector<vector<int>> &prev_solutions) {
    int currentAnswer;
    if (target == 0) {
        return 1;
    }
    if (target < 0) {
        return 0;
    }
    if (currentCoin >= values.size()) {
        return 0;
    }
    if (prev_solutions[target][currentCoin] != -1) {
        return prev_solutions[target][currentCoin];
    }
    long long answer = (Coins(target - values[currentCoin], values, currentCoin, prev_solutions) + Coins(target, values, currentCoin + 1, prev_solutions))%1000000007;
    prev_solutions[target][currentCoin] = answer;
    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> values;
    int n;
    int target;
    int currentNumber;
    int ans = 0;
    cin >> n;
    cin >> target;
    vector<vector<int>> prev_solutions(target + 1, vector<int>(n + 1, -1));
    
    for (int i = 0; i < n; ++i) {
        cin >> currentNumber;
        values.push_back(currentNumber);
    }
    
    cout << Coins(target, values, 0, prev_solutions);

    return 0;
}
