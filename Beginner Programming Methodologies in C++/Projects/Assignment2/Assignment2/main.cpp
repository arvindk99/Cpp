//Arvind Kumar
//Lab 2: Small Business Taxes
//Purpose: Calculate the total revenue with proper formatting

#include <iostream>
#include <string>
#include <iomanip>
#define STATETAX 6.75
using namespace std;

int main()
{
    string date;
    const float countyTax = 2.50;
    
    /* Here we initialize all the variables that will be utilized in this
     Lab. Each with self-documenting names that easily applies to the item they
     represent*/
    float totalCollected, sales, totalCountyTax, totalStateTax, totalSalesTax;
       
    cout << setprecision(2) << fixed;
    cout << "Month: ";
    getline(cin, date);
    cout << left << setw(21) <<"Total Collected:";
    cin >> totalCollected;
    
    /*The last two equations here represent the calculations of
     taxes in dollars which are found by first converting the percentage
     values to decimals then multiplying by the amount sold, or sales.*/
    sales=totalCollected/(1+(countyTax/100)+(STATETAX/100));
    totalCountyTax = (countyTax/100)*sales;
    totalStateTax = (STATETAX/100)*sales;
    
    //The sales tax is calculated by the sum of both the county and state taxes.
    totalSalesTax = totalCountyTax + totalStateTax;
    
    
    /*With the help of iomanip, setw, setprecision, left, and right, I was able
     to lineup the decimals perfectly and set the number of decimals per value to
     a maximum of 2.*/
    cout << left << setw(10) << "Sales:" << right << setw(19) << sales << endl;
    cout << left << setw(10) << "County Sales Tax:" << right << setw(12) << totalCountyTax << endl;
    cout << left << setw(10) << "State Sales Tax:" << right << setw(13) << totalStateTax << endl;
    cout << left << setw(10) << "Total Sales Tax:" << right << setw(13) << totalSalesTax << endl;
    
    
    cout << "\n\nCreated by: Arvind Kumar" << endl;
    return 0;
}


/*
 Month: September 2019
 Total Collected:     87321.58
 Sales:               79928.22
 County Sales Tax:     1998.21
 State Sales Tax:      5395.15
 Total Sales Tax:      7393.36


 Created by: Arvind Kumar
 Program ended with exit code: 0
 */
