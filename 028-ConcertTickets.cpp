#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    multiset<int> ticketPrices;
    vector<int> People;
    int n;
    int m;
    int currentValue;
    cin >> n;
    cin >> m;
    
    for (int i = 0; i < n; ++i) {
        cin >> currentValue;
        ticketPrices.insert(currentValue);
    }
    
    for (int i = 0; i < m; ++i) {
        cin >> currentValue;
        People.push_back(currentValue);
    }
    
    auto currentTicket = ticketPrices.begin();
    
    for (int i = 0; i < m; ++i) {
        currentTicket = ticketPrices.upper_bound(People[i]);
        if (currentTicket != ticketPrices.begin()) {
            --currentTicket;
            cout << *currentTicket << "\n";
            ticketPrices.erase(currentTicket);
        } else {
            cout << -1 << "\n";
        }
    }
    
    return 0;
}
