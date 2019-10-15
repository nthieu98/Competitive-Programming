#include <iostream>
#include <cmath>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <sstream>
#define for1(i,a,b) for(int i = a; i <= b; i++)
#define for2(i,a,b) for(int i = a; i >= b; i--)
#define maxn 200
#define maxc 100000010000

using namespace std;

vector <int> a[maxn];
int n, m, t , h;
char ch;
int b[maxn][maxn];

void nhap()
{
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    cin >> n >> t;
    cin >> m;
    int x = 100, y = 100, sl = 1, h = 0;
    b[x][y] = 1;
    for1(i,1,m)
    {
        cin >> ch;
        if(ch == 'U') y--;
        if(ch == 'D') y++;
        if(ch == 'L') x--;
        if(ch == 'R') x++;

    }
}

void chuanbi()
{

}

void dijkstra()
{

}

void xuli()
{
    dijkstra();
}

void ghikq()
{

}

int main()
{
    freopen("safe.inp","r",stdin);
    freopen("safe.out","w",stdout);
    nhap();
    chuanbi();
    xuli();
    ghikq();
}
