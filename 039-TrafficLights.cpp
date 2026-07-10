#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int x;
    int currentNumber;
    cin >> n;
    cin >> x;
    multiset<int> streetDist = {n};
    set<int> lightPos = {0, n};
    
    for (int i = 0; i < x; ++i) {
        cin >> currentNumber;
        auto range = lightPos.upper_bound(currentNumber);
        streetDist.erase(streetDist.find(*range - *prev(range)));
        streetDist.insert(abs(currentNumber - *range));
        streetDist.insert(abs(currentNumber - *prev(range)));
        lightPos.insert(currentNumber);
        cout << *prev(streetDist.end()) << " ";
    }
    
    return 0;
}
