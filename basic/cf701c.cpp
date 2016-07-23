#include <cstdio>
#include <iostream>
#include <cstring>
#include <set>
#include <map>
using namespace std;
#define pr(x) cout << #x << ": " << x << "  " 
#define pl(x) cout << #x << ": " << x << endl;

struct jibancanyang
{
    int n, t;
    string str;

    void two() {
        int l = 0, r = 0;
        map<char, int> st;
        int ret = int(1e9);
        while (l < n) {
            while (r < n && (int)st.size() < t) {
                st[str[r++]]++;
            }
            if (t <= (int)st.size()) ret = min(ret, r - l);
            else break;
            st[str[l]]--;
            if (st[str[l]] == 0) st.erase(str[l]);
            l++;
        }
        cout << ret << endl;
    }

    void run() {
        cin >> n >> str;
        set<char> st;
        for (int i = 0; i < (int)str.size(); i++) {
            st.insert(str[i]);
        }
        t = st.size();
        two();
    }

}ac;

int main()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    ac.run();
    return 0;
}
