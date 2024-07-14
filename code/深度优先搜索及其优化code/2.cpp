#include<bits/stdc++.h>
using namespace std;

int a[20],vis[20];
void dfs(int step){
	if(!check()) return;
	if(step > 8) {output(); return;}
	for(int i = 1; i <= 8; i++){
		if(vis[i] == i) continue;
		a[step] = i; dfs(step+1);
	}
}

int check() {}
void output() {}
int main()
{
	return 0;
}