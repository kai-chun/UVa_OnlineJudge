#include <iostream>
#include <string>
using namespace std;

int main(){
    int command_num, tmp;
    string command;

    while(cin >> command_num){
        // end of input
        if (command_num == 0){
            break;
        }

        int dice[3] = {1, 2, 3}; // top, north, and west faces

        for (int i = 0; i < command_num; i++){
            cin >> command;

            tmp = dice[0];
            if (command.compare("north") == 0){
                dice[0] = 7 - dice[1];
                dice[1] = tmp;
            } else if (command.compare("south") == 0){
                dice[0] = dice[1];
                dice[1] = 7 - tmp;
            } else if (command.compare("west") == 0){
                dice[0] = 7 - dice[2];
                dice[2] = tmp;
            } else if (command.compare("east") == 0){
                dice[0] = dice[2];
                dice[2] = 7 - tmp;
            }
        }

        cout << dice[0] << endl;
    }

    return 0;
}