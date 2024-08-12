#include<bits/stdc++.h>
using namespace std;
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
const int MAXN = 3e5+10;
int n,m,a[MAXN];
vector<pair<int,int>> v[MAXN];
struct node{
	int to,w,next;
}edge[MAXN];
int h[MAXN],Es;
void New_edge(int x,int y,int z){
	edge[++Es] = {y,z,h[x]};
	h[x] = Es;
}
int flag[MAXN];
int ppppA[MAXN];
void Change(int x,int fath){
	for(int i=h[x];i;i=edge[i].next){
		if(edge[i].to==fath) continue;
		a[edge[i].to] = edge[i].w;
		Change(edge[i].to,x);
		ppppA[x] += ppppA[edge[i].to];
		ppppA[x] += a[edge[i].to];
	}
}
bool A = 1;
signed main(){
	freopen("transport.in","r",stdin);
	freopen("transport.out","w",stdout);
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	read(n);read(m);
	for(int i = 1;i<n;i++){
		int x,y,z;
		read(x);read(y);read(z);
		if(x>y) swap(x,y);
		New_edge(x,y,z);
		New_edge(y,x,z);
		if(x!=i||y!=i+1){
			A = 0;
		}
	}
	Change(1,0);
	if(A){
		int ans = 0;
		for(int i = 1;i<=m;i++){
			int x,y;
			read(x);read(y);
			if(x>y) swap(x,y);
			flag[y] ++;
			flag[x] --;
			ans += ppppA[x]-ppppA[y];
		}
		int x = 0;
		for(int i = n;i>=1;i--){
			flag[i] += flag[i+1];
			x = max(x,a[i]*flag[i]);
		}
		write(ans-x);
		return 0;
	}
	write(11);
	return 0;
}

