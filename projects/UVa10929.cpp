#include <iostream>
#include <string>
using namespace std;

int main(){
    string num;
    int oddSum, evenSum, length;

    while (cin >> num){
        if (num == "0"){
            break;
        }

        oddSum = 0;
        evenSum = 0;
        length = num.length();

        for (int i = 0; i < length-1; i+=2){
            evenSum = evenSum + (int)num[i] - 48;
            oddSum = oddSum + (int)num[i+1] - 48;
        }
        if (length % 2 == 1){
            evenSum = evenSum + (int)num[length-1] - 48;
        }

        if ((oddSum - evenSum) % 11 == 0){
            cout << num << " is a multiple of 11.\n";
        } else {
            cout << num << " is not a multiple of 11.\n";
        }
    }

    return 0;
}