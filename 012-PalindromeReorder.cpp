#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long No_of_letters[26] = {0};
    string Non_Palindrome;
    int Same_Letter = 0;
    char Odd_Letter = '\0';
    long long odd_numbers = 0;
    cin >> Non_Palindrome;
    
    for (char x:Non_Palindrome) {
        ++No_of_letters[x - 'A'];
    }
    
    for (int i = 0; i <= 25; ++i) {
        if (No_of_letters[i] != 0) {
            ++Same_Letter;
        }
    }
    
    if (Same_Letter == 1) {
        cout << Non_Palindrome;
        return 0;
    }
    
    for (int i = 0; i <= 25; ++i) {
        if (No_of_letters[i] != 0 && No_of_letters[i] % 2 != 0) {
                if (Odd_Letter == '\0') {
                    Odd_Letter = (char)(i + 'A');
                } else {
                    cout << "NO SOLUTION";
                    return 0;
                }
            }
    }
    
    for (int i = 0; i <= 25; ++i) {
        if (No_of_letters[i] != 0) {
            for (int y = 0; y < No_of_letters[i]/2; ++y) {
                cout << (char)(i + 'A');
            }
        }
    }
    if (Odd_Letter != '\0') {
        cout << Odd_Letter;
    }
    for (int i = 25; i >= 0; --i) {
        if (No_of_letters[i] != 0) {
            for (int y = 0; y < No_of_letters[i]/2; ++y) {
                cout << (char)(i + 'A');
            }
        }
    }
    
    return 0;
}
