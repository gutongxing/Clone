#include<bits/stdc++.h>
#define endl '\n'
//#define int long long
using namespace std;
//Fast IO
void read(int &x){
	int k = 1;
	x = 0;
	char tmp;
	do{tmp = getchar();if(tmp=='-') k*=-1;}while(!isdigit(tmp));
	while(isdigit(tmp)) x*=10,x+=tmp-'0',tmp=getchar();
	x*=k;
}
void write(int x){
	if(x==0) putchar('0');
	if(x<0) putchar('-'),x=-x;
	stack<int> st;
	while(x) st.push(x%10),x/=10;
	while(!st.empty()) putchar(st.top()+'0'),st.pop();
}
void write(char x){
	putchar(x);
}
void write(int x,char y){
	write(x);write(y);
}
const int MAXN = 1e5+10;
int n;
struct tree{
	int a,b,c;
}t[MAXN];
int ddl[MAXN],use[MAXN];
int sum(int S,int E,int P){
	return (S+E)*P/2;
}
int P(int a,int b,int c){
	return (b-a)/c+1;
}
#define a t[i].a
#define b t[i].b
#define c t[i].c
bool check(int Time){
	for(int i = 1;i<=n;i++){
		if(t[i].c>0){
			int l = 1,r = Time,ans;
			while(l<=r){
				int mid = (l+r)>>1;
				if(sum(b+c*x,b+c*Time,P(b+c*x,b+c*Time,c))>=a){
					ans = mid;
					l = mid+1;
				}else r = mid-1;
			}
			ddl[i] = ans;
		}else if(t[i].c==0){
			ddl[i] = Time-(a-1)/b-1;
		}else{
			int endness = b/c;
			int l = 1,r = Time,ans;
			while(l<=r){
				int mid = (l+r)>>1;
				if(sum(b+c*x,b+c*endness,P(b+c*endness,b+c*x,c))>=a){
					ans = mid;
					l = mid+1;
				}else if()
			}
		}
		
	}
}
#undef a
#undef b
#undef c
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	read(n);
	for(int i = 1;i<=n;i++){
		read(t[i].a);read(t[i].b);read(t[i].c);
	}
	int l = 0,r = 1e9,ans;
	while(l<=r){
		int mid = (l+r)>>1;
		if(check(mid)) ans = mid,r = mid-1;
		else l = mid+1;
	}
	write(ans);
	return 0;
}

