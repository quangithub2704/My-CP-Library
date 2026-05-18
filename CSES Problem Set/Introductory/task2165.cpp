/*
 * Problem: CSES 2165 - Tower of Hanoi
 * Link: https://cses.fi/problemset/task/2165
   
 * Complexity: 
    - Time: O(2^n) vì mỗi bước đệ quy sinh ra 2 lời gọi hàm mới.
    - Space: O(n) do bộ nhớ Stack của đệ quy.
 
 * Ý tưởng (Chia để trị / Đệ quy):
    - Bản chất bài toán N đĩa là bài toán con của $N-1$ đĩa nhưng thay đổi vai trò các cọc.
    - Để dời đĩa lớn nhất (N) từ Cọc 1 sang Cọc 3:
      Bước 1: Dời N-1 đĩa trên cùng từ Cọc 1 sang Cọc 2 (Cọc 3 làm cọc trung gian).
      Bước 2: Dời đĩa N từ Cọc 1 sang Cọc 3.
      Bước 3: Dời N-1 đĩa từ Cọc 2 sang Cọc 3 (Cọc 1 làm cọc trung gian).
   
 * Lưu ý khi code: 
    - Cần truyền linh hoạt vai trò (Từ, Đến, Trung gian) vào tham số hàm đệ quy.
    - Số bước di chuyển tối thiểu luôn là $2^n - 1$.
 */
#include "bits/stdc++.h"
using namespace std;

//----------------------------
int n;

//----------------------------
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
