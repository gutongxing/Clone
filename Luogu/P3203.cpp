#include<bits/stdc++.h>
using namespace std;
const int MAXN = 4e5+10;
struct SPLAY{
	int son[2],sum;
	int fath,val;
	bool tag;
}tree[MAXN];
int n,m;
map<pair<int,int>,bool> mp;
inline void pushup(int id){
	tree[id].sum = tree[tree[id].son[0]].sum+tree[id].val+tree[tree[id].son[1]].sum;
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
inline void splay(int x){
	while(real(x)){//实边 
		int p = tree[x].fath;
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
int p[MAXN];
signed main(){
	read(n);
	for(int i = 1;i<=n;i++) tree[i].val = tree[i].sum = 1;
	for(int i = 1;i<=n;i++){
		read(p[i]);
		tree[i].fath = i+p[i]; 
	}
	read(m);
	for(int i = 1;i<=m;i++){
		int op;
		read(op);
		if(op==1){
			int x;
			read(x);x++;
			Access(x);splay(x);
			write(tree[x].sum);putchar('\n');
		}else{
			int x,y;
			read(x);read(y);x++;
			Access(x);splay(x);
			tree[x].son[0] = tree[tree[x].son[0]].fath = 0;p[x] = y;
			tree[x].fath = p[x]+x;
		}
	}
	return 0;
}
