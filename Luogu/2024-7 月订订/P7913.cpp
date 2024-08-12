#include<bits/stdc++.h>
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
void special_read(int &x,int k){
	x = k;int p = 1;char ch;
	ch = getchar();
	while(isdigit(ch)){
		x*=10;
		x+=ch-'0';
		ch = getchar();
	}
	x*=p;
}
void write(char k){
    putchar(k);
}
const int MAXN = 1e5+10;
int n,m1,m2,cnt1,cnt2;
struct node{
    int time,type,id;
}a1[MAXN],a2[MAXN];
bool cmp(node a,node b){
    return a.time<b.time;
}
set<int> can1,can2;
int allot1[MAXN],allot2[MAXN];
int sum1[MAXN],sum2[MAXN]; 
signed main(){
	freopen("airport3.in","r",stdin);
	freopen("airport3.out","w",stdout);
    read(n);read(m1);read(m2);
    for(int i = 1;i<=m1;i++){
		read(a1[++cnt1].time);a1[cnt1].id = i;a1[cnt1].type = 1;
		read(a1[++cnt1].time);a1[cnt1].id = i;a1[cnt1].type = 2;		
    }
    for(int i = 1;i<=m2;i++){
		read(a2[++cnt2].time);a2[cnt2].id = i;a2[cnt2].type = 1;
		read(a2[++cnt2].time);a2[cnt2].id = i;a2[cnt2].type = 2;		
    }
    for(int i = 1;i<=m1;i++) can1.insert(i);
	for(int i = 1;i<=m2;i++) can2.insert(i);
    sort(a1+1,a1+1+cnt1,cmp);
    sort(a2+1,a2+1+cnt2,cmp);
    for(int i = 1;i<=cnt1;i++){
    	if(a1[i].type==1){
    		allot1[a1[i].id] = *can1.begin();
    		sum1[*can1.begin()]++;
    		can1.erase(can1.begin());
		}else{
			can1.insert(allot1[a1[i].id]);
		}
	}
    for(int i = 1;i<=cnt2;i++){
    	if(a2[i].type==1){
    		allot2[a2[i].id] = *can2.begin();
    		sum2[*can2.begin()]++;
    		can2.erase(can2.begin());
		}else{
			can2.insert(allot2[a2[i].id]);
		}
	}
	for(int i = 1;i<=m1;i++){
		sum1[i] += sum1[i-1];
	}
	for(int i = 1;i<=m2;i++){
		sum2[i] += sum2[i-1];
	}
	int ans = 0;
	for(int i = 0;i<=n;i++){
		ans = max(ans,sum1[i]+sum2[n-i]);
	}
	write(ans);
    return 0;
}
