#include <iostream>

using namespace std;

int main()
{
  int n, ans = 0;
  string str1, str2;
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> str1 >> str2;
    if(str2 == "hard"){
      for(int j = 0; j < str1.size(); j++)
        if(str1[j] == 'a'){
          ans++;
          break;
        }
    }
  }
  cout << ans;
  return 0;
}
