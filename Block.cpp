
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
    int line_count=0,check_count;
    fp.open("database.txt",ios::in);
    while(getline(fp,input))
        line_count++;
    check_count = line_count-1;


    fp.close();

    //CHEECK
    fp.open("database.txt",ios::in);
    char temp_prevstr[64],temp_currstr;
    while(getline(fp,input))
    {
    if(check_count==line_count)
        break;

    check_count++;
    int i,j;
    for(i=3+65,j=0;i<3+65+64;i++,j++)
        temp_prevstr[j]=input[i];

    temp_prevstr[j]='\0';
    getline(fp,input);
    {
       int flag=0;
        if(line_count>1)
        for(i=3,j=0;i<4+63;i++,j++)
          {
              if(input[i] != temp_prevstr[j])
             flag =1;
          }
         if(flag==1)
            {
                cout<<"\nInvalid by block \n"<<endl;
                exit(1);
            }

    }
    fp.seekg(-52, ios::cur);
    }
    fp.close();



int temp_index=0;
{
   // Chain verify
   ifstream fp3;

   fp3.open("database.txt",ios::in);
   while(getline(fp3,input))
   {
       temp_index++;
   }
   if(_nIndex<=temp_index)
   {
       int i,j;
    fp.open("database.txt",ios::in);
     int line_count=0,check_count=0;
    while(getline(fp,input))
        line_count++;
    fp.close();
    fp.open("database.txt",ios::in);
    int flag =1;
    while(check_count<line_count && flag==1)
    {
        check_count++;
        getline(fp,input);
    for(i=0;input[i]!=' ';i++)
        chIndex[i] = input[i];
    chIndex[i]='\0';
    str_chIndex.assign(chIndex);
    i = i+2;
    for(j=0;j<64;j++,i++)
        chPrevHash[j]=input[i];
    chPrevHash[j] = '\0';
   str_chprevhash.assign(chPrevHash);


    for(j=0;j<63;j++,i++)
        chcurrhash[j]=input[i];
    chcurrhash[j]='\0';
    str_chcurrhash.assign(chcurrhash);
    i++;
    for(j=0;j<10;i++,j++)
     chTime[j]=input[i];
    chTime[j]='\0';
    temp_chTime.assign(chTime);



    for(j=0;input[i]!=' ';i++,j++)
        chNonce[j]=input[i];
    chNonce[j]='\0';
    i++;
    for(j=0;input[i]!='\0';j++,i++)
       chData[j]=input[i];
    temp_chNonce.assign(chNonce);
    temp_chData.assign(chData);

    string verify = _CheckCalculateHash();
    char c_str[nDifficulty + 1];
    for (uint32_t i = 0; i < nDifficulty; ++i)
    {
        c_str[i] = '0';
    }
    c_str[nDifficulty] = '\0';

    string check_str(c_str);
    cout<<verify<<endl;
    for(int k=0;k<4;k++)
        if(verify[k]!='0')
         flag=0;
    }


if(flag==0)
{
    cout<<temp_index<<endl;
    cout<<"Invalid by hash ";
    exit(2);
}
   }

fp.close();
}



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


     if(file_check==1 && _nIndex>=1 && store_file==0)
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
     else if(file_check==1 && _nIndex>=1 && store_file==1)
     {
        ofstream fp2;
        ifstream fp1;
     fp1.open("database.txt",ios::in);
     fp2.open("store.txt",ios::out);
      while(getline(fp1,input))
         {
             int y;
             char store_flag[50];
             int k;
             for(k=0;input[k]!='_';k++);
             for(y=0;input[k]!='\0';k++,y++)
                store_flag[y]=input[k];
            store_flag[y] ='\0';
            string str_store_flag(store_flag);
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
