#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	ll T,n,i,x;
	cin>>T;
	while(T--){
		cin>>n;
		ll ml=1e9,mr=1e9;
		ll ans=1e16,sum=0,cnt1=0,cnt2=0;
		for(i=1;i<=n;i++){
			cin>>x;
			sum+=x;
			if(i%2)ml=min(ml,x),cnt1++;
			else mr=min(mr,x),cnt2++;
			ans=min(ans,sum+ml*(n-cnt1)+mr*(n-cnt2));
		}
		cout<<ans<<'\n';
	}
}
