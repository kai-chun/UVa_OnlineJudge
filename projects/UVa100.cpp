#include <iostream>
using namespace std;

int main(void){
    int i, j, time, temp, max, start, end;
    
    while(cin >> i >> j){
        max = -1;

        //check if i <= j
        if (i > j){
            start = j;
            end = i;
        }else{
            start = i;
            end = j;
        }

        for (int k = start; k <= end; k++){
            time = 0;
            temp = k;

            while (temp != 1){
                if (temp % 2 == 1){    // temp is odd
                    temp = 3 * temp + 1;
                } else {  // temp is even
                    temp = temp / 2;
                }
                time++;
            }
            time++;

            if (max < time){
                max = time;
            }
        }
        cout << i << " " << j << " " << max << "\n";
    }
    return 0;
}