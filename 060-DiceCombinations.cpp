#include <iostream>
#include <vector>

using namespace std;

long long findPreviousCombo(int n, vector<long long> &prev_solutions) {
    long long answer = 0;
    if (n == 0) {
        return 1;
    } else if (n < 0) {
        return 0;
    } else {
        if (prev_solutions[n] != -1) {
            return prev_solutions[n];
        } else {
            for (int i = 1; i <= 6; ++i) {
                answer = (answer + findPreviousCombo(n-i, prev_solutions)) % 1000000007;
            }
        }
    }
    prev_solutions[n] = answer;
    return answer;
}

int main()
{
    vector<long long> prev_solutions;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    
    prev_solutions.resize(n + 1, -1);
    
    cout << findPreviousCombo(n, prev_solutions);
    
    return 0;
}
