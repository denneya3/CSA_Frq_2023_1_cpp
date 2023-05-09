#include <iostream>
using namespace std;

class AppointmentBook{
private:
    bool blocks[8][60]; // true = occupied

    bool isMinuteFree(int period, int minute){
        return !blocks[period-1][minute];
    }
    void reserveBlock(int period, int startMinute, int duration){
        for (int minute = startMinute; minute <= duration+startMinute; minute++){
            blocks[period-1][minute] = true;
        }
    }
public:
    void defaultSetup(){
        for (int i = 1; i <= 5; i++){

        }
    }

    int findFreeBlock(int period, int duration){
        for (int minute = 1; minute<= 59; minute++){
            if (isMinuteFree(period, minute) && minute+duration<=59){
                return minute;
            }
        }
        return -1;
    }

    bool makeAppointment(int startPeriod, int endPeriod, int duration){
        for (int cP = startPeriod; cP <= endPeriod; cP++){
            int findBlock = findFreeBlock(cP, duration);
            if (findBlock != -1){
                reserveBlock(cP, findBlock, duration);
                return true;
            }
        }
        return false;
    }

    void printArrangement(){
        cout << blocks;
    }
};

int main() {
    AppointmentBook book;

    bool mAp = book.makeAppointment(1, 8, 20);
    cout << mAp;
    //book.printArrangement();

    return 0;
}
