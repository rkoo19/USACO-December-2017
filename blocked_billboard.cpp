#include <iostream>
#include <fstream>

using namespace std;

int max (int v1, int v2) {
    if (v1<v2) {
        return v2;
    } else {
        return v1;
    }
}

int min (int v1, int v2){
     if (v1<v2) {
        return v1;
    } else {
        return v2;
    }
}

int intersection(int x1, int y1, int x2, int y2, int a1, int b1, int c1, int d1){

    int x_overlap = max(0, min(x2, c1) - max(x1, a1));
    int y_overlap = max(0, min(y2, d1) - max(y1, b1));
    int overlap_area = x_overlap * y_overlap;

    return overlap_area;

}

int main() {

    ifstream myfile ("billboard.in");
    ofstream myoutfile ("billboard.out");

    if(myfile.is_open()){

        int b1x1, b1y1, b1x2, b1y2, b2x1, b2y1, b2x2, b2y2, tx1, ty1, tx2, ty2;

        myfile >> b1x1 >> b1y1 >> b1x2 >> b1y2 >> b2x1 >> b2y1 >> b2x2 >> b2y2 >> tx1 >> ty1 >> tx2 >> ty2;

        int b1x = b1x2 - b1x1;
        int b1y = b1y2 - b1y1;
        int b1totalarea = b1x * b1y;

        int b2x = b2x2 - b2x1;
        int b2y = b2y2 - b2y1;
        int b2totalarea = b2x * b2y;

        int totalArea = b1totalarea + b2totalarea;

        int intersectedArea = intersection(b1x1, b1y1, b1x2, b1y2, tx1, ty1, tx2, ty2) + intersection(b2x1, b2y1, b2x2, b2y2, tx1, ty1, tx2, ty2);

        myoutfile << totalArea - intersectedArea << "\n";

    }

    myfile.close();
    myoutfile.close();

}