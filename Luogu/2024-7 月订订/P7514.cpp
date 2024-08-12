#include<bits/stdc++.h>
#define endl '\n'
//#define int long long
using namespace std;
//Fast IO
void read(int &x){
	int k = 1;
	x = 0;
	char tmp;
	do{tmp = getchar();if(tmp=='-') k*=-1;}while(!isdigit(tmp));
	while(isdigit(tmp)) x*=10,x+=tmp-'0',tmp=getchar();
	x*=k;
}
void write(int x){
	if(x==0) putchar('0');
	if(x<0) putchar('-'),x=-x;
	stack<int> st;
	while(x) st.push(x%10),x/=10;
	while(!st.empty()) putchar(st.top()+'0'),st.pop();
}
void write(char x){
	putchar(x);
}
void write(int x,char y){
	write(x);write(y);
}
int n,m,a[4000100],b[4000100];
bool t[4000100];
struct node{
	int num,flag,belong;
}p[4000100];
bool cmp(node a,node b){
	return a.num<b.num;
}
signed main(){
//	freopen("card3.in","r",stdin);
//	freopen(".out","w",stdout);
	read(n);read(m);
	for(int i = 1;i<=n;i++){
		read(a[i]);
		p[i].num = a[i];
		p[i].belong = i;
		p[i].flag = 1;
	}
	for(int i = 1;i<=n;i++){
		read(b[i]);
		p[i+n].num = b[i];
		p[i+n].belong = i;
		p[i+n].flag = 2;
	}
	sort(p+1,p+1+2*n,cmp);
	int l = 0,r = 2*n+1,sum = 0;
	while(l+1<=r-1){
		if(p[l+1].flag==2){
			if(t[p[l+1].belong]) break;
			t[p[l+1].belong] = 1;
			l++;
		}else{
			if(t[p[l+1].belong]) break;
			if(sum+1>m) break;
			t[p[l+1].belong] = 1;
			sum++;
			l++;
		}
	}
	while(l+1<=r-1){
		if(p[r-1].flag==2){
			if(t[p[r-1].belong]) break;
			t[p[r-1].belong] = 1;
			r--;
		}else{
			if(t[p[r-1].belong]) break;
			if(sum+1>m) break;
			t[p[r-1].belong] = 1;
			sum++;
			r--; 
		}
	}
	int minn = p[r-1].num-p[l+1].num;
	while(l>=0){
		if(p[l].flag==2){
			t[p[l].belong] = 0;
		}else{
			sum--;
			t[p[l].belong] = 0;
		}
		l--;
		while(l+1<=r-1){
			if(p[r-1].flag==2){
				if(t[p[r-1].belong]) break;
				t[p[r-1].belong] = 1;
				r--;
			}else{
				if(t[p[r-1].belong]) break;
				if(sum+1>m) break;
				t[p[r-1].belong] = 1;
				sum++;
				r--; 
			}
		}
		minn = min(minn,p[r-1].num-p[l+1].num);
//		cout << l << " " << " " << r << " " << p[r-1].num-p[l+1].num << endl;
	}
	write(minn);
	return 0;
}
