/**********************jibancanyang**************************
 *Author*        :jibancanyang
 *Created Time*  : 一  7/11 16:03:03 2016
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

#define inf INF 
#define maxn 205
char gra[maxn][maxn],lit[maxn][maxn],vis[maxn][maxn];
int a[30][5],c[30];
int tot;

int check()
{
    int i,j,x,y;
    int flag=1;
    for(i=1;i<=tot;i++){
        x=a[i][0];
        y=a[i][1];
        if(lit[x][y])continue;
        else flag=0;
    }
    return flag;
}


int main()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int n,m,i,j,h,k;
    int x1,x2,x3,y1,y2,y3,x,y,now,xx1,xx2,yy1,yy2,xx,yy,s,zt;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n==0 && m==0)break;
        tot=0;
        for(i=1;i<=n;i++){
            scanf("%s",gra[i]+1);
            for(j=1;j<=m;j++){
                if(gra[i][j]=='.'){
                    tot++;
                    a[tot][0]=i;
                    a[tot][1]=j;
                    a[tot][2]=(1<<(tot-1) );
                }
            }

        }
        if(tot==0){
            printf("0\n");continue;
        }
        int ans=inf;
        for(h=1;h<=4;h++){
            for(k=1;k<=tot;k++){
                for(i=1;i<=tot;i++){
                    vis[a[i][0] ][a[i][1]  ]=0;
                    lit[a[i][0] ][a[i][1]  ]=0;
                }
                x=a[k][0];
                y=a[k][1];
                if(h==1){
                    x1=x-1; y1=y;
                    x2=x;   y2=y+1;
                }
                else if(h==2){
                    x1=x+1; y1=y;
                    x2=x; y2=y+1;
                }
                else if(h==3){
                    x1=x+1; y1=y;
                    x2=x; y2=y-1;

                }
                else if(h==4){
                    x1=x-1; y1=y;
                    x2=x; y2=y-1 ;
                }


                if(x1>=1 && x1<=n && y1>=1 && y1<=m){
                    if(gra[x1][y1]=='#')continue;
                }
                if(x2>=1 && x2<=n && y2>=1 && y2<=m){
                    if(gra[x2][y2]=='#')continue;
                }
                vis[x][y]=1;lit[x][y]=1;
                if(x1>=1 && x1<=n && y1>=1 && y1<=m){
                    lit[x1][y1]=1;
                }
                if(x2>=1 && x2<=n && y2>=1 && y2<=m){
                    lit[x2][y2]=1;
                }

                if(check()){
                    ans=min(ans,1);break;
                }

                for(zt=1;zt<=(1<<tot)-1;zt++){
                    int s=zt;
                    for(i=1;i<=tot;i++){
                        vis[a[i][0] ][a[i][1]  ]=0;
                        lit[a[i][0] ][a[i][1]  ]=0;

                    }
                    if(x1>=1 && x1<=n && y1>=1 && y1<=m){
                    if(gra[x1][y1]=='#')continue;
                    }
                    if(x2>=1 && x2<=n && y2>=1 && y2<=m){
                        if(gra[x2][y2]=='#')continue;
                    }
                    vis[x][y]=1;lit[x][y]=1;
                    if(x1>=1 && x1<=n && y1>=1 && y1<=m){
                        lit[x1][y1]=1;
                    }
                    if(x2>=1 && x2<=n && y2>=1 && y2<=m){
                        lit[x2][y2]=1;
                    }
                    if(s&(a[k][2] ))continue;
                    int wei=0;
                    int geshu=0;
                    while(s)
                    {
                        wei++;
                        c[wei]=s%2;
                        if(c[wei]==1)geshu++;
                        s/=2;
                    }
                    if(geshu+1>ans)continue;
                    int flag1=1;
                    for(i=1;i<=wei;i++){
                        if(c[i]==1){
                            xx=a[i][0];
                            yy=a[i][1];
                            xx1=xx-1;yy1=yy;
                            xx2=xx;yy2=yy+1;
                            if(xx1>=1 && xx1<=n && yy1>=1 && yy1<=m){
                                if(gra[xx1][yy1]=='#'){
                                    flag1=0;break;
                                }
                            }
                            if(xx2>=1 && xx2<=n && yy2>=1 && yy2<=m){
                                if(gra[xx2][yy2]=='#'){
                                    flag1=0;break;
                                }
                            }
                            vis[xx][yy]=1;lit[xx][yy]=1;
                            if(xx1>=1 && xx1<=n && yy1>=1 && yy1<=m){
                                lit[xx1][yy1]=1;
                            }
                            if(xx2>=1 && xx2<=n && yy2>=1 && yy2<=m){
                                lit[xx2][yy2]=1;
                            }
                        }
                    }
                    if(flag1){
                        if(check()){
                            ans=min(ans,geshu+1);
                        }
                    }
                }

            }
            if(ans==1)break;
        }
        if(ans==inf)printf("-1\n");
        else printf("%d\n",ans);
    }
    return 0;
}
