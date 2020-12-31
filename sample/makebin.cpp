/*
This code generates 'sample.bin'.
Here its information is.
File size: 8,000 bytes
Data number in the file: 1,000
Single data size: 8 bytes
Single data structure:
|LSB                             MSB|
|0     26|27    35|36    48|49    63|
|  time  |  line  |  sine  | cosine |
*/

#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

// Sample data structure
#pragma pack(push, 1)
typedef struct {
    unsigned long long time : 27;
    unsigned long long line : 9;
    unsigned long long sine : 13;
    unsigned long long cosine : 15;
} BinStructure;
#pragma pack(pop)

// Make samples
void MakeSamples(BinStructure* out, unsigned int num) {
    const double PI = 3.14159265359;
    
    memset(out, 0, sizeof(BinStructure) * num);
    for(unsigned int i = 0; i < num; i++) {
        out[i].time = i;
        out[i].line = out[i].time;
        out[i].sine = 4000 * (sin(2.0 * PI * 0.01 * out[i].time) + 1.0);
        out[i].cosine = 16000 * (cos(2.0 * PI * 0.01 * out[i].time) + 1.0);
    }
}

int main() {
    
    // Make samples
    unsigned int sampleNum = 1000;
    cout << "Making " << sampleNum << " samples" << endl;
    cout << "Element's size is " << sizeof(BinStructure) << " bytes" << endl;
    BinStructure* buf = new BinStructure[sampleNum];
    MakeSamples(buf, sampleNum);
    
    // Write
    ofstream ofs;
    const char* FNAME = "sample.bin";
    ofs.open(FNAME, ios::binary | ios::out);
    if (ofs.is_open()) {
        ofs.write(reinterpret_cast<char*>(buf), sizeof(BinStructure) * sampleNum);
        ofs.close();
        cout << FNAME << " generated" << endl;
    }

    delete [] buf;
    return 0;
}