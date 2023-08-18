//1.
#include <iostream>
#include <cstring>

using namespace std;

string s, t;
string a, b;

int main(){
    getline(cin, s);
    getline(cin, a);
    getline(cin, b);
    for(int i = 0; i < s.size(); i++){
        bool flag = true;
        if(i + a.size() <= s.size()){
            for(int j = 0; j < a.size(); j++){
                char p = s[i + j], q = a[j];
                if('a' <= p && p <= 'z') p = p - 'a' + 'A';
                if('a' <= q && q <= 'z') q = q - 'a' + 'A';
                if(p != q)
                    flag = false;
            }
        }
        else
            flag = false;

        if(flag == true){
            t += b;
            i += a.size() - 1;
        }
        else
            t += s[i];
    }
    cout << t << endl;
}