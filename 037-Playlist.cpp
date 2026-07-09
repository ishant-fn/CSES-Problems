#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int currentNumber;
    cin >> n;
    vector<int> numbers;
    set<int> currentWindowElements;
    
    for (int i = 0; i < n; ++i) {
        cin >> currentNumber;
        numbers.push_back(currentNumber);
    }
    
    int ptr1 = 0;
    int ptr2 = 0;
    int MaxConsecutive = 0;
    
    while (ptr2 < n) {
        if (currentWindowElements.count(numbers[ptr2]) == 1) {
            currentWindowElements.erase(numbers[ptr1]);
            ++ptr1;
        } else if (currentWindowElements.count(numbers[ptr2]) == 0) {
            currentWindowElements.insert(numbers[ptr2]);
            ++ptr2;
        }
        if (MaxConsecutive < (ptr2-ptr1)) {
            MaxConsecutive = (ptr2-ptr1);
        }
    }
    
    cout << MaxConsecutive;
    
    return 0;
}
