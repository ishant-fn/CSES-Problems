#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long n = 0;
    long long current_number = 0;
    long long previous_number = 0;
    long long moves = 0;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> current_number;
        if (i == 0) {
            previous_number = current_number;
        } else {
            if (previous_number > current_number) {
                moves += previous_number - current_number;
            } else {
                previous_number = current_number;
            }
        }
    }
    
    cout << moves;
    return 0;
}
