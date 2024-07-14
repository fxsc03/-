#include<bits/stdc++.h>
using namespace std;
int a,b,vis[1000010];

queue <int> q;
struct state {
    int x,y;//坐标
    int c; //0-未使用魔法，1-变红，2-变黄 
};
queue <state> q;
int Vis[110][110][3];


void bfs(int x,int y){
    for(int i = 0; i <= 100000; i++) vis[i] = -1;
    q.push(x); vis[x] = 0;
    while(! q.empty()) {
        int p = q.front();
        q.pop();
        //if(p == y) break;
        if(p + a <= 100000 && vis[p + a] == -1)
        vis[p + a] = vis[p] + 1, q.push(p + a);
        if(p - b >= 0 && vis[p - b] == -1)
        vis[p - b] = vis[p] + 1, q.push(p - b);
 }
}
int main()
{
    ios::sync_with_stdio(false);
    return 0;
}