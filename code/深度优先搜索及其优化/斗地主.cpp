#include<bits/stdc++.h>
using namespace std;
int T,n,bj1,bj2,ans=0x7fffffff,num[1000];
void dfs(int k)
{
    if(k>=ans) return;


    int len=0;
    for(int i=3;i<=14;i++)
    {
        if(num[i]==0) {len=0;continue;}
        len++;
        if(len>=5)//有5便出顺子 
        {
            for(int j=i-len+1;j<=i;j++) num[j]--;
            dfs(k+1);
            for(int j=i-len+1;j<=i;j++) num[j]++;
        }
    }
    
    len=0;
    for(int i=3;i<=14;i++)
    {
        if(num[i]<2) {len=0;continue;}
        len++;
        if(len>=3)
        {
            for(int j=i-len+1;j<=i;j++) num[j]-=2;
            dfs(k+1);
            for(int j=i-len+1;j<=i;j++) num[j]+=2;
        }
    }
    



    len=0;
    for(int i=3;i<=14;i++)
    {
        if(num[i]<3) {len=0;continue;}
        len++;
        if(len>=2)
        {
            for(int j=i-len+1;j<=i;j++) num[j]-=3;
            dfs(k+1);
            for(int j=i-len+1;j<=i;j++) num[j]+=3;
        }
    }
    


    
    for(int i=2;i<=14;i++)
    {
        if(num[i]==4)
        {
            num[i]=0;
            dfs(k+1);
            num[i]=4;//炸弹 
            
            num[i]=0;
            for(int j=2;j<=15;j++)
            {
                if(num[j]==0||j==i) continue;
                num[j]--;
                for(int s=2;s<=15;s++)
                {
                    if(num[s]==0||s==j) continue;
                    num[s]--;
                    dfs(k+1);
                    num[s]++;
                }
                num[j]++;
            }
            num[i]=4;//四带二 
            
            num[i]=0;
            for(int j=2;j<=14;j++)
            {
                if(num[j]<2||j==i) continue;
                num[j]-=2;
                for(int s=2;s<=14;s++)
                {
                    if(num[s]<2||s==j) continue;
                    num[s]-=2;
                    dfs(k+1);
                    num[s]+=2;
                }
                num[j]+=2;
            }
            num[i]=4;//四带两对 
            
            num[i]=1;
            dfs(k+1);
            num[i]=4;//三张 
            
            num[i]=1;
            for(int j=2;j<=15;j++)
            {
                if(num[j]==0||j==i) continue;
                num[j]--;
                dfs(k+1);
                num[j]++;	
            }
            num[i]=4;//三带一 
            
            num[i]=1;
            for(int j=2;j<=14;j++)
            {
                if(num[j]<2||j==i) continue;
                num[j]-=2;
                dfs(k+1);
                num[j]+=2;
            }
            num[i]=4;//三带二 
            
        }
        
        if(num[i]==3)
        {
            num[i]=0;
            dfs(k+1);
            num[i]=3;//三张 
            
            num[i]=0;
            for(int j=2;j<=15;j++)
            {
                if(num[j]==0||j==i) continue;
                num[j]--;
                dfs(k+1);
                num[j]++;	
            }
            num[i]=3;//三带一 
            
            num[i]=0;
            for(int j=2;j<=14;j++)
            {
                if(num[j]<2||j==i) continue;
                num[j]-=2;
                dfs(k+1);
                num[j]+=2;
            }
            num[i]=3;//三带二
            
        }
    }
    
    for(int i=2;i<=15;i++) if(num[i]) k++;
     ans=min(ans,k);
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d%d",&T,&n);
    while(T--)
    {
        memset(num,0,sizeof(num));
        bj1=0,bj2=0;
        for(int i=1;i<=n;i++)
        {
            int x,y; scanf("%d%d",&x,&y);
            if(x==0) num[15]++;
            if(x==1) num[14]++;
            num[x]++;
        }
        dfs(0); 
        printf("%d\n",ans);
        ans=0x7fffffff;
    }
    return 0;
}