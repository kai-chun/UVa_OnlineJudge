#include <iostream>
#include <string>
using namespace std;

int main(){
    int testCase_num;
    string strA, strB;
    long long int strA_value, strB_value;

    cin >> testCase_num;
    for (int i = 0; i < testCase_num; i++){
        cin >> strA >> strB;
        
        // turn strA and strB into decimal
        long long int tmp = 1;
        strA_value = 0;
        strB_value = 0;
        for (int j = strA.length()-1; j >= 0; j--){
            strA_value += strA[j] * tmp;
            tmp *= 2;
        }
        tmp = 1;
        for (int j = strB.length()-1; j >= 0; j--){
            strB_value += strB[j] * tmp;
            tmp *= 2;
        }
        
        // find the greatest common divisor of strA and strB 前面是大的
        if (strA_value < strB_value){
            tmp = strA_value;
            strA_value = strB_value;
            strB_value = tmp;
        }
        while (strB_value != 0){
            tmp = strA_value % strB_value;
            strA_value = strB_value;
            strB_value = tmp;
        }

        if (strA_value != 1){
            cout << "Pair #" << (i+1) << ": All you need is love!" << endl;
        } else {
            cout << "Pair #" << (i+1) << ": Love is not all you need!" << endl;
        }
    }
    return 0;
}