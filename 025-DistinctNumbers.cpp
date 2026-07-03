#include <iostream>
#include <set>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    set<long long> numbers = {};
    long long n;
    cin >> n;
    long long current_number = 0;

    for (long long i = 0; i < n; ++i) {
        cin >> current_number;
        numbers.insert(current_number);
    }
    
    cout << numbers.size() << "\n";
    
    return 0;
}
