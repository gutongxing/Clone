#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
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
	int n,a,b,p[200010],q[200010],maxa,maxb;
	signed main(){
		read(n);read(a);read(b);
		for(int i = 1;i<=n;i++){
			read(p[i]);
		}
		for(int i = 1;i<=n;i++){
			read(q[i]);
		}
		sort(p+1,p+1+n);
		reverse(p+1,p+1+n);
		sort(q+1,q+1+n);
		reverse(q+1,q+1+n);
		int now,suma=0,sumb=0;
		now = 1;
		do{
			maxa += p[now];suma++;
			if(maxa>a) break;
		}
		while(++now<=n);
		now = 1;
		do{
			maxb += q[now];sumb++;
			if(maxb>b) break;
		}
		while(++now<=n);
		cout << min(suma,sumb);
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

