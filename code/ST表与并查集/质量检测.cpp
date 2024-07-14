#include<bits/stdc++.h>
using namespace std;
int n,m,a[100010],f[100010][25];//f[i][j]表示i~i+2^j-1
void ST()
{
	for(int i=1;i<=n;i++) f[i][0]=a[i];
	for(int j=1;j<=20;j++)
	{
		for(int i=1;i<=n;i++)
		{
			if(i+(1<<j)-1<=n)
			{
				f[i][j]=min(f[i][j-1],f[i+(1<<(j-1))][j-1]);
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	ST();
	for(int i=1;i<=n-m+1;i++)
	{
		int  k = log2(m);
		cout<<min(f[i][k],f[(i+m-1) - (1<<k)+1 ][k])<<"\n";
	}
	return 0;
}