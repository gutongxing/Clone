#include<bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
#define endl '\n'
//#define int long long
void read(int &x){
	int k = 1;x = 0;char tmp;
	do{tmp = getchar();if(tmp=='-') k*=-1;}while(!isdigit(tmp));
	while(isdigit(tmp)) x*=10,x+=tmp-'0',tmp=getchar();x*=k;
}
void read(char &x){do{x = getchar();}while(x=='\n'||x==' '||x=='\r');}
void write(int x){
	if(x<0) putchar('-'),x=-x;stack<int> st;
	while(x) st.push(x%10),x/=10;
	while(!st.empty()) putchar(st.top()+'0'),st.pop();
}
void write(char x){putchar(x);}
void write(int x,char y){write(x);write(y);}
const int MAXN = 1e5+10;
//Normaly
int n,m,q;
vector<int> v[MAXN];
//BFS
int need[MAXN][2];
void bfs(){
	memset(need,0x3f,sizeof(need)); 
	queue<pair<pair<int,int>,int>> q;
	q.push({{1,0},0});
	need[1][0] = 0;
	while(!q.empty()){
		int x = q.front().first.first;
		int y = q.front().first.second;
		int d = q.front().second;
		q.pop();
		for(int i:v[x]){
			if(need[i][!y]==INF){
				need[i][!y] = d+1;
				q.push({{i,!y},d+1});
			}
		}
	}
}
signed main(){
	freopen("work.in","r",stdin);
	freopen("work.out","w",stdout);
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	read(n);read(m);read(q);
	for(int i = 1;i<=m;i++){
		int U,V;
		read(U);read(V);
		v[U].push_back(V);
		v[V].push_back(U);
	}
	bfs();
	for(int i = 1;i<=q;i++){
		int x,y;
		read(x);read(y);
		if(y>=need[x][y&1]) puts("Yes");
		else puts("No");
	}
	return 0;
}

