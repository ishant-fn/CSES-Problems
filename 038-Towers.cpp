#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int currentNumber;
    cin >> n;
    multiset<int> towers;
    
    for (int i = 0; i < n; ++i) {
        cin >> currentNumber;
        auto suitableTower = towers.upper_bound(currentNumber);
        if (suitableTower != towers.end()) {
            towers.erase(suitableTower);
            towers.insert(currentNumber);
        } else {
            towers.insert(currentNumber);
        }
    }
    
    cout << towers.size();
    
    return 0;
}
