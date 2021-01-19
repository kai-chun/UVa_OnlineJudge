#include <iostream>
#include <algorithm>
#include <cstdlib> 
using namespace std;

class Number{
    public:
        int number;
        int mod;
};

bool sortFunc(Number, Number);

int main(){
    int num, mod_value;

    while (cin >> num >> mod_value){
        if (num == 0 && mod_value == 0){
            break;
        }

        Number set[num];
        for (int i = 0; i< num; i++){
            cin >> set[i].number;
            set[i].mod = set[i].number % mod_value;
        }

        sort(set, set+num, sortFunc);

        cout << num << " " << mod_value << endl;
        for (int i = 0; i < num; i++){
            cout << set[i].number << endl;
        }
    }

    cout << "0 0" << endl;

    return 0;
}

bool sortFunc(Number x, Number y){
    if (x.mod == y.mod){
        if (abs(x.number) % 2 == 0 && abs(y.number) % 2 == 0){ // both are even
            return (x.number < y.number); // the smaller even number will precede the larger even number
        } else if (abs(x.number) % 2 == 1 && abs(y.number) % 2 == 1){ // both are odd
            return (x.number > y.number); // the larger odd number will precede the smaller odd number 
        } else {
            if (abs(x.number) % 2 == 1){ // the odd number will precede the even number
                return true;
            }
            return false;
        }
    } else {
        return (x.mod < y.mod);
    }  
}