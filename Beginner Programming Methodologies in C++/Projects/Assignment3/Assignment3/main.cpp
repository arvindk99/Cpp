//NAME: Arvind Kumar
//EMAIL: arvindskumar01@gmail.com
//LAB#: 3
//LAB TITLE: ETS Costs

#include <iostream>
#include <string>
#include <iomanip>
#define TAXRATE .0925
using namespace std;

int main()
{
    /*Here we initialize three different sets of variables. A set of constant
     floats which have the prices for each item stored, the other group is
     to ask the user the quantity bought of each item. The final grouping
     is the floats representing the values we will have to calculate.*/
    const float externalMonitor = 182.15, dellKeyboard = 18.30, dellMouse = 16.45, windowsOS = 2020.00, networkPrinter = 1100.00;
    int numMonitor, numKeyboard, numMouse, numOS, numPrinter;
    float monitorPrice, keyboardPrice, mousePrice, OSPrice, printerPrice, subtotal, tax, total;
   
    
    
    /*By utilizing setprecision() we are able to set the maximum number of
     decimal places that we go to*/
    cout << setprecision(2) << fixed;
    cout<<"How many External Monitors were ordered? ";
    cin >> numMonitor;
    cout<<"How many Dell Keyboard players were ordered? ";
    cin >> numKeyboard;
    cout << "How many Dell Mouse units were ordered? ";
    cin>> numMouse;
    cout << "How many Windows OS were ordered? ";
    cin >> numOS;
    cout << "How many Network Printers were ordered? ";
    cin >> numPrinter;
    
    
    
    /*Here we do all the calculations for each item in the invoice. We
     go about this business by multplying the user input for the quantity
     of each item to the fixed constant prices.*/
    monitorPrice = numMonitor * externalMonitor;
    keyboardPrice = numKeyboard * dellKeyboard;
    mousePrice = numMouse * dellMouse;
    OSPrice = numOS * windowsOS;
    printerPrice = numPrinter * networkPrinter;
    
    
    /*Here we calculate values such as subtotal, tax, and total. Subtotal
     is the easiest to calculate because you would simply add all the prices
     after from above. The tax was found by multiplying the defined taxrate
     at the top with the subtotal, and the total was found by just adding
     tax and subtotal together.*/
    subtotal = monitorPrice+keyboardPrice+mousePrice+OSPrice+printerPrice;
    tax = subtotal*TAXRATE;
    total = tax+subtotal;
    
    
    /*Here we have the print statements for all the information that we want
     to know. With the help of the <iomanip> library, we were able to use left,
     right, and setw() to fit the appropriate spacing for each item.*/
    cout << "\n\n"<<left << setw(5) << "QTY" << left << setw(21) << "Description" << left << setw(18) << "Unit Price" << "Total Price" << endl;
    cout << right << setw(2) << numMonitor << right << setw(19) << "External Monitor" << right << setw(14) << externalMonitor << right << setw(19) << monitorPrice << endl;
    cout << right << setw(2) << numKeyboard << right << setw(16) << "Dell Keyboard" << right << setw(17) << dellKeyboard << right << setw(19) << keyboardPrice << endl;
    cout << right << setw(2) << numMouse << right << setw(13) << "Dell Mouse" << right << setw(20) << dellMouse << right << setw(19) << mousePrice << endl;
    cout << right << setw(2) << numOS << right << setw(13) << "Windows OS" << right << setw(20) << windowsOS << right << setw(19) << OSPrice << endl;
    cout << right << setw(2) << numPrinter << right << setw(18) << "Network Printer" << setw(15) << networkPrinter << right << setw(19) << printerPrice << endl;
    
    cout << "\n" <<right << setw(26) << "Subtotal" << right << setw(18) << subtotal << endl;
    cout << right << setw(26) << "Tax" << right << setw(18) << tax << endl;
    cout << right << setw(26) << "Total" << right << setw(18) << total << endl;
    
    cout << "\n\nCreated by: Arvind Kumar" << endl;
    return 0;
    
}



/*
 How many External Monitors were ordered? 3
 How many Dell Keyboard players were ordered? 12
 How many Dell Mouse units were ordered? 5
 How many Windows OS were ordered? 6
 How many Network Printers were ordered? 7


 QTY  Description          Unit Price        Total Price
  3   External Monitor        182.15             546.45
 12   Dell Keyboard            18.30             219.60
  5   Dell Mouse               16.45              82.25
  6   Windows OS             2020.00           12120.00
  7   Network Printer        1100.00            7700.00

                   Subtotal          20668.30
                        Tax           1911.82
                      Total          22580.12


 Created by: Arvind Kumar
 Program ended with exit code: 0
 */


/*
How many External Monitors were ordered? 1
How many Dell Keyboard players were ordered? 1
How many Dell Mouse units were ordered? 10
How many Windows OS were ordered? 10
How many Network Printers were ordered? 5


QTY  Description          Unit Price        Total Price
 1   External Monitor        182.15             182.15
 1   Dell Keyboard            18.30              18.30
10   Dell Mouse               16.45             164.50
10   Windows OS             2020.00           20200.00
 5   Network Printer        1100.00            5500.00

                  Subtotal          26064.95
                       Tax           2411.01
                     Total          28475.96


Created by: Arvind Kumar
Program ended with exit code: 0
 */
