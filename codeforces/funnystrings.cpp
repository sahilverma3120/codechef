#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        ll x,y,a,b;
        cin>>x>>y>>a>>b;
        if(a==b){
            cout<<min(x/a,y/b)<<endl;
            continue;
        }
        ll d=a*a-b*b;
        ll n1 = (a*x - b*y)/d;
        ll ct=max(min(x/a,y/b),min(x/b,y/a));
        for(int i=n1-3;i<=n1+3;i++){
            if(i<0)
                continue;
            ll c2=min((x-a*i)/b,(y-i*b)/a);
            if(c2<0)
                continue;
            ct=max(i+c2,ct);
        }
        cout<<ct<<endl;
    }
    return 0;
}
