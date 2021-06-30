#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		char s[1010];
		for(int i=0;i<n;i++)
			cin >> s[i];
		int f=0;
		int cnt=0;
		for(int i=0;i<n;i++){
			if(s[i]=='0')
				cnt++;
			if(s[i]!=s[n-i-1])
				f=1;
		}
		if(!f){
			if(n%2!=0&&s[n/2]!='1'&&cnt!=1)
				cout << "ALICE" << endl;
			else 
				cout << "BOB" << endl;
		}else{
			if(n%2!=0&&cnt==2&&s[n/2]=='0')
				cout << "DRAW" << endl;
			else
				cout << "ALICE" << endl;
		}
	}
	return 0;
}
