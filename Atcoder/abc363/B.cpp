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
int n,m,x;
vector<int> v;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	read(n);read(m);read(x);
	for(int i = 1;i<=n;i++){
		int x;
		read(x);
		v.push_back(x);
	}
	sort(v.begin(),v.end());
	int l = 0,r = 500,ans = 0;
	while(l<=r){
		int mid = (l+r)>>1;
		if(n-(lower_bound(v.begin(),v.end(),m-mid)-v.begin())>=x){
			ans = mid;
			r = mid-1;
		}else l = mid+1;
	}
	write(ans);
	return 0;
}
