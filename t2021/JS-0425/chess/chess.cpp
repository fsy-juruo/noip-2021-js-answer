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
大家好，我是JS-0425号选手，本人的所有整活事项将写在下方。
1. 关于 freopen ： line 90 
2. 关于友链 ： line 96 
3. 关于文明 ； line 104 
4. 关于毒奶 ： line 110 
5. 关于生日 ： line 112 
6. 关于游记 ： line 114 ~~514~~（谨慎食用，最好放到剪贴板里） 
*/

// freopen("chess.out","r",stdout);
// froepen('chess.in',"w",stdin);
// 恭喜亲爱的找整活人的同学：您被钓鱼了。
// 明显，这两串freopen在它们所不应该在的地方。
// 别急着收录，赶紧都督上下文，一起收录。 

// @bilibilitdasc 巨佬，感谢您在CSP-S中加上了我的友链，作为“广告费”，我这里也写一下友链（请收录人勿打码，谢谢） 
// 蒟蒻：@sszcdjr （zxx）
// 巨佬1：@bilibilitdasc （qjm）
// 巨佬2：@huagaohan （hgh）
// 巨佬3：@littlewave
// 另注1：前3人cf号同名
// 另注2：请勿人肉

// 傻逼CCF！傻逼NOIP！tmd智障！出题人没妈！
// 学校是我家，出题人没妈
// wow，我才知道，CCF和我一样傻逼。
// 猪呢？CCF呢？
// 想不出来别的了，就这么多QwQ

// 我tmd要是分数大于等于130我吃屎！

// NOIP当天是我的生日QwQ，本来以为可以得到高分，结果连T1都不会www

// NOIP2021 游记（爆炸记）
/*
## 11.？

进入NOIP！本来以为CSP-S 2=都不一定，这回成功晋级（CSP-S准考证号：JS-00656） 

## 11.2~11.19

平均以一天2绿/蓝的速度刷简单DP，以为能像CSP-S那样幸运，AC一道DP保底。

## 11.20 6:30

起床，前往nfls考场。

## 11.20 7:30

到达考场前，与hgh巨佬见面（貌似是第一次吧），门口与bilibilitdasc，huagaohan等人聊了好一会儿。

## 11.20 7:50

进入考场，简单整活了一会儿，结果发现考场的键盘"g"和"h"是反的/fn/fn/fn （注：本想写"考场的键盘'h'和'g'"，结果再次入坑QwQ） 

## 11.20 8:25

下载网页卡了好久才出来，严重浪费时间！

## 11.20 8:30

比赛正式开始！

首先看T1，感觉写个暴力过70分就行了，100分不会了，15min码完。

结果JSOI Linux爆炸，怎么提交都是“编译错误”，啥也提交不上去，慌了好一会儿，技术人员15min后过来修了一下，就好了。

我只想说：傻逼JSOI Linux，影响参赛体验！JS干嘛没事找事搞个这傻逼玩意。

## 11.20 9:05

OK，T1成功提交，预计得分70分（我开到了1e6，如果CCF还是用脚造数据。我觉得可以有80分吧 <- 奇思妙想） 

看T2，首先想暴力偏分，约30分（Testcase1~4，14~15）。

还没开始写，想到玄学状压DP可以过Testcase1~10，具体思路如下：

dp_{i,j} 表示填了i个数，和是j的方案数。

dp_{i,j}×a_k -> dp{i+1,j+(1<<k)} 

然后简单做了一下，用时20min，成功过大样例，应该可以得到50分。

目前预计得分：70+50+0+0=120 ，希望不要挂分 <- 继续奇思妙想 

## 11.20 9:40 

看了T3T4，不大会，回去看T1，把数组开到1e7，跑了一下后1000个数，用时2.0s，貌似开了O2可以过，但是不敢尝试，万一过不了就是0分，不想打赌了 （本身分就这么少www） 

## 11.20 10:10

决定T3暴力。（测试点1~3）

对于n<3或n>4，直接输出原来序列的方差。

对于n=3：考虑是否把a_2换成a_1+a_3-a_2。

对于n=4：dfs每次更改a_2或a_3，根据计算，复杂度并不高。

目前预计得分：70+50+15+0=135 。

## 11.20 10:45

决定T4尝试点7~8 ~~（才不会告诉你因为我考前没有复习图论所以不会点1~2呢） ~~ 。

大概思路就是尝试往左，往右，往上。往下，各1格，可以ans++，最后输出，应该是正确的吧！10分到手！ <- 再来奇思妙想

## 11.20 11:20

开始写游记，整活。 
*/ 
