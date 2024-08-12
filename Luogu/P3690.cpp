#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 3e5+10;
struct SPLAY{
	int son[2],sum;
	int fath,val;
	bool tag;
}tree[MAXN];
inline void pushup(int id){
	tree[id].sum = tree[tree[id].son[0]].sum^tree[id].val^tree[tree[id].son[1]].sum;
}
inline void maketag(int id){
	if(!id) return;
	swap(tree[id].son[0],tree[id].son[1]);
	tree[id].tag = 1;
}
inline void pushdown(int id){
	if(tree[id].tag){
		tree[id].tag = 0;
		maketag(tree[id].son[0]);
		maketag(tree[id].son[1]);
	}
}
inline bool real(int x){//x与父亲之间的连边是否为实边 
	return x&&((tree[tree[x].fath].son[0]==x)||(tree[tree[x].fath].son[1]==x))&&tree[x].fath;
}
inline void rotate(int id){
	int is = tree[tree[id].fath].son[1]==id;
	int fath = tree[id].fath;
	if(real(fath)){
		int k = tree[tree[fath].fath].son[1]==fath;
		tree[tree[fath].fath].son[k] = id;
	}
	tree[id].fath = tree[fath].fath;
	tree[fath].son[is] = tree[id].son[is^1];
	tree[tree[id].son[is^1]].fath = fath;
	tree[id].son[is^1] = fath;
	tree[fath].fath = id;
	pushup(fath);
	pushup(id);
}
inline void PUSH_DOWN(int x){
	stack<int> st;
	while(x){
		st.push(x);
		x = tree[x].fath;
	}
	while(!st.empty()){
		pushdown(st.top());
		st.pop();
	}
}
inline void splay(int x){
	PUSH_DOWN(x);
	while(real(x)){//实边 
		int p = tree[x].fath;
		pushdown(p);
		pushdown(x);
		if(!real(p)){//虚边 
			rotate(x);
		}else{
			if((tree[p].son[1]==x)==(tree[tree[p].fath].son[1]==p)) rotate(p);
			else rotate(x);
			rotate(x);
		}
	}
}
inline void Access(int x){
	int y = 0;
	while(x){
		splay(x);
		tree[x].son[1] = y;
		pushup(x);
		y = x;
		x = tree[x].fath;
	}
}
inline void Evert(int x){
	Access(x);
	splay(x);
	maketag(x);
}
inline int Find_Root(int x){
	Access(x);
	splay(x);
	int now = x,tmp = x;
	while(now){
		pushdown(now);
		tmp = now;
		now = tree[now].son[0];
	}
	splay(tmp);
	return tmp;
}
inline void Link(int x,int y){
	Evert(x);
	tree[x].fath = y;
}
inline void Cut(int x,int y){
	Evert(x);
	Access(y);
	splay(y);
	tree[y].son[0] = tree[x].fath = 0;
}
inline int Ask(int x,int y){
	Evert(x);
	Access(y);
	splay(y);
	return tree[y].sum;
}
inline void Change(int x,int y){
	Evert(x);
	tree[x].val = y;
	pushup(x);
}
int n,m;
map<pair<int,int>,bool> mp;
inline void read(int &x){
	x = 0;
    int f = 1;
    char ch = getchar();
    while(!isdigit(ch)){
        if(ch == '-') f = -1;
        ch = getchar();
    }
    while(isdigit(ch)){
    	x = x*10+ch-'0';
		ch=getchar();
	}
    x*=f;
}
void write(int x) {
	stack<int> st;
	do{
	st.push(x%10);x /= 10;
	}while(x);
	while(!st.empty()){
		putchar(st.top() + 48);
		st.pop();
	}
}
signed main(){
	freopen("P3690_7.in","r",stdin);
	freopen("P3690_7.ans","w",stdout);
	read(n);read(m);
	for(int i = 1;i<=n;i++){
		int x;
		read(x);
		Change(i,x);
	}
	for(int i = 1;i<=m;i++){
		int opt,x,y;
		read(opt);read(x);read(y);
		switch(opt){
		case 0:{
			write(Ask(x,y));
			puts("");
			break;
		}
		case 1:{
			int k = min(x,y),p = max(x,y);
			x = k;y = p;
			if(Find_Root(x)!=Find_Root(y)){
				Link(x,y);
				mp[{x,y}] = 1;
			}
			break;
		}
		case 2:{
			int k = min(x,y),p = max(x,y);
			x = k;y = p;
			auto tmp = mp.find({x,y});
			if(tmp!=mp.end()){
				Cut(x,y);
				mp.erase(tmp);
			}
			break;
		}
		case 3:{
			Change(x,y);
			break;
		}
		}
	}
	return 0;
}
