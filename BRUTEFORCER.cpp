#include <iostream>
#include <string>
using namespace std;

void password_bypass(string password_string) {
    int pos_pass[9999] = {0 * 9999};
    char char_arr[94] = {' ','!','"','#','$','%','&','(',')','*','+',',',
                          '-','.','/','0','1','2','3','4','5','6','7','8','9',
                          ':',';','<','=','>','?','@','A','B','C','D','E','F',
                          'G','H','I','J','K','L','M','N','O','P','Q','R','S',
                          'T','U','V','W','X','Y','Z','[','\\',']','^','_','`',
                          'a','b','c','d','e','f','g','h','i','j','k','l','m',
                          'n','o','p','q','r','s','t','u','v','w','x','y','z',
                          '{','|','}','~'};
    int start_point = 89;
    int arr_end = 93;
    bool bypassed = false;
    string pos_pas_str = "";
    int count = 0;
    while (bypassed == false) {
        for (int i = 0; i < 90; i++) {
            if (pos_pass[i] == arr_end) {
                pos_pass[i - 1] = pos_pass[i - 1] + 1;
                pos_pass[i] = 0;
            }
        }
        pos_pass[start_point] = pos_pass[start_point] + 1;

        for (int nom : pos_pass) {
            if (char_arr[nom] != ' ') {
                pos_pas_str = pos_pas_str + char_arr[nom];
            }
        }
        cout << "CURRENT COUNT: " << count << "  |  ";
        cout << pos_pas_str;
        if (pos_pas_str == password_string) {
            bypassed = true;
            cout << "\n";
            cout << "IT TOOK " << count << " TO GUESS PASSWORD";
        } else {
            pos_pas_str = "";
        }
        cout << "\n";
        count = count + 1;
    }
}


int main() {
    //string password_string = "MORa3*@hO7rl";
    string password_string = "1234";
    password_bypass(password_string);
    return 0;
}