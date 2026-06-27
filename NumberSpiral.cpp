#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long x = 0;
    long long y = 0;
    long long t = 0;
    cin >> t;
    while (t > 0) {
        cin >> y;
        cin >> x;
        if (y == x) {
            cout << (x*x+(y - 1)*(y - 1)+1)/2 << "\n";
        } else if (y > x) {
            if (y % 2 == 0) {
                cout << y*y - (x-1) << "\n";
            } else {
                cout << (y-1)*(y-1) + 1 + (x-1) << "\n";
            }
        } else {
            if (x % 2 == 1) {
                cout << x*x - (y-1) << "\n";
            } else {
                cout << (x-1)*(x-1) + 1 + (y-1) << "\n";
            }
        }
        --t;
    }
    return 0;
}
