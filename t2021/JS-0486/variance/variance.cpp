#include <bits/stdc++.h>
#include <bits/stdtr1c++.h>
using namespace std;
vector<int> v;
int n;
int ans=0x3f3f3f3f;

string vtos(vector<int> v){
    string s="";
    for(auto i:v){
        while(i){
            s.push_back(i%10+'0');
            i/=10;
        }
        s.push_back('#');
    }
    return s;
}

bool operator<(vector<int> va,vector<int> vb){
    return vtos(va)<vtos(vb);
}

set<vector<int> > van_dijk;
set<vector<int> > lfc;
set<vector<int> > llfc;
int tot=0;

bool discover(){
    bool f=true;
    for(auto a:llfc){
        for(int i=2;i<n;i++){
            a[i]=a[i+1]+a[i-1]-a[i];
            if(van_dijk.count(a)) continue; 
            f=false;
            van_dijk.insert(a);
            lfc.insert(a);
            a[i]=a[i+1]+a[i-1]-a[i];
        }
    }
    if(f) return false;
    else return true;
}

int main(){
    freopen("variance.in","r",stdin);
    freopen("variance.out","w",stdout);
    scanf("%d",&n);
    v.push_back(-1);
    for(int i=1;i<=n;i++){
        int x;scanf("%d",&x);
        v.push_back(x);
    }

    van_dijk.insert(v);
    llfc.insert(v);

    while(1){
        lfc.clear();
        bool f=discover();
        lfc.insert(v);
        for(auto a:lfc){
            int s=0,q=0;
            for(auto x:a) if(x!=-1) s+=x,q+=x*x;
            ans=min(ans,n*q-s*s);
        }
        if(!f) break;
        llfc=lfc;
    }

    cout<<ans<<endl;

    return 0;
}
