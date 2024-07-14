#define ll long long
#include<bits/stdc++.h>
using namespace std;
ll n,a[100010],ans,sum1[100010],sum2[100010];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int k=1;k<=22;k++)
	{
		memset(sum1,0,sizeof(sum1));
		memset(sum2,0,sizeof(sum2));

		for(int i=1;i<=n;i++)
		{
			if((1<<(k-1))&a[i])
			{
				sum1[i]=sum2[i-1]; sum2[i]=sum1[i-1]; sum1[i]++;
			}
			else
			{
				sum1[i]=sum1[i-1]; sum2[i]=sum2[i-1]; sum2[i]++;
			}
		}

        
		for(int i=1;i<=n;i++)
		{
			if(a[i]&(1<<(k-1))) ans+=sum1[i]*(1<<(k-1));
			else ans+=sum1[i]*(1<<(k-1));
		}
	}
	cout<<ans<<"\n";
	return 0;
}