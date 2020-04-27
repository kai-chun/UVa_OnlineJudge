#include <iostream>
#include <cmath>
using namespace std;

int main (){
    int a, b;
    int a_sqrt, b_sqrt, count;

    while (cin >> a >> b){
        if (a == 0 && b == 0){
            break;
        }

        a_sqrt = (int)ceil(sqrt(a));
        b_sqrt = (int)sqrt(b);
        count = b_sqrt - a_sqrt + 1;

        cout << count << endl;
    }
    return 0;
}