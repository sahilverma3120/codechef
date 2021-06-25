#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define rep(i,n) for (int i=0;i<n;i++)

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef pair<ll,ll> pll;
typedef vector<pll> vpl;
typedef set<ll> sll;
typedef unordered_set<ll> usll;
typedef queue<ll> qll;

ll infty=1e20;
ll prime=998244353;

int main(){
    ll n,m;cin>>n>>m;
    vvll tim (n, vll {});
    rep(i,n){
        ll a,b,c;
        cin>>a>>b>>c;
        tim[i]={a-1,b,c};
    }
    vvvll pot (m+1,vvll (n,vll {}));
    rep(i,m+1){
        rep(j,n){
            ll x=tim[j][1];
            ll cont=1e5;
            if(tim[j][0]==0){
                //cout<<(cont+x-1)/cont<<endl;
                if(i<(cont-1+x)/cont)continue;
                pot[i-(cont-1+x)/cont][j].push_back(i);
            }
            if(tim[j][0]==1){
                if(i==0)continue;
                ll y=(i*cont)/x;
                if((i-1)*cont<y*x){
                    pot[y][j].push_back(i);
                }
            }
        }
    }
    priority_queue<vll> q;
    q.push({0,0,0});
    vll wh (m,infty);
    if(n==198){
        cout<<"hei"<<endl;
    }
    while(q.size()){
        vll u=q.top();
        q.pop();
        //cout<<u[0]<<" "<<u[1]<<" "<<u[2]<<endl;
        if(u[0]+n==0)continue;
        //cout<<u[0]<<" "<<u[1]<<" "<<u[2]<<endl;
        q.push({u[0]-1,0,u[2]});
        if(-u[1]==tim[-u[0]][2])continue;
        for(auto i: pot[-u[2]][-u[0]]){
            wh[i-1]=min(wh[i-1],-u[0]);
            q.push({u[0],u[1]-1,-i});
        }
    }
    rep(i,m)if(wh[i]==infty)wh[i]=-2;
    rep(i,m)cout<<wh[i]+1<<" ";
    cout<<endl;
}


