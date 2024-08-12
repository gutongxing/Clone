#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
//#define int long long
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
	while(x) st[++tot]=x%10,x/=10;
	do{putchar(st[tot--]+'0');} while(tot>0);
}
void write(int x,char y){write(x);write(y);}
const int MAXN = 1e6+10;
struct node{
	int l,r,fath;
	int opt;bool val;
}a[MAXN<<2];
int root = 1e5+10;
int val[MAXN],n;
bool get(int x){
	if(a[x].opt == 1){
		return a[x].val = get(a[x].l)&get(a[x].r);
	}else if(a[x].opt == 2){
		return a[x].val = get(a[x].l)|get(a[x].r);
	}else if(a[x].opt == 3){
		return a[x].val = !get(a[x].l);
	}else return a[x].val = val[x];
}
stack<int> st;
signed main(){
//	freopen("expr.in","r",stdin);
//	freopen("expr.out","w",stdout);
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	char tmp;tmp=getchar();
	while(tmp!='\n'){
		while(tmp==' ') tmp = getchar();
		if(tmp=='x'){
			int x;read(x);
			st.push(x);
		}else if(tmp=='&'){
			++root;
			a[root].l = st.top();st.pop();
			a[root].r = st.top();st.pop();
			a[a[root].l].fath = root;
			a[a[root].r].fath = root;
			a[root].opt = 1;
			st.push(root);
		}else if(tmp=='|'){
			++root;
			a[root].l = st.top();st.pop();
			a[root].r = st.top();st.pop();
			a[a[root].l].fath = root;
			a[a[root].r].fath = root;
			a[root].opt = 2;
			st.push(root);
		}else if(tmp=='!'){
			++root;
			a[root].l = st.top();st.pop();
			a[a[root].l].fath = root;
			a[root].opt = 3;
			st.push(root);
		}
		tmp = getchar();
	}
	read(n);
	for(int i = 1;i<=n;i++){
		read(val[i]);
	}
	int q;
	read(q);
	if(q<=1000){
		while(q--){
			int k;
			read(k);
			val[k]^=1;
			write(get(root),'\n');
			val[k]^=1;
		}
	}else{
		while(q--){
			int k;
			read(k);
			int now = a[k].fath,ans = val[k]^1;bool ch = a[a[now].fath].l==now;
			do{
				if(a[now].opt == 1){
					if(ch) ans = ans&a[a[now].r].val;
					else ans = ans&a[a[now].l].val;
				}else if(a[now].opt == 2){
					if(ch) ans = ans|a[a[now].r].val;
					else ans = ans|a[a[now].l].val;
				}else if(a[now].opt == 3){
					ans ^= 1;
				}
				ch = a[a[now].fath].l==now;
				now = a[now].fath;
			}while(now!=root);
			write(ans,'\n');
		}
	}
	return 0;
}

