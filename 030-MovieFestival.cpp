#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<pair<int, int>> Times;
    
    int n;
    int startTime;
    int endTime;
    cin >> n;
    
    for (int i = 0; i < n; ++i) {
        cin >> startTime;
        cin >> endTime;
        Times.push_back({endTime, startTime});
    }
    
    int TotalMovies = 0;
    int CurrentMovieEnd = 0;
    sort(Times.begin(), Times.end());
    
    for (int i = 0; i < n; ++i) {
        if (Times[i].second >= CurrentMovieEnd) {
            ++TotalMovies;
            CurrentMovieEnd = Times[i].first;
        }
    }
    
    cout << TotalMovies;
    
    return 0;
}
