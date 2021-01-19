#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

class Robot{
    public:
        int x;
        int y;
        int lost; // yes: 1, no: 0
        int ori_index;
        string instr;

        int is_lost(int x_bound, int y_bound){
            if (x > x_bound || x < 0){
                return 1;
            } else if (y > y_bound || y < 0){
                return 1;
            } else {
                return 0;
            }
        }
};

int main(){
    int upper_right_x, upper_right_y;
    Robot robot;
    char robot_ori[4] = {'E', 'N', 'W', 'S'}; 
    char origin_ori;

    cin >> upper_right_x >> upper_right_y;

    // initial map[][]
    int map[upper_right_x+1][upper_right_y+1];
    for (int i = 0; i <= upper_right_x; i++){
        for (int j = 0; j <= upper_right_y; j++){
            map[i][j] = 0;
        }
    }

    while (cin >> robot.x >> robot.y >> origin_ori){
        cin >> robot.instr;

        // find the index of origin_ori in robot_ori[]
        robot.ori_index = distance(robot_ori, strchr(robot_ori, origin_ori));
        robot.lost = 0;

        int tmp_x = robot.x;
        int tmp_y = robot.y;

        for (int i = 0; i < robot.instr.length(); i++){
            if (robot.instr[i] == 'L'){ // turn left
                robot.ori_index ++;
                if (robot.ori_index > 3){
                    robot.ori_index = 0;
                }
            } else if (robot.instr[i] == 'R'){ // turn right
                robot.ori_index --;
                if (robot.ori_index < 0){
                    robot.ori_index = 3;
                }
            } else if (robot.instr[i] == 'F'){ // move forward
                tmp_x = robot.x;
                tmp_y = robot.y;

                if (robot_ori[robot.ori_index] == 'E'){
                    robot.x ++;
                } else if (robot_ori[robot.ori_index] == 'N'){
                    robot.y ++;
                } else if (robot_ori[robot.ori_index] == 'W'){
                    robot.x --;
                } else if (robot_ori[robot.ori_index] == 'S'){
                    robot.y --;
                }

                // check if robot losts
                robot.lost = robot.is_lost(upper_right_x, upper_right_y);
                if (robot.lost){
                    robot.x = tmp_x;
                    robot.y = tmp_y;

                    if (map[robot.x][robot.y] == 1){
                        // It's the scent, won't move off the edge
                        robot.lost = 0;
                    } else {
                        map[robot.x][robot.y] = 1;
                        break;
                    }
                }
            }
        }

        // output 
        cout << robot.x << " " << robot.y << " " << robot_ori[robot.ori_index];
        if (robot.lost == 1){
            cout << " LOST";
        }
        cout << endl;
    }
    return 0;
}