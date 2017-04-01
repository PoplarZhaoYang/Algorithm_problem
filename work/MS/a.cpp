#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
#define pr(x) cout << #x << ": " << x << "  " 
#define pl(x) cout << #x << ": " << x << endl;
int n;
double pp, qq; 


int main()
{
#ifdef xiaoai
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    cin >> pp >> qq >> n;
    double now = 1, res = 0;
    qq /= 100.0;
    for (int i = 1; i <= n; ++i) {
        double cp = 1, gp = int(pp / now) / 100.0;
        int j = 1;
        pr(gp);
        while (gp < 1.0){
            res += cp * gp * j;
            pr(cp * gp * j);
            cp *= (1 - gp);
            gp += qq;
            j++;
        }
        res += cp * j;
        pl(cp * j)
        now *= 2;
    }
    printf("%.2f\n", res);
    return 0;
}


