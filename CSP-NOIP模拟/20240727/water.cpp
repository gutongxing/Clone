#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int MAXN = 200010;
const int MAXQ = 400010;
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
namespace subtask1{
    void dfs(int k,int d,int w,int from){
        h[k] = (h[k]*w)%l;
        if(d){
            for(int i:v[k]){
                if(i==from) continue;
                dfs(i,d-1,w,k);
            }
        }
    }
	signed main(){
		while(q--){
            int T;
            read(T);
            if(T==1){
                int x,d,w;
                read(x);read(d);read(w);
                dfs(x,d,w,0);
            }else{
                int x;
                read(x);
                write(h[x],'\n');
            }
        }
		return 0;
	}
}
struct question{
    int T,x,d,w;
}ques[MAXQ];
namespace subtask2{
    int ti[MAXN];
    signed main(){
        for(int i = 1;i<=n;i++){
            ti[i] = 1;
        }
        for(int i = 1;i<=q;i++){
            if(ques[i].T==1){
                if(ques[i].d==0) h[ques[i].x] = (h[ques[i].x]*ques[i].w)%l;
                ti[ques[i].x] = (ti[ques[i].x]*ques[i].T)%l;
            }else{
                int ans = h[ques[i].x]*ti[ques[i].x]%l;
                for(int i:v[ques[i].x]){
                    ans = (ans*ti[i])%l;
                }
                write(ans);
            }
        }
        return 0;
    }
}
namespace subtask4{
    int maxn[MAXN];
    void dfs(int k,int d,int from){
        if(maxn[k]>=d) return;
        maxn[k] = d;
        h[k] = 0;
        if(d){
            for(int i:v[k]){
                if(i==from) continue;
                dfs(i,d-1,k);
            }
        }
    }
    signed main(){
        for(int i = 1;i<=q;i++){
            if(ques[i].T==1){
                dfs(ques[i].x,ques[i].d,0);
            }else{
                write(h[i]);
            }
        }
        return 0;
    }

}
namespace subtask{
	signed main(){
        bool task2 = 1,task4 = 1;
		for(int i = 1;i<=q;i++){
            int T;
            read(T);
            ques[i].T = T;
            if(T==1){
                int x,d,w;
                read(x);read(d);read(w);
                if(d>1) task2 = 0;
                if(w!=0) task4 = 0;
                ques[i].x = x;
                ques[i].d = d;
                ques[i].w = w;
            }else{
                int x;
                read(x);
                ques[i].x = x;
            }
        }
        if(task2) return subtask2::main();
        if(task4) return subtask4::main();
		return 0;
	}
    
}
signed main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
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
    if(n<=1000&&q<=1000) return subtask1::main();
	return subtask::main();
}
