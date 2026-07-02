#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string text;
    cin >> text;
    int n = text.size();
    
    vector<char> letters = {};
    vector<string> text_store = {};
    
    for (int i = 0; i < n; ++i) {
        letters.push_back(text[i]);
    }
    
    text = "";
    
    sort(letters.begin(), letters.end());
    
    do {
        for (int i = 0; i < n; ++i) {
            text = text + letters[i];
        }
        text_store.push_back(text);
        text = "";
    } while (next_permutation(letters.begin(), letters.end()));
    
    cout << text_store.size() << "\n";
    
    for (string x: text_store) {
        cout << x << "\n";
    }
    
    return 0;
}
