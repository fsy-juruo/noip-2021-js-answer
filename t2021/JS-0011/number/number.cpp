#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e7 + 5;

int nxt[maxn];
bool has[maxn], ok[maxn];

int main(){
  freopen("number.in", "r", stdin);
  freopen("number.out", "w", stdout);
  
  int T; scanf("%d", &T);

  for(int i = 1; i < maxn; ++i)
    has[i] = (has[i / 10] || (i % 10 == 7)), ok[i] = true;
  for(int i = 1; i < maxn; ++i){
    if(has[i]){
      ok[i] = false;
      for(int j = i + i; j < maxn; j += i)
	ok[j] = false;
    }
  }

  for(int i = maxn - 1; i; --i){
    if(ok[i])
      nxt[i] = i;
    else{
      if(i + 1 == maxn)
	nxt[i] = -1;
      else
	nxt[i] = nxt[i + 1];
    }
  }
  
  while(T--){
    int x; scanf("%d", &x);
    if(ok[x])
      printf("%d\n", nxt[x + 1]);
    else
      puts("-1");
  }
  return 0;
}
