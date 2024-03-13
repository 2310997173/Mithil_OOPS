#include<iostream>
#include<string.h>
#include<iomanip>
#include<stdlib.h>
#include<windows.h>
#include<cstdio>

using namespace std;
void setConsoleColor(WORD c)

{

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);

}

class Employee
{
    char *name;
    char *designation;
    int salary;
    char *phone;
    char *city;

    public:
        Employee(){}
        Employee(char *an, char *ad, int as, char *ap,char *ac)
        { 
            name = new char( strlen(an)+1 );
            strcpy(name,an);
            designation = new char( strlen(ad)+1 );
            strcpy(designation,ad);
            phone = new char( strlen(ap)+1 );
            strcpy(phone,ap);
            salary = as;
            city = new char( strlen(ac)+1 );
            strcpy(city,ac);
        }

        void getData(char *an, char *ad, int as, char *ap, char *ac)
        {
            name = new char( strlen(an)+1 );
            strcpy(name,an);
            designation = new char( strlen(ad)+1 );
            strcpy(designation,ad);
            phone = new char( strlen(ap)+1 );
            strcpy(phone,ap);
            salary = as;
            city = new char( strlen(ac)+1 );
            strcpy(city,ac);
        }


        void show()
        {
            setConsoleColor(FOREGROUND_BLUE);
            cout<<setw(15)<<left<<name<<"  ";
            cout<<setw(13)<<left<<designation<<"  ";
            cout<<setw(8)<<right<<salary<<" ";
            cout<<setw(10)<<right<<phone<<" ";
            cout<<setw(20)<<left<<city<<endl;

        }

        static void drawHeader()
        {
            setConsoleColor(FOREGROUND_RED);
            cout<<setw(15)<<left<<"Name"<<"  ";
            cout<<setw(13)<<left<<"Designation"<<"  ";
            cout<<setw(8)<<left<<"Salary"<<" ";
            cout<<setw(10)<<left<<"Phone"<<" ";
            cout<<setw(20)<<left<<"City"<<endl;


        }

        static void drawLine(int frequency=74, char symbol='-')
        {
            int i;
            setConsoleColor(FOREGROUND_GREEN);
            for(i = 0; i<=frequency; i++)
                cout<<symbol;
            cout<<endl;
        }

        char * retDesignation(){
         return designation;
        }

        char * retCity(){
        return city;
        }

        char * retName(){
        return name;
        }

        int retSalary(){
        return salary;
        }


};

int main()
{
  Employee ob1("Vikas", "Professor", 120000,"9416378016", "Ambala" );
  int n,i;
  char empname[20], empdesig[20], empphone[20],empcity[20];
  int empsalary;

  cout<<"Enter Number of Employees: ";
  cin>>n;
  Employee ob[10];
  cout<<" Enter Details of Employees "<<endl;
  for(i=0; i<n;i++)
  {
      cout<<"\nEmployee "<<i+1<<endl;
      cout<<"Name:  ";
      fflush(stdin);
      cin.getline(empname,15);
      cout<<"Designation:  ";
      fflush(stdin);
      cin.getline(empdesig,20);
      cout<<"Salary: ";
      cin>>empsalary;
      fflush(stdin);
      cout<<"Phone: ";
      cin>>empphone;
      cout<<"City: ";
      cin>>empcity;

      ob[i].getData(empname,empdesig,empsalary,empphone,empcity);

  }
  Employee::drawHeader();
  Employee::drawLine(76, '-');
  for(i=0; i<n;i++)
    ob[i].show();


 cout<<" \n Display all Managers \n";

 Employee::drawHeader();
 Employee::drawLine();
 for(i=0; i<n;i++)
    {
      if (strcmp(ob[i].retDesignation(),"Manager")== 0)
                                            ob[i].show();
    }

 cout<<" \n Display all Chandigarhians \n";

 Employee::drawHeader();
 Employee::drawLine();
 for(i=0; i<n;i++)
    {
      if (strcmp(ob[i].retCity(),"Chandigarh")== 0)
                                            ob[i].show();
    }


cout<<" \n Display all Employees whose name start with n and salary more than 12000 \n";

 Employee::drawHeader();
 Employee::drawLine();
 for(i=0; i<n;i++)
    {
      if (*(ob[i].retName())== 'N'  && ob[i].retSalary()>=12000)
                                            ob[i].show();
    }

}
