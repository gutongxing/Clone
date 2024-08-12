#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 18+10;
struct node{
	int a,b;
}a[MAXN];
int sum,n;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n;
	for(int i = 1;i<=n;i++){
		cin >> a[i].a >> a[i].b;
	}
	for(int i = 1;i<=n;i++){
		for(int j = i+1;j<=n;j++){
			if(a[i].a==a[j].a||a[i].b==a[j].b) sum++;
		}
	}
	if(sum&1){
		cout << "Aoki";
	}else{
		cout << "Takahashi";
	}
	return 0;
}
