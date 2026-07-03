#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<long long> people = {};
    vector<long long> houses = {};
    long long n;
    long long m;
    long long k;
    cin >> n;
    cin >> m;
    cin >> k;
    long long current_person = 0;
    long long current_house = 0;
    long long suitable_houses = 0;

    for (long long i = 0; i < n; ++i) {
        cin >> current_person;
        people.push_back(current_person);
    }
    
    for (long long i = 0; i < m; ++i) {
        cin >> current_house;
        houses.push_back(current_house);
    }
    
    sort(people.begin(), people.end());
    sort(houses.begin(), houses.end());
    
    current_person = 0; // reusing as a pointer
    current_house = 0; // also reusing as a pointer
    
    while (current_house < m && current_person < n) {
        if (houses[current_house] < people[current_person] - k) {
            ++current_house;
        } else if (houses[current_house] > people[current_person] + k) {
            ++current_person;
        } else {
            ++current_house;
            ++current_person;
            ++suitable_houses;
        }
    }
    
    cout << suitable_houses << "\n";
    
    return 0;
}
