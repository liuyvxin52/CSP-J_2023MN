//1.
#include <bits/stdc++.h>

using namespace std;

const int Maxn = /*1->*//*<-1*/;
int n, a[Maxn];
long long s[Maxn], ans;

bool check(int l, int r){
    if(s[r] - s[l - 1] == /*2->*//*<-2*/) return true;
    return false;
}



int main(){
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++)
        s[i] = a[i - 1] + a[i];
    ans = /*3->*//*<-3*/;
    for(int i = 1; i <= n; i++){
        int l = 1, r = n, pos = n;
        while(/*4->*//*<-4*/){
            int mid = (l + r) >> 1;
        }
    }
}