#include <bits/stdc++.h>
using namespace std;
vector<int> qp[200005];
vector<int> clm[200005];
vector<int> row[200005];
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,m,q;
		cin>>n>>m>>q;
		for(int i=0;i<=n+1;i++){
			qp[i].clear();
			for(int j=1;j<=m+2;j++){
				qp[i].push_back(0);
			}
		}
		for(int i=1;i<=n;i++){
			string s;
			cin>>s;
			clm[i].clear();
			clm[i].push_back(10000);
			for(int j=0;j<m-1;j++){
				clm[i].push_back(s[j]-'0');
			}
			clm[i].push_back(10000);
		}
		for(int j=0;j<m-1;j++){
			clm[0].push_back(10000);
		}
		for(int i=1;i<n;i++){
			string s;
			cin>>s;
			row[i].clear();
			row[i].push_back(10000);
			for(int j=0;j<m;j++){
				row[i].push_back(s[j]-'0');
			}
		}
		for(int j=0;j<m;j++){
			row[0].push_back(10000);
		}
		for(int j=0;j<m;j++){
			row[n].push_back(10000);
		}
		while(q--){
			int col,v,x,y;
			cin>>col>>v>>x>>y;
			qp[x][y]=col*100005+v;
			int ans=0;
			if(clm[x][y-1]==1&&(qp[x][y-1]==0||(qp[x][y-1]%100005<=v&&qp[x][y-1]/100005!=col))){
				ans++;
			}
			if(clm[x][y]==1&&(qp[x][y+1]==0||(qp[x][y+1]%100005<=v&&qp[x][y+1]/100005!=col))){
				ans++;
			}
			if(row[x-1][y]==1&&(qp[x-1][y]==0||(qp[x-1][y]%100005<=v&&qp[x-1][y]/100005!=col))){
				ans++;
			}
			if(row[x][y]==1&&(qp[x+1][y]==0||(qp[x+1][y]%100005<=v&&qp[x+1][y]/100005!=col))){
				ans++;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
/*
Things to check:
1. freopen
2. read twice ~~code ones,,debuh forever~~
3. for dp: any more dimensions? what does it mean? how to transfer?
4. keep your code clumsy but easy to understand.
5. check:i++ or j++?
6. if you feel bad,just write brute force and try to make it quicker
7. write every problem: just brute force for T3,T4
*/
/*
��Һã�����JS-0425��ѡ�֣����˵������������д���·���
1. ���� freopen �� line 90 
2. �������� �� line 96 
3. �������� �� line 104 
4. ���ڶ��� �� line 110 
5. �������� �� line 112 
6. �����μ� �� line 114 ~~514~~������ʳ�ã���÷ŵ�������� 
*/

// freopen("chess.out","r",stdout);
// froepen('chess.in',"w",stdin);
// ��ϲ�װ����������˵�ͬѧ�����������ˡ�
// ���ԣ�������freopen����������Ӧ���ڵĵط���
// ������¼���Ͻ����������ģ�һ����¼�� 

// @bilibilitdasc ���У���л����CSP-S�м������ҵ���������Ϊ�����ѡ���������Ҳдһ������������¼������룬лл�� 
// �X�m��@sszcdjr ��zxx��
// ����1��@bilibilitdasc ��qjm��
// ����2��@huagaohan ��hgh��
// ����3��@littlewave
// ��ע1��ǰ3��cf��ͬ��
// ��ע2����������

// ɵ��CCF��ɵ��NOIP��tmd���ϣ�������û�裡
// ѧУ���Ҽң�������û��
// wow���Ҳ�֪����CCF����һ��ɵ�ơ�
// ���أ�CCF�أ�
// �벻��������ˣ�����ô��QwQ

// ��tmdҪ�Ƿ������ڵ���130�ҳ�ʺ��

// NOIP�������ҵ�����QwQ��������Ϊ���Եõ��߷֣������T1������www

// NOIP2021 �μǣ���ը�ǣ�
/*
## 11.��

����NOIP��������ΪCSP-S 2=����һ������سɹ�������CSP-S׼��֤�ţ�JS-00656�� 

## 11.2~11.19

ƽ����һ��2��/�����ٶ�ˢ��DP����Ϊ����CSP-S�������ˣ�ACһ��DP���ס�

## 11.20 6:30

�𴲣�ǰ��nfls������

## 11.20 7:30

���￼��ǰ����hgh���м��棨ò���ǵ�һ�ΰɣ����ſ���bilibilitdasc��huagaohan�������˺�һ�����

## 11.20 7:50

���뿼������������һ�����������ֿ����ļ���"g"��"h"�Ƿ���/fn/fn/fn ��ע������д"�����ļ���'h'��'g'"������ٴ����QwQ�� 

## 11.20 8:25

������ҳ���˺þòų����������˷�ʱ�䣡

## 11.20 8:30

������ʽ��ʼ��

���ȿ�T1���о�д��������70�־����ˣ�100�ֲ����ˣ�15min���ꡣ

���JSOI Linux��ը����ô�ύ���ǡ�������󡱣�ɶҲ�ύ����ȥ�����˺�һ�����������Ա15min���������һ�£��ͺ��ˡ�

��ֻ��˵��ɵ��JSOI Linux��Ӱ��������飡JS����û�����¸����ɵ�����⡣

## 11.20 9:05

OK��T1�ɹ��ύ��Ԥ�Ƶ÷�70�֣��ҿ�����1e6�����CCF�����ý������ݡ��Ҿ��ÿ�����80�ְ� <- ��˼���룩 

��T2�������뱩��ƫ�֣�Լ30�֣�Testcase1~4��14~15����

��û��ʼд���뵽��ѧ״ѹDP���Թ�Testcase1~10������˼·���£�

dp_{i,j} ��ʾ����i����������j�ķ�������

dp_{i,j}��a_k -> dp{i+1,j+(1<<k)} 

Ȼ�������һ�£���ʱ20min���ɹ�����������Ӧ�ÿ��Եõ�50�֡�

ĿǰԤ�Ƶ÷֣�70+50+0+0=120 ��ϣ����Ҫ�ҷ� <- ������˼���� 

## 11.20 9:40 

����T3T4������ᣬ��ȥ��T1�������鿪��1e7������һ�º�1000��������ʱ2.0s��ò�ƿ���O2���Թ������ǲ��ҳ��ԣ���һ�����˾���0�֣��������� ������־���ô��www�� 

## 11.20 10:10

����T3�����������Ե�1~3��

����n<3��n>4��ֱ�����ԭ�����еķ��

����n=3�������Ƿ��a_2����a_1+a_3-a_2��

����n=4��dfsÿ�θ���a_2��a_3�����ݼ��㣬���ӶȲ����ߡ�

ĿǰԤ�Ƶ÷֣�70+50+15+0=135 ��

## 11.20 10:45

����T4���Ե�7~8 ~~���Ų����������Ϊ�ҿ�ǰû�и�ϰͼ�����Բ����1~2�أ� ~~ ��

���˼·���ǳ����������ң����ϡ����£���1�񣬿���ans++����������Ӧ������ȷ�İɣ�10�ֵ��֣� <- ������˼����

## 11.20 11:20

��ʼд�μǣ���� 
*/ 
