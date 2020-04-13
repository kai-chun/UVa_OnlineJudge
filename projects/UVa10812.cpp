#include <iostream>
using namespace std;

int main(){
    int n;
    long long int sum, dif; // a+b = sum, a-b = dif 
    long long int a, b;

    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> sum >> dif;

        a = (sum + dif) / 2;
        b = (sum - dif) / 2;

        if ((sum + dif) % 2 == 1 || (sum - dif) % 2 == 1 || a < 0 || b < 0){
            cout << "impossible" << endl;
        } else {
            cout << a << " " << b << endl;
        }
    }
    return 0;
}
