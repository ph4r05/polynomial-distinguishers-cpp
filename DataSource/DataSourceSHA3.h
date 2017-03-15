//
// Created by Dusan Klinec on 27.06.16.
//

#ifndef BRUTTE_FORCE_DATASOURCESHA3_H
#define BRUTTE_FORCE_DATASOURCESHA3_H

#include "DataSource.h"
#include "../DataGenerators/sha3/Sha3Interface.h"

#define SHA3_MD6 1
#define SHA3_TANGLE 2
#define SHA3_KECCAK 3
#define SHA3_SHA256 4

#define SHA3_DEFAULT_HASH_INIT -999
#define SHA3_MAX_OUTPUT 4096

class DataSourceSHA3 : public DataSource {
public:
    // hash_init should be used only in special circumstances (keccak default init  - faulty)
    // hash_init = parameter to Init() function of the hash. In most cases it is equal to outputSize*8
    // set to SHA3_DEFAULT_HASH_INIT to use outputSize*8 value.
    DataSourceSHA3(unsigned long seed, int hash, int rounds, unsigned outputSize = 16, int hash_init = SHA3_DEFAULT_HASH_INIT);
    ~DataSourceSHA3();

    virtual long long getAvailableData() override;
    virtual void read(char *buffer, size_t size) override;
    virtual void read(char *buffer, char* messages, size_t messagesize, size_t size);
    virtual std::string desc() override;

protected:
    int m_hashFunction;
    int m_outputSize;
    long long m_counter;
    int m_rounds;
    int m_hash_init;
    Sha3Interface * m_sha3;
private:
};


#endif //BRUTTE_FORCE_DATASOURCESHA3_H
