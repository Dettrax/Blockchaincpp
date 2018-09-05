
#include<fstream>
#include "Blockchain.h"

Blockchain::Blockchain()
{
    _vChain.emplace_back(Block(0, "Genesis Block",0,0));
    _nDifficulty = 4;
}

void Blockchain::AddBlock(Block bNew)
{


    ifstream fp;



    fp.open("database.txt",ios::in);
    string input;
    char temp_str[64];
    while(getline(fp,input))
    {
        int i,j=0;
    for(i=2+65,j=0;i<2+65+64;i++,j++)
        temp_str[j]=input[i];
    temp_str[j]='\0';
    }
    string str(temp_str);
   // cout<<str;
    string  st = _GetLastBlock().sHash;
    if(bNew._nIndex==1)
    bNew.sPrevHash = st;
    else if(bNew._nIndex>1)
        bNew.sPrevHash = str;
    bNew.MineBlock(_nDifficulty);
    _vChain.push_back(bNew);
}

Block Blockchain::_GetLastBlock() const
{
    return _vChain.back();
}
