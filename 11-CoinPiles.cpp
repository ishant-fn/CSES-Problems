#include <iostream>
using namespace std;

int main()
{
    long long t = 0;
    long long a = 0;
    long long b = 0;
    
    cin >> t;
    while (t > 0) {
        cin >> a;
        cin >> b;
        if (a < b) {
            if ((a + b) % 3 == 0 && a * 2 >= b) {
                cout << "YES" << "\n";
            } else {
                cout << "NO" << "\n";
            }
        } else {
            if ((a + b) % 3 == 0 && b * 2 >= a) {
                cout << "YES" << "\n";
            } else {
                cout << "NO" << "\n";
            }
        }
        --t;
    }
    return 0;
}
