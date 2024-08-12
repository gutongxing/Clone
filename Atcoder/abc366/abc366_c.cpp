// Problem: C - Balls and Bag Query
// Contest: AtCoder - AtCoder Beginner Contest 366
// URL: https://atcoder.jp/contests/abc366/tasks/abc366_c
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
//#define int long long
namespace gtx{
//	Fast IO
	void read(int &x){
		x = 0;int h = 1;char tmp;
		do{tmp=getchar();if(tmp=='-')h*=-1;}while(!isdigit(tmp));
		while(isdigit(tmp)) x*=10,x+=tmp-'0',tmp=getchar();
		x*=h;
	}
	void read(char &x){do{x=getchar();}while(x==' '||x=='\n'||x=='\r');}
	void write(char x){putchar(x);}
	void write(int x){
		if(x<0) putchar('-'),x=-x;int st[200]={0},tot=0;
		do{st[++tot]=x%10,x/=10;} while(x);
		while(tot){putchar(st[tot--]+'0');};
	}
	void write(int x,char y){write(x);write(y);}
	const int MAXN = 3e5+10;
	struct SPLAY{
		int son[2],all;
		int num,sum,fath;
	}tree[MAXN];
	int root,cnt;
	void pushup(int id){
		tree[id].all = tree[tree[id].son[0]].all+tree[tree[id].son[1]].all+1;
	}
	void rotate(int id){
		int is = tree[tree[id].fath].son[1]==id;
		int fath = tree[id].fath;
		if(tree[id].fath){
			int k = tree[tree[tree[id].fath].fath].son[1]==tree[id].fath;
			tree[tree[tree[id].fath].fath].son[k] = id;
			tree[id].fath = tree[tree[id].fath].fath;
		}
		tree[fath].son[is] = tree[id].son[is^1];
		tree[tree[id].son[is^1]].fath = fath;
		tree[id].son[is^1] = fath;
		tree[fath].fath = id;
		pushup(fath);
		pushup(id);
	}
	void splay(int x,int y){
		while(tree[x].fath!=y){
			int p = tree[x].fath;
			if(tree[p].fath==y){
				rotate(x);
			}else{
				if((tree[p].son[1]==x)==(tree[tree[p].fath].son[1]==p)) rotate(p);
				else rotate(x);
				rotate(x);
			}
		}
		if(!y) root = x;
	}
	void insert(int x){
		int now = root,fath = 0,k;
		stack<int> st;
		while(now){
			st.push(now);
			if(tree[now].num==x){
				tree[now].sum++;
				while(!st.empty()){
					int k = st.top();st.pop();
					pushup(k);
				}
				splay(now,0);
				return;
			}
			if(tree[now].num>x){
				fath = now;k = 0;
				now = tree[now].son[0];
			}else{
				fath = now;k = 1;
				now = tree[now].son[1];
			}
		}
		now = ++cnt;
		if(fath){
			tree[now].fath = fath;
			tree[fath].son[k] = now;
		}else root = now;
		tree[now].num = x;
		tree[now].sum = 1;
		tree[now].all = 1;
		while(!st.empty()){
			int k = st.top();st.pop();
			pushup(k);
		}
		splay(now,0);
	}
	void find(int x){
		int now = root;
		while(now){
			if(tree[now].num==x) break;
			if(tree[now].num>x) now = tree[now].son[0];
			else now = tree[now].son[1];
		}
		splay(now,0);
	}
	void Delete(int x){
		find(x);
		if(!(--tree[root].sum)){
			tree[tree[root].son[0]].fath = 0;
			tree[tree[root].son[1]].fath = 0;
			if(tree[root].son[0]){
				int k = tree[root].son[1];
				int now = tree[root].son[0],fath=0;
				while(now){
					fath = now;
					now = tree[fath].son[1];
				}
				splay(fath,0);
				tree[fath].son[1] = k;
				tree[k].fath = fath;
				tree[root].all += tree[k].all;
			}else root = tree[root].son[1];
		}
	}
	int pre(int k){
		insert(k);
		find(k);
		int now = tree[root].son[0];
		int fath = 0;
		while(now){
			fath = now;
			now = tree[now].son[1];
		}
		int ans = tree[fath].num;
		Delete(k);
		return ans;
	}
	int suc(int k){
		insert(k);
		find(k);
		int now = tree[root].son[1];
		int fath = 0;
		while(now){
			fath = now;
			now = tree[now].son[0];
		}
		int ans = tree[fath].num;
		Delete(k);
		return ans;
	}
	int Rank(int k){
		insert(k);
		find(k);
		int ans = tree[tree[root].son[0]].all+1;
		Delete(k);
		return ans;
	}
	int kth(int k){
		int now = root;
		while(now){
			if(tree[tree[now].son[0]].all<k){
				if(tree[tree[now].son[0]].all+tree[now].sum>=k) return tree[now].num;
				k -= tree[tree[now].son[0]].all+tree[now].sum; 
				now = tree[now].son[1];
			}
			else now = tree[now].son[0];
		}
		return -1;
	}
	signed main(){
		int q;
		read(q);
		while(q--){
			int tp,x;
			read(tp);
			switch(tp){
			case 1:{
				read(x);
				insert(x);
				break;
			}
			case 2:{
				read(x);
				Delete(x);
				break;
			}
			case 3:{
				write(tree[root].all,'\n');
			}
			}
		}
		return 0;
	}
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T = 1;
//	gtx::read(T);
	while(T--) gtx::main();
	return 0;
}
