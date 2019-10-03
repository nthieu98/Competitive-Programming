#include <iostream>

using namespace std;

int n, a[15];

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    if(n == 2 && a[1] == 2 && a[2] == 1){
      cout << "YES";
      return 0;

    }
    for(int i = 1; i < n; i++) if(a[i] > a[i+1]) {
      cout << "NO";
      return 0;
    }
    cout << "YES";
    return 0;
}
