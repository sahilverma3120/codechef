#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
    int n;
    cin>>n;
    int a[n],sum=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    sum = sum/2;
    sort(a,a+n);
   int cnt=0;
   int ans=0;
        for(int i=n-1;i>=0;i--){
            ans+=a[i];
            cnt++;
            if(ans>sum)
                break;
        }
        cout<<cnt<<endl;
    return 0;
}
