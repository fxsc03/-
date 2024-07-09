#include<bits/stdc++.h>
using namespace std;
int n,ans=-99999999,a[200],f1[200][200],f2[200][200];//f1是区间最大值 f2是区间最小值 
char b[200];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) cin>>b[i]>>a[i];
    memset(f2,0x3f,sizeof(f2));
    memset(f1,-0x3f,sizeof(f1));
    for(int i=1;i<=n-1;i++) a[i+n]=a[i],b[i+n]=b[i];
    for(int i=1;i<=2*n-1;i++) f1[i][i]=a[i],f2[i][i]=a[i];
    

    //f1是区间最大值 f2是区间最小值 
    for(int len=2;len<=n;len++)
    for(int i=1;i+len-1<=2*n-1;i++)
    {
        int j=i+len-1;
        for(int k=i;k<=j-1;k++)
        {
            if(b[k+1]=='t')
            {
                f1[i][j]=max(f1[i][j],f1[i][k]+f1[k+1][j]);
                f2[i][j]=min(f2[i][j],f2[i][k]+f2[k+1][j]);
            }
            else
            {
                f1[i][j]=max(f1[i][j],max(f1[i][k]*f1[k+1][j],f2[i][k]*f2[k+1][j]));
                f2[i][j]=min(f2[i][j],min(f2[i][k]*f2[k+1][j],min(f1[i][k]*f2[k+1][j],f2[i][k]*f1[k+1][j])));
            }
        }
    }



    for(int i=1;i<=n;i++) ans=max(ans,f1[i][i+n-1]);
    printf("%d\n",ans);
    for(int i=1;i<=n;i++) if(f1[i][i+n-1]==ans) printf("%d ",i);
    return 0;
}