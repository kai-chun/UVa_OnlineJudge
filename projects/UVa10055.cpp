#include <iostream>
#include <stdlib.h>
using namespace std;

int main(){
    long long int h_army, op_army, dif;

    while(cin >> h_army >> op_army){
        dif = abs(h_army - op_army);
        cout << dif << endl;
    }

    return 0;
}