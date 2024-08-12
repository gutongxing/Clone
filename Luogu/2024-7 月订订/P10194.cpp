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
    const int MAXN = 1e7+10;
    int n,m,cha[MAXN];
    void add(int l,int r,int s,int e){
    	if(l>r) return;
    	if(l==r){
    		cha[l] += s;
    		cha[l+1] -= 2*s;
    		cha[l+2] += s;
    		return;
		}
        int d = (e-s)/(r-l);
        cha[l] += s;
        cha[l+1] += d-s;
        cha[r+1] += -d-e;
        cha[r+2] += e;
        //  l   l+1 l+2 l+3 ... r-1 r   r+1     r+2
        //  +s  +d  +d  +d  ... +d  +d  -e      0
        //  +s  +d-s                    -d-e    e
    }
    void add(int l,int r,int s){
        add(l,r,s,s);
    }
    int val[MAXN];
    int a[MAXN],h[MAXN];
    const int INF = 0x3f3f3f3f;
    void Step1(){
        int minn = INF,mini = 0;
        for(int i = 1;i<=n;i++){
            if(val[i]<minn){
                minn = val[i];
                mini = i;
            }
        }
        vector<int> v;
        for(int i = mini;i<=n;i++){
            v.push_back(val[i]);
        }
        for(int i = 1;i<mini;i++){
            v.push_back(val[i]);
        }
        for(int i = 0;i<n;i++){
            val[i+1] = v[i];
        }
    }
    void Step2(){
        //From left to right sigel stack
        stack<pair<int,int>> st;
        st.push({val[1],1});
        for(int i = 2;i<=n;i++){
            while(st.top().first>=val[i]&&st.top().second!=1) st.pop();
            h[i] = i-st.top().second;
            st.push({val[i],i});
        }
    }
    void Step3(){
        //From right to left sigel stack
        stack<pair<int,int>> st;
        st.push({val[1],n+1});
        for(int i = n;i>1;i--){
            while(st.top().first>val[i]) st.pop();
            a[i] = st.top().second-i;
            st.push({val[i],i});
        }
    }
    void Step4(){
        #define a a[i]
        #define h h[i]
        for(int i = 2;i<=n;i++){
            if(a<=h){
                add(1,a-1,1*val[i],(a-1)*val[i]);
                add(a,h,a*val[i]);
                add(h+1,h+a-1,(a-1)*val[i],val[i]);
            }else{
                add(1,h-1,1*val[i],(h-1)*val[i]);
                add(h,a,h*val[i]);
                add(a+1,h+a-1,(h-1)*val[i],val[i]);
            }
        }
        #undef a
        #undef h
        add(1,n+1,val[1],val[1]*(n+1)); 
    }
    void Step5(){
        for(int i = 1;i<=n+1;i++) cha[i] += cha[i-1];
        for(int i = 1;i<=n+1;i++) cha[i] += cha[i-1];
    }
    signed main(){
        read(n);
        for(int i = 1;i<=n;i++){
            read(val[i]);
        }
        Step1();
        Step2();
        Step3();
        for(int i = 1;i<=n;i++) write(a[i],' ');write('\n');
        for(int i = 1;i<=n;i++) write(h[i],' ');write('\n');
        Step4();
        Step5();
        for(int i = 2;i<=n;i++){
            write(cha[i],'\n');
        }
            write(cha[n],'\n');
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
