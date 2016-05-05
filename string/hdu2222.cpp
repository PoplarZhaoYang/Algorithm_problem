/**********************jibancanyang**************************
 *Author*        :jibancanyang
 *Created Time*  : 三  5/ 4 21:54:15 2016
 *File Name*     : jy.cpp
**Problem**:
**Analyse**:
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
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
vector<int> vi;
#define pr(x) cout << #x << ": " << x << "  " 
#define pl(x) cout << #x << ": " << x << endl;
#define pri(a) printf("%d\n",(a));
#define xx first
#define yy second
#define sa(n) scanf("%d", &(n))
#define sal(n) scanf("%lld", &(n))
#define sai(n) scanf("%I64d", &(n))
#define rep(i, a, n) for (int i = a; i < n; i++)
#define vep(c) for(decltype((c).begin() ) it = (c).begin(); it != (c).end(); it++) 
const int mod = int(1e9) + 7, INF = 0x3fffffff;
const int maxn = 1e6 + 5;
const int max_word = 55;
const int max_charset = 26;


char word[max_word], text[maxn];

struct node {
    int cnt;            //单词的个数
    node *next[max_charset];     //叶子结点
    node *fail;         //失败指针
    node(void) {
        cnt = 0;
        for (int i = 0; i < max_charset; i++) next[i] = NULL;
        fail = NULL;
    }
};

//Trie的构造
void insert(node *p, char *s) {
    for(int i = 0; s[i] != '\0'; i++) {
        int idx = s[i] - 'a';
        if(p -> next[idx] == NULL) p -> next[idx] = new node();
        p = p -> next[idx];
    }
    p -> cnt++; //表示该单词出现过，并保存出现次数
}

void AC_Automation(node *root)
{   
    queue <node* > q; //结点队列
    q.push(root);
    //得到fail指针  
    while (!q.empty()) {
        node *p = q.front();  q.pop();
        for(int i = 0; i < max_charset; i++) {
            if(p -> next[i]) {
                //root下第一层结点的失败指针都指向root
                if(p == root) p -> next[i] -> fail = root;
                //当前结点的失败指针指向其失败结点的儿子结点
                else p -> next[i] -> fail = p -> fail -> next[i];
                q.push(p -> next[i]);
            } else { //trie树优化
                if(p == root)  p -> next[i] = root;
                else p -> next[i] = p -> fail -> next[i];
            }
        }
    }
}

int query(node *root) //text中有多少个是ac自动机中的串?
{
    int cnt = 0, len = strlen(text);
    node *p = root;
    for(int i = 0; i < len; i++) {
        int idx = text[i] - 'a';
        while (!(p -> next[idx]) && p != root) p = p -> fail;
        p = p -> next[idx];
        if(!p) p = root;
        node *tmp = p;
        while(tmp != root) {
            if(tmp -> cnt >= 0) {
                cnt += tmp -> cnt;
                tmp -> cnt = -1;
            }
            else break;
            tmp = tmp -> fail;
        }
    }
    return cnt;  
}

int main(void)
{
#ifdef LOCAL
    freopen("/Users/zhaoyang/in.txt", "r", stdin);
    //freopen("/Users/zhaoyang/out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int T; sa(T);
    while (T--) {
        int n; sa(n);
        node *root = new node;
        rep (i, 0, n) {
            scanf("%s", word);
            insert(root, word);
        }
        AC_Automation(root);
        scanf("%s", text);
        pri(query(root));
    }
    return 0;
}
