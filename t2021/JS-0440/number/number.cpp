#include<bits/stdc++.h>
#define N 10000005
using namespace std; 
int T,x[200005],p[3000005],cnt,ans[10000005],mx,now;
bitset<N>vis1,vis2,vis3;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&T);
	for(int i=1;i<=T;i++){
		scanf("%d",&x[i]);
		mx=max(mx,x[i]);		
	}
	for(int i=2;i<=10000000;i++){
		if(i%10==7||vis3[i/10])vis3[i]=vis2[i]=1;
		if(i%7==0)vis2[i]=1;
	}
	for(int i=2;i<=10000000;i++){
		if(!vis1[i]){
			for(int j=i;j<=10000000;j+=i){
				vis1[j]=1;
				if(vis2[i]||vis2[j/i])vis2[j]=1;
			}
		}
	}
	now=10000001;
	for(int i=10000000;i>=1;i--){
		ans[i]=now;
		if(!vis2[i])now=i;
	}
	for(int i=1;i<=T;i++){
		if(!vis2[x[i]])printf("%d\n",ans[x[i]]);
		else printf("-1\n");
	}
	fclose(stdin);
	fclose(stdout);
}
//T1����
//��ȴ�887�죬��һ���888�ˣ� 
//��ָһ�㣬���컹�Ǻ�npy wxt��׵ĵ�400�졣
//��������400����
//Ҳû������CSP��300+�ְ��� 
//�����������϶�Ҫ���������ϼ���
//�󱣻���˽��Ҫ����ߵ�ȫ�ų�������һ���˶�֪������˭�� 
//freopen("number.in","r",stdin);(�ղ���) 
//��ǰд��һЩ������ϣ������ʱ�����RP++!
