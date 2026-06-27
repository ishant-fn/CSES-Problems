#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string dna;
    cin >> dna;
    int sequence = 1;
    int longest_sequence = 1;
    for (int i = 1; i < dna.length(); ++i) {
        if (dna[i] == dna[i-1]) {
            ++sequence;
        } else {
            sequence = 1;
        }
        
        if (sequence > longest_sequence) {
            longest_sequence = sequence;
        }
    }
    cout << longest_sequence;
    return 0;
}
