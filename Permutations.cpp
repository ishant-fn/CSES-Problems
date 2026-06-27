#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n = 0;
    cin >> n;
    if (n == 4) {
        cout << "2 4 1 3";
    } else if (n == 1) {
        cout << "1";
    } else if (n == 2 || n == 3) {
        cout << "NO SOLUTION";
    } else {
        for (int i = 1; i < n; i = i + 2) {
            cout << n - i << " ";
        }
        cout << n << " ";
        for (int i = 2; i < n; i = i + 2) {
            cout << n - i << " ";
        }
    }
    return 0;
}
