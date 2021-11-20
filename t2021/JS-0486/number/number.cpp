#include <bits/stdc++.h>
using namespace std;
//luogu uid:243057

int t;

bool check(int x){
    while(x){
        int y=x%10;
        if(y==7) return false;
        else x/=10;
    }
    return true;
}

namespace sub1{
    const int N=1000010;
    bool f[N];
    void pre(){
        for(int i=1;i<N;i++){
            if(!check(i)) f[i]=1;
        }

        for(int i=1;i<N;i++){
            if(f[i]){
                for(int j=i+i;j<N;j+=i){
                    f[j]=1;
                }
            }
        }
    }

    int main(){
    	pre();
        while(t--){
            int x;
            cin>>x;
            if(f[x]) printf("-1\n");
            else{
                for(int i=x+1;;i++){
                    if(!f[i]){
                        printf("%d\n",i);
                        break;
                    }
                }
            }
        }

        return 0;
    }
}

namespace sub2{
    const int N=20000010;
    bool f[N];
    void pre(){
        for(int i=1;i<N;i++){
            if(!check(i)) f[i]=1;
        }

        for(int i=1;i<N;i++){
            if(f[i]){
                for(int j=i+i;j<N;j+=i){
                    f[j]=1;
                }
            }
        }
    }

    int main(){
    	pre();
        while(t--){
            int x;
            cin>>x;
            if(f[x]) printf("-1\n");
            else{
                for(int i=x+1;;i++){
                    if(!f[i]){
                        printf("%d\n",i);
                        break;
                    }
                }
            }
        }

        return 0;
    }
}

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    scanf("%d",&t);
    if(t<=10000) return sub1::main();
    else return sub2::main();
    return 0;
}
