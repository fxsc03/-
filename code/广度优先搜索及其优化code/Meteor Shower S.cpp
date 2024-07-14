#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;//无限大
int mp[302][302];//表示流星到达时间
bool v[302][302];//有无走过
struct point {
	int x,y,step;//步数也就是时间
};
int dx[]= {0,0,-1,1},dy[]= {-1,1,0,0};//四个方向 



int BFS(point a) {
	queue<point>q;
	q.push(a);
	v[a.x][a.y]=1;//标记为走过
	while(!q.empty()) {
		point b=q.front();
		q.pop();
		for(int d=0; d<4; ++d) {
			point c;
			c.x=b.x+dx[d],c.y=b.y+dy[d],c.step=b.step+1;
			if(c.x==-1||c.y==-1)continue;//判边界
			if(mp[c.x][c.y]==inf)return c.step;//永远不会有流星
			if(c.step<mp[c.x][c.y]&&!v[c.x][c.y]) {//在流星到达之前并且没走过
				q.push(c);
				v[c.x][c.y]=1;//标记为走过
			}
		}
	}
	return -1;
}



int main() {
	int m;
	scanf("%d",&m);
	memset(mp,0x3f,sizeof(mp));//由于是按字节赋值，刚好是mp[?][?]=inf
	for(int i=1,x,y,t; i<=m; ++i) {
		scanf("%d%d%d",&x,&y,&t);
		mp[x][y]=min(mp[x][y],t);
		for(int d=0; d<4; ++d) {
			if(x+dx[d]==-1||y+dy[d]==-1)continue;//判边界
			mp[x+dx[d]][y+dy[d]]=min(mp[x+dx[d]][y+dy[d]],t);
			//更新此位置流星最早到达时间
		}
	}
	printf("%d",BFS((point) {
		0,0,0
	}));
	//相当于
	//point a;
	//a.x=a.y=a.step=0;
	//printf("%d",BFS(a));
	return 0;
}