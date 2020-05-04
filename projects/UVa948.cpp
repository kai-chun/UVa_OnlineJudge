#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    int n, tmp, index = 2;
    int dec_base;
    vector<int> fib;
    string fib_base;

    // store the Fibonacci sequence into the vector
    fib.push_back(1);
    fib.push_back(2);
    while (fib.back() <= 100000000){
        fib.push_back(fib[index-2] + fib[index-1]);
        index++;
    }

    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> dec_base;
        tmp = dec_base;
        index = fib.size() - 1;
        fib_base = ""; // Fibonaccimal base
        
        while (tmp != 0){
            if (tmp >= fib[index]){
                if (fib_base == "" || fib_base.back() != '1'){ // don't use two consecutive Fibonacci numbers
                    fib_base = fib_base + "1";
                    tmp = tmp - fib[index];
                }
            } else if (fib_base == ""){
                
            } else {
                fib_base = fib_base + "0";
            }
            index--;   
        }
        for (; index >= 0; index--){
            fib_base = fib_base + "0";
        }
        cout << dec_base << " = " << fib_base << " (fib)" << endl;
    }

    return 0;
}