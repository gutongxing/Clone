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
vector<int> v[MAXN];
int maxn,maxd;
void dfs1(int x,int fath,int dep){
    if(dep>maxd){
        maxd = dep;
        maxn = x;
    }
    for(int i:v[x]){
        if(i==fath) continue;
        dfs1(i,x,dep+1);
    }
}
int from[MAXN];
void dfs2(int x,int fath,int dep){
    if(dep>maxd){
        maxd = dep;
        maxn = x;
    }
    for(int i:v[x]){
        if(i==fath) continue;
        dfs2(i,x,dep+1);
    }
    from[x] = fath;
}
vector<int> diameter;
int find(int x,int k,int fath){
    if(k==1) return 1;
    int ans = 0;
    for(int i:v[x]){
        if(i==fath) continue;
        ans += find(i,k-1,x);
    }
    return ans;
}
int n,m,cnt;
signed main(){
    read(n);
    cnt = n;
    for(int i = 1;i<n;i++){
        int x,y;
        read(x);read(y);
        ++cnt;
        v[x].push_back(cnt);
        v[y].push_back(cnt);
        v[cnt].push_back(x);
        v[cnt].push_back(y);
    }
    dfs1(1,0,1);
    int tmp = maxn;
    dfs2(maxn,0,maxd);
    int now = maxn;
    diameter.push_back(maxn);
    do{now=from[now];diameter.push_back(now);}while(now!=tmp);
    int center = diameter[diameter.size()/2];
    int ans = 1,p = 1;
    for(int i:v[center]){
		int tmp = find(i,diameter.size()/2,center);
		p += tmp;
        ans*=(tmp+1);
		ans%=998244353;
    }
    write(((ans-p)%998244353+998244353)%998244353);
    return 0;
}
