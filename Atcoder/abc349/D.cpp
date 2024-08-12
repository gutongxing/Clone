#include<bits/stdc++.h>
using namespace std;
const int MAXN = 500;
int n,m,p,bj[MAXN][MAXN];
int b[MAXN][MAXN];
char a[MAXN][MAXN];
struct node{
	int x,y,e;
}S,T;
int mp[MAXN][MAXN];
queue<node> q;
void push(int x,int y,int e){
	if(x<1||y<1) return;
	if(x>n||y>m) return;
	if(a[x][y]=='#') return;
	if(bj[x][y]) e = max(e,b[x][y]);
	if(e==-1) return;
	if(mp[x][y]>=e) return;
	mp[x][y] = e;
	q.push({x,y,e});
}
signed main(){
//	freopen("room.in","r",stdin);
//	freopen("room.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1;i<=n;i++){
		scanf("%s",a[i]+1);
		for(int j = 1;j<=m;j++){
			mp[i][j] = -1;
			if(a[i][j]=='S'){
				S.x = i;
				S.y = j;
				S.e = 0;
			}else if(a[i][j]=='T'){
				T.x = i;
				T.y = j;
			}
		}
	}
	scanf("%d",&p);
	for(int i = 1;i<=p;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		b[x][y] = z;
		bj[x][y] = 1;
	}
	push(S.x,S.y,-1);
	while(!q.empty()){
		auto x = q.front();q.pop();
		if(x.x == T.x&&x.y == T.y){
			puts("Yes");
			return 0;
		}
		push(x.x-1,x.y,x.e-1);
		push(x.x+1,x.y,x.e-1);
		push(x.x,x.y-1,x.e-1);
		push(x.x,x.y+1,x.e-1);
	}
	printf("No");
	return 0;
}
