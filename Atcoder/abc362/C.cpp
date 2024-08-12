#include<bits/stdc++.h>
#define int long long
using namespace std;
//Fast IO
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
	do x = getchar();
	while(x=='\n'||x==' '||x=='\r');
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
void write(char x){
	putchar(x);
}
void write(int x,char y){
	write(x);write(y);
}
const int MAXN = 4e5+10;
int n,m,l[MAXN],r[MAXN],dong[2][MAXN],now,sum[2];
signed main(){
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n;
	for(int i = 1;i<=n;i++){
		cin >> l[i] >> r[i];
		if(l[i]<0&&r[i]>0){
			now += 0;
			dong[1][i] = r[i];
			dong[0][i] = l[i];
			sum[1] += r[i];
			sum[0] += l[i];
		}else if(l[i]>=0){
			now += l[i];
			dong[1][i] = r[i]-l[i];
			sum[1] += r[i]-l[i];
		}else {now += r[i];
			dong[0][i] = l[i]-r[i];
			sum[0] += l[i]-r[i];
		};
	}
	if(now>0){
		if(now+sum[0]<=0){
			puts("Yes");
			for(int i = 1;i<=n;i++){
				if(l[i]<0&&r[i]>0){
					if(now+l[i]<=0){
						cout << -now;
						now = 0;
					}else{
						cout << l[i];
						now += l[i];
					}
				}else if(l[i]>=0){
					cout << l[i];
				}else {
					if(now+l[i]-r[i]<=0){
						cout << r[i]-now;
						now = 0;
					}else{
						cout << l[i];
						now += l[i]-r[i];
					}
				};
				cout << " ";
			}
		}else puts("No");
	}else if(now==0){
		if(1){
			puts("Yes");
			for(int i = 1;i<=n;i++){
				if(l[i]<0&&r[i]>0){
					cout << 0;
				}else if(l[i]>=0){
					cout << l[i];
				}else {
					cout << r[i];
				};
				cout << " ";
			}
		}else puts("No");
	}else{
		if(now+sum[1]>=0){
			puts("Yes");
			for(int i = 1;i<=n;i++){
				if(l[i]<0&&r[i]>0){
					if(now+r[i]>=0){
						cout << now;
						now = 0;
					}else{
						cout << r[i];
						now -= r[i];
					}
				}else if(l[i]>=0){
					if(now+r[i]-l[i]>=0){
						cout << l[i]-now;
						now = 0;
					}else{
						cout << r[i];
						now += r[i]-l[i];
					}
				}else {
					cout << r[i];
				};
				cout << " ";
			}
		}else puts("No");
	}
	return 0;
}

