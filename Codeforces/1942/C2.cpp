#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,x,y,a[200010],ans,sum[200010];
signed main(){
	scanf("%lld",&T);
	while(T--){
		if(T==0){
			int x= 0;
		}
		scanf("%lld%lld%lld",&n,&x,&y);
		ans = x-2;
		memset(sum,0,sizeof sum);
		for(int i = 1;i<=x;i++){
			scanf("%lld",a+i);
		}
		sort(a+1,a+1+x);
		x++;
		a[x] = a[1]+n;
		for(int i = 2;i<=x;i++){
			if(a[i]-a[i-1]<2) continue;
			else if(a[i]-a[i-1]==2) ans++;
			else{
				sum[a[i]-a[i-1]-1]++;
			}
		}
		if(!y){
			printf("%lld\n",ans);
		}else{
			if(y<=sum[3]){
				printf("%lld\n",ans+y*3);
			}else{
				ans += sum[3]*3;
				y-=sum[3];
				if(y<=sum[2]){
					printf("%lld\n",ans+y*2);
				}else{
					ans += sum[2]*2;
					y-=sum[2];int ssum = 0;
					for(int i = 4;i<=200000;i++){
						if(y<=0) break;
						int tmp = y/(i-2);tmp = min(tmp,sum[i]);
						y-=tmp*(i-2);
//						ssum
						ans += tmp*(i-1);
					}
					printf("%lld\n",ans);
				}
			}
		}
	}
	return 0;
}
