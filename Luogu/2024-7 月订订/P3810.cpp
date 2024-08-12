#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
//#define int long long
//Fast IO
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
const int MAXN = 3*(2e5+10);
struct node{
    int id,x,y,z;
    bool ques;
}a[MAXN];
int c[MAXN]={0};
int lowbit(int x){
    return x&-x;
}
void modify(int x,int y){
    for(int i = x;i<MAXN;i+=lowbit(i)){
        c[i] += y;
    }
}
int ask(int x){
    int res = 0;
    for(int i = x;i;i-=lowbit(i)){
        res += c[i];
    }
    return res;
}
bool cmp_x(node a,node b){
    if(a.x==b.x){
        if(a.y==b.y){
            if(a.z==b.z) return a.ques<b.ques;
			else return a.z<b.z;
        }else return a.y<b.y;
    }else return a.x<b.x;
}
bool cmp_y(node a,node b){
    if(a.y==b.y){
        if(a.z==b.z) return a.ques<b.ques;
		else return a.z<b.z;
    }else return a.y<b.y;
}
int f[MAXN];
int n,k,p[MAXN];
void CDQ(int l,int r){
//	cout << l << " " << r << endl;
    if(l==r) return;
    int mid = (l+r)>>1;
    CDQ(l,mid);
    CDQ(mid+1,r);
	vector<node> v;
    for(int i = l;i<=mid;i++){if(a[i].ques==0) v.push_back(a[i]);}
    for(int i = mid+1;i<=r;i++){if(a[i].ques==1) v.push_back(a[i]);}
    sort(v.begin(),v.end(),cmp_y);
    for(auto i:v){if(i.ques){f[i.id] += ask(i.z);}else modify(i.z,1);}
    for(auto i:v){if(!i.ques) modify(i.z,-1);}
}
signed main(){
//	freopen("P3810_7.in","r",stdin);
//	freopen("P3810_7.out","w",stdout);
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	read(n);read(k);
    for(int i = 1;i<=n;i++){
        int x,y,z;
        read(x);read(y);read(z);
        a[i] = {i,x,y,z,0};
        a[i+n] = {i,x,y,z,1};
    }
    sort(a+1,a+1+2*n,cmp_x);
    CDQ(1,2*n);
    for(int i = 1;i<=n;i++){
        p[f[i]]++;
//        write(f[i],' ');
    }
//    write('\n');
    for(int i = 1;i<=n;i++){
        write(p[i],'\n');
    }
	return 0;
}
