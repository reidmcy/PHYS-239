#include <iostream>

using namespace std;

int x = 0;

int main() {
    while (1) {
        cout << "||    ##   ||    ||    ##   ||    ||    ##   ||    " << endl;
        cout << "||   #  #  ||    ||   #  #  ||    ||   #  #  ||    " << endl;
        cout << "||   #  #  ||    ||   #  #  ||    ||   #  #  ||    " << endl;
        cout << "|___  ##   |___  |___  ##   |___  |___  ##   |___  " << endl << endl;
        cout << "LOL      LOLLOL    LOL     LOL      LOLLOL    LOL   " << endl;
        cout << "LOL    LOL    LOL  LOL     LOL    LOL    LOL  LOL   " << endl;
        cout << "LOL    LOL    LOL  LOL     LOL    LOL    LOL  LOL   " << endl;
        cout << "LOL    LOL    LOL  LOL     LOL    LOL    LOL  LOL   " << endl;
        cout << "LOLLOL   LOLLOL    LOLLOL  LOLLOL   LOLLOL    LOLLOL" << endl << endl;
        if (x % 5 == 0) {
            cout << "\033[1;35;41m";
        }
        else if (x % 5 == 1) {
            cout << "\033[1;36;43m";
        }
        else if (x % 5 == 2) {
            cout << "\033[1;31;44m";
        }
        else if (x % 5 == 3) {
            cout << "\033[1;32;45m";
        }
        else {
            cout << "\033[1;34;46m";
        }
        x++;
        usleep(400);
    }
}
