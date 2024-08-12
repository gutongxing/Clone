#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
const int MAXN = 120;
const int MAXK = 5*2;
const int MOD = 998244353;
int n,K,ans;
int f[MAXN][MAXN][MAXK];
long long mmm, ppp;
void init(int pp) { mmm = ((__int128)1 << 64) / pp; ppp = pp; }
inline long long o(const long long x){
    return x - ((__int128(x) * mmm) >> 64) * ppp;
}
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
void write(int k){
	if(k<0) write('-');
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
namespace math{
	int frac[MAXN];
	int qpow(int a,int b){
		if(b==0) return 1;
		if(b==1) return a;
		int k = qpow(a,b>>1);
		k = o(k*k);
		if(b&1) k = o(k*a);
		return k;
	}
	void frac_init(){
		frac[0] = 1;
		for(int i = 1;i<MAXN;i++){
			frac[i] = frac[i-1]*i;
			frac[i]%=MOD;
		}
	}
}
using namespace math;
signed main(){
	read(n);read(K);
	init(MOD);
	math::frac_init();
	f[0][0][0] = 1;
	for(int i = 1;i<=n;i++){
		for(int j = 0;j<i;j++){
			for(int k = 0;k<(1<<(2*K+1));k++){
				bool flag = 1;
				for(int p = 0;p<(2*K+1);p++){
					if(k&(1<<p)){
						if(p+i-K<1){
							flag = 0;
						}else if(p+i-K>n){
							flag = 0;
						}
					}
				}
				if(!flag) continue;
				int t = k<<1;
				f[i][j][k] = o(o(f[i-1][j][t]+f[i][j][k])+f[i-1][j-1][k|1]);
				for(int is = 0;is<(2*K+1);is++){
					if(t&(1<<is)&&((i-K+is+1)>=1)&&((i-K+is+1)<=n)){
						f[i][j][k] = o(f[i][j][k]+f[i-1][j][t^(1<<is)]);
						f[i][j][k] = o(f[i][j][k]+f[i-1][j-1][t]);
					}
				}
cout << i << " " << j << " " << k << " " << f[i][j][k] << endl;
			}
		}
	}
	for(int j = 0;j<=n;j++){
		for(int k = 0;k<(1<<(2*K-1));k++){
			ans = o(o(o(qpow(-1,j)*frac[n-j])*f[n][j][k])+ans);
		}
	}
	write(ans);
	puts("");
	return 0;
}
