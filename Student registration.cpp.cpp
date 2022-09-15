//header files
#include <iostream>
#include <fstream>
#include<string>
using namespace std;

/*
this function add student record to text file
Argument1: filename
Argument2: Pointer to studentCount
*/
void addStudent(string filename, int *studentCount, int *inCityFees, int *outCityFees){
cout<<endl<<"Press any key to add Students details";
getchar();
ofstream file(filename.c_str(), ios::app);
char name[50];
cout<<endl<<"\n Enter Name of Student : ";
gets(name);

file<<endl<<name;

int state=-1;
cout<<endl<<"\n Press 1 for In-City or 2 for Out-Of-City : ";
cin>>state;

if(state==1)
file<<" | In-City";
else if(state==2)
file<<" | Out-Of-City";
else
file<<" | NA";

int tutionFees;
cout<<endl<<"Enter Tution Fees : ";
cin>>tutionFees;

char choice;
cout<<endl<<"Do you want to enroll for any Technology ? y/n : ";
cin>>choice;

int technology = 0;

if(choice=='Y' || choice=='y'){
char plan;
cout<<endl<<" # Select Optional Technology #";
cout<<endl<<"A -> AI/ML";//Charges--> Rs 3,500
cout<<endl<<"B -> AWS";//Charges--> Rs 4,500
cout<<endl<<"C -> IOT";//Charges--> Rs 3,200
cout<<endl<<"D -> Cyber-Security";//Charges--> Rs 3,000

cout<<endl<<"Select any alphabet ( A, B, C, D ) : ";
cin>>plan;

switch(plan){     	
case 'A':
case 'a': technology = 3500;   break;
case 'B':
case 'b': technology = 4500; break;
case 'C':
case 'c': technology = 3200; break;
case 'D':
case 'd' : technology = 3000; break;
default: cout<<endl<<"Invalid Choice..";
}

if(technology!=0)
file<<" | Tech. Enrolled : "<<plan;
else
file<<" | Tech. Enrolled : None"<<plan;

file<<" | "<<tutionFees;

if(state==1){
*inCityFees = *inCityFees + tutionFees + technology;
}
else if(state==2){
*outCityFees = *outCityFees + tutionFees + technology;
}

}
*studentCount = *studentCount + 1;
file.close();
}

/*
function generate the final report by adding total fees details
Argument1: filename
Argument2: Pointer to studnetCount
*/
void generateReport(const string filename, const int *studentCount, const int *inCityFees, const int *outCityFees){
if(*studentCount==0){
cout<<endl<<"Error: There should be atleast one record to generate report.";
}
else{
ofstream file(filename.c_str(), ios::app);
file<<endl<<"Total Tuition fees Paid for all In-City Students : "<<*inCityFees;
file<<endl<<"Total Tuition fees Paid for all Out-of-City Students : "<<*outCityFees;
file.close();
cout<<endl<<"Success: "<<filename<<" generated ";		
}
	
}


//program runs from this function
int main(int argc, char** argv) {
	
int choice = 0;
string fileName = "tuition_report.txt";
int studentCount =0;
int inCityFees = 0;
int outCityFees =0;

//empty file if it already exist
ofstream file(fileName.c_str(), ios::out);
file.close();

while(choice!=-1){
cout<<endl<<"## (College Student Tuition) ##"<<endl;
cout<<endl<<"1 Add Student Details";
cout<<endl<<"2 Generate Report";
cout<<endl<<"-1 Exit";
cout<<"\n\n Enter your choice : ";
cin>>choice;

switch(choice){
case 1: addStudent(fileName, &studentCount, &inCityFees, &outCityFees);
	break;
case 2: generateReport(fileName, &studentCount, &inCityFees, &outCityFees);
	break;
case -1: cout<<endl<<"thank you for using software!!";
	break;
default: cout<<endl<<"Invalid Choice.."; getchar();
	
}
	
}

return 0;
}

