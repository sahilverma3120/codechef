
#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int x=0,now;
		for(int i=1;i<=n;i++){
			cin>>now;
			cout<<(x&(~now))<<' ';
			x=now^(x&(~now));
		}
		cout<<endl;
	}
} 
