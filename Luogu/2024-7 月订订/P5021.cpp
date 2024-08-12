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
int n,m,a[2][120];
bool f[1210];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	read(n);read(m);
	int k;read(k);
	f[k] = 1;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			read(a[i&1][j]);
			if(i!=1)
			for(int k = 1;k<1200;k++){
				if(k-a[(i+1)&1][j]+a[i&1][j]<0) continue;
				f[k-a[(i+1)&1][j]+a[i&1][j]] |= f[k];
			}
			for(int i = 1200-1;i>0;i--){
			if(f[i]){
				cout << i << endl;
				break;
			}
		}
		}
	}
		for(int i = 1200-1;i>0;i--){
			if(f[i]){
				cout << i << endl;
				return 0;
			}
		}
	cout << "XJYhateGTX";
	return 0;
}

