#include <iostream>

using namespace std;

int main()
{
  long long TC, n, k, m;
  cin >> TC;
  for(int i = 1; i <= TC; i++){
    cin >> n >> k >> m;
    cout << m*n - k << endl;
  }
    return 0;
}
