#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
using namespace std;
#define pr(x) cout << #x << ": " << x << "  " 
#define pl(x) cout << #x << ": " << x << endl;
const int maxn = 1003;
int N, M, K;
int G[maxn][maxn];
int cs[maxn];
vector<int> chen[maxn];
vector<int> yz;
bool isyz[maxn];
int par[maxn];


int main()
{
#ifdef xiaoai
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    cin >> N >> M >> K;
    for (int i = 1; i <= M; ++i) cin >> cs[i];
    chen[0].push_back(0);
    for (int i = 1; i <= M; ++i) {
        for (int j = 0; j < cs[i]; ++j) {
            int x; cin >> x;
            chen[i].push_back(x);
        }
    }
    for (int i = 0; i < K; ++i) {
        int x;
        cin >> x;
        isyz[x] = true;
        yz.push_back(x);
    }
    for (int i = 0; i < K; ++i){
        for (int j = 0; j < K; ++j) {
            int x; cin >> x;
            G[yz[i]][yz[j]] = x;
        }
    }

    for (int now = M; now >= 1; now--) {
        for (int i = 0, ls = 0; i < int(chen[now].size()) && ls < (int)chen[now - 1].size(); i++, ls++) {
            while (ls < (int)chen[now - 1].size() && isyz[chen[now - 1][ls]]) ls++;
            if (ls == (int)chen[now - 1].size()) break;
            while (!isyz[chen[now][i]]) i++;
            par[chen[now][i]] = chen[now - 1][ls];
            isyz[chen[now][i]] = false;
            isyz[chen[now - 1][ls]] = true;
            for (int j = i + 1; j < int(chen[now].size()); j++) {
                if (G[chen[now][i]][chen[now][j]] == 2) {
                    par[chen[now][j]] = chen[now - 1][ls];
                    isyz[chen[now][j]] = false;
                }
            }
            for (int j = 1; j <= N; ++j) {
                if (isyz[j]) G[chen[now - 1][ls]][j] = G[chen[now][i]][j] - 1;
                if (isyz[j]) G[j][chen[now - 1][ls]] = G[j][chen[now][i]] - 1;
            }
        }
    }
    for (int i = 1; i <= N; ++i) {
        if (i != 1) printf(" ");
        printf("%d", par[i]);
    }
    puts("");
    return 0;
}
