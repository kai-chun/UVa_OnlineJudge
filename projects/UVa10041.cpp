#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(void){
    int case_num, rel_num, median, sum;
    int addr[500];

    cin >> case_num;
    for (int i = 0; i < case_num; i++){
        median = 0;
        sum = 0;
        cin >> rel_num;

        for (int j = 0; j < rel_num; j++){
            cin >> addr[j];
        }

        // Find the median of addr[]
        sort(addr, addr + rel_num); 
        if (rel_num % 2 == 1){
            median = addr[rel_num / 2];
        } else {
            median = (addr[rel_num / 2 - 1] + addr[rel_num / 2]) / 2;
        }

        // compute the sum of distance to each one of relatives
        for (int j = 0; j < rel_num; j++){
            sum = sum + abs(addr[j] - median);
        }
        cout << sum << "\n";
    }  
    return 0; 
}