#include<bits/stdc++.h>
using namespace std;
int n,a[10010],sum[10010],f1[1010][1010],f2[1010][1010],ans1,ans2=9999999;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),a[i+n]=a[i],sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++) sum[i+n]=sum[n]+sum[i];
	for(int i=1;i<=n;i++) f2[i][i]=0;



	for(int len=2;len<=n;len++)
	for(int i=1;i+len-1<=2*n-1;i++)
	{
		int j=len+i-1;
		f2[i][j]=9999999;
		for(int k=i;k<=j-1;k++)
		{
			f1[i][j]=max(f1[i][k]+f1[k+1][j]+sum[j]-sum[i-1],f1[i][j]);
			f2[i][j]=min(f2[i][k]+f2[k+1][j]+sum[j]-sum[i-1],f2[i][j]);
		}
	}



	for(int i=1;i<=n;i++) ans1=max(ans1,f1[i][i+n-1]),ans2=min(ans2,f2[i][i+n-1]);
	printf("%d\n%d\n",ans2,ans1);
	return 0;
}