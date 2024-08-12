#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 5e5+10; 
class DSU{
	private:
		int fath[MAXN];
	public:
		int get_father(int k){
			if(k==fath[k]) return k;
			return fath[k] = get_father(fath[k]);
		}
		bool merge(int x,int y){
			int dx = get_father(x);
			int dy = get_father(y);
			if(dx==dy) return false;
			fath[dx] = dy;return true;
		}
		void clear(int n){
			for(int i = 1;i<=n;i++){
				fath[i] = i;
			}
		}
}dsu1,dsu2;
struct node{
	int k;
	vector<int> v;
}a[MAXN];
bool cmp(node a,node b){
	return a.k<b.k;
}
int n,m,ans;
signed main(){
	
	return 0;
}
