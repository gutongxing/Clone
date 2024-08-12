#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
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
const int MAXN = 1e4+10;
int n;
int a[MAXN];
signed main(){
	freopen("cowlendar.in","r",stdin);
	freopen("cowlendar.out","w",stdout);
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	read(n);
	for(int i = 1;i<=n;i++) read(a[i]);
	sort(a+1,a+1+n);
	n = unique(a+1,a+1+n)-a-1;
	int k = a[1]/4;
	int sum = 0;
	for(int i = 1;i<=k;i++){
		if(i==6){
			int p =0 ;
		}
		bool flag = 1;
		int aa=0x3f3f3f3f3f3f3f3f,bb=0x3f3f3f3f3f3f3f3f,cc=0x3f3f3f3f3f3f3f3f;
		for(int j = 1;j<=n;j++){
			if(aa==0x3f3f3f3f3f3f3f3f){
				aa = a[j]%i;
			}else if(aa==a[j]%i) continue;
			else if(bb==0x3f3f3f3f3f3f3f3f){
				bb = a[j]%i;
			}else if(bb==a[j]%i) continue;
			else if(cc==0x3f3f3f3f3f3f3f3f){
				cc = a[j]%i;
			}else if(cc==a[j]%i) continue;
			else flag = 0;
		}
		if(flag) sum += i;
//		if(flag) cout << i << endl;
	}
	write(sum);
	return 0;
}

