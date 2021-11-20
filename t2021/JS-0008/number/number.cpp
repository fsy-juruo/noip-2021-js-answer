#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 1e7 + 10;
bool have[mxn], can[mxn];
int nex[mxn];

const int mxsz = 1 << 25;
char ibuf[mxsz], *iend = ibuf + mxsz, *ipos = iend;
char obuf[mxsz], *oend = obuf + mxsz, *opos = obuf;

inline char get_char() {
	if (ipos == iend) iend = (ipos = ibuf) + fread(ibuf, 1, mxsz, stdin);
	return ipos == iend ? EOF : *ipos ++;
}

inline void fast_flush() {
	fwrite(obuf, 1, opos - obuf, stdout);
	opos = obuf;
}

inline void put_char(char c) {
	if (opos == oend) fwrite(opos = obuf, 1, mxsz, stdout);
	*opos ++ = c;
}

inline void read(int &x) {
	x = 0; char c = get_char();
	while (c <= 32) c = get_char();
	while (c > 32) x = x * 10 + c - 48, c = get_char();
}

inline void writeln(int x) {
	static char stk[25];
	char *top = stk;
	if (x < 0) put_char(45), x *= -1; 
	if (!x) *top ++ = 48;
	while (x) *top ++ = x % 10 + 48, x /= 10;
	while (top -- != stk) put_char(*top);
	put_char(10);
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	for (int i = 1; i < mxn; ++ i) can[i] = true;
	for (int i = 1; i < mxn; ++ i) {
		have[i] = false;
		for (int x = i; x; x /= 10) have[i] |= x % 10 == 7;
	}
	for (int i = 1; i < mxn; ++ i) {
		if (have[i] && can[i]) {
			for (int j = i; j < mxn; j += i) {
				can[j] = false;
			}
		}
	}
	for (int i = mxn - 1, last = -1; i; -- i) {
		if (can[i]) {
			nex[i] = last;
			last = i;
		}
	}
	int q;
	read(q);
	while (q --) {
		int x;
		read(x);
		if (!can[x]) writeln(-1);
		else writeln(nex[x]);
	}
	fast_flush();
	return 0;
}

