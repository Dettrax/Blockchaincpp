#include<string.h>
#include "Blockchain.h"
#include<fstream>
#include<stdlib.h>
static int check_des =0;
struct node
{
	int priority;
	int info;
	struct node *link;
};
class Priority_Queue
{
    private:
        node *front;
    public:
        Priority_Queue()
        {
            front = NULL;
        }
       void insert(int item, int priority)
        {
            node *tmp, *q;
            tmp = new node;
            tmp->info = item;
            tmp->priority = priority;
            if (front == NULL || priority < front->priority)
            {
                tmp->link = front;
                front = tmp;
            }
            else
           {
                q = front;
                while (q->link != NULL && q->link->priority <= priority)
                    q=q->link;
                tmp->link = q->link;
                q->link = tmp;
            }
            }
void del()
{
            node *tmp;
            if(front == NULL)
                cout<<"Queue Underflow\n";
            else
            {
                tmp = front;
                cout<<"Deleted item is: "<<tmp->info<<endl;
                front = front->link;
                free(tmp);
            }
        }
void display()
{
           node *ptr;
            ptr = front;
            if (front == NULL)
            cout<<"Queue is empty\n";
            else
            {	cout<<"Queue is :\n";

                cout<<"Priority       Item\n";
                ofstream fp;
               fp.open("test1.txt",ios::out);
                while(ptr != NULL)
                 {
                    cout<<ptr->priority<<"                 "<<ptr->info<<endl;
                    fp<<ptr->info;
                    fp<<"\n";
                    ptr = ptr->link;
                  }
                }
            }
};
int main()
{
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout<<"                                            INITIALIZING BLOCKCHAIN TECHNOLOGY "<<endl;
    cout<<"                                            Press Enter to continue ";
    getchar();
    system("clear");
    void databaseview();
    void errorhandling();
    cout<<"       BLOCKCHAIN ALGORITHM IN C++ TO DEVELOPE A IMMUTABLE LEDGER  Data structure: priority queue"<<endl<<endl;
    cout<<"THIS PROGRAM CONTAINS A COPYWRITE HEADER AND CPP FILE SHA256 PROVIDED BY zedwood.com BASED ON Olivier Gay's version"<<endl<<endl;
    cout<<"DEFAULT DIFFICULTY LEVEL HAS BEEN SET TO 4 "<<endl<<endl;
    cout<<"                           THIS PROGRAM IS DEVELOPED BY ASHISH PANDEY "<<endl<<endl;
    cout<<"                           JONDHALE COLLEGE COMPUTER ENGINEERING\n\n";
    string input;
    int que();
    void copy();
    int print();
    Blockchain bChain = Blockchain();
    void Instructions();
    Instructions();
    int ask;
    cout<<"\nDo you want to read instruction on database 1.yes 0.no  ";
    cin>>ask;
    if(ask == 1)
        databaseview();
    cout<<"\nDo you want to read instruction on Error handling 1.yes 0.no  ";
    cin>>ask;
    if(ask == 1)
        errorhandling();
    cout<<"\n\nEntering  mempool \n";
    que();
 ifstream check;
 string check_str;
 check.open("test1.txt",ios::in);
while(getline(check,check_str))
{
    int q;
    char asend[50];
    for(q=0;check_str[q]!='\0';q++)
    asend[q] = check_str[q];
    asend[q] = '\0';
    string str_asend(asend);
    char amt[20], from_name[20],to_name[20];
    ifstream as;
    as.open("test.txt",ios::in);
while(getline(as,input))
{
    int p,j=0;
  for(p=0;input[p]!='_';p++)
            amt[p] = input[p];
  amt[p] = '\0';
 int y=0;
  p++;
  for(j=0;input[p]!='_';p++,j++)
  {
      from_name[j] = input[p];
  }
  from_name[j]='\0';
  for(p++,j=0;input[p]!='\0';p++,j++)
   {
       to_name[j] = input[p];
   }
  to_name[j] = '\0';
{
string str_amount(amt);
string str_from(from_name);
string str_to(to_name);
if(str_amount == str_asend)
 {
   int choice;
    choice = check_des;
      ifstream fp;
    fp.open("database.txt",ios::in);
    int line_count=0;
    while(getline(fp,input))
        line_count++;
       fp.open("database.txt",ios::in);
    while(getline(fp,input))
        line_count++;
       if(choice==1){
        if(line_count<4)                         //LINE LIMITOR
         {
        string buffer;
         string transaction_amt,from="",to="";
        transaction_amt=str_amount;
         from=str_from;
         to=str_to;
         string transaction = "_"+from +"_"+ to +"_"+transaction_amt;
            cout << "Mining block "<<line_count+1<<" ...." << endl;
            bChain.AddBlock(Block(line_count+1,transaction,0,0));
        }
        else
           copy();
       }
    else if(choice==2)
           {
               int q=1;
               cout<<"Parsing info "<<endl;
               cout<<"Processing store.txt"<<endl;
               cout<<"Data in security check database ";
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
}
}
}
}
cout<<"\nAll process completed \n\n        terminating program";
return 0;
}
int print()
{
    int ch;
    cout<<"\n Enter choice\n1.Mine block\n2.retrieve info  ";
    cin>>ch;
    return ch;
}
void copy()
{
  fstream a,b;
char ch;
a.open("database.txt",ios::in);
b.open("Database.dat",ios::app);
while (!a.eof())
{
a.get(ch);
b<<ch;
}
a.close();
b.close();
ofstream ofs;
ofs.open("database.txt", std::ofstream::out | std::ofstream::trunc);
ofs.close();
}
int que()
{
    {
    int did();
    int choice, item, priority;
    Priority_Queue pq;
        choice = did();
        char amount[20];
        ifstream fp;
        string input;
        int count_of_lines=0;
        fp.open("test.txt",ios::in);
        while(getline(fp,input))
            count_of_lines++;
        fp.close();
        int pri[count_of_lines];
        fp.open("test.txt",ios::in);
 int j=0;
 while(getline(fp,input))
{
        int i = 0;
        for(i=0;input[i]!='_';i++)
            amount[i] = input[i];
        amount[i] = '\0';
        string amt(amount);
        stringstream geek(amt);
        int x;
        geek>>x;
        pri[j] = x;
        j++;
}
int size = sizeof(pri)/sizeof(pri[0]);
int i;
for (i = 0; i < size-1; i++)
 for (j = 0; j < size-i-1; j++)
           if (pri[j] < pri[j+1])
              swap(pri[j], pri[j+1]);
int check_pr=1;
for(i=0;i<size;i++)
           {
            priority = check_pr;
            pq.insert(pri[i], priority);
            check_pr++;
           }
          pq.display();
    return 0;
}
}
int did()
{
    ofstream fp;
    fp.open("test.txt",ios::out);
    int ch=0,chek=0;
    string str;
    cout<<"Do you want to mine or view records  1.mine 0.view ";
    cin>>chek;
    if(chek == 0)
    cout<<"If you don't want to mine and just store and view data from database first enter 1 put dummy as 9_9_9 then enter 0"<<endl;
    cout<<"Enter 1 for storing records in mempool and 0 to finish proceed with mining (if the database already have 4 entries then this entry will be considered dummy )  ";
    cin>>ch;
    while(ch != 0)
    {
        cout<<"Enter file amt_from_to ";
        cin>>str;
        fp<<str;
        fp<<"\n";
    cout<<"Enter 1 for storing records in mempool and 0 to finish proceed with mining  ";
    cin>>ch;
    }
    if(chek == 1)
        check_des = 1;
    else if(chek == 0)
         check_des =2;

        return 1;
}
void Instructions()
{
    cout<<"    Instructions to execute this program "<<endl;
    cout<<" Every input in this program is highly case sensitive and format sensitive even a slight mistake may change the output"<<endl;
    cout<<"\n\n"<<endl;
    cout<<"1. Store the data in mempool by the format Amount_Sender_Receiver "<<endl;
    cout<<"2. The data will then be stored in a temporary database called database.txt (at max 4 records at a time) where all the security checks will be performed"<<endl;
    cout<<"3. Then data in the database will be appended to Database.dat where further processes like organizing data storing output can be performed"<<endl;
    cout<<"4. Then data will be filtered from the cryptography hash,nonce,index,difficulty level and timestamp and stored to store.txt"<<endl;
    cout<<"Store.txt can be used by developers to check whether the input data matches with organized data in organized.txt"<<endl;
}
void databaseview()
{
    cout<<"\n\nThis are the instruction to study database.txt"<<endl;
    cout<<"I made database.txt to implement security checks which are the main purpose of making this in blockchain"<<endl;
    cout<<"The database contains the following data in this order"<<endl;
    cout<<"   Index n.o,difficulty level,previous block hash,current block hash,timestamp,Nonce and data";
    cout<<"The purpose of making other database 'Database.dat' was to append the data when the index n.o crosses 4"<<endl;
    cout<<"Eg : my program can hold at max  4 records at a time in database.txt after that all the records will be appended in Database.dat and database.txt will be cleared to add more records\n"<<endl;
    cout<<"The Database.dat do not contain any security check as that part was implemented to check out for glitch that restrict the max 4 records in database.txt ,if the glitch is solved then there will be no need for Database.dat and the ledger will be fully secured"<<endl;
}
void errorhandling()
{
    cout<<"invalid by difficulty means that difficulty level data of any row has been changed "<<endl;
    cout<<"invalid by previous hash  means that any one of the hash(either previous or current ) has been changed in row"<<endl;
    cout<<"invalid by hash means that  the transaction history or the hash of last block  or any character in the file has been changed"<<endl;
}
