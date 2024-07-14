#include<bits/stdc++.h>
using namespace std;
const int MAXM=60;
int a[MAXM],b[MAXM],sum[MAXM],n,m,c,ans;
int f[MAXM][MAXM][2];
int main()
{
  scanf("%d%d",&n,&c);
  for(int i=1;i<=59;i++)
  for(int j=1;j<=59;j++)
  for(int k=0;k<=1;k++) f[i][j][k]=9999999;
  for(int i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]),sum[i]=sum[i-1]+b[i];
  f[c][c][0]=f[c][c][1]=0;
  for(int len=2;len<=n;len++)
    for(int i=1;i+len-1<=n;i++)
      {
    int j=i+len-1;

    

    f[i][j][0]=min(f[i+1][j][0]+(a[i+1]-a[i])*(sum[i]+sum[n]-sum[j]),
    f[i+1][j][1]+(a[j]-a[i])*(sum[i]+sum[n]-sum[j]));
    f[i][j][1]=min(f[i][j-1][0]+(a[j]-a[i])*(sum[i-1]+sum[n]-sum[j-1]),
    f[i][j-1][1]+(a[j]-a[j-1])*(sum[i-1]+sum[n]-sum[j-1]));

    
        }
  ans=min(f[1][n][0],f[1][n][1]);
  printf("%d",ans);
  return 0;
}