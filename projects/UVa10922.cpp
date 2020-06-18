#include <iostream>
#include <string>
using namespace std;

int main(){
    string num, tmp;
    int digitSum, degree;

    cin >> num;
    while (num != "0"){
        digitSum = 0;
        degree = 0;
        
        // check if digitSum is multiple of 9 
        for (int i = 0; i < num.length(); i++){
            digitSum = digitSum + (num[i] - '0');
        }
        
        // if digitSum is multiple of 9, check its 9-degree
        while (digitSum != 0 && digitSum != 9 && digitSum % 9 == 0){
            degree++;
            tmp = to_string(digitSum);
            digitSum = 0;
            for (int i = 0; i < tmp.length(); i++){
                digitSum = digitSum + (tmp[i] - '0');
            }
        }
        if(digitSum == 9){
            degree++;
        }
        
        if (degree == 0){
            cout << num << " is not a multiple of 9." << endl;
        } else {
            cout << num << " is a multiple of 9 and has 9-degree " << degree << "." << endl;
        }

        cin >> num;
    }
    return 0;
}