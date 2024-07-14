#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cctype>
#define ll long long
#define R register
#define N 55
using namespace std;
template<typename T>inline void read(T &a){
    char c=getchar();T x=0,f=1;
    while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
    while(isdigit(c)){x=(x<<1)+(x<<3)+c-'0';c=getchar();}
    a=f*x;
}
ll n,m,w[N],mid,suma[1<<21],sumb[1<<21],cnta,cntb,ans;
inline void dfs(R int l,R int r,R ll sum,R ll a[],R ll &cnt){
    if(sum>m)return;
    if(l>r){
        a[++cnt]=sum;
        return;
    }
    dfs(l+1,r,sum+w[l],a,cnt);
    dfs(l+1,r,sum,a,cnt);
}
int main(){


    cin>>n>>m;
    for(R int i=1;i<=n;i++)read(w[i]);
    mid=n>>1;
    dfs(1,mid,0,suma,cnta);
    dfs(mid+1,n,0,sumb,cntb);
    sort(suma+1,suma+1+cnta);
    for(R int i=1;i<=cntb;i++)
        ans+=upper_bound(suma+1,suma+1+cnta,m-sumb[i])-suma-1;
    printf("%lld\n",ans);
    return 0;


    
}