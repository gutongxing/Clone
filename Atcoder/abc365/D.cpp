#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
//#define int long long
namespace gtx{
//	Fast IO
    int read(int &x){
        x = 0;int h = 1;char tmp;
        do{tmp=getchar();if(tmp=='-')h*=-1;}while(!isdigit(tmp));
        while(isdigit(tmp)) x*=10,x+=tmp-'0',tmp=getchar();
        x*=h;
        return x;
    }
    char read(char &x){do{x=getchar();}while(x==' '||x=='\n'||x=='\r');return x;}
    void write(char x){putchar(x);}
    void write(int x){
        if(x<0) putchar('-'),x=-x;int st[200]={0},tot=0;
        do{st[++tot]=x%10,x/=10;} while(x);
        while(tot){putchar(st[tot--]+'0');};
    }
    void write(int x,char y){write(x);write(y);}
    int n,dp[200300][3];
	char a[200300];
    signed main(){
        read(n);
        for(int i = 1;i<=n;i++) read(a[i]);
		//0:R	1:S		2:P
		for(int i = 1;i<=n;i++){
			if(a[i]=='R'){
				dp[i][0] = max(dp[i-1][1],dp[i-1][2]);
				dp[i][2] = max(dp[i-1][0],dp[i-1][1])+1;
			}else if(a[i]=='S'){
				dp[i][0] = max(dp[i-1][1],dp[i-1][2])+1;
				dp[i][1] = max(dp[i-1][0],dp[i-1][2]);
			}else if(a[i]=='P'){
				dp[i][1] = max(dp[i-1][0],dp[i-1][2])+1;
				dp[i][2] = max(dp[i-1][0],dp[i-1][1]);
			}
//			cout << i << " " << dp[i][0] << " " << dp[i][1] << " " << dp[i][2] << endl;
		}
		write(max({dp[n][0],dp[n][1],dp[n][2]}));
        return 0;
    }
}
signed main(){
// 	freopen(".in","r",stdin);
// 	freopen(".out","w",stdout);
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T = 1;
//	gtx::read(T);
    while(T--) gtx::main();
    return 0;
}
