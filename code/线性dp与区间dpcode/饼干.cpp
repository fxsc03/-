#include<bits/stdc++.h>
using namespace std;
int n,m,g[10000],c[5010],ans[5010],f[35][5010],a[35][5010],b[35][5010];
bool cmp(int x,int y)
{
    return x>y;
}
bool cmp2(int x,int y)
{
    return g[x]>g[y];
}
void structure(int x,int y)
{
    if(x==0) return;
    structure(a[x][y],b[x][y]);
    if(a[x][y]==x)
    {
        for(int i=1;i<=x;i++) ans[c[i]]++;
    }
    else
    {
        for(int i=a[x][y]+1;i<=x;i++) ans[c[i]]=1;
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&g[i]),c[i]=i;
    sort(c+1,c+n+1,cmp2);
    //sort(g+1,g+n+1,cmp);
    memset(f,0x3f,sizeof(f));
    //for(int i=1;i<=n;i++) f[i][i]=0;
    f[0][0]=0;
    for(int i=1;i<=n;i++)
    for(int j=i;j<=m;j++)
    {
        f[i][j]=f[i][j-i];
        a[i][j]=i; b[i][j]=j-i;
        for(int k=0;k<=i-1;k++)
        {
            int sum=0;
            for(int s=k+1;s<=i;s++) sum+=g[c[s]]*k;
            //f[i][j]=min(f[i][j],f[k][j-(i-k)]+sum);
            if(f[i][j]>f[k][j-(i-k)]+sum)
            {
                f[i][j]=f[k][j-(i-k)]+sum;
                a[i][j]=k; b[i][j]=j-(i-k);
            }
        }
    }
    printf("%d\n",f[n][m]);
    structure(n,m);
    for(int i=1;i<=n;i++) printf("%d ",ans[i]);
    return 0;
} 