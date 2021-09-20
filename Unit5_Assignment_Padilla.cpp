/*Briana Padilla, 09/18/2021, COSC 1436-57001, REPLIT.COM, This program displays the networth of the following x employees after deductions from pre-taxes and taxes by using functions */
#include <iostream>
#include <string>
#include<locale> //locale lo toupper()
#include<iomanip>//set precision
using namespace std;

double weeklyPay(double, double,string,int);

int main();

{    
cout << fixed << setprecision(2); 
cout << weeklyPay (47.0, 505.75,"BRIANA",1) << endl;

cout<<weeklyPay (45, 55.25,"MELIVIN",1) << endl;

cout<<weeklyPay (15, 65.25,"SUSAN",2) << endl;

cout<<weeklyPay (41, 14.75,"MIKA",1) << endl;

cout<<weeklyPay (25, 15.0,"ELDRIDGE",2) << endl;

cout<<weeklyPay(55,203.50,"FREEDOM ",1)<<endl;

cout<<weeklyPay(32.5,100.25,"TYSON ",1)<<endl;
            
  return 0;
}


double weeklyPay(double hours, double rate, string name, int empType)

{
double netPay = 0.0;
double grossPay = 0.0;
double taxableWages = 0.0;

double ss = 0.062;
double med = 0.0145; 
double ssWages = 0.0; 
double medWages = 0.0;

double fit = 0.0;
double fitTax = 0.0; 
double dental = 0.0; 
double retirement = 0.0;

double hoursFull = 40.0, 
overtimeRate = 2.0, 
overTimeIfAny = 0.0;
  
locale loc; 
string status = ""; 
string reset = "\x1b[0m";
string color = "\x1b[" + to_string(32) + ";4m"; //green and underlined
string color2 = "\x1b[" + to_string(34) + ";1m"; //blue
cout<<color<<endl; //color 
for(int i = 0; i < name.length(); i++ )
  {
cout<<toupper(name[i],loc); 
  }
cout<<reset<<endl; //a line after the name
status = (empType == 1) ? "Fulltime" : "Parttime"; //set status 
cout<<"Status: "<<status<<endl; 
  

overTimeIfAny = ((hours - hoursFull) > 0.0) ? (hours - hoursFull) : 0.0;  
if(empType == 1) //overtime for fulltime only
  
 
fit = (rate < 15.0) ? 0.12 : 0.15; //rate less than $15? yes 12%fit or else 15%
 
dental = (empType == 1) ? 17.00 : 0.00; //deduduction for dental fulltime employes else
retirement = (empType == 1) ? 77.00 : 0.00; //retirement deduction for fulltime employees -77 else
  

grossPay = (hours <= hoursFull) ? (hours * rate) : 
((hoursFull * rate) + ((overTimeIfAny)*(overtimeRate * rate))); 

cout << "Gross Pay: $" << grossPay<<endl;  
taxableWages = grossPay - (dental + retirement);
fitTax = taxableWages * fit; 
//grosspay c-out, formula fro fit
  
 
ssWages = grossPay * ss; //sswage tax
medWages =  grossPay * med; //medwage tax
 
//print deductions
cout<<color2<<"DEDUCTIONS (preTaxm :"<<reset<<endl; 
cout<<"Dental Deduction: $"<<dental<<endl;
cout<<"Ret. Deduction: $"<<retirement<<endl;
cout<<"Taxable Wages (for FIT):$"<<taxableWages<<endl; 
cout<< color2 <<"DEDUCTIONS:"<<reset<<endl;//color after deductions 
cout<<"FIT Rate: "<< fit<< endl; 
cout<<"FIT Tax Amount: $"<<fitTax<<endl; 
  
cout<<"Social security = $"<<ssWages<<endl;
cout<<" Medicare deduction = $"<<medWages<<endl;

netPay = grossPay - (dental + retirement + fitTax + ssWages + medWages); 

cout<<"NET PAY for " << name << " "<< color << "$"; 

  return netPay; 
}