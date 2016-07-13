/**********************jibancanyang**************************
 *Author*        :jibancanyang
 *Created Time*  : 三  7/13 10:21:19 2016
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
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
#define pr(x) cout << #x << ": " << x << "  " 
#define pl(x) cout << #x << ": " << x << endl;
#define pri(a) printf("%d\n",(a))
#define xx first
#define yy second
#define sa(n) scanf("%d", &(n))
#define sal(n) scanf("%lld", &(n))
#define sai(n) scanf("%I64d", &(n))
#define vep(c) for(decltype((c).begin() ) it = (c).begin(); it != (c).end(); it++) 
const int mod = int(1e9) + 7, INF = 0x3f3f3f3f;
const int maxn = 1e5 + 13;
#define ll long long
#define sc scanf
#define pf printf
#define pi 2*acos(0.0)
int main()
{
 string s,a,b;
 char m[3000];
 memset(m,0,sizeof(m));
 m['A']='A';
 m['E']='3';
 m['H']='H';
 m['I']='I';
 m['J']='L';
 m['L']='J';
 m['M']='M';
 m['O']='O';
 m['S']='2';
 m['T']='T';
 m['U']='U';
 m['V']='V';
 m['W']='W';
 m['X']='X';
 m['Y']='Y';
 m['Z']='5';
 m['1']='1';
 m['2']='S';
 m['3']='E';
 m['5']='Z';
 m['8']='8';
 while(cin>>s){
  a=b="";
  int len=s.size();
  for(int i=len-1;i>=0;i--)
  {
      a+=s[i];
      b+=m[s[i]];
  }
  if (s==a && s==b)
  cout<<s<<" -- is a mirrored palindrome."<<endl<<endl;
  else if (s==a && s!=b)
   cout<<s<<" -- is a regular palindrome."<<endl<<endl;
  else if (s!=a && s==b)
  cout<<s<<" -- is a mirrored string."<<endl<<endl;
  else
   cout<<s<<" -- is not a palindrome."<<endl<<endl;
 }
 return 0;
}
