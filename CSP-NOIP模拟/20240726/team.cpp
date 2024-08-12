#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
//#define int long long
const int MAXN = 3e5+10;
int n,a[MAXN],b[MAXN],c[MAXN];
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
namespace SUBTASK1{
	const int INF = 0x3f3f3f3f;
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
	signed main(){
		int ans = -INF;
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=n;j++){
				if(i==j) continue;
				for(int k = 1;k<=n;k++){
					if(i==k) continue;
					if(j==k) continue;
					if(
					a[i]>max(a[j],a[k])&&
					b[j]>max(b[i],b[k])&&
					c[k]>max(c[j],c[i])&&
					true){
						ans = max(ans,a[i]+b[j]+c[k]);
					}
					if(
					a[i]>max(a[j],a[k])&&
					c[j]>max(c[i],c[k])&&
					b[k]>max(b[j],b[i])&&
					true){
						ans = max(ans,a[i]+c[j]+b[k]);
					}
					if(
					b[i]>max(b[j],b[k])&&
					a[j]>max(a[i],a[k])&&
					c[k]>max(c[j],c[i])&&
					true){
						ans = max(ans,b[i]+a[j]+c[k]);
					}
					if(
					b[i]>max(b[j],b[k])&&
					c[j]>max(c[i],c[k])&&
					a[k]>max(a[j],a[i])&&
					true){
						ans = max(ans,b[i]+c[j]+a[k]);
					}
					if(
					c[i]>max(c[j],c[k])&&
					a[j]>max(a[i],a[k])&&
					b[k]>max(b[j],b[i])&&
					true){
						ans = max(ans,c[i]+a[j]+b[k]);
					}
					if(
					c[i]>max(c[j],c[k])&&
					b[j]>max(b[i],b[k])&&
					a[k]>max(a[j],a[i])&&
					true){
						ans = max(ans,c[i]+b[j]+a[k]);
					}
				}
			}
		}
		if(ans==-INF) puts("-1");
		else write(ans);
		return 0;
	}
}
namespace SUBTASK2{//	Fast IO
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
	map<pair<pair<int,int>,int>,int> mp;
	signed main(){
		for(int i = 1;i<=n;i++){
			mp[{{a[i],b[i]},c[i]}] = 1;
		}
		n = 0;
		for(auto tmp:mp){
			a[++n] = tmp.first.first.first;
			b[n] = tmp.first.first.second;
			c[n] = tmp.first.second;
		}
		return SUBTASK1::main();
	}
}
namespace SUBTASK100pts{//	Fast IO
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
		int a,b,c;
	}t[MAXN];
	bool cmpa(node a,node b){
		return a.a>b.a;
	}
	bool cmpb(node a,node b){
		return a.b>b.b;
	}
	bool cmpc(node a,node b){
		return a.c>b.c;
	}
	int cnt = 0;
	signed main(){
		for(int i = 1;i<=n;i++){
			t[i].a = a[i];
			t[i].b = b[i];
			t[i].c = c[i];
		}
		int i;
		sort(t+1,t+1+n,cmpa);
		i = 1;
		for(;i<=min(n,100);i++){
			a[++cnt] = t[i].a;
			b[cnt] = t[i].b;
			c[cnt] = t[i].c;
		}
		while((++i)<=n&&t[i].a==t[i-1].a){
			a[++cnt] = t[i].a;
			b[cnt] = t[i].b;
			c[cnt] = t[i].c;
		}
		sort(t+1,t+1+n,cmpb);
		i = 1;
		for(;i<=min(n,100);i++){
			a[++cnt] = t[i].a;
			b[cnt] = t[i].b;
			c[cnt] = t[i].c;
		}
		while((++i)<=n&&t[i].b==t[i-1].b){
			a[++cnt] = t[i].a;
			b[cnt] = t[i].b;
			c[cnt] = t[i].c;
		}
		sort(t+1,t+1+n,cmpc);
		i = 1;
		for(;i<=min(n,100);i++){
			a[++cnt] = t[i].a;
			b[cnt] = t[i].b;
			c[cnt] = t[i].c;
		}
		while((++i)<=n&&t[i].c==t[i-1].c){
			a[++cnt] = t[i].a;
			b[cnt] = t[i].b;
			c[cnt] = t[i].c;
		}
		n = cnt;
		return SUBTASK2::main();
	}
}
signed main(){
	freopen("team.in","r",stdin);
	freopen("team.out","w",stdout);
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//	int T = 1;
////	gtx::read(T);
//	while(T--) gtx::main();
	read(n);
	bool flag1 = n<=300;
	bool flag2 = true;
	for(int i = 1;i<=n;i++){
		read(a[i]);read(b[i]);read(c[i]);
		if(a[i]>5||b[i]>5||c[i]>5) flag2 = false;
	}
	if(flag1) return SUBTASK1::main();
	if(flag2) return SUBTASK2::main();
	return SUBTASK100pts::main();
}

