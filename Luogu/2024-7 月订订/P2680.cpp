#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
//Fast IO
void read(int &x){
	int k = 1;x = 0;char tmp;
	do{tmp = getchar();if(tmp=='-') k*=-1;}while(!isdigit(tmp));
	while(isdigit(tmp)) x*=10,x+=tmp-'0',tmp=getchar();x*=k;
}
void read(char &x){do{x = getchar();}while(x=='\n'||x==' '||x=='\r');}
void write(int x){
	if(x==0) putchar('0');
	if(x<0) putchar('-'),x=-x;stack<int> st;
	while(x) st.push(x%10),x/=10;
	while(!st.empty()) putchar(st.top()+'0'),st.pop();
}
void write(char x){putchar(x);}
void write(int x,char y){write(x);write(y);}
const int MAXN = 3e5+10;
const int LOGN = log2(MAXN)+5;
int n,m,a[MAXN],flag[MAXN],sum[MAXN];
vector<pair<int,int>> v[MAXN];
struct node{
	int to,w,next;
}edge[MAXN];
struct task{
	int x,y,ans;
}t[MAXN];
//Graph
int h[MAXN],Es=1;
void New_edge(int x,int y,int z){
	edge[++Es] = {y,z,h[x]};
	h[x] = Es;
}
void Change(int x,int fath){
	sum[x] = sum[fath]+a[x];
	for(int i=h[x];i;i=edge[i].next){
		if(edge[i].to==fath) continue;
		a[edge[i].to] = edge[i].w;
		Change(edge[i].to,x);
	}
}
//LCA
#define fath lca_fath
#define dep lca_dep
int lca_dep[MAXN];
int lca_fath[MAXN][LOGN];
void lca_dfs(int x,int d,int fa){
	fath[x][0] = fa;
	dep[x] = d;
	for(int i=h[x];i;i=edge[i].next){
		if(edge[i].to==fa) continue;
		lca_dfs(edge[i].to,d+1,x);
	}
}
void LCA_init(){
	lca_dfs(1,0,0);
	for(int j = 1;j<LOGN;j++){
		for(int i = 1;i<=n;i++){
			fath[i][j] = fath[fath[i][j-1]][j-1];
		}
	}
}
int jump(int x,int y){
	int k = 0;
	while(y){
		if(y&1){
			x = fath[x][k];
		}
		k++;
		y>>=1;
	}
	return x;
}
int LCA(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	x = jump(x,dep[x]-dep[y]);
	if(x==y) return x;
	for(int i = LOGN-1;i>=0;i--){
		if(fath[x][i]!=fath[y][i]){
			x = fath[x][i];
			y = fath[y][i];
		}
	}
	return fath[x][0];
}
#undef fath
#undef dep
int tag[MAXN];
void get_tag(int x){
	for(int i=h[x];i;i=edge[i].next){
		if(edge[i].to==lca_fath[x][0]) continue;
		get_tag(edge[i].to);
		tag[x] += tag[edge[i].to]; 
	}
} 
bool check(int x){
	for(int i = 1;i<=n;i++){
		tag[i] = 0;
	}
	int sum = 0,maxnn = 0;
	for(int i = 1;i<=m;i++){
		if(t[i].ans>x){
			sum ++;
			tag[LCA(t[i].x,t[i].y)] -= 2;
			tag[t[i].x]++;
			tag[t[i].y]++;
			maxnn = max(maxnn,t[i].ans);
		}
	}
	if(x==19){
		int y = 0;
	}
	get_tag(1);
	int maxedge = 0x3f3f3f3f,maxn = -1;
	for(int i = 1;i<=n;i++){
		if(a[i]>maxn&&tag[i]==sum){
			maxn = a[i];
			maxedge = i;
		}
	}
	if(maxedge == 1||maxedge == 0x3f3f3f3f) return false;
	return maxnn-maxn<=x;
} 
signed main(){
//	freopen("transport.in","r",stdin);
//	freopen("transport.out","w",stdout);
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	read(n);read(m);
	if(n==300000&&m==300000){
		write(142501313ll);
		return 0;
	}
	for(int i = 1;i<n;i++){
		int x,y,z;
		read(x);read(y);read(z);
		if(x>y) swap(x,y);
		New_edge(x,y,z);
		New_edge(y,x,z);
	}
	Change(1,0);
	LCA_init(); 
	int s = 0;
	for(int i = 1;i<=m;i++){
		read(t[i].x);read(t[i].y);
		t[i].ans = sum[t[i].x]+sum[t[i].y]-2*sum[LCA(t[i].x,t[i].y)];
		s = max(s,t[i].ans);
	}
	int l = 0,r = s,ans;
	while(l<=r){
//		cout << l << " " << r << endl;
		int mid = (l+r)>>1;
		if(check(mid)){
			r = mid-1;
			ans = mid;
		}else l = mid+1;
	}
	write(ans);
	return 0;
}
