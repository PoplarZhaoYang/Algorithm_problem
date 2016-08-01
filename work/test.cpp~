#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAXN 1010
char r[1010];
int sa[1010];
int wa[MAXN],wb[MAXN],wv[MAXN],ws[MAXN];
int height[MAXN],rnk[MAXN];
inline bool cmp(int *r,int a,int b,int len){
    return r[a]==r[b]&&r[a+len]==r[b+len];
}
void SA(int n,int m){
    int i,j,p,*x=wa,*y=wb,*t;
    for(i=0;i<m;i++)
        ws[i]=0;
    for(i=0;i<n;i++)
        ws[x[i]=r[i]]++;
    for(i=1;i<m;i++)
        ws[i]+=ws[i-1];
    for(i=n-1;i>=0;i--)
        sa[--ws[x[i]]]=i;
    for(j=p=1;p<n;j<<=1,m=p){
        for(p=0,i=n-j;i<n;i++)
            y[p++]=i;
        for(i=0;i<n;i++){
            if(sa[i]>=j)
                y[p++]=sa[i]-j;
        }
        for(i=0;i<m;i++)
            ws[i]=0;
        for(i=0;i<n;i++)
            ws[wv[i]=x[y[i]]]++;
        for(i=1;i<m;i++)
            ws[i]+=ws[i-1];
        for(i=n-1;i>=0;i--)
            sa[--ws[wv[i]]]=y[i];
        for(t=x,x=y,y=t,x[sa[0]]=0,p=i=1;i<n;i++)
            x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
    }
}
void Height(int n){
    int i,j,k=0;
    for(i=1;i<=n;i++)   //sa[0]是以'\0'为首的后缀
        rnk[sa[i]]=i;
    for(i=0;i<n;height[rnk[i++]]=k)
        for(k?k--:0,j=sa[rnk[i]-1];r[i+k]==r[j+k];k++);
}
void solve(int n){
    long long sum=0;
    sum+=n-sa[1];
    for(int i=2;i<=n;i++)
        sum+=n-sa[i]-height[i];
    printf("%lld\n",sum);
}
int main(){
    int i,j,t,T,n;
    scanf("%d",&T);
    for(t=1;t<=T;t++){
        memset(height,0,sizeof(height));
        scanf("%s",r);
        n=strlen(r);
        SA(n+1,130);
        Height(n);
        solve(n);
    }
}
