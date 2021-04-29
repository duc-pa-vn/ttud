#include <bits/stdc++.h>

#define fti(i, x, y) for(int i = (x), _y = (y); i <= _y; ++ i)
#define ftd(i, x, y) for(int i = (x), _y = (y); i >= _y; -- i)
#define ll long long
#define pb push_back

using namespace std;

const int N = 102, M = 502, MOD = 1e9 + 7;
int n, m, a[N], f[N][M];

void inp()
{
    scanf("%d %d", &n, &m);
    fti(i, 1, n) scanf("%d", &a[i]);
}

void proc()
{
    f[0][0] = 1;
    fti(i, 1, n)
        fti(j, 1, m) {
            int x = 1;
            while(j - x * a[i] >= 0) {
                f[i][j] += f[i - 1][j - x * a[i]];
                f[i][j] %= MOD;
                ++ x;
            }
        }
    printf("%d\n", f[n][m]);
}

int main()
{
    inp();
    proc();
}
