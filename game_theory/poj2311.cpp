#include <iostream>
#include <set>
#include <cstring>
#include <cstdio>
#define pl(x) std::cout << #x << ": " << x << std::endl
#define pr(x) std::cout << #x << ": " << x 

struct solve
{
    int  dp[222][222];
    int n, m;

    void init() {
        memset(dp, -1, sizeof(dp));
    }

    void input() {
        init();
        //while (std::cin >> n >> m) {
        while (~scanf("%d%d", &n, &m)) {
            puts(run(n, m) ? "WIN" : "LOSE");
        }
    }

    int run(int x, int y) {
        if (dp[x][y] != -1) return dp[x][y];
        std::set<int> S;
        for (int i = 2; i <= x - 2; i++) S.insert(run(i, y) ^ run(x - i, y));
        for (int i = 2; i <= y - 2; i++) S.insert(run(x, i) ^ run(x, y - i));
        int cnt = 0;
        while (S.count(cnt)) cnt++;
        return dp[x][y] = cnt;
    }
}ac;

int main()
{
    ac.input();
    return 0;
}
