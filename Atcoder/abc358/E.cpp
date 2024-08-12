#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 998244353;
const int MAXN = 1e4+10;
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
void read(char x){
    do x = getchar();
    while(x=='\n'||x==' '||x=='\r');
}
namespace math{
	int mu[MAXN],prime[MAXN];
	bitset<MAXN> is_prime;
	int frac[MAXN];
	int qpow(int a,int b){
		if(b==0) return 1;
		if(b==1) return a;
		int k = qpow(a,b>>1);
		k*=k;k%=MOD;
		if(b&1) k*=a;k%=MOD;
		return k;
	}
	int inv(int a){
		return qpow(a,MOD-2);
	}
	int C(int n,int m){
		if(n<m) return 0;
		return frac[n]*inv(frac[m]*frac[n-m]%MOD)%MOD;
	}
    int A(int n,int m){
        if(n<m) return 0;
        return frac[n]*inv(frac[m]);
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
int k,p=1,sum,f[MAXN][MAXN][2];
signed main(){
    frac_init();
    read(k);
    f[0][0][0] = 1;
    int ans = 0;
    for(int i = 0;i<26;i++){
        int x;read(x);
        for(int j = 0;j<=k;j++){
            f[i+1][j][0] += f[i][j][0];
            f[i+1][j][1] += f[i][j][1];
            if(j+x<MAXN) f[i+1][j+x+1][0] += f[i][j][1];
            if(j+x<MAXN) f[i+1][j+x+1][1] += f[i][j][0];
        }
    }
    for(int i = 1;i<=26;i++){
        for(int j = 0;j<=k;j++){
            for(int K = 0;K<=k;K++){
                ans += f[i][K][0]*C(j-K+i-1,j-1)%MOD;ans%=MOD;
                ans -= f[i][K][1]*C(j-K+i-1,j-1)%MOD;ans%=MOD;
            }
        }
    }
    write((ans%MOD+MOD)%MOD);
    return 0;
}