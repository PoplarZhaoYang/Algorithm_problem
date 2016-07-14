/**********************jibancanyang**************************
 *Author*        :jibancanyang
 *Created Time*  : 一  5/ 9 11:49:40 2016
 *File Name*     : 
 这很trie图建立转移规则，然后dp。
 大数模板


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
typedef int ll;
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
#define vep(c) for(decltype((c).begin() ) it = (c).begin(); it != (c).end(); it++) 
const int mod = int(1e4) + 7, INF = 0x3fffffff;
const int maxn = 1e5 + 13;

const int maxtrie = 500 + 12; //注意这里为最多500个单词,每个单词最多500个字母,所以节点最多为乘
const int maxcharset = 50; //字符集合
int charst = 0;
char buf[111];
char alphabet[300];
int N, M, P;


struct Trie
{
    int next[maxtrie][maxcharset], fail[maxtrie], end[maxtrie];
    int root, L;
    int newnode(void) {
        for (int i = 0;i < maxcharset;i++) next[L][i] = 0;
        end[L++] = 0;
        return L - 1;
    }
    int getid(char c) {
        return alphabet[(int)c];
    }
    void init(void) {
        L = 0;
        root = newnode();
    }
    void insert(char buf[]) {
        int len = (int)strlen(buf);
        int now = root;
        for(int i = 0; i < len; i++) {
            if(next[now][getid(buf[i])] == 0)
                next[now][getid(buf[i])] = newnode();
            now = next[now][getid(buf[i])];
        }
        end[now] = true;
    }
    void build(void) {
        queue<int> Q;
        fail[root] = root;
        for(int i = 0;i < maxcharset;i++)
            if(next[root][i] == 0) next[root][i] = root;
            else {
                fail[next[root][i]] = root;
                Q.push(next[root][i]);
            }
        while (!Q.empty())  {
            int now = Q.front(); Q.pop();
            for(int i = 0;i < maxcharset;i++)
                if(next[now][i] == 0) {
                    next[now][i] = next[fail[now]][i]; //trie树的优化
                    end[now] = end[now] || end[fail[now]]; //核心
                }
                else {
                    fail[next[now][i]]=next[fail[now]][i];
                    Q.push(next[now][i]);
                }
        }
    }
}ac;


int dp[55][maxtrie];


#define MAXN 9999  
#define MAXSIZE 10  
#define DLEN 4  
  
class BigNum  
{   
private:   
    int a[40];    //可以控制大数的位数   
    int len;       //大数长度  
public:   
    BigNum(){ len = 1;memset(a,0,sizeof(a)); }   //构造函数  
    BigNum(const int);       //将一个int类型的变量转化为大数  
    BigNum(const char*);     //将一个字符串类型的变量转化为大数  
    BigNum(const BigNum &);  //拷贝构造函数  
    BigNum &operator=(const BigNum &);   //重载赋值运算符，大数之间进行赋值运算  
  
    friend istream& operator>>(istream&,  BigNum&);   //重载输入运算符  
    friend ostream& operator<<(ostream&,  BigNum&);   //重载输出运算符  
  
    BigNum operator+(const BigNum &) const;   //重载加法运算符，两个大数之间的相加运算   
    BigNum operator-(const BigNum &) const;   //重载减法运算符，两个大数之间的相减运算   
    BigNum operator*(const BigNum &) const;   //重载乘法运算符，两个大数之间的相乘运算   
    BigNum operator/(const int   &) const;    //重载除法运算符，大数对一个整数进行相除运算  
  
    BigNum operator^(const int  &) const;    //大数的n次方运算  
    int    operator%(const int  &) const;    //大数对一个int类型的变量进行取模运算      
    bool   operator>(const BigNum & T)const;   //大数和另一个大数的大小比较  
    bool   operator>(const int & t)const;      //大数和一个int类型的变量的大小比较  
  
    void print();       //输出大数  
};   
BigNum::BigNum(const int b)     //将一个int类型的变量转化为大数  
{   
    int c,d = b;  
    len = 0;  
    memset(a,0,sizeof(a));  
    while(d > MAXN)  
    {  
        c = d - (d / (MAXN + 1)) * (MAXN + 1);   
        d = d / (MAXN + 1);  
        a[len++] = c;  
    }  
    a[len++] = d;  
}  
BigNum::BigNum(const char*s)     //将一个字符串类型的变量转化为大数  
{  
    int t,k,index,l,i;  
    memset(a,0,sizeof(a));  
    l=strlen(s);     
    len=l/DLEN;  
    if(l%DLEN)  
        len++;  
    index=0;  
    for(i=l-1;i>=0;i-=DLEN)  
    {  
        t=0;  
        k=i-DLEN+1;  
        if(k<0)  
            k=0;  
        for(int j=k;j<=i;j++)  
            t=t*10+s[j]-'0';  
        a[index++]=t;  
    }  
}  
BigNum::BigNum(const BigNum & T) : len(T.len)  //拷贝构造函数  
{   
    int i;   
    memset(a,0,sizeof(a));   
    for(i = 0 ; i < len ; i++)  
        a[i] = T.a[i];   
}   
BigNum & BigNum::operator=(const BigNum & n)   //重载赋值运算符，大数之间进行赋值运算  
{  
    int i;  
    len = n.len;  
    memset(a,0,sizeof(a));   
    for(i = 0 ; i < len ; i++)   
        a[i] = n.a[i];   
    return *this;   
}  
istream& operator>>(istream & in,  BigNum & b)   //重载输入运算符  
{  
    char ch[MAXSIZE*4];  
    int i = -1;  
    in>>ch;  
    int l=strlen(ch);  
    int count=0,sum=0;  
    for(i=l-1;i>=0;)  
    {  
        sum = 0;  
        int t=1;  
        for(int j=0;j<4&&i>=0;j++,i--,t*=10)  
        {  
            sum+=(ch[i]-'0')*t;  
        }  
        b.a[count]=sum;  
        count++;  
    }  
    b.len =count++;  
    return in;  
  
}  
ostream& operator<<(ostream& out,  BigNum& b)   //重载输出运算符  
{  
    int i;    
    cout << b.a[b.len - 1];   
    for(i = b.len - 2 ; i >= 0 ; i--)  
    {   
        cout.width(DLEN);   
        cout.fill('0');   
        cout << b.a[i];   
    }   
    return out;  
}  
  
BigNum BigNum::operator+(const BigNum & T) const   //两个大数之间的相加运算  
{  
    BigNum t(*this);  
    int i,big;      //位数     
    big = T.len > len ? T.len : len;   
    for(i = 0 ; i < big ; i++)   
    {   
        t.a[i] +=T.a[i];   
        if(t.a[i] > MAXN)   
        {   
            t.a[i + 1]++;   
            t.a[i] -=MAXN+1;   
        }   
    }   
    if(t.a[big] != 0)  
        t.len = big + 1;   
    else  
        t.len = big;     
    return t;  
}  
BigNum BigNum::operator-(const BigNum & T) const   //两个大数之间的相减运算   
{    
    int i,j,big;  
    bool flag;  
    BigNum t1,t2;  
    if(*this>T)  
    {  
        t1=*this;  
        t2=T;  
        flag=0;  
    }  
    else  
    {  
        t1=T;  
        t2=*this;  
        flag=1;  
    }  
    big=t1.len;  
    for(i = 0 ; i < big ; i++)  
    {  
        if(t1.a[i] < t2.a[i])  
        {   
            j = i + 1;   
            while(t1.a[j] == 0)  
                j++;   
            t1.a[j--]--;   
            while(j > i)  
                t1.a[j--] += MAXN;  
            t1.a[i] += MAXN + 1 - t2.a[i];   
        }   
        else  
            t1.a[i] -= t2.a[i];  
    }  
    t1.len = big;  
    while(t1.a[len - 1] == 0 && t1.len > 1)  
    {  
        t1.len--;   
        big--;  
    }  
    if(flag)  
        t1.a[big-1]=0-t1.a[big-1];  
    return t1;   
}   
  
BigNum BigNum::operator*(const BigNum & T) const   //两个大数之间的相乘运算   
{   
    BigNum ret;   
    int i,j,up;   
    int temp,temp1;     
    for(i = 0 ; i < len ; i++)  
    {   
        up = 0;   
        for(j = 0 ; j < T.len ; j++)  
        {   
            temp = a[i] * T.a[j] + ret.a[i + j] + up;   
            if(temp > MAXN)  
            {   
                temp1 = temp - temp / (MAXN + 1) * (MAXN + 1);   
                up = temp / (MAXN + 1);   
                ret.a[i + j] = temp1;   
            }   
            else  
            {   
                up = 0;   
                ret.a[i + j] = temp;   
            }   
        }   
        if(up != 0)   
            ret.a[i + j] = up;   
    }   
    ret.len = i + j;   
    while(ret.a[ret.len - 1] == 0 && ret.len > 1)  
        ret.len--;   
    return ret;   
}   
BigNum BigNum::operator/(const int & b) const   //大数对一个整数进行相除运算  
{   
    BigNum ret;   
    int i,down = 0;     
    for(i = len - 1 ; i >= 0 ; i--)  
    {   
        ret.a[i] = (a[i] + down * (MAXN + 1)) / b;   
        down = a[i] + down * (MAXN + 1) - ret.a[i] * b;   
    }   
    ret.len = len;   
    while(ret.a[ret.len - 1] == 0 && ret.len > 1)  
        ret.len--;   
    return ret;   
}  
int BigNum::operator %(const int & b) const    //大数对一个int类型的变量进行取模运算      
{  
    int i,d=0;  
    for (i = len-1; i>=0; i--)  
    {  
        d = ((d * (MAXN+1))% b + a[i])% b;    
    }  
    return d;  
}  
BigNum BigNum::operator^(const int & n) const    //大数的n次方运算  
{  
    BigNum t,ret(1);  
    int i;  
    if(n<0)  
        exit(-1);  
    if(n==0)  
        return 1;  
    if(n==1)  
        return *this;  
    int m=n;  
    while(m>1)  
    {  
        t=*this;  
        for( i=1;i<<1<=m;i<<=1)  
        {  
            t=t*t;  
        }  
        m-=i;  
        ret=ret*t;  
        if(m==1)  
            ret=ret*(*this);  
    }  
    return ret;  
}  
bool BigNum::operator>(const BigNum & T) const   //大数和另一个大数的大小比较  
{   
    int ln;   
    if(len > T.len)  
        return true;   
    else if(len == T.len)  
    {   
        ln = len - 1;   
        while(a[ln] == T.a[ln] && ln >= 0)  
            ln--;   
        if(ln >= 0 && a[ln] > T.a[ln])  
            return true;   
        else  
            return false;   
    }   
    else  
        return false;   
}  
bool BigNum::operator >(const int & t) const    //大数和一个int类型的变量的大小比较  
{  
    BigNum b(t);  
    return *this>b;  
}  
  
void BigNum::print()    //输出大数  
{   
    int i;     
    cout << a[len - 1];   
    for(i = len - 2 ; i >= 0 ; i--)  
    {   
        cout.width(DLEN);   
        cout.fill('0');   
        cout << a[i];   
    }   
    cout << endl;  
}  

BigNum d[55][maxtrie];
/*
int main(void)  
{  
    int i,n;  
    BigNum x[101];      //定义大数的对象数组  
    x[0]=1;  
    for(i=1;i<101;i++)  
        x[i]=x[i-1]*(4*i-2)/(i+1);  
    while(scanf("%d",&n)==1 && n!=-1)  
    {  
        x[n].print();  
    }  
}  
*/

int main(void)
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
  //  freopen("out.txt", "w", stdout);
#endif
    while (~scanf("%d%d%d", &N, &M, &P)) {
        char temp[60];
        scanf("%s", temp);
        int len = strlen(temp);
        for (int i = 0; i < (int)strlen(temp); i++) {
            alphabet[(int)temp[i]] = i;
        }
        ac.init();
        for (int i = 0; i < P; i++) {
            scanf("%s", buf);
            ac.insert(buf);
        }
        ac.build();
        for (int i = 0; i <= M; i++) {
            for (int j = 0; j < ac.L; j++) 
                //dp[i][j] = 0;
                d[i][j] = 0;
        }
        //dp[0][0] = 1;
        d[0][0] = 1;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < ac.L; j++) {
                for (int k = 0; k < len; k++) {
                    int u = ac.next[j][k];
                    if (!ac.end[u])
                        //dp[i + 1][u] = dp[i + 1][u] + dp[i][j];
                        d[i + 1][u] = d[i + 1][u] + d[i][j];
                }
            }
        }
        BigNum ans = 0;
        for (int i = 0; i < ac.L; i++) 
            //anst = anst + dp[M][i];
            ans = ans + d[M][i];
        //pri(anst);
        ans.print();
    }
    return 0;
}

