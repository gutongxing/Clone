#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
//Fast IO
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
int n,m;
vector<int> v[MAXN];
struct Real{
	int p,q;
//	A real number that is p/q
};
int gcd(int a,int b){
	return __gcd(a,b);
}
int lcm(int a,int b){
	return a*b/__gcd(a,b);
}
Real operator / (Real a,int b){
	int tmp = __gcd(b,a.p);
	b /= tmp;
	a.p /= tmp;
	a.q *= b;
	return a;
}
Real operator + (Real a,Real b){
	int k = lcm(a.q,b.q);
	a.p *= k/a.q;
	a.q *= k/a.q;
	b.p *= k/b.q;
	b.q *= k/b.q;
	a.p += b.p;
	int tmp = __gcd(a.p,a.q);
	a.p /= tmp;
	a.q /= tmp;
	return a;
}
Real operator += (Real &a,Real b){
	a = a+b;
	return a;
}
void write(Real a){
	write(a.p,' ');write(a.q,'\n');
}
int rd[MAXN];
Real water[MAXN];
void topo(){
	queue<int> q;
	for(int i = 1;i<=n;i++){
		if(rd[i]==0) q.push(i),water[i]={1,1};
	}
	while(!q.empty()){
		int tmp = q.front();q.pop();
		if(v[tmp].size()==0) continue;
		auto l = water[tmp]/(int)v[tmp].size();
		for(int i:v[tmp]){
			water[i] += l;
			if(--rd[i]==0) q.push(i);
		}
	}
}
signed main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	read(n);read(m);
	for(int i = 1;i<=n;i++){
		int k;
		read(k);
		while(k--){
			int y;
			read(y);
			rd[y]++;
			v[i].push_back(y);
		}
		water[i] = {0,1};
	}
	topo();
	for(int i = 1;i<=n;i++){
		if(v[i].size()==0){
			write(water[i]);
		}
	}
	return 0;
}

