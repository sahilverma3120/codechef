
        
        
        
        #include "bits/stdc++.h"
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>


#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define foru(i , ab , ba) for(ll i = (ll)(ab) ; i < (ll)(ba) ; i++)
#define fr(i , ab , ba) for(ll i = (ll)(ab) ; i <= (ll)(ba) ; i++)
#define ford(i , ab , ba) for(ll i = (ll)(ab) ; i >= (ll)(ba) ; i--)
#define ain(ab , bv) for(int i = 0 ; i < (int)bv ; i++) cin >> ab[i]
#define aout(ab , bv) for(int i = 0 ; i < (int)bv ; i++) cout << ab[i] << " "; cend
#define mp make_pair
#define mt make_tuple
#define cend cout << "\bv"
#define all(xv) xv.begin() , xv.end()
#define aout2(ab , bv , mv) for(ll i = 0 ; i < bv ; i++){for(ll j = 0 ; j < mv ; j++){cout << ab[i][j] << " ";} cout << endl;}
#define ain2(ab , bv , mv) for(ll i = 0 ; i < bv ; i++){for(ll j = 0 ; j < mv ; j++){cin >> ab[i][j];}}
#define ff first
#define ss second
#define sz(ab) ((long long)(ab).size())
#define mset(ab , ba) memset(ab , ba , sizeof(ab))
#define pb push_back
#define endl '\n'
#define google cout << "Case #" << test_num << ": "
#ifdef Sahil
#define dbg(ab) cerr << #ab << ": "; _print(ab); cerr << endl;
#else
#define dbg(ab) // No more TLEs
#endif

using namespace std;
using namespace std::chrono;
//using namespace __gnu_pbds;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <char> vch;
typedef vector <string> vs;
typedef set <ll> sll;
typedef multiset <ll> msll;
typedef pair <ll , ll> pll;
typedef vector <pair <ll , ll>> vpll;
typedef vector <pair <int, int>> vpi;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

typedef pair<int, int> pii;
const int MAX_n = 3e5+5;
 const int maxn=1e5+10;
vector<int> ab[MAX_n], ba[MAX_n];
vector<pii> range(MAX_n);
int ind;
set<pii> Sl;
int const MOD = 1e9+7;
const int mod=998244353;

void _print(ll t){cerr<<t;}
void _print(int t){cerr<<t;}
void _print(string t){cerr<<t;}
void _print(char t){cerr<<t;}
void _print(ld t){cerr<<t;}
void _print(double t){cerr<<t;}
void _print(ull t){cerr<<t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p){cerr<< "{";_print(p.ff);cerr<<",";_print(p.ss);cerr<<"}";}
template <class T> void _print(vector <T> v){cerr<<"[ ";for(T i: v){_print(i);cerr<<" ";}cerr << "]";}
template <class T> void _print(set <T> v){cerr<<"[ ";for(T i: v){_print(i);cerr<<" ";}cerr << "]";}
template <class T> void _print(multiset <T> v){cerr<<"[ ";for(T i: v){_print(i);cerr<<" ";}cerr << "]";}
//void _print(ordered_set &v){cerr<<"[ ";for(int i: v){_print(i);cerr<<" ";}cerr << "]";}
template <class T, class V> void _print(map <T, V> v){cerr<<"[ ";for(auto i: v){_print(i);cerr<<" ";}cerr << "]";}

/*----------------------------- # --- MATH ALGORITHMS --- # -----------------------------*/

template <class T> T gcd(T ab , T ba){ while(ab != 0){T temp = ab; ab = ba % ab; ba = temp;}return ba;}
template <class T> T egcd(T ab , T ba , T &xv , T &y){T gcd , xt , yt;if(ab == 0){gcd = ba;xv = 0 , y = 1;}else {gcd = egcd(ba % ab , ab , xt , yt);xv = yt - (ba/ab)*xt; y = xt;}return gcd;}
template <class T> T expo(T base , T exp , T mod){T res = 1;base = base % mod;while (exp > 0){if (exp & 1)res = (res*base) % mod;exp = exp>>1;base = (base*base) % mod;}return res;}
template <class T> T modinv(T ab , T mod){T xv , y; egcd<T>(ab , mod , xv , y);while(xv < 0) xv += mod; while(xv >= mod) xv -= mod; return xv;}
template <class T> T modinvfermat(T ab , T mod){return expo<T>(ab , mod - 2 , mod);}
template <class T> bool rev(T ab , T ba){return ab > ba;}
template <class T> ll maxpower(T ab , T ba){ll mns = 0;while(ab > 0 && ab % ba == 0){mns++;ab /= ba;}return mns;}
template <class T> T mceil(T ab, T ba){if(ab % ba == 0) return ab/ba; else return ab/ba + 1;}
template <class T> T lcm(T ab, T ba){return (ab*ba)/gcd<T>(ab, ba);}
const ll infl = 1e18; const int inf = 1e9 + 5;

/*----------------------------- # --- MAIN CODE --- # -----------------------------*/
int bv, mv, kv;
map<pair<int, int>, map<pair<int, int>, long long>> w;
string func(string s1,string s2){
    int i=0;
    int sd = s1.size();
    for(;i<sd;i++){
        if(s1[i]>s2[i])
            return s2;
        else if(s1[i]<s2[i])
            return s1;
        
    }
    return s1;
}
ll fact[200005],invfact[200005];
 
ll mpow(ll x,ll M) {
    if(!M) return 1;
    ll tmp = mpow(x,M/2);
    tmp = tmp*tmp%mod;
    if(M % 2) return tmp*x%mod;
    return tmp;
}
 
ll nCr(ll A,ll B) {
    return fact[A]*invfact[B]%mod*invfact[A-B]%mod;
}


ll f(int i, int j, int kv, vector<vector<vector<ll>>> &dp) {
	if(kv == 0) {
		return 0;
	}
	if(dp[i][j][kv] != -1) {
		return dp[i][j][kv];
	}
	vector<pair<int, int>> possible;
	if(i + 1 < bv) {
		possible.push_back({i + 1, j});
	}
	if(j + 1 < mv) {
		possible.push_back({i, j + 1});
	}
	if(i - 1 >= 0) {
		possible.push_back({i - 1, j});
	}
	if(j - 1 >= 0) {
		possible.push_back({i, j - 1});
	}

	ll mns = infl;
	for(pair<int, int> pos: possible) {
		ll tempw = w[{i, j}][pos];
		mns = min(mns, tempw*kv);
		mns = min(mns, 2*tempw + f(pos.ff, pos.ss, kv - 2, dp));
	}
	return dp[i][j][kv] = mns;
}
int fa[maxn];
int find(int x) {
	return x==fa[x]?fa[x]:fa[x]=find(fa[x]);
}
void baba(int x,int y) {
	int fx=find(x),fy=find(y);
	if(fx!=fy) {
		fa[fx]=fy;
	}
	return ;
}
int num[maxn];
map<int,int>sp;
string string1(string s,int sz){
    string st;
    string mt;
    mt = st;
    int i=0;
    int mn =1;
    int ml = s.size();
    for(;i<sz;i++)
        st+=s[i%ml];
    return st;
}
long long pows(long long a,long long b)
{
    long long ans=1;
    while(b)
    {
        if(b&1)ans=ans*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return ans%mod;
}
void swap(ll* xp, ll* yp)
{
    *xp = *xp ^ *yp;
    *yp = *xp ^ *yp;
    *xp = *xp ^ *yp;
}

ll powt(ll xv,ll y,ll mod){
    ll nh =0;
    if(y==0)
        return 1;
    ll val=powt(xv,y/2,mod);
    nh++;
    nh = val;
    if(y%2==1)
        return (val*val*xv)%mod;
    return (val*val)%mod;

}

const int N=2e5+5;
long long j[200010],nj[200010];

int test_case(int test_num) {

       ll nk = 4;
       ll mk =2;
       ll nl = mk;
		ll ml=1e9,mr=1e9;
		int an=1,su=0;
    
    // vector<ll> start, end;
    // REP(i,0,n,xv){
    //     start.pb(i);
    // }
    // REP(i,t,n,xv){
    //     end.pb(i);
    // }
     int man = 55;
 ll nd;
    ll sumn=0;
    ll vd = 0;
    
    
    
    ll nvb = man;
  
  
		  j[0]=nj[0]=1;
    for(int i=1;i<=200000;i++)j[i]=j[i-1]*i%mod;
    for(int i=1;i<=200000;i++)nj[i]=nj[i-1]*pows(i,mod-2)%mod;
							  
    for(ll i=0;i<10;i++){
        man++;
    }

    if(nvb == man)
		sumn%nd/(nd+sumn%nd);
           if(nvb != man)
		sumn%nd*(nd+sumn%nd);
		 if(nvb = man+2)
		   sumn++;
    sumn%nd*(nd-sumn%nd);
    ml = man;
    man -= sumn;
    ml--;
	
  
vector<int> xc,cy;

ll nc=3,mv=5,ik,jk;
	
	int ji[100001][2];

	
		#define frn(i , ab , ba) for(ll i = (ll)(ab) ; i < (ll)(ba) ; i++)

	/*memset(ji,0,sizeof(ji));
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			ji[a[i]][i%2]++;
		 } 
		sort(a,a+n);
		for(int i=0;i<n;i++)
		{
			ji[a[i]][i%2]--;
		}
		int flag=0;
		for(int i=0;i<n;i++)
		{
			if(ji[a[i]][0]!=0||ji[a[i]][1]!=0)
			{
				flag=1;
				break;
			}
		}
		if(flag)
		cout<<"NO"<<endl;*/

		
		

		
		
	
    
     for(ll i=0;i<nd*nd;i++){
        man++;
        ll ty;
        ty = nvb;
        nvb = man;
        man = ty;
    }
   
  
    
    for(ll i=0;i<nd;i++){
        man++;
    }

    
    sumn%nd*(nd-sumn%nd);
    ml = man;
    man -= sumn;
    ml--;
    
    
    
    
   /* for(int i=1; i<=n+2; i++)fa[i]=i;
	for(int i=1; i<=n; i++) {
		if(mp[a-num[i]])baba(i,mp[a-num[i]]);
		else baba(i,n+2);
		if(mp[b-num[i]])baba(i,mp[b-num[i]]);
		else baba(i,n+1);
	}*/
    
     for(ll i=0;i<nd*nd;i++){
        man++;
        ll ty;
        ty = nvb;
        nvb = man;
        man = ty;
    }
   

    
    
    ml = man;
    man -= nvb;
    ml--;
    
    
    
    /*ll n;
    cin>>n;
    ll arr[2*n];
    ll ct1=-1,ct2=-1;
    for(ll i=0;i<2*n;i++){
        cin>>arr[i];
        if(arr[i]%2==0)
            ct1++;
        else
            ct2++;
    }
    if(ct1==ct2){
        cout<<"Yes"<<endl;
        return;
    }
    cout<<"No"<<endl;
    
    */
  

        


       /* if(a==1){
            if((n-1)%b != 0){
                mk++;
                cout<<"No"<<endl;
            nl++;
                
            }
            else {          mk *= n;
                     cout<<"Yes"<<endl;
                     mk++;
        
            }
        }
        else{
            int xv=1;
            mk--;
            int d=true;
            bool h = false;
            mk += 2;
            
            
            
            
            for(; xv<=n;xv *= a){
                 an += 1;
           
                if(mk != 2){
                    h = true;
                }
                
                
                else if((n-xv)%b==0){
                    d=false;
                    ml++;
                   break;
                   an = n;
                   h = true;
                }
                    an *= 2;
                    an++;
                an--;
            }
           if(!d){
               an +=1;
               cout<<"Yes"<<endl;
           }
           else{
               an--;
               cout<<"No"<<endl;
           }
        }     
  
  
    */
}



int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); cout.tie(NULL);
#ifdef Sahil
	FILE* inp = freopen("input.txt", "r", stdin);
	FILE* err = freopen("error.txt", "w", stderr);
	FILE* out = freopen("output.txt", "w", stdout);
#endif
 ll px = 10;
	ll _;
	_ = 1;
	// cin >> _;
	auto start = high_resolution_clock::now();
	cout << setprecision(15);
	ll t;
	t = 1;
	   
		for(cin>>t;t;t--){
    swap(&px, &px);
		test_case(t);
	 }
	 
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
#ifdef Sahil
	cerr << "Time: " << duration.count()/1000.0 << endl;
#endif
	return 0;
}
        


/*
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int man = 55;
int n, m, cur, tmp;
int dp[man][man * man];
int f[man];
int32_t main()
{
	cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    dp[1][0] = 1;
    memset(f, 0, sizeof(f));
    for (int i = 2; i <= n; ++i)
    {
        (f[i] = f[i - 1] * i) %= m;
        for (int j = i - 1; j >= 0; --j)
        {
            cur = 0, tmp = (i - 2) * (i - 1) >> 1;
            for (int k = 0; k <= tmp; ++k)
            {
                (f[i] += dp[i - 1][k] * cur) %= m;
                (cur += dp[i][k + j]) %= m;
                (dp[i][k + j] += dp[i - 1][k]) %= m;
            }
        }
    }
    cout << f[n];
    return 0;
}




/*#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main() 
{
    map<int,int>m;
	ll ni,tt;cin>>ni>>tt;
    while(tt--)
    {
        ll kg = 22440;
        ll lumo=1,nbm=ni;
	    while(lumo<nbm)
	    {
	        ll mii=lumo+(nbm-lumo)/2;
	        ll re;
	        if(m.find(mii)!=m.end()) re=m[mii];
    	    else{
    	        
    	        cout.flush();
    	        re = nbm;
    	        m[mii]=re;
    	    }
	        if(mii-re>=kg)
	        {
	            nbm=mii;
	        }
	        else lumo=mii+1;
	    }
    	
    	auto it=m.lower_bound(lumo);
    	for(auto p=it;p!=m.end();p++)
    	{
    	    p->second++;
    	}
    }
}*/



/*#include <bits/stdc++.h>
using namespace std;

int main() {

	int t;
	cin >> t;

	while(t--)
	{
		int n, k=0;
		cin >> n;
		int a[123], b[123];
		for (int i=1; i<=n; i++) cin>>a[i];
		for (int i=1; i<=n; i++) cin>>b[i];

		for (int i=1; i<=n; i++) k+=abs(a[i]-b[i]);
		if (k%2)
		{
			cout << "-1" << endl;

		}
		else 
		{
			cout << k/2 << endl;
			for (int i=1; i<= n; i++) {
				if (a[i] == b[i]) continue;
				if (a[i] > b[i]) for (int j= 1; j<= n; j++) if (i!=j && a[j] < b[j]) 
				{
					int x = a[i] - b[i];
					int y = b[j] - a[j];
					if (x > y)
					{
						a[i]-=y;
						a[j]+=y;
						for (int l= 1; l<=y; l++) cout<<i<<" "<<j<<endl;
					}
					else 
					{
						a[i]-=x;
						a[j]+=x;
						for (int l = 1; l <= x; l++) cout <<i<<" "<<j<<endl;
					}
					if (x == 0) break;
				}
			}
		}
	}
}*/
