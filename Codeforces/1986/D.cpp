#include<bits/stdc++.h>
using namespace std;
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
void write(char x){
	putchar(x);
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
const int MAXN = 2e5+10;
int T,n;
char ans[MAXN];
struct node{
	char x;int pos;
}a[MAXN];
bool cmp(node a,node b){
	return a.x==b.x?a.pos<b.pos:a.x<b.x;
}
signed main(){
	ios::sync_with_stdio(0);
	read(T);
	while(T--){
		read(n);
		for(int i = 1;i<=n;i++) read(ans[i]),a[i].x = ans[i],a[i].pos = i;
		sort(a+1,a+1+n,cmp);
		bool fg = 0;
		for(int i = 1;i<=n;i++){
			if(a[i].x=='0'){
				if(a[i].pos>2||(n-a[i].pos)>=2) fg = 1;
			}else break;
		}
		if(fg) cout << "0\n";
		else{
			int now = 0x3f3f3f3f,maxpos = 0;
			for(int i = 1;i<n;i++){
				if(((now>((ans[i]-'0')*10+ans[i+1]-'0'))&&((now%10==1&&ans[i]==1)||ans[i+1]!='1'))||(now%10==1&&((((ans[i]-'0')==now/10)&&((ans[i+1]-'0')!=1))))){
					now =  (ans[i]-'0')*10+ans[i+1]-'0';
					maxpos = i;
				}
			}
			int ans1 = 0;
			if(maxpos!=1){
				ans1 = ans[1]-'0';
				for(int i = 2;i<maxpos;i++){
					if(ans[i]!='1') if(ans1==1) ans1 = ans[i]-'0'; else ans1 += ans[i]-'0';
				}
			}
			if(ans1==1) ans1 = now;
			else if(now!=1||maxpos==1) ans1 += now;
			if(maxpos!=n-1){
				for(int i = maxpos+2;i<=n;i++){
					if(ans[i]!='1') ans1 += ans[i]-'0';
				}
			}
			cout << ans1 << '\n';
		}
	}
	return 0;
}
