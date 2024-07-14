#define ll long long
#include<bits/stdc++.h>
using namespace std;
ll n,ans,c[10],S=100010;
ll d[10],s,f[100020];
int main()
{
	cin>>c[1]>>c[2]>>c[3]>>c[4]>>n;
	f[0]=1;
	for(int i=1;i<=4;i++)
	{
		for(int j=c[i];j<=S;j++)
		{
			f[j]+=f[j-c[i]];
		}
	}
	while(n--)
	{
		cin>>d[1]>>d[2]>>d[3]>>d[4]>>s;		


		ans=f[s];
		for(int k=1;k<=15;k++)
		{
			ll sum=0; ll cnt=0;
			for(int i=1;i<=4;i++)
			{
				if(( k>>(i-1) ) &1 ) sum+=(d[i]+1)*c[i],cnt++;
			}
			if(sum>s) continue;
			if(cnt%2==0) ans+=f[s-sum];
			else ans-=f[s-sum];
		}



        
		cout<<ans<<"\n";
	}
	return 0;
}