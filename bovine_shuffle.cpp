#include <iostream>
#include <fstream>

using namespace std;

int main(){

    ifstream myfile ("shuffle.in");
    ofstream myoutfile ("shuffle.out");
    
    int numberOfCows;

    if(myfile.is_open()){

        myfile >> numberOfCows;

        int shuffleOrder[numberOfCows];
        int orderID[numberOfCows];
        int firstShuffle[numberOfCows];
        int secondShuffle[numberOfCows];
        int thirdShuffle[numberOfCows];

        for(int i = 0; i < numberOfCows; i++){

            myfile >> shuffleOrder[i];

        }

        for(int i = 0; i < numberOfCows; i++){

            myfile >> orderID[i];

        }

        for(int i = 0; i < numberOfCows; i++){

            firstShuffle[i] = orderID[shuffleOrder[i]-1];

        }

        for(int i = 0; i < numberOfCows; i++){

            secondShuffle[i] = firstShuffle[shuffleOrder[i]-1];

        }

        for(int i = 0; i < numberOfCows; i++){

            thirdShuffle[i] = secondShuffle[shuffleOrder[i]-1];

        }

        for(int i = 0; i < numberOfCows; i++){

            myoutfile << thirdShuffle[i] << "\n";

        }

    }

    myfile.close();
    myoutfile.close();

}