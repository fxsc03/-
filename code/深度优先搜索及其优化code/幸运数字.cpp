#include <cstdio>
#include <algorithm>
#define maxn 100000
#define ll long long
using namespace std;
ll tmp, luck[maxn], tot=-1, A, B, ans;


void dfs1(ll x)
{
	if(x>B)return;
	luck[++tot]=x;
	dfs1(x*10+6);
	dfs1(x*10+8);
}

inline ll gcd(ll a, ll b){return !b?a:gcd(b,a%b);}

inline ll lcm(ll a, ll b){return a/gcd(a,b)*b;}

inline void dfs2(ll pos, ll k, ll x)
{
	if(x>B)return;
	if(pos>tot)
	{
		if(k==0)return;
		if(k&1)ans+=B/x-A/x;
		else ans-=B/x-A/x;
		return;
	}
	dfs2(pos+1,k,x);
	ll g=gcd(x,luck[pos]);
	if(double(x/g)*luck[pos]>(double)B)return;
	dfs2(pos+1,k+1,lcm(x,luck[pos]));
}
bool cmp(ll a, ll b){return a>b;}

int main()
{
	ll x, i, j;
	scanf("%lld%lld",&A,&B);A--;
	dfs1(0);
	sort(luck+1,luck+tot+1,cmp);
	x=0;
	for(i=1;i<=tot;i++)
	{
		for(j=i+1;j<=tot;j++)
			if(luck[i]%luck[j]==0)break;
		if(j>tot)luck[++x]=luck[i];
	}
	tot=x;
	dfs2(1,0,1);
	printf("%lld",ans);
	return 0;
}