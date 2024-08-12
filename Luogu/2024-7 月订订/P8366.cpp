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
    const int MAXN = 21;
    int f[2][MAXN][MAXN][MAXN][MAXN][MAXN][MAXN],n;
    //       1     2     3     13    21    32
    char a[MAXN];
    int QMOD_M,QMOD_P;
    void init(int pp){
        QMOD_M=((__int128)1<<64)/pp;
        QMOD_P=pp;
    }
    inline int qmod(int x){
        return x-((__int128(x)*QMOD_P)>>64)*QMOD_P;
    }
	signed main(){
        read(n);n*=3;
        for(int i = 1;i<=n;i++) read(a[i]);
        for(int i = 1;i<=n;i++){
            for(int a = 1;a<=n+1;a++){
            for(int b = 1;a+b<=n+1;b++){
            for(int c = 1;a+b+c<=n+1;c++){
            for(int d = 1;a+b+c+d<=n+1;d++){
            for(int e = 1;a+b+c+d+e<=n+1;e++){
            for(int f = 1;a+b+c+d+e+f<=n+1;f++){
                f[i&1][a][b][c][d][e][f] = 0;
            }}}}}}
            for(int a = 1;a<=n+1;a++){
            for(int b = 1;a+b<=n+1;b++){
            for(int c = 1;a+b+c<=n+1;c++){
            for(int d = 1;a+b+c+d<=n+1;d++){
            for(int e = 1;a+b+c+d+e<=n+1;e++){
            for(int f = 1;a+b+c+d+e+f<=n+1;f++){
                
            }}}}}}
            if(a[i]=='1'||a[i]==0){
                f[i&1][a][b][c][d][e][f] = 
                qmod(qmod(f[(i+1)&1][a-1][b][c][d][e][f]+qmod((b+1)*f[(i+1)&1][a][b+1][c][d-1][e][f])+
                qmod((f+1)*dp[])));
            }
            if(a[i]=='1'||a[i]==0){
                f[i&1][a][b][c][d][e][f] = 
                qmod(qmod(f[(i+1)&1][a-1][b][c][d][e][f]+qmod((b+1)*f[(i+1)&1][a][b+1][c][d-1][e][f])+
                qmod((f+1)*dp[])));
            }
            if(a[i]=='1'||a[i]==0){
                f[i&1][a][b][c][d][e][f] = 
                qmod(qmod(f[(i+1)&1][a-1][b][c][d][e][f]+qmod((b+1)*f[(i+1)&1][a][b+1][c][d-1][e][f])+
                qmod((f+1)*dp[])));
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
	gtx::read(T);
	while(T--) gtx::main();
	return 0;
}