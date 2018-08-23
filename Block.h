

//#ifndef TESTCHAIN_BLOCK_H


#include <cstdint>
#include <iostream>
#include <sstream>

using namespace std;

class Block {
public:
    string sHash;
    string sPrevHash;

    Block(uint32_t nIndexIn, const string &sDataIn,int file_check,int store_file);

    void MineBlock(uint32_t nDifficulty);
     uint32_t _nIndex;
     int file_check=0;
     int store_file=0;
private:
    //uint32_t _nIndex;
    uint32_t _nNonce;
    string _sData;
    time_t _tTime;

    string _CalculateHash() const;
    string _CheckCalculateHash() const;
};


