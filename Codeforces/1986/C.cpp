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
int T,n,m;
char ans[MAXN];
struct node{
	char k;int id;
}a[MAXN];
bool cmp(node a,node b){
	return a.k<b.k;
}
int ind[MAXN];
bitset<MAXN> vis;
map<int,int> mp;
signed main(){
	read(T);
	while(T--){
		read(n);read(m);mp.clear();
		for(int i = 1;i<=m;i++) vis[i] = 1;
		for(int i = 1;i<=n;i++) read(ans[i]);
		for(int i = 1;i<=m;i++){
			int x;
			read(x);
			mp[x]++;
		}
		for(int i = 1;i<=m;i++) read(a[i].k),a[i].id = i;
		sort(a+1,a+1+m,cmp);
		int now = 1;
		for(auto tmp:mp){
			while(tmp.second){
				ans[tmp.first] = a[now].k;
				int p = vis._Find_first();tmp.second--;
				vis[a[now].id] = 0;
				while(tmp.second&&p<a[now].id){
					vis[p] = 0;
					tmp.second--;
					p = vis._Find_next(p);
				}
				while(++now<=n&&!vis[a[now].id]){
					int x = 0;
				}
			}
		}
		for(int i = 1;i<=n;i++) write(ans[i]);
		puts("");
	}
	return 0;
}
