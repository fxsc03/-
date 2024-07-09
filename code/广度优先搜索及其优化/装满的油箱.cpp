#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int C = 105;   // 最大油量
const int N = 1005;  // 点的数量
const int M = 20005; // 边的数量

struct Point     // 存每个点的状态
{
    int d, u, c; // d 存到这个点所花费的油钱，u 存点的编号，c 存当前还剩多少油
    bool operator < (const Point &t) const // 重载小于号。按大于好反过来重载小于号，后面在建堆的时候建大根堆就可以了
    {
        return d > t.d;
    }
};
int n, m;
int p[N], dist[N][C]; // p 存每个点上的油价，dist 存到每个被拆的点的最低油钱
int h[N], w[M], e[M], ne[M], idx; // 存图
bool st[N][C];        // 用于 dijkstra 中记录每个点是否已经出队

void add(int a, int b, int c) // 加边函数
{
    e[ ++ idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx;
}

// 求出从 start 到 end，油箱容量为 c 的最短距离。若不能到，返回 -1
inline int dijkstra(int c,int start,int end)
{
    priority_queue<Point> heap;      // 由于按大于号重载了小于号，所以建大根堆即可
    memset(dist, 0x3f, sizeof dist); // 将到所有点的油钱都初始化为正无穷
    memset(st, false, sizeof st);    // 将 st 初始化为 false
    heap.push((Point){0, start, 0}); // 将 start 加入堆中
    dist[start][0] = 0;              // 到该点的油钱初始化为 0
    while (heap.size())
    {
        Point t = heap.top();       // 取出堆顶元素
        heap.pop();
        if (t.u == end) return t.d; // 如果到了 end，返回到 end 的距离
        if (st[t.u][t.c]) continue; // 如果该点已经出队过，则跳过
        st[t.u][t.c] = true;        // 记录该点已经出队过
        if (t.c < c)                // 如果 t.c + 1 <= c，说明可以在该点加油，扩展一下加油的情况
            if (dist[t.u][t.c + 1] > t.d + p[t.u]) // 如果这次加油后的油钱比原来的低，
            {
                dist[t.u][t.c + 1] = t.d + p[t.u]; // 那么更新原来的
                heap.push((Point){dist[t.u][t.c + 1], t.u, t.c + 1}); // 该点加入堆中
            }
        for (int i = h[t.u]; i; i = ne[i]) // 遍历该点所有能到达的点
            if (t.c >= w[i])               // 如果用当前所剩的油量能到该点
                if (dist[e[i]][t.c - w[i]] > t.d) // 如果这次到该点的油钱小于原来的
                {
                    dist[e[i]][t.c - w[i]] = t.d; // 那么更新原来的
                    heap.push((Point){t.d, e[i], t.c - w[i]}); // 将该点加入堆中
                }
    }
    return -1; // 如果到不了 end，返回 -1
}

int main()
{
    scanf("%d%d", &n, &m);  // 读入点数和边数
    for (int i = 0; i < n; i ++ )
        scanf("%d", &p[i]); // 读入每个点的油价

    while (m -- )           // 读入 m 条边并建图
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c), add(b, a, c); // 无向边
    }

    int T;
    scanf("%d", &T);        // 读入问题数量
    while (T -- )           // 处理每个问题
    {
        int C, S, E;
        scanf("%d%d%d", &C, &S, &E);
        int d = dijkstra(C, S, E);
        if (d == -1) puts("impossible");
        else    printf("%d\n", d);
    }

    return 0;
}

/*


..........
..X.......
..M.X...X.
X........G
.X..X.X.X.
........X
..XX....X.
X........X
...ZX.X...
...Z..X..X




*/