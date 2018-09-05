#include "Blockchain.h"
#include<fstream>
int main()
{
     
      cout<<"                            BLOCKCHAIN ALGORITHM IN C++ "<<endl<<endl;
    cout<<"THIS PROGRAM CONTAINS A COPYWRITE HEADER AND CPP FILE SHA256 PROVIDED BY zedwood.com BASED ON Olivier Gay's version"<<endl<<endl;
    cout<<"DEFAULT DIFFICULTY LEVEL HAS BEEN SET TO 4 "<<endl<<endl;
    cout<<"                           THIS PROGRAM IS DEVELOPED BY ASHISH PANDEY "<<endl<<endl;
    cout<<"                           JONDHALE COLLEGE COMPUTER ENGINEERING\n\n";

     
     
     
    int print();
    Blockchain bChain = Blockchain();

   int choice;
    choice = print();
      ifstream fp;
    fp.open("database.txt",ios::in);
    int line_count=0;
    string input;
    while(getline(fp,input))
        line_count++;

       fp.open("database.txt",ios::in);


    while(getline(fp,input))
        line_count++;
       if(choice==1){
        string buffer;
         string transaction_amt,from="",to="";
        getline(cin,buffer);
        cout<<"amt  ";
        cin>>transaction_amt;
        getline(cin,buffer);
         cout<<"from  ";
         getline(cin,from);
         getline(cin,buffer);
         cout<<"to  ";
         getline(cin,to);
     //  cout<<line_count<<endl;
         string transaction = "_"+from +"_"+ to +"_"+transaction_amt;
         cout<<transaction<<endl;
         if(line_count<10)
         {
            cout << "Mining block "<<line_count+1<<" ...." << endl;
            bChain.AddBlock(Block(line_count+1,transaction,0,0));
        }
        else
           {
               cout<<"Make another database max 9 entry allowed make another database to add more"<<endl;
               exit(0);
           }
       }
    else if(choice==2)
           {
               int q=0;
               cout<<"Do you want to store outputs 1.yes 0.no ";
               cin>>q;
               cout<<"Entry from retrieval and parsing info "<<endl;
               bChain.AddBlock(Block(line_count+1,"_Entry_for_retrieving",1,q));
               int ch =2;
               if(q==1){
               cout<<"\nDo you want organised data 1.yes 2.no";
               cin>>ch;
               if(ch==1)
               {
                   ifstream fr;
                   ofstream fp2;
                   fr.open("store.txt",ios::in);
                   fp2.open("Organised.txt",ios::out);
                   while(getline(fr,input))
                   {
                       int k,i;
                       char from[10],to[10],amt[10],ch2[2];
                       ch2[0] = input[0];
                       ch2[1] = '\0';
                       string ty(ch2);
                       string str1 = "Block no ";
                       string str2 = " Contains following data ";
                      fp2<<"\nBlock no "<<ty<<" Contains following data "<<endl;;
                      for(k=0;input[k]!='_';k++);
                      for(k++,i=0;input[k]!='_';k++,i++)
                          from[i] = input[k];
                          from[i] ='\0';
                      string str_from(from);
                      for(k++,i=0;input[k]!='_';k++,i++)
                          to[i] = input[k];
                          to[i] ='\0';
                    string str_to(to);
                      for(k++,i=0;input[k]!='\0';k++,i++)
                          amt[i] = input[k];
                          amt[i] ='\0';
                        string str_amt(amt);
                    fp2<<"Sender "<<str_from<<"\nReciver "<<str_to<<"\namount "<<str_amt<<endl;
                   }
                   fr.close();
                   fp2.close();
               }
               }
           }





    fp.close();
    return 0;
}
int print()
{
    int ch;
    cout<<"\n Enter choice\n1.Mine block\n2.retrieve info  ";
    cin>>ch;
    return ch;
}
