#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
//#define int long long
namespace gtx{
//	Fast IO
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
	#include<bits/stdc++.h>
	using namespace std;
	const int MAXN = 1e6+10;
	char a[MAXN];
	char x[MAXN],y[MAXN];
	int n,nxt[MAXN],p,q,aa,bb,cc,dd;
	signed main(){
		scanf("%s",a+1);
		n = strlen(a+1);
		scanf("%s%s",x+1,y+1);
		p = strlen(x+1);
		q = strlen(y+1);
		aa=bb=cc=dd=0;
		for(int i = 1;i<=p;i++){
			if(x[i]=='0')aa++;
			else if(x[i]=='1')bb++;
		}
		for(int i = 1;i<=q;i++){
			if(y[i]=='0')cc++;
			else if(y[i]=='1')dd++;
		}
		aa-=cc;
		dd-=bb;
		if(dd==0) return puts(aa==0?"Yes":"No"),0;
		if(n*aa%dd!=0) return puts("No"),0;
		int size_of_t = n*aa/dd;
		if(size_of_t==n) return puts("Yes"),0;
		if(size_of_t<0) return puts("No"),0;
		for(int i = 1;i<=__gcd(size_of_t,n);i++){
			bool flag = 1;
			for(int j = i;j+__gcd(size_of_t,n)<=n;j+=__gcd(size_of_t,n)){
				if(a[j]!=a[j+__gcd(size_of_t,n)]) flag = 0;
				else flag = 1;
			}
			if(!flag) return puts("No"),0;
		}
		return puts("Yes"),0;
	}
}
signed main(){
// 	freopen(".in","r",stdin);
// 	freopen(".out","w",stdout);
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define file_read 114514
#ifdef file_read
	freopen("B_01_small_case_01.in","r",stdin);
	freopen("B_01_small_case_01.out","w",stdout);
#endif
	int T = 1;
	gtx::read(T);
	while(T--) gtx::main();
	return 0;
}
