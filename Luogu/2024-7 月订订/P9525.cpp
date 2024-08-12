#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
//#define int long long
const int MAXN = 3e5+10;
int n,a[MAXN],b[MAXN],c[MAXN];
namespace SUBTASK100pts{
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
	struct node{
		int a,b,c,i;
	}t[MAXN];
	struct cmpa{
		bool operator ()(const node a,const node b){
			return !(a.a>b.a);
		}
	};
	struct cmpb{
		bool operator ()(const node a,const node b){
			return !(a.b>b.b);
		}
	};
	struct cmpc{
		bool operator ()(const node a,const node b){
			return !(a.c>b.c);
		}
	};
	priority_queue<node,vector<node>,cmpa>pqa;
	priority_queue<node,vector<node>,cmpb>pqb;
	priority_queue<node,vector<node>,cmpc>pqc;
	bitset<MAXN> vis;
	signed main(){
		for(int i = 1;i<=n;i++){
			pqa.push({a[i],b[i],c[i],i});
			pqb.push({a[i],b[i],c[i],i});
			pqc.push({a[i],b[i],c[i],i});
		}
		while(!pqa.empty()&&!pqb.empty()&&!pqc.empty()){
			auto tmpa = pqa.top();
			auto tmpb = pqb.top();
			auto tmpc = pqc.top();
			if(tmpa.b==tmpb.b) vis[tmpa.i] = 1;
			if(tmpa.c==tmpc.c) vis[tmpa.i] = 1;
			if(tmpb.a==tmpa.a) vis[tmpb.i] = 1;
			if(tmpb.c==tmpc.c) vis[tmpb.i] = 1;
			if(tmpc.a==tmpa.a) vis[tmpc.i] = 1;
			if(tmpc.b==tmpb.b) vis[tmpc.i] = 1;
			if(!vis[tmpa.i]&&!vis[tmpb.i]&&!vis[tmpc.i]){
				write(tmpa.a+tmpb.b+tmpc.c);
				return 0;
			}
			if(!pqa.empty()&&vis[tmpa.i]) pqa.pop();
			if(!pqb.empty()&&vis[tmpb.i]) pqb.pop();
			if(!pqc.empty()&&vis[tmpc.i]) pqc.pop(); 
		}
		write(-1);
		return 0;
	}
}
signed main(){
//	freopen("team.in","r",stdin);
//	freopen("team.out","w",stdout);
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//	int T = 1;
////	gtx::read(T);
//	while(T--) gtx::main();
	SUBTASK100pts::read(n);
	for(int i = 1;i<=n;i++){
		SUBTASK100pts::read(a[i]);SUBTASK100pts::read(b[i]);SUBTASK100pts::read(c[i]);
	}
	return SUBTASK100pts::main();
}

