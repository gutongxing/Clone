#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
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
void write(__int128 x){
	if(x<0) putchar('-'),x=-x;int st[200]={0},tot=0;
	do{st[++tot]=x%10,x/=10;} while(x);
	while(tot){putchar(st[tot--]+'0');};
}
void write(int x,char y){write(x);write(y);}
//数位指个位，十位，百位，千位。。。
	static __int128 find(int index) {
		int count = 0;            
		int number = 9;                        //记录数位上的回文数，如个位回文数为9
		int w = 0;                            //记录数位
		
		__int128 half;                            //保存回文数的左半边的结果
		__int128 h = 1;                            //回文数的左半边的起始基数
		__int128 res;                            //结果
		
		while(true) {
			if(w > 0 && w%2 == 0) {            //每进两个数位，回文数乘以10
				number *= 10;
			}
			w++;                            //数位加一
			if(count + number > index)        //回文数大于查找的回数,跳出
				break;
			
			count += number;                //回文数加上当前数位上的回文数
		}
		
		index -= count;                        //在当前数位上的位置。如w=5,index=50,则万位上的第50个回文数是我们所求
		
		for(int i = 0; i < (w-1) / 2; i++) {    //求回文数的左半边的基数，如回文数在万位上，则为100
			h *= 10;
		}
		
		half = h + index;                        //回文数的左半边，如100 + 50 = 150
		
		res = half;
		
		if(w%2 != 0)                            //如果为奇数，则中间那个数不必算入右半边了！
			half /=10;
		
		while(half != 0) {                        //拼接回文数
			res = res *10 + half % 10;
			half /= 10;
		}
		return res;
	}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int x;
	read(x);
	if(x==1) write(0ll);
	else write(find(x-2));
	return 0;
}
