/*
抽象成一个最短路，横纵坐标和为奇数的点，永远走不到
每一步的长度为0或1，1表示需要反转一下
dx,dy确定点的坐标，ix,iy确定线的坐标
在读入数据的时候，我们输入的是线，但是我们的BFS是按照点来做的
所以向四个方向扩展时，每一个点要找对应4个方向的线，看看走到对角线上点的位置
需要0还是1 

*/

#include<cstring>
#include<iostream>
#include<algorithm>
#include<deque>//双端队列

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N=510, M=N*N;

int n, m;
char g[N][N];
int dist[N][N];//注意起点是从0,0开始的
bool st[N][N];

int bfs()
{
    memset(dist, 0x3f, sizeof dist);
    memset(st, 0, sizeof st);
    dist[0][0]=0;
    deque<PII> q;
    q.push_back({0, 0});
    char cs[]="\\/\\/";// 表示某个点可选的走到4个点的花费为0字符，\/\/,顺时针
    int dx[]={-1, -1, 1, 1}, dy[]={-1, 1, 1, -1};//表示可以走到的四个点的坐标
    int ix[]={-1, -1, 0, 0}, iy[]={-1, 0, 0, -1};//  把格子上的点和线分开看



    while(q.size())
    {
        PII t=q.front();
        q.pop_front();
        if(st[t.x][t.y]) continue;
        st[t.x][t.y]=true;
        for(int i=0; i<4; i++)
        {
            int a=t.x+dx[i], b=t.y+dy[i];
            if(a<0 || a>n || b<0 || b>m) continue;
            int ca=t.x+ix[i], cb=t.y+iy[i];
            int d=dist[t.x][t.y]+(g[ca][cb] != cs[i]);
            if(d<dist[a][b])
            {
                dist[a][b]=d;
                if(g[ca][cb]!=cs[i]) q.push_back({a, b});
                else q.push_front({a, b});
            }
        }

    }  


    return dist[n][m];//这里的n，m就是实打实的n，m
}

int main()
{
    int T;
    cin>>T;

    while(T--)
    {
        scanf("%d%d", &n, &m);
        for(int i=0; i<n; i++) scanf("%s", g[i]);

        int t=bfs();

        //优化，和是奇数，直接无解
        if((n+m)&1) puts("NO SOLUTION");
        else printf("%d\n", t);
    }

    return 0;
}