#include <bits/stdc++.h>

using namespace std;


struct node {
	int lson, rson, fa, lazytag, xorr, val;
} at[114514];
int n, m;

bool root(int x) { //判splay根
	int f = at[x].fa;

	return at[f].lson != x && at[f].rson != x;
}

void reverse(int x) {
	if (!x)
		return;
	swap(at[x].rson, at[x].lson);
	at[x].lazytag ^= 1;
}

void pushup(int x) {
	at[x].xorr = at[at[x].rson].xorr ^ at[at[x].lson].xorr ^ at[x].val;
}

void push_down(int x) {
	if (at[x].lazytag) {
		reverse(at[x].lson);
		reverse(at[x].rson);
		at[x].lazytag = 0;
	}
}

void push(int x) { 
	if (!root(x))
		push(at[x].fa);
	//pushup(x);
	push_down(x);
}

void rotate(int x) {
	int f = at[x].fa, xl = at[x].lson, xr = at[x].rson;
	if (!root(f)) {
		if (at[at[f].fa].rson == f)
			at[at[f].fa].rson = x;
		else
			at[at[f].fa].lson = x;
	}
	if (at[f].rson == x) { //左旋
		at[x].fa = at[f].fa;
		at[x].lson = f;
		at[f].fa = x;
		at[f].rson = xl;
	} else {
		at[x].fa = at[f].fa;
		at[x].rson = f;
		at[f].fa = x;
		at[f].lson = xr;
	}
	pushup(f);
	pushup(x);
}

void splay(int x) { //splay旋转
	int f, g;
	push(x);
	while (!root(x)) {
		f = at[x].fa;
		g = at[f].fa;
		if (root(f)) {
			rotate(x);
		} else if ((at[g].lson == f && at[f].lson == x) || (at[g].rson == f && at[f].rson == x)) {
			rotate(f);
			rotate(x);
		} else {
			rotate(x);
			rotate(x);
		}
	}
	pushup(x);
}

void access(int x) { //建立实链
	int child = 0;
	while (x > 0) {
		//cout << 1;
		splay(x);
		at[x].rson = child;
		pushup(x);
		//cout << x << ":" << at[x].xorr << endl;
		child = x;
		x = at[x].fa;
	}
	//cout << endl << endl;
}

void makeroot(int x) { //把x弄成根
	access(x);
	splay(x);
	reverse(x);
}

int findroot(int x) {
	access(x);
	splay(x);
	while (at[x].lson) {
		push_down(x);
		x = at[x].lson;
	}
	return x;
}

void spilt(int x, int y) { //建立x,y的实链
	makeroot(x);
	access(y);
	splay(y);
}

void cut(int x, int y) {
	spilt(x, y);
	if (at[y].lson != x || at[x].rson)
		return;
	at[x].fa = 0;
	at[y].lson = 0;
	pushup(y);
}

void link(int x, int y) {
	if (findroot(x) != findroot(y)) {
		//cout << findroot(x) << endl << findroot(y) << endl;
		makeroot(x);
		at[x].fa = y;
		pushup(y);
	}

}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &at[i].val);
		at[i].xorr = at[i].val;
	}

	while (m--) {
		int opt, a, b;
		cin >> opt >> a >> b;
		if (opt == 0) { 
			spilt(a, b);
			printf("%d\n", at[b].xorr);
		} else if (opt == 1)
			link(a, b);
		else if (opt == 2)
			cut(a, b);
		else {
			splay(a);
			at[a].val = b;
			
		}
	}
}
