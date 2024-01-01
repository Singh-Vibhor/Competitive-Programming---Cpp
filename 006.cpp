#include <iostream>

#include <iomanip>

#include <string>



using namespace std;



const int SINGLE_ROOM_RATE = 60;

const int DOUBLE_ROOM_RATE = 75;

const int KING_ROOM_RATE = 100;

const int SUITE_ROOM_RATE = 150;

const int MAX_FLOORS = 5;

const int MAX_ROOMS_PER_FLOOR = 30;



int main() {


    string location;

    int numFloors, totalRooms, occupiedSingle, occupiedDouble, occupiedKing, occupiedSuite;
    totalRooms = 0;

    int totalOccupiedRooms = 0;
    int occupiedRooms = 0, allRooms = 0;

    double hotelIncome = 0.0;

    double occupancyRate = 0.0;

    int minRooms = MAX_ROOMS_PER_FLOOR + 1;

    int minFloor = 0;



    cout << "============================================================" << endl;

    cout << "                    BlueMont Hotel " << endl;

    cout << "============================================================" << endl;



    cout << "Enter the location of this hotel chain: ";

    getline(cin, location);



    do {

        cout << "Enter total number of floors of the hotel: ";

        cin >> numFloors;

        if (numFloors < 1 || numFloors > MAX_FLOORS) {

            cout << "Number of floors should be between 1 & 5!! Please try again." << endl;

        }

    } while (numFloors < 1 || numFloors > MAX_FLOORS);

   


    for (int i = 1; i <= numFloors; ++i) {


        do {



            do {

                cout << "Enter total number of rooms on the " << i << " floor: ";

                cin >> totalRooms;

                if (totalRooms < 1 || totalRooms > MAX_ROOMS_PER_FLOOR) {

                    cout << "Number of rooms should be between 1 & 30!! Please try again." << endl;

                }



            } while (totalRooms < 1 || totalRooms > MAX_ROOMS_PER_FLOOR);

            cout << "How many SINGLE rooms are occupied on the " << i << " floor: ";

            cin >> occupiedSingle;

            cout << "How many DOUBLE rooms are occupied on the " << i << " floor: ";

            cin >> occupiedDouble;

            cout << "How many KING rooms are occupied on the " << i << " floor: ";

            cin >> occupiedKing;

            cout << "How many SUITES are occupied on the " << i << " floor: ";

            cin >> occupiedSuite;



            totalOccupiedRooms = occupiedSingle + occupiedDouble + occupiedKing + occupiedSuite;



            if (totalOccupiedRooms > totalRooms) {

                cout << "Total number of occupied rooms exceeds the total number of rooms on this floor. Please try again!!" << endl;
                continue;
            }

            occupiedRooms += totalOccupiedRooms;
            allRooms += totalRooms;
            
        } while (totalOccupiedRooms > totalRooms);



        hotelIncome += (occupiedSingle*SINGLE_ROOM_RATE) +

            (occupiedDouble*DOUBLE_ROOM_RATE) +

            (occupiedKing*KING_ROOM_RATE) +

            (occupiedSuite*SUITE_ROOM_RATE);



        if (totalRooms < minRooms) {

            minRooms = totalRooms;

            minFloor = i;

        }

    }



    occupancyRate = ((occupiedRooms*1.0) / (allRooms*1.0))*100;
    cout<<allRooms<<" "<<occupiedRooms<<endl;


    cout << "====================================================================================================" << endl;
    cout << "                            BlueMont Hotel located in " << location << "." << endl;
    cout << "====================================================================================================" << endl;
    cout << endl;
    cout << "                             TODAY'S ROOM RATES <US&/NIGHT>" << endl;
    cout << endl;
    cout << left << setw(20) << "Single Room" << setw(30) << "Double Room" << setw(25) << "King Room" << setw(20) << "Suite Room" << endl;
    cout << right << setw(10) << SINGLE_ROOM_RATE << setw(15) << DOUBLE_ROOM_RATE << setw(30) << KING_ROOM_RATE << setw(30) << SUITE_ROOM_RATE << endl;
    cout << endl;
    cout << "====================================================================================================" << endl;

    cout << " Hotel Income: $" << fixed << setprecision(2) << hotelIncome << endl;

    cout << " Total # of rooms: " << allRooms << endl;

    cout << " Total # occupied rooms: " << occupiedRooms << endl;

    cout << " Total # unoccupied rooms: " << allRooms - occupiedRooms << endl;

    cout << " Occupancy Rate: " << fixed << setprecision(2) << occupancyRate << "%" << endl;

    cout << minFloor << "th Floor with " << minRooms << " rooms, has the least number of rooms." << endl;

    if (occupancyRate < 60) {

        cout << "Need to improve Hotel occupancy rate!!" << endl;

    }



    cout << "\nThank You for testing my program!!" << endl;

    cout << "PROGRAMMER: Rhea M Ashtamkar" << endl;

    cout << "CMSC 140 PROJECT 3" << endl;

    cout << "Due Date: 2nd November, 2023" << endl;



    return 0;

}