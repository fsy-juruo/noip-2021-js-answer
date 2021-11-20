#include<bits/stdc++.h>
using namespace std;

const int V=1e7+100;

bool have7(int x){
    while(x){
        if(x%10==7)return true;
        x/=10;
    }
    return false;
}

int nxt[V+5];
bool vis[V+5];

void mian(){
    int x;
    cin>>x;
    if(vis[x])cout<<"-1\n";
    else cout<<nxt[x+1]<<'\n';
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    for(int i=1;i<=V;i++)if(!vis[i]&&have7(i)){
        for(int j=i;j<=V;j+=i)vis[j]=1;
    }
    for(int i=V;i>=1;i--)nxt[i]=vis[i]?nxt[i+1]:i;
    int T;
    cin>>T;
    while(T--)mian();

    return 0;
}