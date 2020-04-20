#include "iostream"
#include "fstream"
#include "iomanip"
#include "conio.h"
#include "time.h"
using namespace std;
char choice;	
char go;
int found;
char nm[50];
int num;
int i=0,j=0;
char pas[20],Uname[20],Buffer[20],Upas[20];
const int MAX = 80; //size of buffer
char buffer[MAX]; //character buffer
fstream File;

class User
{
protected:
	    char user_name[50];
		char father_name[100];
		char adress[50];
		char gender[50];
	    char user_id[50];
		float with_amount;
		int  age;
public:
	    User()//:user_name( )//,father_name( ),adress( ),gender( ),user_id( ),age(0)
		{}
	    void  view_balance(int);
	    void  transaction_history();
		void  withdraw_amount(int);
		void  GetName();
		void  GetFname();
		void  GetGender();
		void  GetUid();
		void  GetAdress();                  //Functions For Modifying
		void  GetAge();
		char *get_uname()
		{return user_name;}                           void set_uname(char *uname)
		{user_name[50]=*uname;}
		char *get_fname()
		{return father_name;}                           void set_fname(char *fname)
		{father_name[100]=*fname;}
		char *get_adress()
		{return adress;}                          void set_adress(char *ud)
{adress[50]=*ud;}
		char *get_gender()
		{return gender;}                          void set_gender(char *ug)
		{gender[50]=*ug;}
		char *get_uid()
		{return user_id;}                             void set_uid(char *uid)
		{user_id[50]=*uid;}
		float get_withamount()
		{return with_amount;}                      void set_withamount(float setam)
		{with_amount=setam;}
		int   get_age()
		{return age;}                               void set_age(int uage)
		{age=uage;}
};
class New_User:public User
{
protected:
		  char profession[50];
public:
	      New_User()//:profession( )
	      {}	
		  void GetProfession();
		  char *get_profession()
		{return profession;}                    void set_profession(char *prof)
		{profession[50]=*prof;}	
};
class Account:public New_User
{
protected:
	    friend class User;
 	    char  account_type[50];
		float balance;
		float deposit;
		int   account_no;
public:
	    Account()//:account_type( ),balance(0),deposit(0),account_no( )
		{}
	    void  view_balance(int);
		void  deposit_amount(int);
		void  show_account() const;
		void  GetActype();
		void  GetAcno();
		void  report() const;	//function to show data in tabular format
		char *get_actype()
		{return account_type;}                    void set_actype(char *actype)
		{account_type[50]=*actype;}
		float get_balace()
		{return balance;}                    void set_balance(int bala)
		{balance=bala;}
		float get_depamount()
		{return deposit;}                 void set_depamount(int depam)
		{deposit=depam;}
		int   get_acno()
		{return account_no;}                      void set_acno(int acno)
		{account_no=acno;}
};
class Admin:public Account     
{	  
public:
	    void show_account() const;	//function to show data on screen
	    void view_all_accounts();
	    void create_new_account();
		void write_account();
	    void delete_account(int);
		void deposit_withdraw(int, int); // function to desposit/withdraw amount for given account
		void modify_by_AccountNo();	//function to add new data
	    void modify_by_Name();
		void modify_by_Profession();
		void modify_by_ID();
		void modify_by_Adress();
		void modify_All();
		void search_by_accountno();
		void search_by_Name();	
}AD;

void  Account ::GetAcno()
{
	fflush(stdin);
	cout<<"Enter New Account No            : ";
	cin>>account_no;
}
void  User    ::GetName()
{
	fflush(stdin);
	cout<<"Enter New  name                 : ";
	gets_s(user_name);
}
void  User    ::GetFname()
{
	fflush(stdin);
	cout<<"Enter New  Father name          : ";
    gets_s(father_name);
}
void  User    ::GetGender()
{
    fflush(stdin);
	cout<<"Enter New Gender                : ";
	gets_s(gender);
}
void  User    ::GetUid()
{
	fflush(stdin);
	cout<<"Enter New ID                    : ";
	cin>>user_id;
}
void  User    ::GetAdress()
{
    fflush(stdin);
	cout<<"Enter New Adress                : ";
	gets_s(adress);

}	
void  User    ::GetAge()
{
	fflush(stdin);
	cout<<"Enter New Age                   : ";
	cin>>age;
}
void  New_User::GetProfession()
{
	fflush(stdin);
	cout<<"Enter Your Profession           : ";
	gets_s(profession);
}
void  Account ::GetActype()
{
	fflush(stdin);
	cout<<"Enter Your Profession     :";
	gets_s(account_type);
}
void  Account ::report() const
{
	cout<<account_no<<setw(10)<<" "<<user_name<<setw(10)<<" "<<account_type<<setw(10)<<deposit<<endl;
}	
void  Admin   ::create_new_account()
{
	system("cls");
	cout<<"\t\t\t********************************"<<endl;
	cout<<"\t\t\t-----New Account Entry Form-----"<<endl;
	cout<<"\t\t\t********************************"<<endl;
	cout<<"Enter Your Name                            : ";     fflush(stdin);         gets_s(user_name);    
	set_uname(user_name);
	cout<<"Enter Your Farther's Name                  : ";     fflush(stdin);         gets_s(father_name);  
	set_fname(father_name);
	cout<<"Enter Your Account No.                     : ";     fflush(stdin);         cin>>account_no;
	set_acno(account_no);
	cout<<"Enter Your Adress                          : ";     fflush(stdin);         gets_s(adress);
	set_adress(adress);
	cout<<"Enter Your ID                              : ";     fflush(stdin);         cin>>user_id;
	set_uid(user_id);
	cout<<"Enter Type of The account (Current/Saving) : ";     fflush(stdin);         gets_s(account_type);
	set_actype(account_type);
	cout<<"Enter Your Gender                          : ";     fflush(stdin);         gets_s(gender);
	set_gender(gender);
	cout<<"Enter Your Profession                      : ";     fflush(stdin);         gets_s(profession);
	set_profession(profession);
	cout<<"Enter Your Age                             : ";     fflush(stdin);         cin>>age;
	set_age(age);
	cout<<"Enter The Initial amount(>=5000 for Saving and >=10000 for current ) : ";   fflush(stdin);
	cin>>deposit;
	set_depamount(deposit);
	cout<<"\n\n\t\tYour Account Is Created Successfully....";
}
void  Admin   ::write_account()
{
	ofstream outFile;
	outFile.open("bank.txt",ios::binary|ios::app);
	AD.create_new_account();
	outFile.write(reinterpret_cast<char *> (&AD), sizeof(Admin));
	outFile.close();
}
void  Admin   ::delete_account(int n)
{
	ifstream inFile;
	ofstream outFile;
	inFile.open("bank.txt",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	inFile.seekg(0,ios::beg);
	inFile.read((char *)&AD, sizeof(Admin));
	while(!inFile.eof())
	{
		if(AD.get_acno()==n)
		{	
			AD.show_account();
			break;
		}inFile.read((char *)&AD, sizeof(Admin));
	}
	outFile.open("bank_Temp.txt",ios::binary|ios::app);	
	inFile.seekg(0,ios::beg);
	inFile.read((char *)&AD, sizeof(Admin));
	while(!inFile.eof())
	{
		if(AD.get_acno()!=n)
		{	
			outFile.write((char *)&AD, sizeof(Admin));
		}inFile.read((char *)&AD, sizeof(Admin));
	}
    inFile.close();
	outFile.close();
	remove("bank.txt");
	rename("bank_Temp.txt","bank.txt");
	cout<<"\n\n\tRecord Deleted ..";
}
void  Admin   ::show_account() const
{
	cout<<"\nAccount No.                    : "<<account_no;
	cout<<"\nAccount Holder Name            : "<<user_name;
	cout<<"\nAccount Holder's Father's Name : "<<father_name;
	cout<<"\nAccount Holder's ID            : "<<user_id;
	cout<<"\nAccount Holder's Adress        : "<<adress;
	cout<<"\nAccount Holder's Age           : "<<age;
	cout<<"\nType of Account                : "<<account_type;
	cout<<"\nAccount Holder's Profession    : "<<profession;
	cout<<"\nBalance amount                 : "<<deposit;
}
void  Admin   ::modify_by_AccountNo()
{
		system("cls");
		cout<<"\n\n\t\t\t***********************"<<endl;
		cout<<"\t\t\t---MODIFY ACCOUNT NO---"<<endl;
		cout<<"\t\t\t***********************"<<endl;
		File.open("bank.txt",ios::app|ios::in|ios::out);
		File.seekg(0);
		cout<<"\n\n*Enter Account No u want to Modify                 : ";
		cin>>num;
		while(File.read(reinterpret_cast<char*>(&AD),sizeof(Admin)))
		{
			if(num==AD.get_acno())
			{
				found=1;			
				cout<<"\n\n-----PREVIOUS RECORD IS-----"<<endl;
				AD.show_account();
				cout<<endl;
				cout<<"\n\n-----MODIFY YOUR NAME----  \n"<<endl;
				int pos=(-1) *sizeof(AD);
				AD.Account::GetAcno();
				File.seekp(- pos,ios::cur);
				File.write(reinterpret_cast<char*>(&AD),sizeof(Admin));
			    File.close();
			cout<<"\nDo us Want to view record After Modification (Y/N)  : ";
			if(_getch()=='y'||_getch()=='Y')
			{
			cout<<"\n-----YOUR MODIFIED RECORD IS-----"<<endl;
			AD.show_account();
			}
			else
			{cout<<"E V SAI E"<<endl;}
			}
		}
			File.close();
			if(found==0)
			cout<<"Record not found!!!"<<endl;
			File.close();
}
void  Admin   ::modify_by_Name()
{
	    system("cls");
		cout<<"\n\n\t\t\t*****************"<<endl;
		cout<<"\t\t\t---MODIFY NAME---"<<endl;
		cout<<"\t\t\t*****************"<<endl;
	    File.open("bank.txt",ios::in|ios::out);
		File.seekg(0);
		cout<<"\n\n*Enter name of Account Holder u want to Modify          :";
		gets(nm);
		while(File.read(reinterpret_cast<char*>(&AD),sizeof(Admin)))
		{
			if(strcmp(nm,AD.get_uname())==0)
			{
				found=1;			
				cout<<"\n\n-----PREVIOUS RECORD IS-----"<<endl;
				AD.show_account();
				cout<<endl;
				cout<<"\n\n-----MODIFY YOUR NAME----  \n"<<endl;
				int pos=(-1) *sizeof(AD);
				AD.User::GetName();
				File.seekp(-pos,ios::cur);
				File.write(reinterpret_cast<char*>(&AD),sizeof(Admin));
			    File.close();
			cout<<"\nDo us Want to view record After Modification (Y/N)  : ";
			if(_getch()=='y'||_getch()=='Y')
			{
			cout<<"\n-----YOUR MODIFIED RECORD IS-----"<<endl;
			AD.show_account();
			}
			else
			{cout<<"E V SAI E"<<endl;}
			}
		}
			File.close();
			if(found==0)
				cout<<"Record not found!!!"<<endl;
			File.close();
}
void  Admin   ::modify_by_ID()
{
	    system("cls");
		cout<<"\n\n\t\t\t***************"<<endl;
		cout<<"\t\t\t---MODIFY ID---"<<endl;
		cout<<"\t\t\t***************"<<endl;
		File.open("bank.txt",ios::in|ios::out);
		File.seekg(0);
		cout<<"\n\n*Enter ID u want to Modify                 : ";
		cin>>num;
		while(File.read(reinterpret_cast<char*>(&AD),sizeof(Admin)))
		{
			if(nm==AD.get_uid())
			{
				found=1;			
				cout<<"\n-----PREVIOUS RECORD IS-----"<<endl;
				AD.show_account();
				cout<<"\n\n-----MODIFY YOUR ID----  \n"<<endl;
				int pos=(-1) *sizeof(AD);
				AD.Admin::GetUid();
				File.seekp(-pos,ios::cur);
				File.write(reinterpret_cast<char*>(&AD),sizeof(Admin));
			File.close();
			cout<<"\nDo us Want to view record After Modification (Y/N)  : ";
			if(_getch()=='y'||_getch()=='Y')
			{
			cout<<"\n-----YOUR MODIFIED RECORD IS-----"<<endl;
			AD.show_account();
			}
			else
			{cout<<"E V SAI E"<<endl;}
			}
		}
			File.close();
			if(found==0)
			cout<<"Record not found!!!"<<endl;
			File.close();
}
void  Admin   ::modify_by_Profession()
{
	    system("cls");
		cout<<"\n\n\t\t\t***************"<<endl;
		cout<<"\t\t\t---MODIFY PROFESSION---"<<endl;
		cout<<"\t\t\t***************"<<endl;
		File.open("bank.txt",ios::in|ios::out);
		File.seekg(0);
		cout<<"\n\n*Enter Your Profession u want to Modify                 : ";
		gets_s(nm);
		while(File.read(reinterpret_cast<char*>(&AD),sizeof(Admin)))
		{
			if(strcmp(nm,AD.get_profession())==0)
			{
				found=1;			
				cout<<"\n-----PREVIOUS RECORD IS-----"<<endl;
				AD.show_account();
				cout<<"\n\n-----MODIFY YOUR PROFESSION----  \n"<<endl;
				int pos=(-1) *sizeof(AD);
				AD.New_User::GetProfession();
				File.seekp(-pos,ios::cur);
				File.write(reinterpret_cast<char*>(&AD),sizeof(Admin));
			File.close();
			cout<<"\nDo us Want to view record After Modification (Y/N)  : ";
			if(_getch()=='y'||_getch()=='Y')
			{
			cout<<"\n-----YOUR MODIFIED RECORD IS-----"<<endl;
			AD.show_account();
			}
			else
				{cout<<"E V SAI E"<<endl;}
			}
		}
			File.close();
			if(found==0)
			cout<<"Record not found!!!"<<endl;
			File.close();
}
void  Admin   ::modify_by_Adress()
{
	    system("cls");
	    cout<<"\n\n\t\t\t***************"<<endl;
		cout<<"\t\t\t---MODIFY ADRESS---"<<endl;
		cout<<"\t\t\t***************"<<endl;
		File.open("bank.txt",ios::in|ios::out);
		File.seekg(0);
		cout<<"\n\n*Enter Your Adress u want to Modify                 :";
		gets_s(nm);
		while(File.read(reinterpret_cast<char*>(&AD),sizeof(Admin)))
		{
			if(strcmp(nm,AD.get_adress())==0)
			{
				found=1;		
				cout<<"\n-----PREVIOUS RECORD IS-----"<<endl;
				AD.show_account();
				cout<<"\n\n-----MODIFY YOUR ADRESS----  \n"<<endl;
				int pos=(-1) *sizeof(AD);
				AD.New_User::GetAdress();
				File.seekp(-pos,ios::cur);
				File.write(reinterpret_cast<char*>(&AD),sizeof(Admin));
			File.close();
			cout<<"Do us Want to view record After Modification (Y/N)  : ";
			if(_getch()=='y'||_getch()=='Y')
			{
			cout<<"\n-----YOUR MODIFIED RECORD IS-----"<<endl;
			AD.show_account();
			}
			else
			{cout<<"E V SAI E"<<endl;}
			}
		}
			File.close();
			if(found==0)
			cout<<"Record not found!!!"<<endl;
			File.close();
}
void  Admin   ::modify_All()
{
	    system("cls");
		cout<<"\n\n\n\t\t\t***********************"<<endl;
		cout<<"\t\t\t---MODIFY ALL RECORD---"<<endl;
		cout<<"\t\t\t***********************"<<endl;
		File.open("bank.txt",ios::in|ios::out);
		File.seekg(0);
		cout<<"\n*Enter Account No whose all data u want to Modify  : ";
		cin>>num;
		while(File.read(reinterpret_cast<char*>(&AD),sizeof(Admin)))
		{
			if(num==AD.get_acno())
			{
				found=1;
				cout<<"\n-----PREVIOUS RECORD IS-----"<<endl;
				AD.show_account();
				cout<<"\n\n-----MODIFY YOUR WHOLE RECORD----  \n"<<endl;
				int pos=(-1) *sizeof(AD);
				AD.Account ::GetAcno();
				AD.User    ::GetName();
				AD.User    ::GetFname();
				AD.Admin   ::GetUid();
				AD.User    ::GetAdress();
				AD.User    ::GetAge();
				AD.Account ::GetActype();
				AD.New_User::GetProfession();

				File.seekp(-pos,ios::cur);
				File.write(reinterpret_cast<char*>(&AD),sizeof(Admin));
			File.close();
			cout<<"\nDo us Want to view record After Modification (Y/N)  : ";
			if(_getch()=='y'||_getch()=='Y')
			{
			cout<<"\n-----YOUR MODIFIED RECORD IS----- ";
			AD.show_account();
			}
			else
			{cout<<"E V SAI E"<<endl;}
			}
		}
			File.close();
			if(found==0)
			cout<<"Record not found!!!"<<endl;
			File.close();
}
void  Account ::deposit_amount(int x)
{
	deposit+=x;
}
void  User    ::withdraw_amount(int x)
{
		AD.deposit-=x;
}
void  Admin   ::deposit_withdraw(int n, int option)
{
	int amt;
	bool found=false;
	fstream File;
    File.open("bank.txt", ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&AD), sizeof(Admin));
		if(AD.get_acno()==n)
		{
			AD.show_account();
			if(option==1)
			{
				cout<<"\n\n\t*************************"<<endl;
				cout<<"\t---TO DEPOSITE AMOUNT--- "<<endl;
				cout<<"\t*************************"<<endl;
				cout<<"\n\n\n*Enter The amount to be deposited : ";
				cin>>amt;
				AD.deposit_amount(amt);
				AD.show_account();
			}
		    if(option==2)
			{
				cout<<"\n\n\t*************************"<<endl;
				cout<<"\t---TO WITHDRAW AMOUNT--- "<<endl;
				cout<<"\t*************************"<<endl;
				cout<<"\n\n\n*Enter The amount to be withdraw : ";
				cin>>amt;
				int bal=AD.get_depamount()-amt;
				if((bal<500 && AD.get_actype()=="Saving") || (bal<1000 && AD.get_actype()=="Current"))
					cout<<"Insufficience balance!!!";
				else
					AD.withdraw_amount(amt);
				    AD.show_account();
		      }
			int pos=(-1)*static_cast<int>(sizeof(AD));
			File.seekp(pos,ios::cur);
			File.write(reinterpret_cast<char *> (&AD), sizeof(Account));
			cout<<"\n\n\t -----RECORD UPDATED-----";
			found=true;
	       }
         }
    File.close();
	if(found==false)
		cout<<"\n\n _____Record Not Found_____ ";
}
void  Admin   ::view_all_accounts()
{
	system("cls");
	ifstream inFile;
	inFile.open("bank.txt",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	cout<<"\n\n\t\t-----ACCOUNT HOLDER LIST-----\n\n";
	cout<<"===================================================="<<endl;
	cout<<"A/c no.      NAME           Type       Balance"<<endl;
	cout<<"===================================================="<<endl;
	inFile.read(reinterpret_cast<char *> (&AD), sizeof(Admin));
	while(!inFile.eof())
	{
		AD.report();
		inFile.read(reinterpret_cast<char *> (&AD), sizeof(Admin));
	}
	inFile.close();
}
void  Account ::view_balance(int n)
{
	bool flag=false;
	ifstream inFile;
	inFile.open("bank.txt",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	cout<<"\n\t________BALANCE DETAILS________\n\n";
    	while(inFile.read(reinterpret_cast<char *> (&AD), sizeof(Admin)))
	{
		if(AD.get_acno()==n)
		{
			AD.show_account();
			flag=true;
		}
	}
    inFile.close();
	if(flag==false)
		cout<<"\n\nAccount number does not exist";
}
void  Admin   ::search_by_Name()
{
	    system("cls");
		cout<<"\n\n\t\t*******************************"<<endl;
	    cout<<"\t\t  ---Search Accounts by name--- "<<endl;
		cout<<"\t\t*******************************"<<endl;
		File.open("bank.txt",ios::app|ios::in|ios::out);
		File.seekg(0);
		cout<<"\n\n*Enter name of AC.Holder u want to search  : ";
		gets_s(nm);
		File.read(reinterpret_cast<char*>(&AD),sizeof(Admin));
		while(!File.eof())
		{
			if(strcmp(nm,AD.get_uname())==0)
			{
				found=1;
				//cout<<"Name of Account Holder : "<<AD.get_uname()<<endl;
				cout<<"\n\n-----YOUR RECORD IS-----"<<endl;
				AD.show_account();
			}File.read(reinterpret_cast<char*>(&AD),sizeof(Admin));
		}
			if(found==0)
				cout<<"Record not found!!!\n";
			File.close();
}
void  Admin   ::search_by_accountno()
{
	    system("cls");
		cout<<"\n\n\t\t******************************"<<endl;
	    cout<<"\t\t---Search Accounts by Ac.No--- "<<endl;
		cout<<"\t\t******************************"<<endl;
		File.open("bank.txt",ios::app|ios::in|ios::out);
		File.seekg(0);
		cout<<"\n\n*Enter AC. No of the account holder u want to search  : ";
		cin>>num;
		File.read(reinterpret_cast<char*>(&AD),sizeof(Admin));
		while(!File.eof())
		{
			if(num==AD.get_acno())
			{
				found=1;
				cout<<"\n\n-----YOUR RECORD IS-----"<<endl;
				AD.show_account();
			}File.read(reinterpret_cast<char*>(&AD),sizeof(Admin));
		}
				if(found==0)
				cout<<"Record not found!!!\n";
			File.close();
}
void  sleep(unsigned int mseconds)
{
clock_t goal = mseconds + clock();
while (goal > clock());
}
void  loadingbar()  //making a function of loading bar.
{
char r=221;        //these are the ASCII values that we are using

for (int k=1; k>0; k--)
{
system("cls");
sleep(1000);           //delay header file is dos.h
cout<<"\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tWAIT PROJECT IS LOADING"<<endl; 
cout<<"\t\t\t\t\t\t\t\t";
for (int j=0; j<24;j++)
{
sleep(60);
cout<<r;
}
}
}
void UserPassword()
{	U:  //go to lable
	system("cls");
	//logo();
	cout<<"\n\t\tEnter  User Name   :";fflush(stdin);gets(Buffer);
	File.open("Uname.txt",ios::in|ios::out|ios::app);
	File.seekg(0);
	while(File.read((char*)(&AD),sizeof(Admin)))
		{
			if(strcmp(Buffer,Uname)==0)
			{
				found=1;
				cout<<"\n\t\tConfirmed  Authorized User\t:"<<Uname<<endl;
			}
		}
	File.close();
	if(found==0){
		j++;if(j==2)exit(0);		//More than 3 exit
		cout<<"Record not found\n\n\t\tConfirmed  UnAuthorized User\t:"<<Uname;
		sleep(1000);
		File.close();
		goto U;}

	strcat(Buffer,".txt");
	cout<<"\n\t\tEnter Password\t:";fflush(stdin);//gets(pas);
	pas[0]=getch();
while(pas[i]!='\r')
{
i++;
cout<<"*";
pas[i]=getch();
}
pas[i++]='\0';
		
File.open(Buffer,ios::in|ios::out|ios::app); //create file for input
File.getline(Upas, 20); //read a line of text
	if (strcmp(pas,Upas)==0)
		{
		cout <<"\n\n\t\tPassword Accepted";
		sleep(500);
		File.close();File.close();}
	else{
		cout<<"\n\t\tSorry You Are Unauthorized";
		sleep(1000);
		File.close();
		j++;if(j==2)exit(0);	
		goto U;
	}
	File.close();
}
void UserPasswordChange()
{
	fflush(stdin);
	cout<<"\n\t\t***Enter User Name  : "<<endl;fflush(stdin);gets(Uname);
	strcat(Uname,".TXT");
	File.open(Uname); //create file for input
	File.getline(Upas, 20); //read a line of text
	File.close();
	cout<<"\n\t***Enter Your Password : ";
	pas[0]=getch();
while(pas[i]!='\r')
{
i++;
printf("*");
pas[i]=getch();
}
pas[i++]='\0';
	if(strcmp(pas,Upas)==0)
	{
	if( remove(Uname)== -1) // You can change this to a directory of your file.
    cout <<"Error deleting file";
    else
	{cout<<"\n\n\t\tPassword Match";//File Successfully Deleted
	cout<<"\n\t\tEnter New PassWord   :";gets(Upas);
	File.open(Uname,ios::app); //create file for output
	File.write(Upas,20);
	cout<<"\n\t\t\tFor Password Updated Its Going To ShutDown";
	sleep(3000);
	exit(0);
	}
	File.close();}
	else
		cout<<"\n\t\tWrong Password";
}
void AdministratorPassword()
{			l:	//goto label
	cout<<"\n\t\tUser Name     \t:ADMINISTRATOR LOGIN";
	cout<<"\n\t\tEnter Password\t:";//fflush(stdin);gets(pas);
	pas[0]=getch();

while(pas[i]!='\r')
{
i++;
cout<<"*";
pas[i]=getch();
}
pas[i++]='\0';
	File.open("AdminPassword.txt"); //create file for input
	File.getline(Upas,20); //read a line of text
	if (strcmp(pas,Upas)==0)
	{
		cout <<"\n\n\t\tPassword Accepted";
		sleep(500);
		File.close();}
	else{
		cout<<"\n\t\tSorry You Are Unauthorized";
		sleep(1000);
		File.close();
	j++;
	if(j==3)exit(0);
	sleep(1000);
	goto l;
	}
}
void AdministratorPasswordChange()
{
	File.open("AdminPassword.txt"); //create file for input
	File.getline(Upas, MAX); //read a line of text
	File.close();
	cout<<"\n\t\tUser Name\t\t\t:ADMINISTRATOR LOGIN";
	cout<<"\n\t\tEnter Your Previous Password  :";fflush(stdin);//gets(pas);
	pas[0]=getch();
while(pas[i]!='\r')
{
i++;
printf("*");
pas[i]=getch();
}
pas[i++]='\0';
	if(strcmp(Upas,pas)==0)
	{
	if( remove("AdminPassword.TXT")== -1) // You can change this to a directory of your file.
    cout <<"Error deleting file";
    else
	{cout<<"\n\n\t\tPassword Match";//File Successfully Deleted
	cout<<"\n\t\tUser Name\t\t:ADMINISTRATOR LOGIN";
	cout<<"\n\t\tEnter New PassWord   :";gets(Upas);
	File.open("AdminPassword.TXT",ios::app); //create file for output
	File.write(Upas,20);
	cout<<"\n\t\t\tFor Password Updated Its Going To ShutDown";
	sleep(3000);
	exit(0);}
	File.close();}
	else
		cout<<"\n\t\tWrong Password";
}

int main()
{
	int num;
	system("color 7C");
	cout << "\n\n\n\n\n";
	cout << setw(65) << "\t\t\t\t\t\t\t  _______________________________________________   " << endl; sleep(1000);
	cout << setw(65) << "\t\t\t\t\t\t\t||_______________________________________________|| " << endl; sleep(1000);
	cout << setw(65) << "\t\t\t\t\t\t\t||                                               ||" << endl; sleep(1000);
	cout << setw(65) << "\t\t\t\t\t\t\t||           Bank Managemnet System              ||" << endl; sleep(1000);
	cout << setw(65) << "\t\t\t\t\t\t\t||      Submitted To: Mr.Najeeb-ur-Rehman        ||" << endl; sleep(1000);
	cout << setw(65) << "\t\t\t\t\t\t\t||_______________________________________________||" << endl; sleep(1000);
	cout << setw(65) << "\t\t\t\t\t\t\t||                                               ||" << endl; sleep(1000);
	cout << setw(65) << "\t\t\t\t\t\t\t||             Rise Above The Limitzz            ||" << endl; sleep(1000);
	cout << setw(65) << "\t\t\t\t\t\t\t||_______________________________________________||" << endl; sleep(1000);
	cout << setw(65) << "\t\t\t\t\t\t\t||                                               ||" << endl; sleep(1000);
	cout << setw(65) << "\t\t\t\t\t\t\t||                 Group Memberzz                ||" <<endl;  sleep(1000);
	cout << setw(65) << "\t\t\t\t\t\t\t||                   BSCS - (C)                  ||" << endl; sleep(1000);
	cout << setw(65) << "\t\t\t\t\t\t\t|| 16201519-023------------------------DAUD RAUF ||" << endl; sleep(1000);
	cout << setw(65) << "\t\t\t\t\t\t\t|| 16201519-104---------------------HAMZA KHALID ||" << endl; sleep(1000);
	cout << setw(65) << "\t\t\t\t\t\t\t|| 16201519-124-------------------FAISAL MEHMOOD ||" << endl; sleep(1000);
	cout << setw(65) << "\t\t\t\t\t\t\t||_______________________________________________||" << endl; sleep(1000);
	cout << setw(65) << "\t\t\t\t\t\t\t||                                               ||" << endl; sleep(1000);
	cout << setw(65) << "\t\t\t\t\t\t\t||       Department of Computer Science          ||" << endl; sleep(1000);
	cout << setw(65) << "\t\t\t\t\t\t\t||Faculty of Computing and Information Technology||" << endl; sleep(1000);
	cout << setw(65) << "\t\t\t\t\t\t\t||    University of Gujrat, Hafiz Hayat Campus   ||" << endl; sleep(1000);
	cout << setw(65) << "\t\t\t\t\t\t\t||_______________________________________________||" << endl; sleep(1000);
	cout << setw(65) << "\t\t\t\t\t\t\t||_______________________________________________||   " << endl; sleep(1000);

	system("pause");
	//system("cls");	
	loadingbar();
    start: 
	do
	{
		system("cls");
		system("color 9A");
	cout<<"\n\n\t\t**********************************"<<endl;
	cout<<"\t\t----BANKING MANAGEMENT SYSTEM----"<<endl;
    cout<<"\t\t**********************************"<<endl;
cout<<"\n\t\t  1- User's Account"<<endl;
cout<<"\t\t  2- Admins Account"<<endl;
cout<<"\t\t  3- Exit From Program"<<endl;
cout<<"\n\t\t Enter Your Choice or 3 to Exit from Menu:"<<endl;
choice=_getch();
switch(choice)
{
case '1':
	    system("cls");
		system("color 9A");
	cout<<"\n\n\t\t**********************************"<<endl;
	cout<<"\t\t----User's Password Menu----"<<endl;
    cout<<"\t\t**********************************"<<endl;
cout<<"\n\t\t  1- Enter Your Password"<<endl;
cout<<"\t\t  2- Change Password"<<endl;
cout<<"\t\t  3- Back To Main Menu"<<endl;
cout<<"\n\t\t Enter Your Choice or 3 For Back To Main Menu:"<<endl;
choice=_getch();
switch(choice)
{
case '1':
		 system("cls");
		 cout<<"\n\n\t\t\t****************"<<endl;
	     cout<<"\t\t\tUser's Password"<<endl;
	     cout<<"\t\t\t****************"<<endl;
	     UserPasswordChange();
		 break;
case '2':
	     cout<<"\n\n\t\t\t****************"<<endl;
	     cout<<"\t\t\tUser's Change Password"<<endl;
	     cout<<"\t\t\t****************"<<endl;
	     UserPassword();
		 break;
case '3':
	     goto start;
	     break;
}
	     do
	    {
		system("cls");
		system("color 9A");
	cout<<"\n\n\t\t**********************************"<<endl;
	cout<<"\t\t\t---User's Account---"<<endl;
    cout<<"\t\t**********************************"<<endl;
    cout<<"\n\t\t  1- Check Balance"<<endl;
    cout<<"\t\t  2- Withdraw Amount"<<endl;
    cout<<"\t\t  3- Deposit Amount"<<endl;
    cout<<"\t\t  4- Sign Out"<<endl;
    cout<<"\n\t\t Enter Your Choice or 6 to Exit from Menu:"<<endl;
    choice=_getch();
switch(choice)
{
case '1':
	     system("cls");
		 cout<<"\n\n\t\t*************************"<<endl;
	     cout<<"\t\t---Check Your Balance--- "<<endl;
		 cout<<"\t\t*************************"<<endl;
	     cout<<"\n\n\tEnter The account No. : "; cin>>num;
	     AD.view_balance(num);
	     break;
case '2':
	        system("cls");
			cout<<"\n\n\t\t*************************"<<endl;
	        cout<<"\t\t---Withdraw Amount--- "<<endl;
		    cout<<"\t\t************************"<<endl;
	        cout<<"\n\n\tEnter The account No. : "; cin>>num;
			AD.deposit_withdraw(num, 2);
	     break;
case '3':
	        system("cls");
			cout<<"\n\n\t\t*************************"<<endl;
	        cout<<"\t\t---Deposit Amount--- "<<endl;
		    cout<<"\t\t*************************"<<endl;
	        cout<<"\n\n\tEnter The account No. : "; cin>>num;
			AD.deposit_withdraw(num, 1);
	     break;
case '4':
	     cout<<"Signing Out";
	     for(int i=0;i<=10;i++)
	     {sleep(100);cout<<"-";}
	     goto start;
	     break;
	}
cin.ignore();
cin.get();
cout<<"\tEnter y to go to back to main menu =:";
 go=_getche();
}while(choice!=6);//go=='y'||go=='y');
break;
case '2':
	    system("cls");
		system("color 9A");
	cout<<"\n\n\t\t**********************************"<<endl;
	cout<<"\t\t----Admin;s Password Menu----"<<endl;
    cout<<"\t\t**********************************"<<endl;
cout<<"\n\t\t  1- Enter Your Password"<<endl;
cout<<"\t\t  2- Change Password"<<endl;
cout<<"\t\t  3- Back To Main Menu"<<endl;
cout<<"\n\t\t Enter Your Choice or 3 For Back To Main Menu:"<<endl;
choice=_getch();
switch(choice)
{
case '1':
	     system("cls");
	     cout<<"\n\n\t\t\t****************"<<endl;
	     cout<<"\t\t\tAdmin's Password"<<endl;
	     cout<<"\t\t\t****************"<<endl;
	     AdministratorPassword();
		 break;
case '2':
	     AdministratorPasswordChange();
		 break;
case '3':
	     goto start;
	     break;
}
	
	search:
	do
	{
		system("cls");
		system("color 9A");
	cout<<"\n\n\t\t*************************"<<endl;
	cout<<"\t\t---Admin's Account---"<<endl;
    cout<<"\t\t*************************"<<endl;
	cout<<"\n\t\t  1- Create New Account"<<endl;
	cout<<"\t\t  2- View All Accounts List"<<endl;
	cout<<"\t\t  3- Modify Existing Account"<<endl;
	cout<<"\t\t  4- Deleting Account"<<endl;
	cout<<"\t\t  5- Search Account"<<endl;
	cout<<"\t\t  6- Sign Out"<<endl;
	cout<<"\n\t\t Enter Your Choice or 6 to Exit from Menu:"<<endl;
	choice=_getch();
switch(choice)
{
case '1':
	     AD.write_account();
	     break;
case '2':
	     AD.view_all_accounts();
	     break;
case '3':
	     do
	{
		system("cls");
		cout<<"\n\n\t\t*******************************************************"<<endl;
		cout<<"\t\t---Modify Account From Any of  The following options---"<<endl;
		cout<<"\t\t*******************************************************"<<endl;
		cout<<"\n\t\t  1- Modify By Account No."<<endl;
        cout<<"\t\t  2- Modify Your Name"<<endl;
        cout<<"\t\t  3- Modify Your ID"<<endl;
		cout<<"\t\t  4- Modify Your Profession"<<endl;
		cout<<"\t\t  5- Modify Your Adress"<<endl;
		cout<<"\t\t  6- Modify All Details"<<endl;
		cout<<"\t\t  7-Back To Previous Menu"<<endl;
		cout<<"\n\t\t Enter Your Choice or 3 to Exit from Menu:"<<endl;
		choice=_getch();
		switch(choice)
		{
		case '1':
			     AD.modify_by_AccountNo();   
			     break;
		case '2':
                 AD.modify_by_Name();
				 break;
		case '3':
			     AD.modify_by_ID();
			     break;
	    case '4':
			     AD.modify_by_Profession();
				 break;
		case '5':
			     AD.modify_by_Adress();
				 break;
		case '6':
			     AD.modify_All();
				 break;
		case '7':
				 goto search;
				 break;
		default:
			cout<<"Invalid Choice";
		}
cin.ignore();
cin.get();
cout<<"\n\tEnter y to go to back to main menu =:";
go=_getche();
	}while(go=='y'||go=='y');
	     break;
	     
	     
case '4':
	     system("cls");
		 cout<<"\n\n\t\t******************************"<<endl;
	     cout<<"\t\t-----Delete Account----- "<<endl;
		 cout<<"\t\t******************************"<<endl;
	     cout<<"\n\n\tEnter The account No. : "; cin>>num;
	     AD.delete_account(num);
	     break;
case '5':
	do
	{
		system("cls");
		cout<<"\n\n\t\t******************************************************"<<endl;
		cout<<"\t\t---Search Account From Any of  The following options---"<<endl;
		cout<<"\t\t************************************************"<<endl;
		cout<<"\n\t\t  1- Search By Account No."<<endl;
        cout<<"\t\t  2- Search By Name"<<endl;
        cout<<"\t\t  3- Back To Main"<<endl;
		cout<<"\n\t\t Enter Your Choice or 3 to Exit from Menu:"<<endl;
		choice=_getch();
		switch(choice)
		{
		case '1':
			     AD.search_by_accountno();   
			     break;
		case '2':
                 AD.search_by_Name();
				 break;
		case '3':
			     goto search;
			     break;
		default:
			cout<<"Invalid Choice";
		}
cin.ignore();
cin.get();
cout<<"\n\tEnter y to go to back to main menu =:";
go=_getche();
	}while(go=='y'||go=='y');
	     break;
case '6':
	     cout<<"Signing Out";
	     for(int i=0;i<=10;i++)
	     {sleep(100);cout<<".";}
		 goto start;
	     break;
	}
cin.ignore();
cin.get();
cout<<"\n\tEnter y to go to back to main menu =:";
 go=_getche();
}while(choice!=7);//go=='y'||go=='y');
	break;
case '3':
		 exit(0);
		 break;
default:
	    cout<<"invalid"<<endl;
	    break;
}
cin.ignore();
cin.get();
cout<<"\tEnter y to go to back to main menu =:";
 go=_getche();

}while(choice!=6);//go=='y'||go=='y');
_getch();
}
