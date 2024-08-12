#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
//#define int long long
#define double long double
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
const int MAXN = 20;
const double eps = 1e-8;
int T,n,m;
double x[MAXN],y[MAXN],a[MAXN][MAXN],b[MAXN][MAXN];
bitset<MAXN> l[MAXN][MAXN];
int f[1<<MAXN];
int ans = 0x3f3f3f3f;
int lowbit(int x){
	return x&-x;
}
signed main(){
//	freopen("birds.in","r",stdin);
//	freopen("birds.out","w",stdout);
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> T;
	while(T--){
		cin >> n >> m;
		for(int i = 1;i<=n;i++){
			cin >> x[i] >> y[i];
		}
		#define x1 x[i]
		#define x2 x[j]
		#define y1 y[i]
		#define y2 y[j]
		for(int i = 1;i<=n;i++){
			for(int j = i+1;j<=n;j++){
				a[i][j] = 123456789;
				b[i][j] = 123456789;
				double aa = x2*y1-x1*y2;
				if(x1==0) continue;
				if(x2==0) continue;
				if(x1==x2) continue;
				aa/=x1*x2*(x1-x2);
				if(aa>=0) continue;
				double bb = y1/x1-aa*x1;
				a[i][j] = aa;
				b[i][j] = bb;
			}
		}
		#undef x1
		#undef x2
		#undef y1
		#undef y2
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=n;j++){
				l[i][j].reset();
				if(i==j) continue;
				if(a[i][j]==123456789) continue ;
				l[i][j].flip(i-1);
				l[i][j].flip(j-1);
				for(int k = 1;k<=n;k++){
					if(i==k) continue;
					if(j==k) continue;
					if(a[j][k]==123456789) continue;
					if(abs(a[i][j]-a[j][k])<=eps&&abs(b[i][j]-b[j][k])<=eps){
						l[i][j].flip(k-1);
					}
				}
			}
		}
		for(int i = 1;i<(1<<n);i++){
			f[i] = 0x3f3f3f3f;
		}
		f[0] = 0;
		for(int i = 0;i<(1<<n)-1;i++){
			int k = 0;
			for(int j = 1;j<=n;j++){
				if((i&(1<<(j-1)))==0){
					k = j;
					break;
				}
			}
			bitset<MAXN> now(i);
			for(int j = k+1;j<=n;j++){
				if((i&(1<<(j-1)))==0){
					f[(now|l[k][j]).to_ullong()] = min(f[(now|l[k][j]).to_ullong()],f[i]+1);
//					cout << (now|l[k][j]) <<endl; 
				}
			}
			f[i|(1<<(k-1))] = min(f[i|(1<<(k-1))],f[i]+1);
//			cout << bitset<4>(i) << " " << f[i] <<endl;
		}
		write(f[(1<<n)-1],'\n');
	}
	return 0;
}

