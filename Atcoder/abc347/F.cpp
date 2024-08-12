#include<bits/stdc++.h>
using namespace std;
int T,n;
int a[100][100];
int r[100][100];
int d[100][100];
int f[100][100];
struct node{
	int x,y,profit,step;
};
queue<node> pq;
void add(int x,int y,int profit,int step){
	if(x<0) return;
	if(y<0) return;
	if(x>n) return;
	if(y>n) return;
	if(profit<0) return;
	if(f[x][y]>=profit) return;
	f[x][y] = profit;
	pq.push({x,y,profit,step});
}
signed main(){
	memset(f,-1,sizeof(f));
	scanf("%d",&n);
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			scanf("%d",a[i]+j);
		}
	}
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<n;j++){
			scanf("%d",r[i]+j);
		}
	}
	for(int i = 1;i<n;i++){
		for(int j = 1;j<=n;j++){
			scanf("%d",d[i]+j);
		}
	}
	add(1,1,0,0);
	while(!pq.empty()){
		node x = pq.front();
		bool tmp = a[x.x][x.y];
		pq.pop();
		if(x.x==n&&x.y==n){
			printf("%d",x.step);
			break;
		}
		add(x.x,x.y+1,x.profit-r[x.x][x.y],x.step+1);
		add(x.x+1,x.y,x.profit-d[x.x][x.y],x.step+1);
		add(x.x,x.y,x.profit+a[x.x][x.y],x.step+1);
	}
	return 0;
}
/*
3
2 2
00
10
2 2
01
11
2 2
01
11

*/
