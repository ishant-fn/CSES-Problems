#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long n = 0;
    long long inp = 0;
    long long answer = 0;
    cin >> n;
    answer = n*(n+1)/2;
    
    while (n > 1) {
        cin >> inp;
        answer -= inp;
        --n;
    }
    
    cout << answer;
    return 0;
}
