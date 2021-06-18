#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define FAST1 ios_base::sync_with_stdio(false);
#define FAST2 cin.tie(NULL);
ll n;
vector<ll> ask(ll node){
    cout<<"? "<<node+1<<endl;
    vector<ll> ans(n);
    for(ll i=0;i<n;i++){
        cin>>ans[i];
    }
    return ans;
}

void dfs(vector<vector<ll>> & graph,ll u, ll par){
    for(auto & to:graph[u]){
        if(to==par) continue;
        cout<<u+1<<" "<<to+1<<endl;
        dfs(graph,to,u);
    }
}

void solve(){
    cin>>n;
    auto gt = ask(0);
    vector<vector<ll>> graph(n);
    ll osum=0,esum=0;
    for(ll i=0;i<n;i++){
        if(gt[i] & 1){
            osum++;
        }
        else{
            esum++;
        }
    }
    if(esum<=osum){
        for(ll i=0;i<n;i++){
            if(gt[i]==1){
                graph[0].push_back(i);
                graph[i].push_back(0);
            }
        }
        for(ll i=2;i<n;i+=2){
            for(ll j=0;j<n;j++){
                if(gt[j]==i){
                    auto res = ask(j);
                    for(ll k=0;k<n;k++){
                        if(res[k]==1){
                            graph[j].push_back(k);
                            graph[k].push_back(j);
                        }
                    }
                }
            }
        }
    }
    else{
        for(ll i=1;i<n;i+=2){
            for(ll j=0;j<n;j++){
                if(gt[j]==i){
                    auto res = ask(j);
                    for(ll k=0;k<n;k++){
                        if(res[k]==1){
                            graph[j].push_back(k);
                            graph[k].push_back(j);
                        }
                    }
                }
            }
        }
    }
    cout<<"!"<<endl;
    dfs(graph,0,-1);
}

int main(){
    FAST1;
    FAST2;
    ll t=1;
    while(t--){
        solve();
    }
}
