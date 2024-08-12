#include<bits/stdc++.h>
using namespace std;
const int MAXN = 3e5+10;
void read(int &x){
	x = 0;int p = 1;char ch;
	do{
		ch = getchar();
		if(ch=='-') p = -1;
	}while(!isdigit(ch));
	while(isdigit(ch)){
		x*=10;
		x+=ch-'0';
		ch = getchar();
	}
	x*=p;
}
void read(char &x){
	x = getchar();
	while(x==' '||x=='\n'||x=='\r') x = getchar();
}
void write(char x){
	putchar(x);
}
void write(int k){
	if(k<0) putchar('-');
	k = abs(k);
	stack<int> num;
	do{
		num.push(k%10);
		k/=10;
	}while(k);
	while(!num.empty()){
		putchar(num.top()+48);
		num.pop();
	}
}
class Segmnetree{
private:
	struct segmenttree{
		int l,r,maxn;
	}tree[MAXN<<3];
	void pushup(int k){
		tree[k].maxn = max(tree[k*2].maxn,tree[k*2+1].maxn);
	}
public:
	void build(int k,int l,int r){
		tree[k].l = l;
		tree[k].r = r;
		tree[k].maxn = 0;
		if(l==r) return;
		int mid = (l+r)>>1;
		build(k*2,l,mid);
		build(k*2+1,mid+1,r);
	}
	void change(int k,int x,int y){
		if(tree[k].l>x||tree[k].r<x) return;
		if(tree[k].l>=x&&tree[k].r<=x){
			tree[k].maxn = y;
			return;
		}
		change(k*2,x,y);
		change(k*2+1,x,y);
		pushup(k);
	}
	int maxn(int k,int l,int r){
		if(l>r) return 0;
		if(tree[k].l>r||tree[k].r<l) return 0;
		if(tree[k].l>=l&&tree[k].r<=r) return tree[k].maxn;
		return max(maxn(k*2,l,r),maxn(k*2+1,l,r));
	}
}tree1,tree2;
class DSU{
private:
	int fath[MAXN*2],sz[MAXN*2],end[MAXN*2];
public:
	int get_father(int x){
		if(x==fath[x]) return x;
		return fath[x] = get_father(fath[x]);
	}
	void init(int x){
		for(int i = 1;i<=x;i++){
			fath[i] = i;
			sz[i] = 0;
			end[i] = 0;
		}
	}
	bool merge(int x,int y){
		int fx = get_father(x);
		int fy = get_father(y);
		if(fx==fy) return false;
		fath[fy] = fx;
		sz[fx] += sz[fy];
		end[fx] = end[fy];
		return true;
	}
	void add(int x){
		sz[get_father(x)]++;
	}
	void set(int x,int y){
		end[get_father(x)] = y;
	}
	int val(int x){
		return end[get_father(x)];
	}
	int get(int x){
		return sz[get_father(x)];
	}
}dsu;
struct node{
	int x,y,id;
}a[MAXN],b[MAXN];
bool cmp_xx(node a,node b){
	return a.x<b.x;
}
bool cmp_x(node a,node b){
	return a.x<=b.x;
}
bool cmp_y(node a,node b){
	return a.y==b.y?a.id<b.id:a.y<b.y;
}
bool cmp_id(node a,node b){
	return a.id<b.id;
}
int T,n,m,to[2][MAXN];
bitset<MAXN*2> vis;
void dfs(int s,int k,int fa){
	if(!s) dsu.add(s*n+k);
	vis[s*n+k] = 1;
	if(to[s][k]==0){
		dsu.set(s*n+k,s+1);
		return;
	}
	if(dsu.merge(s*n+k,(s^1)*n+to[s][k])){
		if(!vis[(s^1)*n+to[s][k]]) dfs(s^1,to[s][k],k);
	}else{
		dsu.set(s*n+k,-1);
	}
}
int mapping[MAXN];
signed main(){
	read(T);
	while(T--){
		read(n);
		for(int i = 1;i<=n;i++) read(a[i].x);
		for(int i = 1;i<=n;i++) read(a[i].y);
		tree1.build(1,1,n);
		sort(a+1,a+1+n,cmp_xx);
		for(int i = 1;i<=n;i++) tree1.change(1,i,a[i].y);
		read(m);
		for(int i = 1;i<=m;i++) read(b[i].x);
		for(int i = 1;i<=m;i++) read(b[i].y);
		tree2.build(1,1,m);
		sort(b+1,b+1+m,cmp_xx);
		for(int i = 1;i<=m;i++) tree2.change(1,i,b[i].y);
		dsu.init(n+m);int tmp[MAXN]={0};
		for(int i = 1;i<=n;i++) a[i].id = i;
		for(int i = 1;i<=m;i++) b[i].id = i;
		for(int i = 1;i<=n;i++) tmp[i] = lower_bound(b+1,b+1+m,(node){a[i].y,a[i].x},cmp_x)-b;
		for(int i = 1;i<=n;i++) to[0][i] = tree2.maxn(1,tmp[i],m);
		sort(b+1,b+1+m,cmp_y);
		for(int i = 1;i<=n;i++) to[0][i] = to[0][i]?b[lower_bound(b,b+1+m,(node){0,to[0][i],tmp[i]},cmp_y)-b].id:0;
		sort(b+1,b+1+m,cmp_id);
		for(int i = 1;i<=m;i++) tmp[i] = lower_bound(a+1,a+1+n,(node){b[i].y,b[i].x},cmp_x)-a;
		for(int i = 1;i<=m;i++) to[1][i] = tree1.maxn(1,tmp[i],n);
		sort(a+1,a+1+n,cmp_y);
		for(int i = 1;i<=m;i++) to[1][i] = to[1][i]?a[lower_bound(a,a+1+n,(node){0,to[1][i],tmp[i]},cmp_y)-a].id:0;
		sort(a+1,a+1+n,cmp_id);
		for(int i = 1;i<=n+m;i++) vis[i] = 0;
		for(int i = 1;i<=n;i++) if(!vis[i]) dfs(0,i,0);
		for(int i = 1;i<=m;i++) if(!vis[i+n]) dfs(1,i,0);
		int ans1 = 0,ans2 = 0,ans3 = 0;
		for(int i = 1;i<=n+m;i++) if(dsu.get_father(i)==i) switch(dsu.val(i)){case 1:{ans1+=dsu.get(i);break;}case 2:{ans3+=dsu.get(i);break;}case -1:{ans2+=dsu.get(i);break;}};
		write(ans1);write(' ');write(ans2);write(' ');write(ans3);write('\n');
	}
	return 0;
}
