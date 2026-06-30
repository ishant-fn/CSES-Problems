#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<string> output = {"0", "1"};
    int n;
    int current_size = 0;
    string current_text;
    cin >> n;

    for (int x = 1; x < n; ++x) {
        current_size = output.size();
        for (int i = 0; i < current_size; ++i) {
            current_text = "1" + output[(current_size-1) - i];
            output.push_back(current_text);
        }
        for (int i = 0; i < current_size; ++i) {
            current_text = "0" + output[i];
            output[i] = current_text;
        }
    }
    
    for (string x:output) {
        cout << x << "\n";
    }

    return 0;
}
