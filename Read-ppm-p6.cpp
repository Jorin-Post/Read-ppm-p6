#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

int main(){
    ifstream file;
    file.open("stars.ppm", ifstream::binary); // open file in binaty mode other whise it won't read the full file!!
    if (file.fail())
        cout << "Can't open file!" << endl;
    else
        cout << "File open!" << endl;

    // get specs of ppm file   
    string type = "", width="", height="", RGB="";
    file >> type;
    file >> width;
    file >> height;
    file >> RGB;
    cout << type << '\t' << width << '\t' << height << '\t' << RGB << endl;

    // get px coller val RGB
    uint8_t red, green, blue;
    int nearwhite = 0, px =0, t = stoi(width)*stoi(height);
    while (!file.eof()){
        file >> red;
        file >> green;
        file >> blue;
        int r =(int)(red), g = (int)(green), b=(int)(blue);
        //cout << r << '\t' << g << '\t' << b << endl; // don't use on full file!
        if (r > 200 && g > 200 && b > 200) // black is r0 g0 b0 and white is r255 g255 b255
            nearwhite++;
        px++;
    }
    cout << nearwhite << '\t' << px << endl;
    file.close();
}