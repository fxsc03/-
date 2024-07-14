#include<bits/stdc++.h>
using namespace std;



int a[20],vis[20];
int step = 1;
void dfs(){
	if(!check()) return;
	if(step > 8) {output(); return;}
	for(int i = 1; i <= 8; i++){
		if(vis[i] == 1) continue;
		a[step] = i;
		step ++; vis[i] = 1;
		dfs();
		step--; vis[i] = 0;//回溯
	}
}



int check() {}
void output() {}
int main()
{
	return 0;
}