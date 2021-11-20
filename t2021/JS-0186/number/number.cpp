/*I love Chtholly forever!*/
#include<cstdio>
#include<algorithm>
using namespace std;
long long read(){
	char c1=0,c2=0;
	long long tot=0;
	for(c1=getchar();c1<'0'||c1>'9';c1=getchar())c2=c1;
	for(;c1<='9'&&c1>='0';c1=getchar())tot=tot*10ll+c1-'0';
	if(c2=='-')tot=-tot;
	return tot;
}
void put(long long x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)put(x/10);
	putchar(x%10+'0');
}
struct str{
	long long x,id,ans;
	bool operator <(const str a)const{
		return x<a.x;
	}
}num[200005];
bool cmp(str a,str b){return a.id<b.id;}
long long n,max_num=10000010;
bool ch[10000015];
bool check(long long num){
	while(num){if(num%10==7)return 1;num/=10;}
	return 0;
}
void init(){
	for(long long i=1;i<=max_num;i++){
		if(ch[i]==1)continue;
		if(check(i)){
			ch[i]=1;
			for(long long j=1;j<=max_num;j++){
				if(i*j>max_num)break;
				ch[i*j]=1;
			}
		}
	}
	return;
}
void work(){
	sort(num+1,num+n+1);
	long long now=1;
	for(long long i=1;i<=max_num;i++){
		if(now>n)break;
		if(num[now].x>=i)continue;
		if(ch[i]==0){
			if(ch[num[now].x]==1){
				num[now].ans=-1;
				now++;
				i--;
				continue;
			}
			num[now].ans=i;
			now++;
			i--;
		}
	}
	return;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	n=read();
	for(long long i=1;i<=n;i++){
		num[i].x=read();
		num[i].id=i;
	}
	init();work();
	sort(num+1,num+n+1,cmp);
	for(long long i=1;i<=n;i++){
		put(num[i].ans);
		putchar('\n');
	}
	return 0;
}
