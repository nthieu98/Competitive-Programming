#include <iostream>
#include <fstream>
#include <cmath>
#include <cctype>
#include <cstring>
#include <vector>
#include <algorithm>
#include <sstream>
#define reset(b) memset(b, 0, sizeof(b))
#define for1(i,a,b) for(int i = a; i <= b; i++)
#define for2(i,a,b) for(int i = a; i >= b; i--)
#define maxn 500100
#define maxc 1000000100

using namespace std;

int n, m, s, p, dem, top, sl, smax;
typedef int mang[maxn];
mang gt, kt, num, low, st, dd, d, tp, tien, dk, deg, l;
vector <int> a[maxn], duongdi[maxn];

void nhap()
{
    scanf("%d %d", &n, &m);
    for1(i,1,m) a[i].clear();
    for1(i,1,m)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        a[u].push_back(v);
    }
    for1(i,1,n) scanf("%d", &gt[i]);
    scanf("%d %d", &s, &p);
    reset(kt);
    for1(i,1,p)
    {
        int c;
        scanf("%d", &c);
        kt[c] = 1;
    }
}

void chuanbi()
{
    dem = top = 0;
    reset(num);
    reset(dd);
    reset(st);
    reset(dk);
}

void push(int x)
{
    st[++top] = x;
}

int pop()
{
    return st[top--];
}

void visit(int u)
{
    num[u] = low[u] = ++dem;
    push(u);
    for (int i = 0; i < a[u].size(); i++)
    {
        int v = a[u][i];
        if(!dd[v])
            if( num[v] ) low[u] = min(low[u],num[v]);
            else
            {
                visit(v);
                low[u] = min(low[u],low[v]);
            }
    }
    if(num[u] == low[u])
    {
        int v;
        sl++;
        do
        {
            v = pop();
            tp[v] = sl;
            dd[v] = 1;
            tien[sl] += gt[v];
            if(kt[v]) dk[sl] = 1;
        }
        while(v != u);
    }
}

void dfs(int u)
{
    dd[u] = 1;
    for(int i = 0; i < a[u].size(); i++)
    {
        int v = a[u][i];
        if(tp[u] != tp[v]) duongdi[tp[u]].push_back(tp[v]);
        if(!dd[v]) dfs(v);
    }
}

void tim()
{
    int truoc;
    for1(i,1,sl)
        for(int j = 0; j < duongdi[i].size(); j++) deg[duongdi[i][j]]++;
    dem = 0;
    for1(u,1,sl)
        if(deg[u] == 0)
        {
            dem++;
            l[dem] = u;
        }
    truoc = 1;
    while(truoc <= dem)
    {
        int u = l[truoc++];
        for(int i = 0; i < duongdi[u].size(); i++)
        {
            int v = duongdi[u][i];
            deg[v]--;
            if(!deg[v]) l[++dem] = v;
        }
    }
}

bool ktt(int x, int y)
{
    for(int i = 0; i < duongdi[x].size(); i++) if(y == duongdi[x][i]) return true;
    return false;
}

void tim_duong()
{
    d[tp[s]] = tien[tp[s]];
    smax = 0;
    for1(i,1,sl-1)
        for1(j,i+1,sl)
        {
            int u = l[i];
            int v = l[j];
            if(d[v] <= d[u] + tien[v] && ktt(u,v))
            {
                d[v] = d[u] + tien[v];
                if(d[v] > smax && dk[v]) smax = d[v];
            }
        }
}

void topo()
{
    reset(deg);
    reset(l);
    reset(d);
    tim();
    tim_duong();
}

void xuli()
{
    for1(i,1,n) if(!num[i]) visit(i);
    reset(dd);
    for1(i,1,sl) duongdi[i].clear();
    for1(i,1,n) if(!dd[i]) dfs(i);
    topo();
}

void ghikq()
{
    cout << smax;
}

int main()
{
    freopen("atm.inp","r",stdin);
    freopen("atm.out","w",stdout);
    nhap();
    chuanbi();
    xuli();
    ghikq();
}
