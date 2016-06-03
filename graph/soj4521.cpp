/**********************jibancanyang**************************
 *Author*        :jibancanyang
 *Created Time*  : 四  6/ 2 10:26:53 2016
**Problem**:
**Analyse**:
**Get**:
**Code**:
***********************1599664856@qq.com**********************/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <stack>

class Solution
{
private:
    std::vector<int> Graph[10];
    int table[4][4];
    int rule[4][4];
    bool ans;
    bool vis[10], detected[10];
public:
    void input(void) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                std::cin >> table[i][j];
            }
        }
        for (int i = 1; i <= 9; i++) Graph[i].clear();
        memset(vis, 0, sizeof(vis));
        memset(detected, 0, sizeof(detected));
    }
    void build_rule(void) {
        int cnt = 1;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                rule[i][j] = cnt; 
                if (j == 2) rule[i][j + 1] = cnt;
                if (i == 2) rule[i + 1][j] = cnt;
                if (i == 2 && j == 2) rule[i + 1][j + 1] = cnt;
                cnt++;
            }
        }
    }
    void build_graph(void) {
        build_rule();
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if ((i == 0 || i == 3) && (j == 0 || j == 3)) continue;
                int cur = table[i][j];
                if (i == 0 || i == 3) {
                    int one = rule[i][j - 1], two = rule[i][j];
                    Graph[one == cur ? two : one].push_back(cur);
                } else if (j == 0 || j == 3) {
                    int one = rule[i - 1][j], two = rule[i][j];
                    Graph[one == cur ? two : one].push_back(cur);
                } else {
                    int one = rule[i][j], two = rule[i - 1][j], three = rule[i][j - 1], four = rule[i - 1][j - 1];
                    if (one != cur) Graph[one].push_back(cur);
                    if (two != cur) Graph[two].push_back(cur);
                    if (three != cur) Graph[three].push_back(cur);
                    if (four != cur) Graph[four].push_back(cur);
                }
            }
        }
    }
    void dfs(int cur) {
        if (ans) return;
        vis[cur] = true;
        for (int i = 0; i < (int)Graph[cur].size(); i++) {
            int next = Graph[cur][i];
            if (vis[next]) ans = true;
            dfs(next);
        }
        vis[cur] = false;
    }
    void detect_cycle(void) {
        ans = false;
        for (int i = 1; i <= 9; i++) {
            dfs(i);
            if (ans) break;
        }
        puts(ans ? "BOOM!" : "Lucky dog!");
    }
};


int main(void)
{
#ifdef LOCAL
   freopen("/Users/zhaoyang/in.txt", "r", stdin);
    //freopen("/Users/zhaoyang/out.txt", "w", stdout);
#endif
    int T;
    std::cin >> T;
    while (T--) {
        Solution work;
        work.input();
        work.build_graph();
        work.detect_cycle();
    }
    return 0;
}
