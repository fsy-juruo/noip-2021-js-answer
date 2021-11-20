#include <bits/stdc++.h>
using namespace std;
// ×¢ ÊÍ ÈË  
int n,m,k;
const int N=110;
const int mod=998244353;

namespace sub1{
    int mp[200010];
    int v[110];
    int lowbit(int x){return x&(-x);}
    int popcount(int x){
        int s=0;
        while(x){
            s++;
            x-=lowbit(x);
        }
        return s;
    }
    int power(int a,int b){
        int res=1;
        for(;b;b>>=1){
            if(b&1) res=res*a;
            a=a*a;
        }
        return res;
    }
    int p[20];
    int ans[100010][50];
    int ans_tot=0;

    bool solve_ans(int cur,int sum,int num){/*
        if(num==1){
            for(int i=0;i<m;i++) if(p[i]+1==sum){
                ans[ans_tot][n]=i;
                return true;
            }
            return false;
        }*/

        int x=sum-num;
        if(x<=num){
            ans_tot++;
            for(int i=n-num+1;i<=n-num+x;i++)
                ans[ans_tot][i]=1;
            for(int i=n;i>n-num+x;i--)
                ans[ans_tot][i]=0;
            //solve_ans(cur,mp[cur],n);
            return true;
        }/*
        else{
            bool flag=false;
            for(int i=1;i<m;i++){
                if(p[i]-1<=x){
                    ans[ans_tot][n-num+2]=i;
                    if(solve_ans(cur,sum-p[i]-1,num-1)){
                        flag=true;
                        ans_tot++;
                        for(int i=1;i<=n-num+1;i++){
                            ans[ans_tot][i]=ans[ans_tot-1][i];
                        }
                    }
                    else break;
                }
            }
            if(!flag)
                return false;
            else return true;
        }*/

        return false;
    }

    int main(){
        cin>>n>>m>>k;
        for(int i=1;i<=m+1;i++) cin>>v[i];
        int cnt=0;
        for(int i=n;i<=power(2,m)*n;i++){
            if(popcount(i)<=k) mp[++cnt]=i;
        }
        for(int i=1;i<=12;i++) p[i]=power(2,i)-1;
        for(int i=1;i<=cnt;i++) solve_ans(i,mp[i],n);
        int real_ans=0;
        for(int i=1;i<=ans_tot;i++){
            int tot=0;
            int pr=1;
            sort(ans[i]+1,ans[i]+n+1);
            do{
                tot++;
            }while(next_permutation(ans[i]+1,ans[i]+n+1));
            for(int j=1;j<=n;j++){
                pr*=v[ans[i][j]+1];
            }
            real_ans+=pr*tot;
        }

        cout<<real_ans<<endl;
        return 0;
    }
}

int main(){
    freopen("sequence.in","r",stdin);
    freopen("sequence.out","w",stdout);
    return sub1::main();
    return 0;
}
