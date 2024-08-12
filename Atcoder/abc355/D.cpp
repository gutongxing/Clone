#include<bits/stdc++.h>
#define int long long
#define double long double
//#pragma G++ optimize(2) 
using namespace std;
const int MAXN = 5e5+10;
struct node{
	double x,y;
}s[MAXN];
bool cmp(node a,node b){
	return a.y==b.y?a.x<b.x:a.y<b.y;
}
int n;
vector<double> st;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n;
	for(int i = 1;i<=n;i++){
		cin >> s[i].x >> s[i].y; 
	}
	sort(s+1,s+1+n,cmp);
	int now = 1,ans = 0;
	for(int i = 1;i<=n;i++){
		ans += st.end()-lower_bound(st.begin(),st.end(),s[i].x);
		st.push_back(s[i].y);
	}
	cout << ans;
	return 0;
}

