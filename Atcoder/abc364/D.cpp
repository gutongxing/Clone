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
	const int MAXN = 1e5+10;
	int n,q,a[MAXN];
	bool check(int q,int mid,int K){
		int k = upper_bound(a+1,a+1+n,q+mid)-lower_bound(a+1,a+1+n,q-mid);
		return k>=K;
	}
	signed main(){
		read(n);read(q);
		for(int i = 1;i<=n;i++) read(a[i]);
		sort(a+1,a+1+n);
		for(int i = 1;i<=q;i++){
			int b,k;
			read(b);read(k);
			int l = 0,r = 3e8,ans=0;
			if(check(b,7,k)){
				
			}
			while(l<=r){
				int mid = (l+r)>>1;
				if(check(b,mid,k)){
					ans = mid;
					r = mid-1;
				}else l = mid+1;
			}
			write(ans,'\n');
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

