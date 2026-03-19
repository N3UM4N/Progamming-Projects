#include <iostream>
using namespace std;

void traffic_control() {
    int lane1 = 0;
    int lane2 = 0;
    int lane3 = 0;
    int lane4 = 0;
    while (true) {
        int lane1veh = rand() % 10;
        int lane2veh = rand() % 10;
        int lane3veh = rand() % 10;
        int lane4veh = rand() % 10;
        lane1 = lane1 + lane1veh;
        lane2 = lane2 + lane2veh;
        lane3 = lane3 + lane3veh;
        lane4 = lane4 + lane4veh;
        cout << "LANE 1: " << lane1 << "\n";
        cout << "LANE 2: " << lane2 << "\n";
        cout << "LANE 3: " << lane3 << "\n";
        cout << "LANE 4: " << lane4 << "\n";
        if (lane1 > lane2 && lane1 > lane3 && lane1 > lane4) {
            cout << "Allowing flow of lane 1" << "\n";
            int count = 3600000;
            while (count > 0) {
                if (lane1 == 0) {
                    count = 0;
                } else {
                    lane1 = lane1 - 1;
                }
                count = count - 1;
            }
        }
        else if (lane2 > lane1 && lane2 > lane3 && lane2 > lane4) {
            cout << "Allowing flow of lane 2" << "\n";
            int count = 3600000;
            while (count > 0) {
                if (lane2 == 0) {
                    count = 0;
                } else {
                    lane2 = lane2 - 1;
                }
                count = count - 1;
            }
        }
        else if (lane3 > lane1 && lane3 > lane2 && lane1 > lane4) {
            cout << "Allowing flow of lane 3" << "\n";
            int count = 3600000;
            while (count > 0) {
                if (lane3 == 0) {
                    count = 0;
                } else {
                    lane3 = lane3 - 1;
                }
                count = count - 1;
            }
        }
        else if (lane4 > lane1 && lane4 > lane2 && lane4 > lane3) {
            cout << "Allowing flow of lane 4" << "\n";
            int count = 3600000;
            while (count > 0) {
                if (lane4 == 0) {
                    count = 0;
                } else {
                    lane4 = lane4 - 1;
                }
                count = count - 1;
            }
        }

    }
}

int main() {
    traffic_control();
    return 0;
}
