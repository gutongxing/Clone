#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
void read(int &x){
	int k = 1;
	x = 0;
	char tmp;
	do{tmp = getchar();if(tmp=='-') k*=-1;}while(!isdigit(tmp));
	while(isdigit(tmp)) x*=10,x+=tmp-'0',tmp=getchar();
	x*=k;
}
void write(int x){
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
int id,n,m,k,d;
signed main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int id,T;
	read(id);read(T);
	if(id==17||id==18){
		while(T--){
			read(n);read(m);read(k);read(d);
			int ans = 0;
			for(int i = 1;i<=m;i++){
				int x,y,z;
				read(x);read(y);read(z);
				if(y*d<z&&y<=k){
					ans += z-y*d;
				} 
			}
			write(ans,'\n');
		}
	}
		
	
	
	return 0;
}

