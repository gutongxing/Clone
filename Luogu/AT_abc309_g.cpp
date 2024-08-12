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
	scanf("%lld%lld",&n,&K);
	init(MOD);
	math::frac_init();
	f[0][0][0] = 1;//初始每一个位置都能涂 
	for(int i = 1;i<=n;i++){
		for(int j = 0;j<=i;j++){
			for(int k = 0;k<(1<<(2*K-1));k++){
				//最后一列不违反要求
				bitset<2*MAXK+1> to(k);to<<=1;to.reset(K*2-1);
				//最后一列涂最下面
				f[i][j][k] = o(f[i-1][j][to.to_ullong()]);
				//最后一列涂中间
				for(int is = 1;is<(2*K-1);is++){
					if(to[is]){//必须要不能涂
						to.reset(is);
						f[i][j][k] = o(f[i][j][k]+f[i-1][j][to.to_ullong()]);
						to.set(is);
					}
				}
				//最后一列违反要求
				//最后一列涂最下面
				f[i][j][k] = o(f[i][j][k]+f[i-1][j-1][to.to_ullong()+1]);
				//最后一列涂中间
				for(int is = 1;is<(2*K-1);is++){
					if(to[is]){//必须要不能涂
						f[i][j][k] = o(f[i][j][k]+f[i-1][j-1][to.to_ullong()]);
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
	printf("%d",ans);
	return 0;
}
