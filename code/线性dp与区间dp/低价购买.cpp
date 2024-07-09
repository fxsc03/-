#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int a[5005],f[5005],t[5005];
int main(){
    int n,ans=1,ans2=0;
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	f[i]=t[i]=1;
    }
    for(int i=2;i<=n;i++){
        for(int j=1;j<i;j++){
            if(a[j]>a[i]){
                if(f[i]<f[j]+1)f[i]=f[j]+1,t[i]=t[j];
                else if(f[i]==f[j]+1)t[i]+=t[j];
            }


            if(a[j]==a[i])f[j]=t[j]=0;

            
        }
        
        ans=max(ans,f[i]);
    }
    cout<<ans;
    for(int i=1;i<=n;i++)if(f[i]==ans)ans2+=t[i];
    cout<<" "<<ans2;
    return 0;
}