/*
  CSES Task 2165
  ý tưởng là di chuyển n-1 đĩa sang cọc chờ, sau đó di chuyển đĩa n sang cọc đích, rồi di chuyển lại n-1 đĩa sang cọc đích
  lý do: vì muốn di chuyển các đĩa từ cọc 1 sang cọc 3, thì đĩa to nhất phải nằm ở cọc 3; mà muốn di chuyển đĩa to nhất thì n-1 đĩa phải được dời sang cọc 2, rồi sau đó mới di chuyển n-1 đĩa lại cọc 3
  bản chất là di chuyển n-1 đĩa là bài toán con của n đĩa, lúc này cần phải đổi vai trò của các cọc phù hợp với mục tiêu

*/
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
//-----

void toh(int n,int source,int aux,int target){
  if(n==1){
    cout<<source<<' '<<target<<'\n';
    return;
  }
  toh(n-1,source,target,aux);

  cout<<source<<' '<<target<<'\n';

  toh(n-1,aux,source,target);
}

void solve(){
  cin>>n;

  cout<<(1<<n)-1<<'\n';
  toh(n,1,2,3);
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  solve();
}
