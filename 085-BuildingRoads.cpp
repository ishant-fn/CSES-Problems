#include <bits/stdc++.h>
using namespace std;

int FindRoot (vector<int> &Connections, int city) {
    if (Connections[city] == city) {return city;}
    return Connections[city] = FindRoot(Connections, Connections[city]);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int No_of_Cities;
    int No_of_Roads;

    int cityStart;
    int cityDest;

    cin >> No_of_Cities >> No_of_Roads;

    vector<int> Connections(No_of_Cities + 1);
    vector<int> RoadsRequired;

    for (int i = 1; i <= No_of_Cities; ++i) {
        Connections[i] = i;
    }

    for (int i = 0; i < No_of_Roads; ++i) {
        cin >> cityStart >> cityDest;
        Connections[FindRoot(Connections, cityStart)] = FindRoot(Connections, cityDest);
    }

    for (int i = 1; i <= No_of_Cities; ++i) {
        if (FindRoot(Connections, i) == i) {
            RoadsRequired.push_back(i);
        }
    }

    cout << RoadsRequired.size() - 1 << "\n";

    for (int i = 1; i < RoadsRequired.size(); ++i) {
        cout << RoadsRequired[0] << " " << RoadsRequired[i] << "\n";
    }

    return 0;
}