下面提供了一個利用數論求前綴和並藉由二分搜尋求解答案的 C++ 範例程式，藉由對每個 \(x\) 快速計算  
\[
S(x)=\sum_{k=1}^x \gcd(n,k)
\]  
的方法來決定能分到多少位小朋友。  
但注意題意要求：依照順序分糖，若第 \(x+1\) 位小孩的所需糖果（即 \(\gcd(n,x+1)\)）尚無法完全滿足但還有剩，這位也照算作「有分到糖」（partial 分糖）。  

在直接從 \(1\) 到 \(n\) 累計會 TLE（因為 \(n\) 可能非常大），因此我們利用數論技巧：  
- 利用數論性質可證  
  \[
  S(x)=\sum_{d\mid n} \; d\; F\Bigl(\tfrac{n}{d}, \lfloor x/d\rfloor\Bigr)
  \]
  其中  
  \[
  F(N, Y)=\#\{1\le t\le Y: \gcd(t, N)=1\}
  \]
  而 \(F(N,Y)\)可以利用 \(N\) 的質因數採用容斥原理來計算。  
- 接著藉由二分搜尋找出最大 \(x_{\rm full}\) 使得 \(S(x_{\rm full})\le m\)（這代表前 \(x_{\rm full}\) 位小孩都得到足夠糖果）；接下來若 \(x_{\rm full}<n\) 且 \(m-S(x_{\rm full})>0\)（還有剩餘不足以滿足 \(x_{\rm full}+1\) 位小孩所需，但該小孩可拿走剩餘的 partial 糖果），則答案就是 \(x_{\rm full}+1\) 否則就是 \(x_{\rm full}\) 。

以下是完整程式碼（註解中說明了各個部分）： 

---

```cpp
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
using ll = long long;

//----------------------------------------
// 利用 trial division 對 n 進行質因數分解
//----------------------------------------
vector<ll> factorize(ll n) {
    vector<ll> primes;
    for (ll i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            primes.push_back(i);
            while(n % i == 0)
                n /= i;
        }
    }
    if(n > 1) primes.push_back(n);
    return primes;
}

//----------------------------------------
// 利用容斥原理計算 F(N, Y)
// F(N, Y) = 數字 1..Y 中與 N 互質的個數  
// N 的所有質因數存於 vector primes 中（各不重複）
//----------------------------------------
ll countCoprime(ll Y, const vector<ll>& primes) {
    int m = primes.size();
    ll res = 0;
    // 採用 bitmask 遍歷所有非空 subset
    // 共 2^m 個子集，空集單獨處理：空集對應的乘積是 1，且符號為 +1
    res = Y; // 從空集貢獻：Y
    int subsets = 1 << m;
    for(int mask = 1; mask < subsets; mask++){
        ll mult = 1;
        int bits = 0;
        for(int i = 0; i < m; i++){
            if(mask & (1 << i)) {
                bits++;
                // 若乘積超過 Y 就可提前中斷
                if(mult > Y / primes[i]) { 
                    mult = Y + 1;
                    break;
                }
                mult *= primes[i];
            }
        }
        if(mult > Y) continue;
        ll cnt = Y / mult;
        if(bits % 2 == 1) res -= cnt; else res += cnt;
    }
    return res;
}

//----------------------------------------
// 針對每個 n 和 x，計算 S(x) = sum_{k=1}^{x} gcd(n, k)
// 利用下面等式：
//   S(x)= sum_{d|n, d<=x}  d * F(n/d, floor(x/d))
// 其中 F(N, Y) 代表 1<= t <= Y 中與 N 互質的數量
//----------------------------------------
ll sumGcd(ll n, ll x, const vector<ll>& divisors, 
          const vector< vector<ll> >& divisorPrimeFactors) {
    ll total = 0;
    for (size_t i = 0; i < divisors.size(); i++) {
        ll d = divisors[i];
        if(d > x) break;  // 因為 floor(x/d)==0 略過
        ll Y = x / d;
        // divisorPrimeFactors[i] 為 n/d 的質因數（不重複）
        ll cnt = countCoprime(Y, divisorPrimeFactors[i]);
        total += d * cnt;
        // 注意：total 可能很大，但 m 也是很大，故用 ll 型別
    }
    return total;
}

//----------------------------------------
// 列舉 n 的所有因數，並且同時記錄對應 n/d 的質因數  
//----------------------------------------
void getDivisorsWithPrimeFactors(ll n, vector<ll>& divisors, 
                                 vector< vector<ll> >& divisorPrimeFactors) {
    // 先列舉 n 所有的因數
    for (ll i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            divisors.push_back(i);
            if(i * i != n) divisors.push_back(n / i);
        }
    }
    sort(divisors.begin(), divisors.end());
    // 對每個因數 d，計算 n/d 的質因數（不重複）
    for (ll d : divisors) {
        ll nd = n / d;
        vector<ll> fac = factorize(nd);
        divisorPrimeFactors.push_back(fac);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while(T--){
        ll n, m;
        cin >> n >> m;
        
        // 預先列舉 n 的所有因數，以及對應 n/d 的質因數
        vector<ll> divisors;
        vector< vector<ll> > divisorPrimeFactors;
        getDivisorsWithPrimeFactors(n, divisors, divisorPrimeFactors);
        
        // 二分搜尋 x (代表已經完整發到 x 位小朋友，使得 S(x) <= m)
        // x 的範圍必定在 [0, n]
        ll lo = 0, hi = n;
        while(lo < hi){
            ll mid = lo + (hi - lo + 1) / 2;
            ll s = sumGcd(n, mid, divisors, divisorPrimeFactors);
            if(s <= m) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }
        ll full = lo; // 完全滿足的個數
        // 如果還沒到最後一位且 m 還有剩，則下一位小孩可以拿到部分糖果，計入
        ll ans = full;
        if(full < n) {
            ll s = sumGcd(n, full, divisors, divisorPrimeFactors);
            if(m > s) ans = full + 1;
        }
        cout << ans << "\n";
    }
    return 0;
}
```

---

### 主要流程說明

1. **前處理：**  
   對於給定的 \( n \)，我們先列舉所有正因數 \( d \)（利用 \( d \) 與 \( n/d \) 的對稱性），並對每個 \( d \) 求出 \( n/d \) 的質因數分解。這讓後續計算 \( F\Bigl(n/d, \lfloor x/d\rfloor\Bigr) \) 變得快速。

2. **計算 \( F(N, Y) \)：**  
   使用容斥原理計算與 \( N \) 互質的數字個數。這裡利用 bitmask 遍歷 \( N \) 的質因數集合（因數數量通常很小）。

3. **二分搜尋決定 \( x_{\rm full} \)：**  
   利用二分搜尋找出最大 \( x \in [0, n] \) 使得 \( S(x)\le m \)。  
   這裡 \( S(x) \) 的計算是利用前面分解後的公式。

4. **判斷部分發放：**  
   若 \( x_{\rm full} < n \) 且餘下糖果 \( m - S(x_{\rm full})>0 \)（代表下一位小朋友拿部分糖果也算），則答案為 \( x_{\rm full}+1 \)；否則答案就是 \( x_{\rm full} \)。

---

### 與樣例比對

以樣例 \( n=4 \) 為例（根據題目中小朋友應依序拿：\( \gcd(4,1)=1,\gcd(4,2)=2,\gcd(4,3)=1,\gcd(4,4)=4 \)）：  
- m = 0  
  \( S(0)=0 \)，無餘量，答案 0  
- m = 1  
  \( S(1)=1 \) 恰好滿足，答案 1  
- m = 2  
  找到 \( x_{\rm full}=1 \)（因為 \( S(2)=3>2 \)），且餘下 1 顆，故答案 2  
- m = 3  
  \( S(2)=3 \) 滿足，餘下 0，答案 2  
- m = 4  
  \( S(2)=3 \) 滿足、\( S(3)=4 \) 滿足，故 \( x_{\rm full}=3 \)，答案 3  
- m = 5、6、7…依照範例可得答案為 4 等，正符合題目所示結果。

---

此程式藉由數論與二分搜尋的方法將原本 \( O(n) \) 的累加降到約 \( O(\sqrt{n}\cdot2^{\omega(n)}\cdot \log n) \)（其中 \(\omega(n)\) 為 \( n \) 的不同質因數個數），足以應付 \( n \) 非常大的情況。

若有其他疑問或需要進一步優化解釋，請隨時告知！