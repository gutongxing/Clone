#include<bits/stdc++.h>
#define endl '\n'
#define int long long
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
const int MAXN = 1e3+10;
const int INF = 0x3f3f3f3f3f3f3f3f;
int n,m,a[MAXN][MAXN],f[MAXN][MAXN][3];
//     |
//->0  1  2
//        |
void to(int x,int &y){
	y = max(y,x); 
}
signed main(){
	freopen("grid.in","r",stdin);
	freopen("grid.out","w",stdout);
	read(n);read(m);
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			read(a[i][j]);
			f[i][j][0] = f[i][j][1] = f[i][j][2] = -INF;
		}
	}
	f[1][1][0] = f[1][1][1] = a[1][1];
	for(int j = 1;j<=m;j++){
		for(int i = 1;i<=n;i++){
			to(f[i][j][0]+a[i+1][j],f[i+1][j][1]);
			to(f[i][j][1]+a[i+1][j],f[i+1][j][1]);
			to(f[i][j][1]+a[i][j+1],f[i][j+1][0]);
		}
		for(int i = n;i>=1;i--){
			to(f[i][j][0]+a[i-1][j],f[i-1][j][2]);
			to(f[i][j][2]+a[i-1][j],f[i-1][j][2]);
			to(f[i][j][2]+a[i][j+1],f[i][j+1][0]);
		}
		for(int i = 1;i<=n;i++){
			to(f[i][j][0]+a[i][j+1],f[i][j+1][0]);
//			cout << i << " " << j << " " << 0 << " " << f[i][j][0] << endl;
//			cout << i << " " << j << " " << 1 << " " << f[i][j][1] << endl;
//			cout << i << " " << j << " " << 2 << " " << f[i][j][2] << endl;
		}
	}
	write(max(f[n][m][0],f[n][m][1]));
	return 0;
}
