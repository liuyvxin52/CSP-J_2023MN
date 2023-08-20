//1.
#include <bits/stdc++.h>

using namespace std;

const int Maxn = /*1->*/1e6 + 7/*<-1*/;
int n, a[Maxn];
long long s[Maxn], ans;

bool check(int l, int r){
    if(s[r] - s[l - 1] == /*2->*/1LL * (r - l + 1) * a[l]/*<-2*/) return true;
    return false;
}



int main(){
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++)
        s[i] = a[i - 1] + a[i];
    ans = /*3->*/1ll * n * (n - 1) / 2/*<-3*/;
    for(int i = 1; i <= n; i++){
        int l = 1, r = n, pos = n;
        while(/*4->*/l <= r/*<-4*/){
            int mid = (l + r) >> 1;
            if(check(l, mid))
                l = mid + 1, pos = mid;
            else
                r = mid - 1;
        }
        ans -= /*5->*/1ll * (pos - i + 1) * (pos - i) / 2/*<-5*/;
        i = pos + 1;
    }
    cout << ans;
}
/*
参考答案：
1e6 + 7
1LL * (r - l + 1) * a[l]
1ll * n * (n - 1) / 2
l <= r
1ll * (pos - i + 1) * (pos - i) / 2
*/