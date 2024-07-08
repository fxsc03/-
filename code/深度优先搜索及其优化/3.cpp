#include<bits/stdc++.h>
using namespace std;

int a[20],n;
void dfs(int step){
	if(!check()) return;
	if(step > 8) {output(); return;}
	for(int i = 1; i <= 8; i++){
		a[step] = i; dfs(step+1);
	}
}


void dfs(int step)
{
    if(step>n)return;
    a[step]=1;
    dfs(step+1);
    a[step]=0;
    dfs(step+1);
}


int check() {}
void output() {}
int main()
{


    for(int s=0;s<(1<<n);s++)


    for(int s=0;s<(1<<n);s++)
        for(int t=s;t;t=(t-1)&s)


	return 0;
}


