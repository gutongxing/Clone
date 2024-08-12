#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int MAXN = 200010;
const int MAXQ = 400010;
const int MAXD = 50;
const int MOD = 998244353;
int n,l,h[MAXN],q;
vector<int> v[MAXN];
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
namespace subtask{
    int mp[MAXN][MAXD],fath[MAXN];
    void dfs(int x,int fa){
        fath[x] = fa;
        for(int i:v[x]){
            if(i==fa) continue;
            dfs(i,x);
        }
    }
	signed main(){
        dfs(1,0);
        for(int i = 1;i<=n;i++){
            for(int j = 0;j<=40;j++){
                mp[i][j] = 1;
            }
        }
        bool task2 = 1,task4 = 1;
		for(int i = 1;i<=q;i++){
            int T;
            read(T);
            if(T==1){
                int x,d,w;
                read(x);read(d);read(w);
                int now = x;
                do{
                    for(int j = 0;j<=d;j++){
                        mp[now][j] = (mp[now][j]*w)%l;
                    }
                }
                while(now=fath[now]&&d--);
            }else{
                int x;
                read(x);
                int d = 0;
                int ans = h[x];
                int now = x;
                do{ans = (ans*mp[now][d])%l;}
                while((now=fath[now])&&d++<=40);
                write(ans,'\n');
            }
        }
		return 0;
	}
    
}
signed main(){
	// freopen("water.in","r",stdin);
	// freopen("water.out","w",stdout);
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// 	int T = 1;
// //	gtx::read(T);
// 	while(T--) gtx::main();
    read(n);read(l);
    for(int i = 1;i<n;i++){
        int x,y;
        read(x);read(y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(int i = 1;i<=n;i++){
        read(h[i]);
    }
    read(q);
	return subtask::main();
}
