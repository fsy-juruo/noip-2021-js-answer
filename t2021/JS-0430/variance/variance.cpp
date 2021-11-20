#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
ll read()
{
	ll k,f=1;
	char c;
	while((c=getchar())<'0'||c>'9') if(c=='-') f=-1;
	k=c^48;
	while((c=getchar())>='0'&&c<='9')
	k=(k<<3)+(k<<1)+(c^48);
	return k*f;
}
void put(ll k)
{
	if(k<0) putchar('-'),k=~k+1;
	if(k>9) put(k/10);
	putchar(k%10+'0');
}
const ll M=20520;
ll n;
ll a[M];
ll c[M],cnt;
ll l[M],r[M],lt,rt;
bool f;
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	n=read();
	for(ll i=1;i<=n;i++) a[i]=read();
	cnt=a[n]-a[1];
	for(ll i=1;i<n;i++) c[i]=a[i+1]-a[i];
	sort(c+1,c+n);
	reverse(c+1,c+n);
	for(ll i=1;i<n;i+=2) if(c[i]!=0) l[i/2+1]=c[i],l[0]+=c[i],lt++;
	for(ll i=2;i<n;i+=2) if(c[i]!=0) r[i/2]=c[i],r[0]+=c[i],rt++;
	if(lt!=rt) rt++,r[rt]=0;
//	for(ll i=0;i<rt;i++)
//	{
//		sort(l+1,l+lt+1);
//		reverse(l+1,l+lt+1);
//		sort(r+1,r+rt+1);
//		reverse(r+1,r+rt+1);
//		if(l[0]-r[0]<=1) break;
		for(ll j=rt;j>=/*i+*/1;j--)
		{
			ll k=j/*-i*/;
			if(l[k]<=r[j]) continue;
			if(l[0]-l[k]+r[j]>=r[0]-r[j]+l[k])
			{
				l[0]-=l[k]-r[j];
				r[0]+=l[k]-r[j];
				swap(l[k],r[j]);
			}
		}
//	}
//		cout << l[0] << ' ' << r[0] << endl;
	sort(l+1,l+lt+1);
	sort(r+1,r+rt+1);
	reverse(l+1,l+lt+1);
	for(ll i=1;i<=lt;i++) c[i]=l[i];
	for(ll i=lt+1;i<n-1-rt;i++) c[i]=0;
	for(ll i=n-rt;i<=n-1;i++) c[i]=r[i+rt+1-n];
//	for(ll i=1;i<n;i++) cout << c[i] << ' ';
//	cout << endl;
	for(ll i=2;i<=n;i++) a[i]=a[i-1]+c[i-1];
//	for(ll i=1;i<=n;i++) put(a[i]),putchar(' ');
//	putchar('\n');
	for(ll i=1;i<=n;i++) a[i]*=n;
	ll cnt=0;
	for(ll i=1;i<=n;i++) cnt+=a[i];
	a[0]=cnt/n;
	cnt=0;
	for(ll i=1;i<=n;i++) cnt+=(a[i]-a[0])*(a[i]-a[0]);
	cout << cnt/n << endl;
	return 0;
}
