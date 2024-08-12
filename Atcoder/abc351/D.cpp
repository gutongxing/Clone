#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1200;
int n,m,maxn;bool vis[MAXN][MAXN];
int sum[MAXN][MAXN];
char a[MAXN][MAXN];
bool aply(int x,int y){
	return
	(x==1||a[x-1][y]!='#')&&
	(x==n||a[x+1][y]!='#')&&
	(y==1||a[x][y-1]!='#')&&
	(y==m||a[x][y+1]!='#');
}
int dfs(int x,int y){
	if(a[x][y]=='#') return 0;
	if(vis[x][y]) return sum[x][y];
	vis[x][y] = 1;
	sum[x][y] = 0;
	return sum[x][y] = ((y!=1&&(aply(x,y-1)||aply(x,y))?(aply(x,y-1)?dfs(x,y-1):1):0)+1)
	;
}
signed main(){
	scanf("%d%d",&n,&m);
	for(int i = 1;i<=n;i++){
		scanf("%s",a[i]+1);
	}
	for(int i = 1;i<=n;i++){
		int ddd[MAXN] = {0},mmm[MAXN]={0}; 
		for(int j = 1;j<=m;j++){
			if(!vis[i][j]){
				dfs(i,j);
			}
			ddd[j]=((i!=1&&(aply(i-1,j)||aply(i,j))?(aply(i-1,j)?dfs(i-1,j):1):0));
			maxn = max(maxn,sum[i][j]+ddd[j]);
		}
		for(int j = 1;j<=m;j++){
			sum[i][j]+=ddd[j];mmm[j] = sum[i][j];
		}
		for(int j = m-1;j>=1;j--){
			if(aply(i,j+1))sum[i][j] = sum[i][j+1];
			else sum[i][j] = mmm[j+1];
			cout << i << " " << j << " " << sum[i][j]+ddd[j] << endl;
		}
	}
	printf("%d",maxn);
	return 0;
}

