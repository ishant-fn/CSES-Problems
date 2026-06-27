#include <iostream>
using namespace std;
int main() {  
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL); l
  long long n = 0; 
  long long i = 0; 
  long long sum = 0; 
  cin >> n; sum = (n*(n+1))/2; 
  if (n % 4 == 0) { 
    if (sum % 2 == 0) { 
      cout << "YES" << "\n"; 
      sum /= 2; 
      cout << (sum/(n+1))*2 << "\n"; 
      while (i < sum/(n+1)) { 
        cout << i + 1 << " " << n - i << " ";
        ++i;
      } 
      cout << "\n" << n - (sum/(n+1))*2 << "\n";
      while (i < sum/(n+1)*2) { 
        cout << i + 1 << " " << n - i << " "; 
        ++i; 
      } 
    } else { 
      cout << "NO"; 
    } 
  } else if (sum % 2 == 0) { 
    cout << "YES" << "\n";
    sum /= 2;
    cout << (sum/(n+1))*2 + 1 << "\n";
    while (i < sum/(n+1)) {
      cout << i + 1 << " " << n - i << " ";
      ++i;
    }
    cout << n - i << "\n";
    cout << n - ((sum/(n+1))*2 + 1) << "\n";
    while (i < sum/(n+1)*2 + 1) {
      cout << i + 1 << " " << n - i - 1 << " ";
      ++i;
    }
  } else {
    cout << "NO";
  }
  
  return 0;
}
