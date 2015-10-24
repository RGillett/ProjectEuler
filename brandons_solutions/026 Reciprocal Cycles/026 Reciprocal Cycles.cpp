#include <iostream>

using namespace std;

void printFractions();

int main()
{
    long double r = 1;
    cout << r / 3 << endl;
}

/*string toString(double number){
    string numberString = "";
    char onesChar;
    double ones = 0;
    while(true){
        ones = number % 10;
        switch(ones){
            case 0: onesChar = '0'; break;
            case 1: onesChar = '1'; break;
            case 2: onesChar = '2'; break;
            case 3: onesChar = '3'; break;
            case 4: onesChar = '4'; break;
            case 5: onesChar = '5'; break;
            case 6: onesChar = '6'; break;
            case 7: onesChar = '7'; break;
            case 8: onesChar = '8'; break;
            case 9: onesChar = '9'; break;
            default : cout << "Trouble converting number to string.\n";
        }
        number -= ones;
        numberString = onesChar + numberString;
        if(number == 0){
            break;
        }
        number = number/10;
    }
    return numberString;
}*/
