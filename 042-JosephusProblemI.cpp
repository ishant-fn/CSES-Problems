#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    long long i = 2;
    cin >> n;
    queue<int> kids;
    
    for (long long i = 1; i <= n; ++i) {
        kids.push(i);
    }
    
    while (!(kids.empty())) {
        if (i % 2 == 0) {
            kids.push(kids.front());
        } else {
            cout << kids.front() << " ";
        }
        kids.pop();
        i+=1;
    }
}
