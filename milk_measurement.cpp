#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Log {
public:
    int date;
    string name;
    int milk;
    Log (int date, string name, int milk) {
        this->date = date;
        this->name = name;
        this->milk = milk;
    }
};

bool operator <(const Log &a, const Log &b) {
    return a.date < b.date;
}

string maximum(int x, int y, int z){

    if(x > y){

        if(x > z){
            return "Bessie";
        } else if (x==z) {
            return "Tie";
        } else {
            return "Mildred";
        }

    } else{
        if(y > z){
            return "Elsie";
        } else if (y==z) {
            return "Tie";
        } else {
            return "Mildred";
        }

    }

}

int main() {
    int n;
    int date;
    string name;
    string milkstr;
    int milk;
    int Bessie = 7;
    int Elsie = 7;
    int Mildred = 7;
    int rankingBoard = 0;
    string temporaryMaximum = "";

    vector<Log> v;

    ifstream fin ("measurement.in");
    ofstream fout ("measurement.out");

    if (fin.is_open()) {
        fin >> n;

        for (int i=0; i<n; i++) {
            fin >> date >> name >> milkstr;
            if (milkstr.at(0) == '+') {
                milk = stoi(milkstr.substr(1));
            } else {
                milk = -stoi(milkstr.substr(1));
            }

            v.push_back(Log(date, name, milk));
        }
        sort(v.begin(), v.end());
    }

    for (int i=0; i<v.size(); i++) {

        if(v[i].name == "Bessie"){

            Bessie = Bessie + v[i].milk;

        } else if (v[i].name == "Elsie"){

            Elsie = Elsie + v[i].milk;

        } else if (v[i].name == "Mildred"){

            Mildred = Mildred + v[i].milk;

        }

        if(maximum(Bessie, Elsie, Mildred) != temporaryMaximum){

            //cout << "TempMax: " << temporaryMaximum << endl;
            //cout << "Max: " << maximum(Bessie, Elsie, Mildred) << endl;

            rankingBoard++;

            if (maximum(Bessie, Elsie, Mildred) != "Tie") {
                temporaryMaximum = maximum(Bessie, Elsie, Mildred);
            }
        } else if (Bessie == Elsie == Mildred){

            rankingBoard++;

        }

        //cout << "Bessie: " << Bessie << endl;
        //cout << "Elsie: " << Elsie << endl;
        //cout << "Mildred: " << Mildred << endl;
        //cout << endl;
    }

    fout << rankingBoard << endl;

    fin.close();
    fout.close();

}