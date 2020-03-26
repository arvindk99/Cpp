//NAME: Arvind Kumar
//ID: 20372024
//DATE: 11/19/2019
//NAME: arvindskumar01@gmail.com
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

void input(string&, char&, double&, int&, double&, int&);
void calculations(double, int, double&, double&, double&, double&, char, int);
void output(string, double, double, double, double);
void calcTaxes(double ,double ,char ,int ,double& ,double&);


int main() {
    string ename;
    char mStatus;
    double hWage, pYEarnings, fica_tax,curr_earn,income_tax;
    int hWorked, whAllowance;
    
    input(ename, mStatus, hWage, whAllowance, pYEarnings, hWorked);
    
    calculations(hWage, hWorked, pYEarnings, curr_earn, fica_tax, income_tax, mStatus, whAllowance);
    
    output(ename, curr_earn, pYEarnings, fica_tax, income_tax);
}

void input(string &ename, char &mStatus, double& hWage, int& whAllowance, double& pYEarnings, int& hWorked){
    /*
     PRE - ename = reference to employee name
           mStatus = reference to marriage status
           hWage = reference to hourly wage
           whAllowance = reference to withheld allowances
           pYEarnings = reference to previous year's earnings
           hWorked = reference to hours worked
     
     POST - Prompts to enter in values
     
     PURPOSE - Collect all the inputs and assign
               them to the reference variables
     */
    
    cout << "Enter your employee name: ";
    getline(cin,ename);
    
    cout << "Enter your hourly wage: ";
    cin >> hWage;
    
    cout << "Enter your hours worked: ";
    cin >> hWorked;
    
    cout << "Enter your withholding allowances: ";
    cin >> whAllowance;
    
    cout << "Enter your maritalStatus as either 'M' or 'S': ";
    cin >> mStatus;
    mStatus = toupper(mStatus);
    
    cout << "Enter your previous year-to-date earnings: ";
    cin >> pYEarnings;
}

void calculations(double wage, int hours, double &previous_years, double &currentEarnings, double &fica_tax, double &income_tax, char marriage, int whAllowance)
{
    /*
     PRE - wage = hourly wage rate
           hours = hours worked
           previous_years = reference to the previous year's income
           currentEarnings = reference to current earnings
           fica_tax = reference tot he FICA tax
           income_tax = reference to the income tax
           marriage = marriage status
           whAllowance = number of withheld Allowances
     POST - returns the FICA tax value and the income tax values to their
           referenced variables.
     PURPOSE - Nothing
     */
    double wageandahalf = 1.5*wage;
    int extrahours = hours - 40;
    if (hours >40){
        currentEarnings = wage*40;
        currentEarnings = currentEarnings + (extrahours*wageandahalf);
    }
    else{
        currentEarnings = wage*hours;
    }
    
    previous_years += currentEarnings;
    
    calcTaxes(previous_years, currentEarnings, marriage, whAllowance, fica_tax, income_tax);

}

void calcTaxes(double previous_years, double currentEarnings, char marriage, int withholding, double& fica_tax, double& income_tax)
{
    /*
     PRE - previous_years = previous year's income
           currentEarnings = current earnings
           marriage = marital status
           withholding = number of withheld Allowances
           fica_tax = reference to the FICA tax
           income_tax = reference to the income tax
     POST - Nothing, since void function
     PURPOSE - carry out the calculations of the FICA and the Income taxes
     */
    double value;
    
    if(previous_years < 132900){
        fica_tax = currentEarnings*(.062);
    }
    else
    {
        fica_tax = 0.00;
    }
    
    value = currentEarnings - (withholding*80.60);
    if(marriage == 'S')
    {
        if(value < 73){
            income_tax = 0;
        }
        else if(value>73 && value <= 260)
        {
            value -= 73;
            income_tax = 0.10*value;
        }
        else if(value>260 && value <= 832)
        {
            value -= 260;
            income_tax = 18.70 + (.12*value);
        }
        else if(value> 832 && value <= 1692)
        {
            value -= 832;
            income_tax = 87.34 + (.22*value);
        }
        else if(value > 1692 && value <= 3164)
        {
            value -= 1692;
            income_tax = 276.54 + (.24*value);
        }
        else if(value > 3164 && value <= 3998)
        {
            value -= 3164;
            income_tax = 629.82 + (.32*value);
        }
        else if(value > 3998 && value <= 9887)
        {
            value -= 3998;
            income_tax = 896.70 + (.35*value);
        }
        else {
            value -= 9887;
            income_tax = 2957.85 + (.37*value);
        }
    }
    else {
        if(value < 227){
            income_tax = 0;
        }
        else if(value>227 && value <= 600)
        {
            value -= 227;
            income_tax = 0.10*value;
        }
        else if(value>600 && value <= 1745)
        {
            value -= 600;
            income_tax = 37.30 + (.12*value);
        }
        else if(value> 1745 && value <= 3465)
        {
            value -= 1745;
            income_tax = 174.70 + (.22*value);
        }
        else if(value > 3465 && value <= 6409)
        {
            value -= 3465;
            income_tax = 553.10 + (.24*value);
        }
        else if(value > 6409 && value <= 8077)
        {
            value -= 6409;
            income_tax = 1259.66 + (.32*value);
        }
        else if(value > 8077 && value <= 12003)
        {
            value -= 8077;
            income_tax = 1793.42 + (.35*value);
        }
        else {
            value -= 12003;
            income_tax = 3167.52 + (.37*value);
        }
    }
    
}

void output(string ename, double curr_earn, double pYEarnings, double fica_tax, double income_tax)
{
    /*
     PRE - ename = employee name
           curr_earn = current Earnings
           pYEarnings = previous year's income
           fica_tax = FICA tax
           income_tax = income tax
     POST - prints all our results
     PURPOSE - Nothing
     */
    double check;
    check = curr_earn - fica_tax - income_tax;
    
    cout << setprecision(2) << fixed;
    cout << "\n\n" << ename << endl;
    cout << left << setw(22) << "Current Earnings" << right << setw(10) << curr_earn << endl;
    cout << left << setw(22) << "Year-to-date" << right << setw(10) << pYEarnings << endl;
    cout << left << setw(22) << "FICA tax" << right << setw(10) << fica_tax << endl;
    cout << left << setw(22) << "Income Tax Withheld" << setw(10) << right << income_tax << endl;
    cout << left << setw(22) << "Amount of Income" << setw(10) << right << check << endl;
    cout << "\n\nProgrammed by: " << "Arvind Kumar" << endl;

}


/*
 *********************************************************************
 SAMPLE TEST 1
 *********************************************************************
 Enter your employee name: Al Clark
 Enter your hourly wage: 48.50
 Enter your hours worked: 38
 Enter your withholding allowances: 2
 Enter your maritalStatus as either 'M' or 'S': M
 Enter your previous year-to-date earnings: 88600


 Al Clark
 Current Earnings         1843.00
 Year-to-date            90443.00
 FICA tax                  114.27
 Income Tax Withheld       167.12
 Amount of Income         1561.62


 Programmed by: Arvind Kumar
 Program ended with exit code: 0
 */

/*
 *********************************************************************
 SAMPLE TEST 2
 *********************************************************************
 Enter your employee name: Karen Chen
 Enter your hourly wage: 44.00
 Enter your hours worked: 35
 Enter your withholding allowances: 3
 Enter your maritalStatus as either 'M' or 'S': M
 Enter your previous year-to-date earnings: 68200.00


 Karen Chen
 Current Earnings         1540.00
 Year-to-date            69740.00
 FICA tax                   95.48
 Income Tax Withheld       121.08
 Amount of Income         1323.44


 Programmed by: Arvind Kumar
 Program ended with exit code: 0
 */

/*
 *********************************************************************
 SAMPLE TEST 3
 *********************************************************************
 
 Enter your employee name: Nathan Chan
 Enter your hourly wage: 25.50
 Enter your hours worked: 50
 Enter your withholding allowances: 1
 Enter your maritalStatus as either 'M' or 'S': S
 Enter your previous year-to-date earnings: 36295.50


 Nathan Chan
 Current Earnings         1402.50
 Year-to-date            37698.00
 FICA tax                   86.95
 Income Tax Withheld       195.12
 Amount of Income         1120.43


 Programmed by: Arvind Kumar
 Program ended with exit code: 0
*/
