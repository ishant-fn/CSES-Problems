#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<long long> kids = {};
    long long n;
    long long x;
    cin >> n;
    cin >> x;
    long long current_kid = 0;
    long long minimum_gondolas = 0;

    for (long long i = 0; i < n; ++i) {
        cin >> current_kid;
        if (current_kid <= x) {
            kids.push_back(current_kid);
            ++minimum_gondolas;
        }
    }
    
    sort(kids.begin(), kids.end());
    
    long long kid_light = 0;
    long long kid_heavy = n-1;

    while (kid_light < kid_heavy) {
        if (kids[kid_light] + kids[kid_heavy] <= x) {
            --minimum_gondolas;
            ++kid_light;
            --kid_heavy;
        } else {
            --kid_heavy;
        }
    }
    
    cout << minimum_gondolas << "\n";
    
    return 0;
}
