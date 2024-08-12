#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 2e5+10;
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
    x = getchar();
    while(x==' '||x=='\n'||x=='\r') x = getchar();
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
int T,n,m;
struct node{
	int t,id,a,b;
}a[MAXN],b[MAXN];
int pre[MAXN],suc[MAXN];
bool cmp(node a,node b){
	return a.t<b.t;
}
bitset<MAXN> p;
signed main(){
	read(T);
	while(T--){
		read(n);read(m);p.reset();
		int x = n,y = m;
		for(int i = 1;i<=n+m+1;i++){
			read(a[i].a);
		}
        for(int i = 1;i<=n+m+1;i++){
            read(a[i].b);
        }
		int ans = 0,ans1 = 0,now = 0;
		for(int i = 1;i<=n+m+1;i++){
			now = i;
			if(a[i].a>a[i].b){
				if(x--){
					ans += a[i].a;
				}else{
					break;
				}
			}else{
				if(y--){
					ans += a[i].b;
				}else break;
			}
		}
		if(x==-1){
			for(int i = now;i<=n+m+1;i++){
				ans1 += a[i].b;
			}
		}else if(y==-1){
			for(int i = now;i<=n+m+1;i++){
				ans1 += a[i].a;
			}
		}
        for(int i = 1;i<=n+m+1;i++){
			if(i>=now){
				write(ans+ans1-(x==-1?a[i].b:a[i].a));
			}else{
				if(x==-1){
					if(a[i].a>a[i].b){
						write(ans+ans1-a[i].a+a[now].a-a[now].b);
					}else write(ans+ans1-a[i].b);
				}else{
					if(a[i].a<a[i].b){
						write(ans+ans1-a[i].b+a[now].b-a[now].a);
					}else write(ans+ans1-a[i].a);
				}
			}
			putchar(' ');
        }
        putchar('\n');
	}
    return 0;
}