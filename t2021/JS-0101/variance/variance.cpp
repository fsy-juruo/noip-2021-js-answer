#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[10051], ms[10051], vis[10051], w[10051], mm[10051];
double sq(int *s)
{
	double ret = 0, pr, ps, av = 0, N = n;
	for (int i = 1; i <= n; i++)
		av += (double)s[i];
	av /= N;
	for (int i = 1; i <= n; i++)
	{
		pr = (double)s[i] - av;
		ret += pr * pr;
	}
	ret *= n;
	return ret;
}
bool cmp(int aa, int bb)
{
	return aa > bb;
}
long long ans = INT_MAX;
void dfs(int pos)
{
	 if (pos > n)
	 {	 		
	 
	 	for (int i = 1; i <= n; i++)
	 		mm[i] = mm[i - 1] + ms[w[i]];
		int ret = (int)sq(mm);
	 	if (ret < ans)
	 	{
			ans = ret;
		}	
		return ;
	 }
	 for (int i = 2; i <= n; i++)
	 {
	 	if (!vis[i])
	 	{
	 		vis[i] = 1; w[pos] = i;
	 		dfs(pos + 1);
	 		vis[i] = 0;
		 }
	 }
}
int main()
{
	freopen("variance.in","r", stdin);
	freopen("variance.out","w",stdout);
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		ms[i] = a[i] - a[i - 1];
	if (n > 10)
	{
		for (int i = 1; i < n; i++)
	{
		w[i] = ms[i + 1];
	}
	sort(w + 1, w + n, cmp);
	int hd = 2, tl = n, flag = 1, tag = 1;
	ms[hd] = w[1]; ms[tl] = w[2]; int cnt = 3;
	hd++; tl--;
	while (hd <= tl)
	{
		if (flag == 1)
		{
			for (int i = 1; i <= tag && hd <= tl; i++)
			{
				ms[hd] = w[cnt]; hd++; cnt++;	
			}
		}
		else {
			for (int i = 1; i <= tag && hd <= tl; i++)
			{
				ms[tl] = w[cnt]; tl--; cnt++;
			}
		}
		flag ^= 1;
		tag++;
	}
	for (int i = 1; i <= n; i++)
		mm[i] = mm[i - 1] + ms[i];
	ans = (long long)sq(mm);
	cout << ans << '\n';
	}
	else {
		w[1] = 1;
		dfs(2);
		cout << ans << '\n';
	}
	return 0;
}
