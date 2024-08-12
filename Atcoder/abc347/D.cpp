#include<bits/stdc++.h>
#define int long long
using namespace std;
int a,b,c,bit = -1;
vector<bool> bit_c;
vector<bool> bit_a;
vector<bool> bit_b;
queue<int> pos;
int x,y;
signed main(){
	scanf("%lld%lld%lld",&a,&b,&c);
	int i = 0;
	while(c){
		bit_c.push_back(c&1);
		bit++;
		if(c&1){
			if(a<b){
				b--;
				bit_b.push_back(1);
				bit_a.push_back(0);
				y+=(1ll<<bit);
			}else{
				a--;
				bit_a.push_back(1);
				bit_b.push_back(0);
				x+=(1ll<<bit);
			}
		}else{
			pos.push(bit);
		}
		c>>=1;
		i++;
	}
	if(a<0||b<0){
		printf("-1");
	}else if(a!=b){
		printf("-1");
	}else{
		while(a&&b&&bit<60){
			if(pos.size()){
				x+=1ll<<pos.front();
				y+=1ll<<pos.front();
				pos.pop();
			}else{
				bit++;
				x+=1ll<<bit;
				y+=1ll<<bit;
			}
			a--;
			b--;
		}
		if(bit==60) puts("-1");
		else printf("%lld %lld",x,y);
	}
	return 0;
}

