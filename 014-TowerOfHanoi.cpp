#include <iostream>

using namespace std;

void MoveText (int n, int start, int destination, int middle) {
    if (n == 0) {
        return;
    }
    MoveText(n-1, start, middle, destination);
    
    cout << start << " " << destination << "\n";
    
    MoveText(n-1, middle, destination, start);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    int i = 0;
    int total = 1;
    cin >> n;
    
    while (i < n) {
        total *= 2;
        ++i;
    }
    
    cout << total - 1 << "\n";
    
    MoveText(n, 1, 3, 2);

    return 0;
}
