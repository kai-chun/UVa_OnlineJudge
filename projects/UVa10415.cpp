#include <iostream>
#include <string>
#include <string.h>
using namespace std;

char notes[14] = {'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C', 'D', 'E', 'F', 'G', 'A', 'B'};
int finger[14][10] = {
    {0,1,1,1,0,0,1,1,1,1}, // c
    {0,1,1,1,0,0,1,1,1,0}, // d
    {0,1,1,1,0,0,1,1,0,0}, // e
    {0,1,1,1,0,0,1,0,0,0}, // f
    {0,1,1,1,0,0,0,0,0,0}, // g
    {0,1,1,0,0,0,0,0,0,0}, // a
    {0,1,0,0,0,0,0,0,0,0}, // b
    {0,0,1,0,0,0,0,0,0,0}, // C
    {1,1,1,1,0,0,1,1,1,0}, // D
    {1,1,1,1,0,0,1,1,0,0}, // E
    {1,1,1,1,0,0,1,0,0,0}, // F
    {1,1,1,1,0,0,0,0,0,0}, // G
    {1,1,1,0,0,0,0,0,0,0}, // A
    {1,1,0,0,0,0,0,0,0,0}, // B
};

int main(){
    int case_num;
    string song;

    cin >> case_num;
    getline(cin, song); //clear buffer
    for (int i = 0; i < case_num; i++){
        string song;
        int f_num[10] = {0};
        int last_f[10] = {0};
        int note_index;

        getline(cin, song);
        for (int j = 0; j < song.length(); j++){
            // find the index of note to find the fingering
            note_index = distance(notes, strchr(notes, song[j]));
            
            if (j == 0){
                for (int k = 0; k < 10; k++){
                    f_num[k] = finger[note_index][k];
                    last_f[k] = finger[note_index][k];
                }
            } else {
                for (int k = 0; k < 10; k++){
                    // check if finger used in last note
                    if (finger[note_index][k] == 1 && finger[note_index][k] != last_f[k]){
                        f_num[k] ++;
                    }
                    last_f[k] = finger[note_index][k];
                }
            }
        }

        // output
        for (int k = 0; k < 10; k++){
            if (k != 0){
                cout << ' ';
            }
            cout << f_num[k];
        }
        cout << endl;
    }
    return 0;
}