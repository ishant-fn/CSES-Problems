#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> incoming;
    vector<int> outgoing;
    
    int n;
    int currentInorOut;
    cin >> n;
    
    for (int i = 0; i < n; ++i) {
        cin >> currentInorOut;
        incoming.push_back(currentInorOut);
        cin >> currentInorOut;
        outgoing.push_back(currentInorOut);
    }
    
    int entry = 0;
    int leaving = 0;
    int currentGreatest = 0;
    int TheGreatest = 0;
    sort(incoming.begin(), incoming.end());
    sort(outgoing.begin(), outgoing.end());
    
    while (entry < n) {
        if (leaving == n || incoming[entry] < outgoing[leaving]) {
            ++entry;
            ++ currentGreatest;
        } else {
            ++leaving;
            --currentGreatest;
        }
        if (currentGreatest > TheGreatest) {
            TheGreatest = currentGreatest;
        }
    }
    
    cout << TheGreatest;
    
    return 0;
}
