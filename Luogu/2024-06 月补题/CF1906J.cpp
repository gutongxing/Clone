#include<bits/stdc++.h>
using namespace std;
#define int long long
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
const int MAXN = 5100;
const int MOD = 998244353;
const int DIV2 = 499122177;
int f[MAXN][MAXN];
int n,a[MAXN];
int qpow(int x,int y){
    if(y==1) return x;
    if(y==0) return 1;
    int k = qpow(x,y/2);
    k*=k;k%=MOD;
    if(y&1) k*=x;k%=MOD;
    return k;
}
signed main(){
    read(n);
    for(int i = 1;i<=n;i++) read(a[i]);
    f[1][1] = 1;
    for(int i = 1;i<=n;i++){
        //刷表
        int sum = 0,con = 1;
        int times[MAXN] = {0};
        for(int j = i;j<=n;j++){
            times[j] = 1;
        }
        int lst = i;
        for(int j = i;j<n;j++){
            if(a[j]<a[j+1]){
                times[j+1] *= f[i][j]; 
            }
        }
    }
    return 0;
}
