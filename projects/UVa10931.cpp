#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    long long int num, parity;
    string str;


    while (cin >> num){
        if (num == 0){
            break;
        }
        str = "";
        while (num > 0){ // turn num into binary representation
            str += to_string(num % 2);
            num /= 2;
        }
        parity = count(str.begin(), str.end(), '1');
        reverse(str.begin(), str.end());
        
        cout << "The parity of " << str << " is " << parity << " (mod 2)." << endl;
    } 

    return 0;
}