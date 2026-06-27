#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long k = 0;
    long long i = 4;
    long long knights_attacking_knights = 24;
    cin >> k;
    long long total_combinations_of_knights = 0;
    
    switch (k) {
        case 1:
            cout << 0 << "\n";
            break;
        case 2:
            cout << 0 << "\n" << 6 << "\n";
            break;
        default:
            cout << 0 << "\n" << 6 << "\n" << 28 << "\n";
            break;
    }
    
    while (i <= k) {
        total_combinations_of_knights = ((i*i)*((i*i) - 1)) / 2;
        cout << total_combinations_of_knights - knights_attacking_knights << "\n";
        knights_attacking_knights += 8 * (i - 1);
        ++i;
    }
    return 0;
}
