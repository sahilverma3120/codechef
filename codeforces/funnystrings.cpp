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
        for(int i=n1-30;i<=n1+30;i++){
            if(i<0)
                continue;
            ll c2=min((x-a*i)/b,(y-i*b)/a);
            if(x<a*i || y<b*i)
                continue;
            ct=max(i+c2,ct);
        }
        ll n2 = (a*y - b*x)/d;
        for(int i=n2-30;i<=n2+30;i++){
            if(i<0)
                continue;
            ll c2=min((x-b*i)/a,(y-i*a)/b);
            if(x<b*i || y<a*i)
                continue;
            ct=max(i+c2,ct);
        }
        cout<<ct<<endl;
    }
    return 0;
}
