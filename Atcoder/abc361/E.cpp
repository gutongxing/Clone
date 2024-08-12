#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 4e5+10;
//Fast IO
void read(int &x){
	x = 0;int p = 1;char ch;
	do{
		ch = getchar();
		if(ch=='-') p = -1;
	}while(!isdigit(ch));
	while(isdigit(ch)){
		x*=10;
		x+=ch-'0';
		ch = getchar();
	}
	x*=p;
}
void read(char &x){
	do x = getchar();
	while(x=='\n'||x==' '||x=='\r');
}
void write(int k){
	if(k<0) putchar('-');
	k = abs(k);
	stack<int> num;
	do{
		num.push(k%10);
		k/=10;
	}while(k);
	while(!num.empty()){
		putchar(num.top()+48);
		num.pop();
	}
}
void write(char k){
    putchar(k);
}
//Diameter
vector<pair<int,int>> v[MAXN];
int maxn,maxd;
void dfs1(int x,int fath,int dep){
    if(dep>maxd){
        maxd = dep;
        maxn = x;
    }
    for(auto i:v[x]){
        if(i.first==fath) continue;
        dfs1(i.first,x,dep+i.second);
    }
}
int from[MAXN];
void dfs2(int x,int fath,int dep){
    if(dep>maxd){
        maxd = dep;
        maxn = x;
    }
    for(auto i:v[x]){
        if(i.first==fath) continue;
        dfs2(i.first,x,dep+i.second);
    }
    from[x] = fath;
}
int n,m,cnt;
signed main(){
    read(n);
    cnt = n;int ans = 0;
    for(int i = 1;i<n;i++){
        int x,y,z;
        read(x);read(y);read(z);
        v[x].push_back({y,z});
        v[y].push_back({x,z});
        ans+=2*z;
    }
    dfs1(1,0,0);
    dfs2(maxn,0,0);
    write(ans-maxd);
    return 0;
}
