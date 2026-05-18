/*
 * Problem: CSES 1629 - Movie Festival
 * Link: https://cses.fi/problemset/task/1629
 
 * Complexity: 
    - Time: O(n log n + n) vì phải sort sau đó duyệt từng phần tử trong mảng.
    - Space: O(n) do phải lưu input.
   
 * Ý tưởng:
    - Tại sao không sort theo thời gian bắt đầu (Start Time)? Vì nếu một bộ phim bắt đầu rất sớm nhưng kéo dài đến phát ngán, nó sẽ chiếm hết chỗ của các bộ phim khác -> Sai.
    - Tại sao không sort theo thời lượng (Duration) ngắn nhất? Vì một bộ phim ngắn có thể nằm kẹt giữa 2 bộ phim khác, chọn nó sẽ làm mất cơ hội chọn cả 2 bộ phim kia -> Sai.

    => Trở ngại lớn nhất là thời gian kết thúc của bộ phim. Nó kết thúc càng muộn thì càng dễ bỏ lỡ các bộ phim phía sau. Vậy phải ưu tiên thằng kết thúc sớm nhất!
   
 * Lưu ý khi code: 
    Cần phải đổi chỗ thời điểm bộ phim kết thúc và bộ phim bắt đầu trong pair<int,int>
*/
#include "bits/stdc++.h"
using namespace std;

#define fi first
#define se second

typedef pair<int,int> pii;

const int MAX=2e5+7;

//----------------------
int n;
pii a[MAX];

//----------------------
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
