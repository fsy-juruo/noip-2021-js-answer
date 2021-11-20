#include <bits/stdc++.h>
using namespace std;

int read() {
	char ch = getchar();
	int x = 0, f = 1;
	while((ch > '9' || ch < '0') && ch != '-') {
		ch = getchar();
	}
	if(ch == '-') {
		ch = getchar();
		f = -1;
	}
	while(ch >= '0' && ch <= '9') {
		x = x * 10 + ch -'0';
		ch = getchar();
	}
	return x * f;
}

const int maxn = 1e4+10;

int n, ans = 0x7ffff;
int a[maxn];
map<string,bool>m;

void mybfs() {
	queue<string>q;
	string str;
	for(int i=1;i<=n;i++) {
		str += a[i] / 10 + '0';
		str += a[i] % 10 + '0';
	}
	q.push(str);
	m[str] = 1;
	while(q.size()) {
		string s = q.front();
		int cnt = 0, C = 0;
		for(int i=1;i<=n;i++) {
			int j = i*2-2, k = i*2-1;
			cnt += (s[j]-'0')*10+s[k]-'0';
			C += ((s[j]-'0')*10+s[k]-'0')*((s[j]-'0')*10+s[k]-'0');
		}
		ans = min(ans, n*C - cnt*cnt);
		q.pop();
		for(int i=2;i<n;i++) {
			int j = i * 2;
			int x = (s[j-2]-'0')*10+s[j-1]-'0';
			int y = (s[j-4]-'0')*10+s[j-3]-'0';
			int z = (s[j]-'0')*10+s[j+1]-'0';
			int h = y + z - x;
			s[j-2] = h / 10 + '0';
			s[j-1] = h % 10 + '0';
			if(!m[s]) {
				m[s] = 1;
				q.push(s);
			}
		}
	}
	
}

int main() {
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	n = read();
	for(int i=1;i<=n;i++)
		a[i] = read();
	mybfs();
	cout<<ans<<endl;
	return 0;
}
