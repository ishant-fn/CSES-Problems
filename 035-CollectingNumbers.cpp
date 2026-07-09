#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int rounds = 1;
    int currentNumber;
    cin >> n;
    vector<int> positions(n+1);

    for (int i = 1; i <= n; ++i) {
        cin >> currentNumber;
        positions[currentNumber] = i;
    }
    
    for (int i = 2; i <= n; ++i) {
        if (positions[i-1] > positions[i]) {
            ++rounds;
        }
    }
    
    cout << rounds;
    
    return 0;
}
