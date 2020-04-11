 #include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main(){
    int x, index;
    long long int ans, exp;
    long long int a[1000000];
    string s, tmp;

    while (cin >> x){
        cin.ignore();
        getline(cin, s);

        tmp = "";
        index = 0;
        ans = 0;
        exp = 1;
        
        for (int i = 0; i < s.length(); i++){ // input data processing
            if (s[i] != ' '){
                tmp += s[i];
            } else {
                a[index] = atoi(tmp.c_str());
                index++;
                tmp = "";
            }
        }
        a[index] = atoi(tmp.c_str());

        if (x == 0){
            ans = a[index-1];
        } else {
            for (int i = index-1; i >= 0; i--){
                ans += a[i] * (index - i) * exp;
                exp *= x;
            }
        }
        cout << ans << endl;
    }

    return 0;
}