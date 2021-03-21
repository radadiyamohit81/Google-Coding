#include "bits/stdc++.h"
using namespace std;
#define int               long long
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define sz(x)             (int)((x).size())
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount
#define ppcll             __builtin_popcountll

template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.fr>>a.sc;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.fr<<" "<<a.sc;return out;}
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}

const long long INF=1e18;
const int32_t M=1e9+7;
const int32_t MM=998244353;

const int N=0;

void solve(int test){
	cout << "Case #" << test << ": ";
	int r,c;
	cin >> r;
	c = r;
	vector<vector<int>> a(r,vector<int>(c));
	vector<vector<int>> b(r,vector<int>(c));
	vector<int> p(r),q(c);
	
	int R = r + 10;
	
	vector<vector<pii>> v(R + c + 20);
	vector<int> vis(R+c+20);
	
	rep(i,0,r){
		rep(j,0,c){
			cin >> a[i][j];
		}
	}
	
	int tot = 0;
	set<pii> s;
	
	rep(i,0,r){
		rep(j,0,c){
			cin >> b[i][j];
			if(a[i][j] == -1){
				v[i].pb({j+R,b[i][j]});
				v[j+R].pb({i,b[i][j]});
				tot += b[i][j];
				s.insert({0,i});
			}
		}
	}
	
	rep(i,0,r){
		cin >> p[i];
	}
	
	rep(j,0,c){
		cin >> q[j];
	}
	
	int ans = 0;
	
	while(!s.empty()){
		auto cur = *s.begin();
		s.erase(cur);
		int dis = -cur.fr;
		// cout << dis << "\n";
		int ver = cur.sc;
		if(vis[ver]){
			continue;
		}
		ans += dis;
		vis[ver] = 1;
		for(pii x:v[ver]){
			if(vis[x.fr]){
				continue;
			}
			s.insert({-x.sc,x.fr});
		}
	}
	
	ans = tot - ans;
	cout << ans << "\n";
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#ifdef SIEVE
		sieve();
	#endif
	#ifdef NCR
		init();
	#endif
	int t=1;
	cin>>t;
	rep(i,1,t+1) solve(i);
	return 0;
}
