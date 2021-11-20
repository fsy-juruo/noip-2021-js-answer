#include<bits/stdc++.h>
using namespace std;
int n,i,a[11100];
int main()
{
  freopen("variance.in","r",stdin);
  freopen("variance.out","w",stdout);
  scanf("%d",&n);
  for(i=1;i<=n;i++)
    scanf("%d",&a[i]);
  printf("%lld\n",1ll*(a[n]-(a[n]+a[1])/2)*n*(a[n]-(a[n]+a[1])/2));
  return 0;
}
