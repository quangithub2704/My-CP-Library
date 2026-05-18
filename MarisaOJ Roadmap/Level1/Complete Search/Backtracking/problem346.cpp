/*
 * Problem: MarisaOJ 346 - Subset sum
 * Link: https://marisaoj.com/problem/346
 
 * Complexity: 
   - Time: O(2^n) do đây là quay lui thử mọi trường hợp.
   - Space: O(n) do phải lưu stack.

 * Ý tưởng (Đệ quy):
   - Thử mọi tổ hợp bằng cách chọn 1 phần tử trong mảng a sau đó lần lượt chọn thêm phần tử đến hết. Khi không còn phần tử nào, chúng ta sẽ bỏ phần tử ra khỏi tập hợp và chọn tiếp phần tử tiếp theo và thực hiện tương tự.
   - Nếu đã tìm thấy ans rồi thì phải cắt tỉa nó để tránh tính toán thừa thãi. Tương tự như dòng 43 nếu ta cộng thêm phần tử mà > k, chúng ta bỏ qua luôn để tránh tính toán thừa thãi.

   * Ngoài ra bài này còn có cách giải khác là Bitmask. Do trong lúc làm mình nghĩ ra ý tưởng này nên mình để code trên đây luôn :>

 * Lưu ý khi code: 
   - Phải đổi sang kiểu dữ liệu long long vì a[i] và k lên đến 10^18. Đã từng bị WA vì quên đổi long long (dòng 34).
   - Trong lúc code mình lỡ thêm hàm check và kiểm tra điều kịên thoã mãn hay không, nhưng điều đó là không cần thiết vì trong hàm đã có idx=0, tức là nó sẽ chạy tịnh tiến mà không bao giờ đụng vào các phần tử <= i.

*/
#include "bits/stdc++.h"
using namespace std;

#define ll long long

const int MAX=20+7;

//-----------------------
int n;
ll a[MAX],k;

bool ans;
//-----------------------

void subset(int idx=0,ll sum=0){
  if(sum==k){
    ans=1;
    return;
  }
  // tia nhanh
  if(sum>k||ans) return;

  for(int i=idx;i<n;++i)
    if(sum+a[i]<=k)
      subset(i+1,sum+a[i]);
}

void solve(){
  cin>>n>>k;
  for(int i=0;i<n;++i)cin>>a[i];

  sort(a,a+n,greater<ll>());

  subset();
  cout<<(ans?"YES":"NO");
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  solve();
}
