#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
#define pb push_back
#define mp make_pair
/*By sahilverma3120, contest: Codeforces Global Round 13, problem: (A) K-th Largest Value, Accepted*/
#define sp <<" "
#define nl cout<<"\n"
#define pii pair<int,int>
#define int long long int 
#define FOR(i,a) for(int i=0;i<a;i++)
#define print(arr,n) for(int i=0;i<n;i++)cout<<arr[i]<<" "
#define scan(arr,n) for(int i=0;i<n;i++)cin>>arr[i]
#define MOD(x) x%998244353
#define MAX INT_MAX
#define MIN INT_MIN
#define ff first
#define ss second
#define vi vector<int>
#define minimum(a) *min_element(a.begin(), a.end())
#define maximum(a) *max_element(a.begin(), a.end())
#define mem(x,val) memset((x),(val),sizeof(x))
#define sqr(x) x*x
#define startTime clock_t start, end; start = clock();
#define endTime end = clock(); double time_taken = double(end - start) / double(CLOCKS_PER_SEC); cout << "Time taken by program is : " << fixed  << time_taken << setprecision(5);cout << " sec " << endl; 
#define all(a) a.begin(),a.end()
int inverse_factorial[500005];
int books_S[500005];
int moduo=998244353;

int facto[500005];
int gpa[1<<19], gpb[1<<19];
const int mod = 1e9 + 7;
const int inf = 1e10 + 20;

void prep(){
    inverse_factorial[1]=inverse_factorial[0]=1;
    books_S[1]=books_S[0]=1;
    facto[1]=facto[0]=1;
    for(int i=2;i<200005;i++){
        books_S[i] = books_S[moduo%i]*(moduo-moduo/i)%moduo;
    }
    for(int i=2;i<200005;i++){
        facto[i]=(facto[i-1]*i)%moduo;
    }
    for(int i=2;i<200005;i++){
        inverse_factorial[i]=(books_S[i]*inverse_factorial[i-1])%moduo;
    }
}
void solve(){
    int n,q;
    cin>>n>>q;
    int a[n];
    scan(a,n);
    int c=0,b=0;
    FOR(i,n){
        if(a[i])b++;
        else c++;
    }
    FOR(ii,q){
        int x,y;
        int K =0,M=1;
        cin>>x>>y;
        if(x==1){
            if(a[y-1])b--,c++;
            else c--,b++;
            a[y-1]=!a[y-1];
        }
        else{
            if(y<=b)cout<<M;
            else cout<<K;
            nl;
        }
    }
}

signed main(){
    // startTime
  
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
        solve();
  
    return 0;
}
