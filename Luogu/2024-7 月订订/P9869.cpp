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
int c,T,n,m;
const int MAXN = 2*(1e5+10);
int ano[MAXN];
//dsu
int fath[MAXN];
int get_father(int x){
	if(x==fath[x]) return x;
	return fath[x] = get_father(fath[x]);
}
void me(int x,int y){
	int fx = get_father(x);
	int fy = get_father(y);
	fath[fx] = fy;
}
void merge(int x,int y){
	me(x,y);
	me(ano[x],ano[y]);
}
int mp[MAXN];
const int U = MAXN-1;
signed main(){
//	freopen("P9869_7.in","r",stdin);
//	freopen("P9869_7.out","w",stdout);
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	read(c);read(T);
	while(T--){
		read(n);read(m);
//		cout << n << " " << m << endl;
		for(int i = 0;i<=2*n+1;i++) fath[i] = i,mp[i] = i;
		fath[U] = U;
		for(int i = 0;i<=n;i++) ano[i] = i+n+1;
		for(int i = n+1;i<=2*n+1;i++) ano[i] = i-n-1;
		for(int i = 1;i<=m;i++){
			char tmp;int x,y;
			read(tmp);
			if(tmp=='T'){
				read(x);
				mp[x] = 0;
				mp[ano[x]] = ano[0];
			}else if(tmp=='F'){
				read(x);
				mp[x] = ano[0];
				mp[ano[x]] = 0;
			}else if(tmp=='U'){
				read(x);
				mp[x] = U;
				mp[ano[x]] = U;
			}else if(tmp=='+'){
				read(x);read(y);
				mp[x] = mp[y];
				mp[ano[x]] = mp[ano[y]];
			}else{
				read(x);read(y);
				if(x==y){
					swap(mp[x],mp[ano[x]]);
					continue;
				}
				mp[x] = mp[ano[y]];
				mp[ano[x]] = mp[y];
			}
//			cout << "-----------\n";
//			for(int i = 1;i<=2*n+1;i++){
//				if(mp[i]>n){
//					cout << ((i>n)?(to_string(i-n-1)+'\''):to_string(i)) << ": " << mp[i]-n-1 << "\'\n";
//				}else cout << ((i>n)?(to_string(i-n-1)+'\''):to_string(i)) << ": " << mp[i] << "\n";
//			}
		}
		for(int i = 0;i<=2*n+1;i++){
			me(i,mp[i]);
//			cout << i << " " << mp[i] << endl;
		}
//		for(int i = 1;i<=n;i++){
//			if(mp[i]>n){
//				cout << ((i>n)?(to_string(i-n-1)+'\''):to_string(i)) << ": " << mp[i]-n-1 << "\'\n";
//			}else cout << ((i>n)?(to_string(i-n-1)+'\''):to_string(i)) << ": " << mp[i] << "\n";
//		}
		int ans = 0;
		for(int i = 1;i<=n;i++){
			if(get_father(ano[i])==get_father(i)) me(i,U);
		}
		for(int i = 1;i<=n;i++){
			if(get_father(i)==get_father(U)) ans++; 
		}
		write(ans,endl);
	}
	return 0;
}
