#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<pair<int, int>> Numbers;
    
    int n;
    int target;
    int currentNumber;
    cin >> n;
    cin >> target;
    
    for (int i = 1; i <= n; ++i) {
        cin >> currentNumber;
        Numbers.push_back({currentNumber, i});
    }
    
    int leastNumber = 0;
    int greatestNumber = n-1;
    bool Impossible = true;
    sort(Numbers.begin(), Numbers.end());
    
    while (leastNumber < greatestNumber) {
        if (Numbers[leastNumber].first + Numbers[greatestNumber].first < target) {
            ++leastNumber;
        } else if (Numbers[leastNumber].first + Numbers[greatestNumber].first > target) {
            --greatestNumber;
        } else {
            cout << Numbers[leastNumber].second << " " << Numbers[greatestNumber].second << "\n";
            Impossible = false;
            break;
        }
    }
    
    if (Impossible) {
        cout << "IMPOSSIBLE" << "\n";
    }
    
    return 0;
}
