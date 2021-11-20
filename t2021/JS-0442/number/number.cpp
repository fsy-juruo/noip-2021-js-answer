#include<stdio.h>
#include<time.h>
#define N ((int)1e7)
typedef unsigned long long ull;
bool mp[N+17];
int cnt[N+17];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int x1=0;x1!=10;++x1){
		if(x1==7) continue;
		for(int x2=0;x2!=10;++x2){
			if(x2==7) continue;
			for(int x3=0;x3!=10;++x3){
				if(x3==7) continue;
				for(register int x4=0;x4!=10;++x4){
					if(x4==7) continue;
					for(register int x5=0;x5!=10;++x5){
						if(x5==7) continue;
						for(register int x6=0;x6!=10;++x6){
							if(x6==7) continue;
							for(register int x7=0;x7!=10;++x7){
								if(x7==7) continue;
								mp[1000000*x1+\
							       100000*x2+\
							       10000*x3+\
							       1000*x4+\
							       100*x5+\
							       10*x6+x7]=true;
							}
						}
					}
				}
			}
		}
	}
	mp[N]=mp[N+1]=mp[N+2]=mp[N+3]=mp[N+4]=mp[N+5]=mp[N+6]=true;
	for(int i=1;i<=N;++i){
		if(!mp[i]){
			for(register int j=i;j<=N+6;j+=i){
				mp[j]=false;
			}
		}
	}
	for(register int i=1;i!=N+7;++i){
		cnt[i]=mp[i]+cnt[i-1];
	}
	int n;
	scanf("%d",&n);
	while(n--){
		int x;
		scanf("%d",&x);
		if(!mp[x]){
			puts("-1");
		}else{
			register int lef=x+1,rig=N+6,tmp=cnt[x];
			while(lef<rig){
				register int mid=(lef+rig)>>1;
				if(cnt[mid]==tmp){
					lef=mid+1;
				}else{
					rig=mid;
				}
			}
			printf("%d\n",lef);
		}
	}
	return 0;
}
