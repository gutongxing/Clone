#include <cstdio>
#include <cstring>
#include <algorithm>

constexpr int N = 50005;

struct LinkCutTree {
	bool rev[N];
	int fa[N],ch[N][2];
	int val[N],mx[N];

	#define ls(x) (ch[x][0])
	#define rs(x) (ch[x][1])
	#define dir(x) (x == ch[fa[x]][1])
	#define IsRoot(x) (x != ch[fa[x]][0] && x != ch[fa[x]][1])

	inline void PushUp(int x) {
		mx[x] = x;
		if(ls(x) && val[mx[ls(x)]] > val[mx[x]]) mx[x] = mx[ls(x)];
		if(rs(x) && val[mx[rs(x)]] > val[mx[x]]) mx[x] = mx[rs(x)];
	}

	inline void PushDown(int x) {
		if(rev[x]) {
			if(ls(x)) std::swap(ls(ls(x)),rs(ls(x))),rev[ls(x)] ^= 1;
			if(rs(x)) std::swap(ls(rs(x)),rs(rs(x))),rev[rs(x)] ^= 1;
			rev[x] = 0;
		}
	}

	void update(int x) {
		if(!IsRoot(x)) update(fa[x]);
		PushDown(x);
	}

	inline void rotate(int x) {
		int y = fa[x],z = fa[y],d = dir(x),w = ch[x][d ^ 1];
		if(!IsRoot(y)) ch[z][dir(y)] = x;
		ch[y][d] = w,ch[x][d ^ 1] = y;
		fa[y] = x,fa[x] = z;
		if(w) fa[w] = y;
		PushUp(y);
	}

	inline void splay(int x) {
		update(x);
		while(!IsRoot(x)) {
			int y = fa[x],z = fa[y];
			if(!IsRoot(y))
				rotate((ls(y) == x) ^ (ls(z) == y) ? x : y);
			rotate(x);
		}
		PushUp(x);
	}

	inline void access(int x) {
		for(int p = 0;x;p = x,x = fa[x])
			splay(x),rs(x) = p,PushUp(x);
	}

	inline void MakeRoot(int x) {
		access(x),splay(x);
		std::swap(ls(x),rs(x)),rev[x] ^= 1;
	}

	inline int FindRoot(int x) {
		access(x),splay(x);
		while(ls(x)) PushDown(x),x = ls(x);
		splay(x);
		return x;
	}

	inline void split(int x,int y) {
		MakeRoot(x),access(y),splay(y);
	}

	inline void link(int x,int y) {
		MakeRoot(x); fa[x] = y;
	}
}T;

int main() {
	int n,m,ecnt = 0;
	scanf("%d%d",&n,&m);
	int res = 0;
	for(int i = 1;i <= m;++i) {
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		if(u == v) continue;
		T.val[i + n] = w;
		T.MakeRoot(u);
		if(u != T.FindRoot(v)) {
			T.link(i + n,u),T.link(i + n,v);
			++ecnt;
			res += w;
		}
		else {
			T.split(u,v);
			int ep = T.mx[v];
			if(w < T.val[ep]) {
				T.splay(ep);
				T.fa[T.ch[ep][0]] = T.fa[T.ch[ep][1]] = 0;
				T.link(i + n,u);
				T.link(i + n,v);
				res -= T.val[ep];
				res += w;
			}
		}
		if(ecnt == n - 1) printf("%d\n",res);
		else puts("0");
	}
	return 0;
}

