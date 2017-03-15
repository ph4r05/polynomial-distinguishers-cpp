//
// Created by ph4r05
//

#include <iostream>
#include <fstream>
#include "DataSource/DataSourceAES.h"
#include "DataSource/DataSourceRC4.h"
#include "DataSource/DataSourceRC4Column.h"
#include "DataSource/DataSourceSHA3.h"
#include "DataSource/DataSourceEstream.h"
#include "DataSource/DataSourceMD5.h"
#include <string>

using namespace std;

int dataGen(DataSource * ds, string filename){
    size_t buffer_size = 1024*1024*64;
    char* buffer = new char[buffer_size];
    int i;

    ofstream outfile(filename.c_str(), ios::binary);
    for(i=0; i<1024/64; i++) {
        ds->read(buffer, buffer_size);
        outfile.write(buffer, buffer_size);
    }

    outfile.close();
    delete ds;
    return 0;
}

int main(int argc, char *argv[]) {
    unsigned long seed = 0;

    dataGen(new DataSourceMD5(seed, 15), "MD5_r15.bin");
    dataGen(new DataSourceMD5(seed, 16), "MD5_r16.bin");
    dataGen(new DataSourceMD5(seed, 17), "MD5_r17.bin");

    dataGen(new DataSourceSHA3(seed, SHA3_SHA256, 3), "SHA256_r3.bin");
    dataGen(new DataSourceSHA3(seed, SHA3_SHA256, 4), "SHA256_r4.bin");

    dataGen(new DataSourceRC4(seed), "RC4.bin");
    dataGen(new DataSourceRC4Column(seed), "RC4_Col.bin");

    return 0;
}
