#include<bits/stdc++.h>
using namespace std;
int n,c[10],d[10],s,v[50010],f[100020];;
int main()
{
	ios::sync_with_stdio(false);
	cin>>c[1]>>c[2]>>c[3]>>c[4]>>n;
	while(n--)
	{
		int tot = 0; memset(f,0,sizeof(f));
		cin>>d[1]>>d[2]>>d[3]>>d[4]>>s;
		for(int k=1;k<=4;k++)
		{
			for(int i=1;i<=d[k];i*=2)
			{
				tot++;
				v[tot]=c[k]*i;
				d[k]-=i;
			}
			if(d[k]!=0) v[++tot]=d[k]*c[k];
		}
		/*cout<<"------\n";
		for(int i=1;i<=tot;i++) cout<<v[i]<<"  ";*/
		
		f[0]=1;
		for(int i=1;i<=tot;i++)
		{
			for(int j=s;j>=v[i];j--)
			{
				f[j]+=f[j-v[i]];
			}
		}
		cout<<f[s]<<"\n";
	}
	return 0;
}