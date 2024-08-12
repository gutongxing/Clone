#include<bits/stdc++.h>
using namespace std;
const int MAXN = 4e5+1;
int T,n,m;
vector<int> a[MAXN],b[MAXN];
int gcd[MAXN];
inline void read(int &p){
    int x = 0,f = 1;
    char ch = getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9') x = x*10+ch-'0',ch = getchar();
    p = x*f;
}
class DSU{
	private:
	int fath[MAXN]; 
	public:
	int get_father(int x){
		if(fath[x]==x) return x;
		return fath[x] = get_father(fath[x]);
	}
	void merge(int x,int y){
		int fx = get_father(x);
		int fy = get_father(y);
		fath[fx] = fy;
		return;
	}
	void init(int k){
		for(int i = 1;i<=k;i++){
			fath[i] = i;
		}
	}
}h,l;
signed main(){
	read(T);
	while(T--){
		read(n);read(m);h.init(n*m+n);l.init(n*m+m);
		for(int i = 1;i<=n;i++){
			a[i].clear();
			a[i].push_back(0);
			b[i].clear();
			b[i].push_back(0);
		}
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=m;j++){
				int x;
				scanf("%d",&x);
				a[i].push_back(x);
			}
		}
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=m;j++){
				int x;
				scanf("%d",&x);
				b[i].push_back(x);
			}
		}
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=m;j++){
				h.merge(i+n*m,a[i][j]);
			}
		}
		for(int i = 1;i<=m;i++){
			for(int j = 1;j<=n;j++){
				l.merge(i+n*m,a[j][i]);
			}
		}
		bool fg = 1;
		for(int i = 1;i<=n;i++){
			int k = h.get_father(b[i][1]);
			for(int j = 1;j<=m;j++){
				if(k!=h.get_father(b[i][j])) fg = 0;
			}
		}
		if(fg)
		for(int i = 1;i<=m;i++){
			int k = l.get_father(b[1][i]);
			for(int j = 1;j<=n;j++){
				if(k!=l.get_father(b[j][i])) fg = 0;
			}
		}
		if(fg) puts("Yes");
		else puts("No");
	}
	return 0;
}

