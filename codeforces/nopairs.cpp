#include<bits/stdc++.h>
#define pb push_back
using namespace std;
int main()
{
	int t,i,j,k,c,d,x,ans;
	cin>>t;
	vector<int>l(3e7+1);
	for(i=2;i<3e7;i++)
		if(!l[i])
			for(j=i;j<3e7;j+=i)l[j]++;
	while(t--){
		ans=0;
		cin>>c>>d>>x;
		vector<int>s;
		for(j=1;j*j<x;j++)if(x%j==0)s.pb(j),s.pb(x/j);
		if(j*j==x)s.pb(j);
		for(auto q:s)if((x/q+d)%c==0)ans+=1<<l[(x/q+d)/c];
		cout<<ans<<'\n';
	}
}
