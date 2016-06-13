#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
#define pr(x) cout << #x << ": " << x << "  " 
#define pl(x) cout << #x << ": " << x << endl;
class trie
{
private:
    int n, m;
    static const int maxn = 1e5 + 13;
    char word[maxn];
    struct node {
        int num;
        node* son[26];
        node(void) {
            num = 0;
            memset(son, 0, sizeof(son));
        }
    } *root;
    int ans;
public:
    void input(void) {
        root = new node;
        scanf("%d", &n);
        while (n--) {
            scanf("%s", word);
            add();
        }
        scanf("%d", &m);
        while (m--) {
            scanf("%s", word);
            query();
            printf("%d\n", ans);
        }
    }
    void add(void) {
        node *cur = root;
        for (int i = 0; word[i] != '\0'; i++) {
            if ((cur -> son)[word[i] - 'a'] == nullptr) 
                (cur -> son)[word[i] - 'a'] = new node;
            cur = (cur -> son)[word[i] - 'a'];
            (cur -> num)++;
        }
    }
    
    void query(void) {
        node *cur = root;
        for (int i = 0; word[i] != '\0'; i++) {
            if (cur -> son[word[i] - 'a'] == nullptr) {
                ans = 0;
                break;
            }
            cur = cur -> son[word[i] - 'a'];
            if (!word[i + 1]) {
                ans = cur -> num; 
            }
        }
    }
};


int main()
{
#ifdef xiaoai
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    trie temp;
    temp.input();
    return 0;
}
