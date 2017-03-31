#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
using namespace std;
#define pr(x) cout << #x << ": " << x << "  " 
#define pl(x) cout << #x << ": " << x << endl;
map<string, int> dic;
string strs[622];
vector<int> strv[622];
char word[11100];
int cnt = 0;
int n, q;

char llower(char c) {
    if (c >= 'a') return c;
    else return c + 'a' - 'A';
}
void build() {
    for (int i = 0; i < n; ++i){
        string t;
        for (int j = 0; j < (int)strs[i].size(); ++j) {
            if (strs[i][j] == ' ' || j == (int)strs[i].size() - 1) {
                if (!dic.count(t)) {
                    dic[t] = cnt;
                    cnt++;
                }
                strv[i].push_back(dic[t]);
                t = "";
            } else t += llower(strs[i][j]); 
        }
        sort(strv[i].begin(), strv[i].end());
        unique(strv[i].begin(), strv[i].end());
    }
}

int same(vector<int> a, vector<int> b) {
    int ans = 0;
    int l = 0, r = 0;
    while (l < int(a.size()) && r < int(b.size())) {
        if (a[l] == b[r]) ans++, l++, r++;
        else if (a[l] > b[r]) r++;
        else if (a[l] < b[r]) l++;
    }
    return ans;
}

int work(string s) {
    vector<int> now;
    string t;
    for (int j = 0; j < (int)s.size(); ++j) {
        if (s[j] == ' ' || j == (int)s.size() - 1) {
            now.push_back(dic[t]);
            t = "";
        } else t += llower(s[j]); 
    }
    sort(now.begin(), now.end());
    unique(now.begin(), now.end());
    int maxs = 0, maxi = 0;
    for (int i = 0; i < n; ++i) {
        int temp = same(now, strv[i]);
        if (temp > maxs) maxs = temp, maxi = i;
    }
    return maxi;
}

int main()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d%*c", &n, &q);
    for (int i = 0; i < n; ++i){
        cin.getline(word, 100);
        strs[i] = string(word);
    }
    build();
    while (q--) {
        cin.getline(word, 100);
        string qs = string(word);
        int out = work(qs);
        cout <<strs[out] << endl;
    }
    return 0;
}
