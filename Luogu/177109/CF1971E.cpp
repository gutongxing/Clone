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
int T,n,len,q,a[MAXN],b[MAXN];
signed main(){
	read(T);
	while(T--){
		read(len);read(n);read(q);
		for(int i = 1;i<=n;i++){
			read(a[i]);
		}
		for(int i = 1;i<=n;i++){
			read(b[i]);
		}
		for(int i = 1;i<=q;i++){
			int x;
			read(x);
			int l = 1,r = n,ans,mid;
			while(l<=r){
				mid = (l+r)>>1;
				if(x<=a[mid]){
                    r = mid-1;
					ans = mid;
				}else l = mid+1;
			}
			write((b[ans-1]+(long double)1.0*(b[ans]-b[ans-1])*(x-a[ans-1])/(a[ans]-a[ans-1])));putchar(' ');
		}
        puts("");
	}
    return 0;
}