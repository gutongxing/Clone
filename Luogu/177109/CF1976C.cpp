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
		for(int i = 1;i<=n+m+1;i++){
			read(a[i].a);
		}
        for(int i = 1;i<=n+m+1;i++){
            read(a[i].b);
            b[i] = a[i];
			a[i].id = i;
			if(a[i].a>a[i].b){
				a[i].t = i;
			}else a[i].t = i+n+m+1;
        }
		sort(a+1,a+1+n+m+1,cmp);
		for(int i = 1;i<=n;i++){
			p.set(a[i].id);
		}
        pre[0] = suc[n+m+2] = 0;
        for(int i = 1;i<=n+m+1;i++){
            pre[i] = pre[i-1]+a[i].a;
        }
        for(int i = n+m+1;i>=1;i--){
            suc[i] = suc[i+1]+a[i].b;
        }
        for(int i = 1;i<=n+m+1;i++){
            if(p[i]){
                write(pre[n+1]-b[i].a+suc[n+2]);
            }else{
                write(pre[n]-b[i].b+suc[n+1]);
            }
            putchar(' ');
        }
        putchar('\n');
	}
    return 0;
}