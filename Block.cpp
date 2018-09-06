#include<math.h>
#include<string.h>
#include<fstream>
#include "Block.h"
#include "sha256.h"
#include<stdlib.h>
string str_chIndex;
string str_chprevhash;
string str_chcurrhash;
string temp_chTime;
string temp_chNonce;
string temp_chData;
int NONCE=0;
char chIndex[20],chPrevHash[64],chcurrhash[64],chTime[20],chData[100],chNonce[200];

Block::Block(uint32_t nIndexIn, const string &sDataIn,int file_check,int store_file) : _nIndex(nIndexIn), _sData(sDataIn),file_check(file_check),store_file(store_file)
{
    _nNonce = 0;
    _tTime = time(nullptr);
    str_chcurrhash = _CheckCalculateHash();
    sHash = _CalculateHash();
}
void Block::MineBlock(uint32_t nDifficulty)
{
    ifstream fp;
    string input;
    fp.open("database.txt",ios::in);
    while(getline(fp,input))
    {
        char ch = nDifficulty+'0';
        if(input[2]!=ch)
        {
            cout<<"Invalid by difficulty ";
            exit(4);
        }
    }
  fp.close();
   // PREV check
    ifstream fp3;
     char temp_hashcheck[64];
     fp3.open("database.txt",ios::in);
      getline(fp3,input);
     int j,i;
     for(j=0,i=3+64;i<3+64+64;i++,j++)
       temp_hashcheck[j]=input[i];
    temp_hashcheck[j]='\0';
    fp3.close();
    string str_hashcheck(temp_hashcheck);
    fp3.open("database.txt",ios::in);
    getline(fp3,input);
    cout<<"\n";
    while(getline(fp3,input))
    {
      for(j=0,i=3;i<3+64;i++,j++)
      {
          if(input[i] != temp_hashcheck[j])
        {
            cout<<"invallid by prev "<<endl;
            exit(1);
        }
      }
        for(j=0,i=3+64;i<4+64+64;j++,i++)
            temp_hashcheck[j] = input[i];
    }
    fp3.close();
 // hash validity for database.txt
fp.open("database.txt",ios::in);
 int line_count =0;
 while(getline(fp,input))
    line_count++;
 fp.close();
char ch_index[2], ch_previoushash[64],ch_currenthash[64],ch_time[10],ch_nonce[10],ch_data[40];
fp.open("database.txt",ios::in);
while(getline(fp,input))
{
    ch_index[0] = input[0];
    ch_index[1] = '\0';
    str_chIndex.assign(ch_index);
    for(i=3,j=0;i<3+64;i++,j++)
        ch_previoushash[j]=input[i];
    ch_previoushash[j] = '\0';
    str_chprevhash.assign(ch_previoushash);
    for(i=4+64,j=0;i<=3+64+64;i++,j++)
          ch_currenthash[j]=input[i];
    ch_currenthash[j] = '\0';
    str_chcurrhash.assign(ch_currenthash);
    i--;
    for(j=0;j<10;j++,i++)
        ch_time[j] = input[i];
    ch_time[j] = '\0';
    temp_chTime.assign(ch_time);
    for(j=0;input[i]!=' ';i++,j++)
        ch_nonce[j] = input[i];
    ch_nonce[j] = '\0';
    temp_chNonce.assign(ch_nonce);

    for(j=0,i++;input[i]!='\0';i++,j++)
        ch_data[j] = input[i];
    ch_data[j]  = '\0';
    temp_chData.assign(ch_data);
    cout<<endl;
    string check_block = _CheckCalculateHash();
    char cstr[nDifficulty + 1];
    for (uint32_t i = 0; i < nDifficulty; ++i)
    {
        cstr[i] = '0';
    }
    cstr[nDifficulty] = '\0';
    string str(cstr);
    for(int k=0;k<nDifficulty;k++)
    {
        if(check_block[k] != cstr[k])
        {
            cout<<"Invalid by hash "<<endl;
            exit(2);
        }
    }
}
fp.close();
    char cstr[nDifficulty + 1];
    for (uint32_t i = 0; i < nDifficulty; ++i)
    {
        cstr[i] = '0';
    }
    cstr[nDifficulty] = '\0';
    string str(cstr);
    while (sHash.substr(0, nDifficulty) != str)
    {
        _nNonce++;
        sHash = _CalculateHash();
    }
    //For 1st entry
    if(_nIndex==1&&file_check==0)
     {
         ofstream fp1;
     fp1.open("database.txt",ios::out);
     fp1<<_nIndex<<" "<<nDifficulty<<sPrevHash<<sHash<< _tTime<< _nNonce<<" "<< _sData<<"\n";
     fp1.close();
     }
     else if(_nIndex>1&&file_check==0)
     {
    //For 2nd onwards
    ofstream fp1;
     fp1.open("database.txt",ios::app);
     fp1<<_nIndex<<" "<<nDifficulty<<sPrevHash<<sHash<< _tTime<< _nNonce<<" "<< _sData<<"\n";
     fp1.close();
   }
     if(file_check==1 && _nIndex>=1 && store_file==1)
     {
         ifstream fp1;
         fp1.open("database.txt",ios::in);
         while(getline(fp1,input))
         {
             cout<<"Block "<<input[0]<<" Data is :";
             int k;
             for(k=0;input[k]!='_';k++);
             for(;input[k]!='\0';k++)
                cout<<input[k];
             cout<<endl;
         }
         fp.close();
     }
     if(file_check==1 && _nIndex>=1 && store_file==1)
     {
        ofstream fp2;
        ifstream fp1;
     fp1.open("Database.dat",ios::in);
     fp2.open("store.txt",ios::out);
      while(getline(fp1,input))
         {
             int y;
             char store_flag[90];
             int k;
             for(k=0;input[k]!='_';k++);
             for(y=0;input[k]!='\0';k++,y++)
                store_flag[y]=input[k];
            store_flag[y] ='\0';
            string str_store_flag(store_flag);
            if(input[0] == '1' || input[0] == '2' || input[0] == '3' || input[0] == '4')
            fp2<<input[0]<<"  "<<str_store_flag<<endl;
         }
     fp2.close();
     fp1.close();
     }
    cout << "\nBlock mined: " << sHash << endl;

}
inline string Block::_CheckCalculateHash() const
{
    string ss1;
    ss1 = str_chIndex+ str_chprevhash + temp_chTime + temp_chData +temp_chNonce;
    return sha256(ss1);
}
inline string Block::_CalculateHash() const
{
    string timep,indexp,noncep,res;
    timep = to_string(_tTime);
    indexp = to_string(_nIndex);
    noncep = to_string(_nNonce);
    res = indexp + sPrevHash + timep + _sData + noncep;
            return sha256(res);
}
