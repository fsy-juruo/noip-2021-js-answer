/* 
���У�sequence��
����Ŀ������
�������� n, m, k����һ������Ϊ m + 1 ������������ v0, v1, �� �� �� , vm��
����һ������Ϊ n���±�� 1 ��ʼ��ÿ��Ԫ�ؾ������� m �ķǸ��������� {ai}����
�Ƕ�������ȨֵΪ va1 �� va2 �� �� �� �� �� van��
������������ {ai} �������� S = 2^a1 + 2^a2 + �� �� �� + 2^an �Ķ����Ʊ�ʾ�� 1 �ĸ�����
���� k ʱ��������Ϊ {ai} ��һ���Ϸ����С�
�������кϷ����� {ai} ��Ȩֵ�Ͷ� 998244353 ȡģ�Ľ����
�������ʽ��
���ļ� sequence.in �ж������ݡ�
�����һ������������ n, m, k��
�ڶ��� m + 1 ���������ֱ��� v0, v1, �� �� �� , vm��
�������ʽ��
������ļ� sequence.out �С�
��һ��һ����������ʾ���кϷ����е�Ȩֵ�Ͷ� 998244353 ȡģ�Ľ����
k<=n<=30 m<=100*/
#include<stdio.h>
#include<time.h>
#define mod 998244353
#define N 32
#define K 32
#define M 128
typedef long long ll;
ll value[M];
ll jilu[128][32];//2^i-1 j��Ԫ�� 
ll dp[128][128][32]; //��iλ ǰ��j��1 ��j��������k��Ԫ�� 
#define jia(x1,x2)		((ll)((x1)+(x2))%mod)
#define jian(x1,x2)		((ll)((x1)-(x2)+mod)%mod)
#define cheng(x1,x2)	((ll)((x1)*(x2))%mod)
#define cheng2(x) ((ll)(x<<1)%mod)
ll power(ll di,ll zhi){
	ll ans=1;
	while(zhi>0){
		ans=(zhi&1)?cheng(ans,di):ans;
		di=cheng(di,di);
		zhi>>=1;
	}
	return ans;
}
#define ni(x)	power((x),mod-2) 
#define chu(x1,x2)   	(cheng((x1),ni((x2))))
int main(){
	//input
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<=m;++i){
		scanf("%d",value+i);
	}
	//calc dp
	jilu[0][0]=1;
	for(int i=1;i!=128;++i){
		jilu[i][1]=value[i-1];
		for(int j=1;j<=n;++j){
			for(int g=1;g!=j;++g){
				jilu[i][j]=jia(jilu[i][j],cheng(jilu[i-1][j-g],jilu[i-1][g]));
			}
		}
	}
	for(int i=0;i!=128;++i){
		dp[i][0][0]=1;
	}
	for(int i=1;i<=100;++i){
		for(int j=1;j<=i&&j<=n;++j){
			for(int g=1;g<=32;++g){
				dp[i][j][g]=dp[i-1][j][g];
				for(int h=1;h<=g;++h){
					dp[i][j][g]=jia(cheng(dp[i-1][j-1][g-h],jilu[i][h]),dp[i][j][g]);
				}
			}
		}
	}
	//calc
	ll ans=0;
	int i=3;
	for(int j=1;j<=k;++j){
		ans=jia(ans,dp[i][j][n]);
	}
	printf("%lld",ans);
	return 0;
}
