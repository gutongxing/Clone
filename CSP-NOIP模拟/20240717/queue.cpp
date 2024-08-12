#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
//#define int long long
//Fast IO
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
int n,m,q;
namespace Subtask1{
	int a[1010][1010],p[1010][1010];
	signed main(){
		int cnt = 0;
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=m;j++){
				p[i][j] = ++cnt;
			}
		}
		while(q--){
			int x,y;
			read(x);read(y);
			int id = p[x][y];
			write(id,'\n');
			for(int i = y;i<m;i++){
				p[x][i] = p[x][i+1];
			}
			for(int j = x;j<n;j++){
				p[j][m] = p[j+1][m];
			}
			p[n][m] = id;
//			for(int i = 1;i<=n;i++){
//				for(int j = 1;j<=m;j++){
//					cout << p[i][j] << " ";
//				}
//				cout << endl;
//			}
		}
		return 0;
	} 
}
namespace Subtask2{
	int random(){
		return rand()*rand()/rand();
	}
	class FHQ_treap{
		private:
			struct node{
				int lson,rson,sum,suma,val,pri,id;
			}tree[500010];
			int tot = 0;
		public:
			int new_node(int val,int id){
				tree[++tot].val = val;
				tree[tot].id = id;
				tree[tot].pri = random();
				tree[tot].sum = 1;
				return tot;
			}
			void pushup(int k){
				tree[k].sum = tree[tree[k].lson].sum + tree[tree[k].rson].sum + 1;
			}
			int merge(int lroot,int rroot){
				if(!lroot||!rroot) return lroot|rroot;
				if(tree[lroot].pri<tree[rroot].pri){
					tree[rroot].lson = merge(lroot,tree[rroot].lson);
					pushup(rroot);
					return rroot;
				}else{
					tree[lroot].rson = merge(tree[lroot].rson,rroot);
					pushup(lroot);
					return lroot;
				}
			}
			void split(int root,int sum,int &lroot,int &rroot){
				if(!root){
					lroot = 0;
					rroot = 0;
					return;
				}
				if(tree[root].val<=sum){
					lroot = root;
					split(tree[root].rson,sum,tree[root].rson,rroot);
					pushup(lroot);
				}else{
					rroot = root;
					split(tree[root].lson,sum,lroot,tree[root].lson);
					pushup(rroot);
				}
			}
			int root = 0;
			void insert(int x,int id){
				int lroot,rroot;
				split(root,x,lroot,rroot);
				root = merge(lroot,merge(new_node(x,id),rroot));
			}
			void erase(int x){
				int lroot,rroot,llroot;
				split(root,x,lroot,rroot);
				split(lroot,x-1,llroot,lroot);
				lroot = merge(tree[lroot].lson,tree[lroot].rson);
				merge(llroot,merge(lroot,rroot));
			}
			pair<int,int> kth(int x){
				int now = root;
				while(now){
					if(tree[tree[now].lson].sum>=x){
						now = tree[now].lson;
					}else if(tree[tree[now].lson].sum+1==x) return {tree[now].val,tree[now].id};
					else now = tree[now].rson,x-=tree[tree[now].lson].sum+1;
				}
				return {0,0}; 
			}
	}fhq;
	signed main(){
		int sum = 0;
		for(int i = 1;i<=m;i++){
			fhq.insert(++sum,i);
		}
		for(int i = 1;i<=q;i++){
			int x,y;
			read(y);read(x);
			auto tmp = fhq.kth(x);
			write(tmp.second,'\n');
			fhq.erase(tmp.first);
			fhq.insert(++sum,tmp.second);
		}
		return 0;
	}
}
signed main(){
	freopen("queue.in","r",stdin);
	freopen("queue.out","w",stdout);
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	srand(time(0));	
	read(n);read(m);read(q);
	if(n<=1e3&&m<=1e3) return Subtask1::main();
	if(n==1) return Subtask2::main();
	return 0;
}

