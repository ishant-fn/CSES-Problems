#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long Coins(int target, vector<int> &values, vector<int> &prev_solutions) {
    int answer = 0;
    int currentAnswer;
    if (target == 0) {
        return 1;
    }
    if (target < 0) {
        return 0;
    }
    if (prev_solutions[target] != -1) {
        return prev_solutions[target];
    }
    for (int i = 0; i < values.size(); ++i) {
        currentAnswer = Coins(target-values[i], values, prev_solutions);
        answer = (answer + currentAnswer) % 1000000007;
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
    
    cout << Coins(target, values, prev_solutions);

    return 0;
}
