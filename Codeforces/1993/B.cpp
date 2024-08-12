#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
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
	const int MAXN = 2e5+10;
	int n,a[MAXN];
	multiset<int> num[2];
	void debug(){
		int n;
		read(n);
		write(n,'\n');
		for(int i = 1;i<=n;i++){
			int tmp;
			read(tmp);
			write(tmp,' ');
		}
	}
	
	void debug_no_put(){
		int n;
		read(n);
		for(int i = 1;i<=n;i++){
			int tmp;
			read(tmp);
		}
	}
	signed main(){
		read(n);num[0].clear();num[1].clear();
		for(int i = 1;i<=n;i++) read(a[i]),num[a[i]&1].insert(a[i]);
		if(num[0].empty()||num[1].empty()) return puts("0"),0;
		//Turn to odd
		int sum = 0;
		deque<int> v;
		for(int a:num[0]) v.push_back(a);
		while(!v.empty()){
			int ttttt = v.front();v.pop_front();
			if(*num[1].rbegin()>ttttt){
				num[1].insert(ttttt+*num[1].rbegin());
				sum++;
			}else{
				v.push_front(ttttt);
				break;
			}
		}	
		while(!v.empty()){
			int ttttt = v.back();v.pop_back();
			if(*num[1].rbegin()>ttttt){
				num[1].insert(ttttt+*num[1].rbegin());
				sum++;
			}else{
				auto ttmp = --num[1].end();
				num[1].insert(ttttt+*ttmp);
				num[1].erase(ttmp);
				sum++;
				num[1].insert(ttttt+*num[1].rbegin());
				sum++;
			}
		}
		write(sum,'\n');
		return 0;
	}
}
signed main(){
// 	freopen(".in","r",stdin);
// 	freopen(".out","w",stdout);
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T = 1;
	gtx::read(T);
//	if(T==8567){
//		while(T--) if(T==8567-122) gtx::debug(); else gtx::debug_no_put();
//		return 0;
//	}
	while(T--) gtx::main();
	return 0;
}
