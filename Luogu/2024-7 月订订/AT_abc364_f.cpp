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
    const int INF = 0x3f3f3f3f;
    set<pair<int,int>> st;
    int n,q,ans;
    struct node{
        int l,r,w;
    }edge[MAXN];
    bool cmp(node a,node b){
        return a.w<b.w;
    }
    signed main(){
        read(n);read(q);
        for(int i = 1;i<=n;i++) st.insert({i,i});
        for(int i = 1;i<=q;i++){
            read(edge[i].l);read(edge[i].r);read(edge[i].w);
        }
        sort(edge+1,edge+1+q,cmp);
        for(int i = 1;i<=q;i++){
            auto tmp = st.upper_bound({edge[i].l,INF});
            tmp--;
            int l = tmp->first;
            int r = tmp->first;
            // cout << i << " " << edge[i].l << " " << edge[i].r << endl;
            do{
                ans += edge[i].w;
                auto tmpp = tmp++;
                r = tmpp->second;
                // cout << tmpp->first << " " << tmpp->second << endl;
                st.erase(tmpp);
            }
            while(r<edge[i].r&&tmp!=st.end());
            st.insert({l,r});
        }
        if(st.size()!=1) write(-1ll);
        else write(ans);
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