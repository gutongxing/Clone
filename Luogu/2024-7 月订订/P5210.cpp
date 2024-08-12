#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
//#define int long long
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
vector<pair<int,int>> v[MAXN];
int sum,xz;
int dfs(int k,int fath){
	multiset<int> mt;
	vector<int> p;
	for(auto i:v[k]){
		if(i.first==fath) continue;
		int tmp = dfs(i.first,k);
		if(tmp+i.second>=xz) sum++;
		else{
			tmp += i.second;
			mt.insert(tmp);
		}
	}
	while(mt.size()>=2){
		auto tmp = mt.lower_bound(xz-*mt.begin());
		if(tmp!=mt.end()){
			sum++;
			mt.erase(tmp);
		}else p.push_back(*mt.begin());
		mt.erase(mt.begin());
	}
	for(int i:p){
		mt.insert(i); 
	}
	if(mt.size()==0) return 0;
	return *(mt.rbegin());
}
bool check(int x){
	xz = x;
	sum = 0;
	dfs(1,0);
	return sum>=m;
}
signed main(){
//	freopen("track.in","r",stdin);
//	freopen("track.out","w",stdout);
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	read(n);read(m);
	int sum = 0;
	for(int i = 1;i<n;i++){
		int x,y,z;
		read(x);read(y);read(z);
		v[x].push_back({y,z});
		v[y].push_back({x,z});
		sum += z;
	}
	int l = 0,r = sum,ans = 0;
	while(l<=r){
		int mid = (l+r)>>1;
		if(check(mid)){
			l = mid+1;
			ans = mid;
		}else{
			r = mid-1;
		}
	}
	write(ans);
	return 0;
}

