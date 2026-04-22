#include "bits/stdc++.h"
using namespace std;

#define ll long long
#define pb push_back
#define ppb pop_back
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()

typedef vector<int> vi;
typedef set<int> si;
typedef map<int,int> mii;
typedef pair<int,int> pii;

const int MAX=2e5+7;
const int MOD=1e9+7;
//-----
int n;
pii a[MAX];
//-----

void solve(){
  cin>>n;
  for(int i=0;i<n;++i)
    cin>>a[i].se>>a[i].fi;

  sort(a,a+n);

  int ans=1,pos=0;
  for(int i=1;i<n;++i)
    if(a[i].se>=a[pos].fi){
      ++ans;
      pos=i;
    }

  cout<<ans;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  solve();
}
