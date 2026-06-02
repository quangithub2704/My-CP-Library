/*
 * Problem: CSES 1081 - Common Divisors
 * Link: https://cses.fi/problemset/task/1081
   
 * Complexity: 
    - Time: O(MAXA log MAXA) (tổng quát) do thuật toán phải chạy vòng lặp ngoài MAXA lần, vòng trong phải duyệt các bội của MAXA.
    - Space: O(n) (tổng quát) do phải lưu mảng input và mảng tần suất.
 
 * Ý tưởng:
    - Thay vì tư duy theo cách tìm từng ước chung của mỗi phần tử rồi tìm ra 2 số có ước chung lớn nhất; ta hãy tư duy ngược bằng cách giả sử ước chung lớn nhất của 2 số là g sau đó duyệt từng bội của g và kiểm tra trong mảng xem có ít nhất 2 số có thể chia hết cho sô này không, sau đó liên tục giảm g xuống rồi làm tương tự đến khi g=1.
    - Vì sao phải kiểm tra có ít nhất 2 số chia hết cho g? Vì theo toán học, g là ước chung của 2 số khi và chỉ khi 2 số đó chia hết cho g.
    - Vậy tại sao lại phải duyệt qua bội của g? đơn giản vì gọi theo cách khác, 2 số đó được gọi là bội của g nên ta cần phải duyệt từng bội của g.
    - Làm sao để biết bội của g có trong mảng không? Chúng ta sẽ tạo một mảng tần suất để kiểm tra nhanh thay vì phải kiểm tra trực tiếp trong mảng (vốn đã rất lâu kể cả dùng binary search). Sau khi có mảng tần suất rồi thì lúc này ta sẽ tạo biến đếm, duyệt bội của g, sau đó liên tục cộng freq[mul] rồi kiểm tra xem đã >=2 chưa, nếu rồi thì in ra rồi thoát lặp luôn, nếu chưa thì cứ duyệt tiếp như thường.
 * Lưu ý khi code: 
    Đặt tên biến dễ nhận biết, đừng như mình 🐧, đặt biến tầm bậy xong lỗi tùm lum chả biết đường mà fix (code này đã sửa lại tên biến rồi nhá)
 */
#include "bits/stdc++.h"
using namespace std;

#define ll long long

const int MAXN=2e5 +7;
const int MAXA=1e6;

int n,a[MAXN];
int freq[MAXA+1];
void solve(){
  cin>>n;
  for(int i=0;i<n;++i) cin>>a[i];

  for(int i=0;i<n;++i) ++freq[a[i]];

  for(int g=MAXA;x>0;--g){
    int cnt=freq[g];
    if(cnt>=2){
      cout<<g;
      return;
    }
    for(int mul=g*2;mul<=MAXA;mul+=g){
      cnt+=freq[mul];
      if(cnt>=2){
        cout<<g;
        return;
      }
    }
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  solve();
}
