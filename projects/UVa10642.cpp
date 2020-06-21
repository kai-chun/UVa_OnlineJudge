#include <iostream>
using namespace std;

int main(){
    int testCase_num;
    int sourceTotal, source_x, source_y;
    int desTotal, destination_x, destination_y;
    long long int step;

    cin >> testCase_num;
    for (int i = 0; i < testCase_num; i++){
        cin >> source_x >> source_y >> destination_x >> destination_y;

        step = 0;
        sourceTotal = source_x + source_y;
        desTotal = destination_x + destination_y;
        for (int j = sourceTotal+1; j <= desTotal; j++){
            step += j;
        }
        step = step - source_x + destination_x;

        cout << "Case " << i+1 << ": " << step << endl;
    }
    return 0;
}