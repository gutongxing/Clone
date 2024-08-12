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
	const int MAXN = 2e5+10;
	int n,b[MAXN],a[MAXN];
    signed main(){
        read(n);n--;
		for(int i = 1;i<=n+1;i++){
			a[i] = 0;
		}
		for(int i = 1;i<=n;++i){
			read(b[i]);
			a[i]|=b[i];
			a[i+1]|=b[i];
		}
		bool flag = 1;
		for(int i = 1;i<=n;++i){
			if((a[i]&a[i+1])!=b[i]) flag = 0;
		}
		if(flag){
			for(int i = 1;i<=n+1;i++) write(a[i],' ');
			write(endl);
		}else puts("-1");
        return 0;
    }
}
signed main(){
// 	freopen(".in","r",stdin);
// 	freopen(".out","w",stdout);
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T = 1;
	gtx::read(T);
    while(T--) gtx::main();
    return 0;
}
