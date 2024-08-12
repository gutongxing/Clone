#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 500;
int l,r,now,sum;
vector<int> v;
signed main(){
//	freopen("room.in","r",stdin);
//	freopen("room.out","w",stdout);
	scanf("%lld%lld",&l,&r);
	now = l;v.push_back(now);
	while(now!=r){
		int can = 0;
		int tmp = now;
		if(!now) can = 60;
		else while(!(tmp&1)){
			tmp/=2;
			can++;
		}
		if((__int128)now+(1ll<<can)<=r){
			v.push_back(now+(1ll<<can));
			now += (1ll<<can);
		}else{
			while(now+(1ll<<can)>r){
				can--;
			}
			v.push_back(now+(1ll<<can));
			now += (1ll<<can);
		}
	}
	printf("%lld\n",v.size()-1);
	int last = LLONG_MAX;
	for(int i:v){
		if(last!=LLONG_MAX){
			printf("%lld %lld\n",last,i);
		}
		last = i;
	}
	return 0;
}
