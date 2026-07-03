#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int BitIsOne(int number, int place) {
    return (number & (1 << place)) != 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<long long> numbers = {};
    long long n;
    long long sum_set1 = 0;
    long long sum_set2 = 0;
    long long total_difference = 0;
    long long least_difference = 0;
    cin >> n;
    long long current_number = 0;

    for (int i = 0; i < n; ++i) {
        cin >> current_number;
        total_difference += current_number;
        numbers.push_back(current_number);
    }
    
    least_difference = total_difference;
    
    n = (1 << n) - 1;
    
    for (int i = 0; i <= n; ++i) {
        for (int x = 1; x <= numbers.size(); ++x) {
            if (BitIsOne(i, numbers.size() - x)) {
                sum_set1 += numbers[x-1];
            } else {
                sum_set2 += numbers[x-1];
            }
        }
        if (least_difference > abs(sum_set1 - sum_set2)) {
            least_difference = abs(sum_set1 - sum_set2);
        }
        sum_set1 = 0;
        sum_set2 = 0;
    }
    
    cout << least_difference;

    return 0;
}
