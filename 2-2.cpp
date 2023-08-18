//2.
#include <iostream>

using namespace std;

int a[100005], b[100005], n, m;

void very_quick_sort(int l, int r, int p, int q){
    if(l >= r || p > q){    //①
        return;
    }
    int mid = (l + r) / 2;
    int p0 = p - 1;
    int q0 = q + 1;
    for(int i = p; i <= q; i++){
        if(a[i] > mid) b[++p0] = a[i];
        else b[--q0] = a[i];
    }
    for(int i = 1; i <= n; i++)
        a[i] = b[i];
    very_quick_sort(mid + 1, r, p, p0);
    very_quick_sort(l, mid, q0, q);
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    very_quick_sort(1, m, 1, n);
        //②
    for(int i = 1; i <= n; i++)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}
/*
输入:
10 01
10 4 5 2 2 3 1 5 8 3
监视
b:[100005]
[0]:0
[1]:10
[2]:8
[3]:5
[4]:5
[5]:4
[6]:3
[7]:3
[8]:2
[9]:2
[10]:1
调用堆栈    因breakpoint已暂停
  C/C++:g++生成和调试活动文件2    因BREAKPOINT已暂停
    main()      2-2.cpp  31(30):1
断点
All C++ Exceptions
2-2.cpp             31(30)
*/