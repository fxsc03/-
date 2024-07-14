#include<bits/stdc++.h>
using namespace std;
int n,vis[100];
double p1,p2,p3,p4,ans,r[10],xx[5],yy[5],pi=3.14159265358979;
struct node
{
	double length,width;
} d[10];
double dis(double x1,double y1,double x2,double y2)
{
	if(x1>x2) swap(x1,x2);
	if(y1>y2) swap(y1,y2);
	return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}
double getdis(double x,double y)
{
	double ans=9999999;
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==1)
		{
			if(dis(x,y,d[i].length,d[i].width)-r[i]<0) {ans=0; break;}
			ans=min(ans,fabs(dis(x,y,d[i].length,d[i].width)-r[i]));
		}
	}
	double t1=min(fabs(xx[1]-x),fabs(xx[2]-x));
	double t2=min(fabs(yy[1]-y),fabs(yy[2]-y));
	ans=min(ans,min(t1,t2));
	return ans;
}
void dfs(int u,double w)
{
	if(w>ans) ans=w;
	//if(u==n+1) {return;}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==1) continue;
		r[i]=getdis(d[i].length,d[i].width);
		vis[i]=1;
		double wt=pi*r[i]*r[i];
		dfs(i,w+wt);
		vis[i]=0;
	}
}
int main()
{
	scanf("%d",&n);
	scanf("%lf%lf%lf%lf",&p1,&p2,&p3,&p4);
	for(int i=1;i<=n;i++) scanf("%lf%lf",&d[i].length,&d[i].width);
	if(p1<p3) xx[1]=p1,xx[2]=p3;
	else xx[1]=p3,xx[2]=p1;
	if(p2<p4) yy[1]=p2,yy[2]=p4;
	else yy[1]=p4,yy[2]=p2;
	dfs(1,0);
	printf("%d",(int)((xx[2]-xx[1])*(yy[2]-yy[1])-ans+0.5));
	return 0;
}