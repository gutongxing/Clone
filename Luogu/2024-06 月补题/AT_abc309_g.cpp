#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
const int MAXN = 120;
const int MAXK = 5*2;
const int MOD = 998244353;
int n,K,ans;
int f[MAXN][MAXN][1<<MAXK];
long long mmm, ppp;
void init(int pp) { mmm = ((__int128)1 << 64) / pp; ppp = pp; }
inline long long o(const long long x){
    return x - ((__int128(x) * mmm) >> 64) * ppp;
}
//Fast IO
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
void read(char &x){
	do x = getchar();
	while(x=='\n'||x==' '||x=='\r');
}
void write(int k){
	if(k<0) putchar('-');
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
void write(char k){
    putchar(k);
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
			frac[i] = o(frac[i-1]*i);
		}
	}
}
using namespace math;
int get(int x,int p){
	return x-K+p+1;
}
bool illegal(int x,int k){
	for(int i = 0;i<2*K-1;i++){
		if((k&(1<<i))&&!(get(x,i)>=1&&get(x,i)<=n)){
			return true;
		}
	}
	return false;
}
signed main(){
	read(n);read(K);
	init(MOD);
	math::frac_init();
	f[0][0][0] = 1;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<=i;j++){
			for(int k = 0;k<(1<<(2*K-1));k++){
				if(illegal(i,k)) continue;
				int nxt = k>>1;
				f[i+1][j][nxt] = o(f[i+1][j][nxt]+f[i][j][k]);		
				for(int l = 0;l<2*K-1;l++){
					if(!(nxt&(1<<l))&&((get(i+1,l)>=1)&&(get(i+1,l)<=n))){
						int t = nxt|(1<<(l));
						f[i+1][j+1][t] = o(f[i+1][j+1][t]+f[i][j][k]);
					}
				}
// cout << i << " " << j << " " << k << " " << f[i][j][k] << endl;
			}
		}
	}
	for(int j = 0;j<=n;j++){
		for(int k = 0;k<(1<<K);k++){
			ans = o(o(o(qpow(-1,j)*frac[n-j])*f[n][j][k])+ans);
		}
	}
	write((ans+MOD)%MOD);
	puts("");
	return 0;
}
