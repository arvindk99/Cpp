//NAME: Arvind Kumar
//EMAIL: arvindskumar01@gmail.com
//LAB #: 4 IRWD
#include <iostream>
#include <iomanip>
#define GALLONSPERPERSON 50
using namespace std;
double totalBudget1(double residents, char typeResident);
double totalBudget2(double semitotal, char typeResidents);
double totalcost(double totalBudget, double actualCCFUsed);
void output(double totalBudget, double total);



int main(int argc, const char * argv[]) {
    double residents;
    char typeResidents;
    double actualCCFUsed;
    double totalBudget;
    double cost;
    
    cout << setprecision(2)<< fixed;
    cout << "Enter number of people in household: ";
    cin >> residents;
    
    cout <<"Enter type of residence ('S' for single family, 'C' for condo, or 'A' for apartment: ";
    cin >> typeResidents;
    typeResidents = toupper(typeResidents);
    
    cout << "Enter Actual CCF used: ";
    cin >> actualCCFUsed;
    
    /*We have multiple layers of if statements so that it first checks to make sure that we have a
     valid residents input (residents>0). Then it goes through the if statement and checks to see if
     the residents type is a valid input (must be an 's', 'a', or 'c').*/
    if (residents >0){
        if (typeResidents == 'S' || typeResidents == 'A' || typeResidents == 'C'){
            /*Here we call the other three functions to carry out the calculations and the
             output which will then finsih the problem.*/
            totalBudget = totalBudget1(residents,typeResidents);
            cost = totalcost(totalBudget, actualCCFUsed);
            output(totalBudget, cost);
        }
        else{
            cout << "\nPlease restart the program and enter a valid residence type."<< endl;
        }
    }
    else{
        cout << "\nPlease restart the program and enter a valid number of resident." << endl;
    }
    
    return 0;
}


double totalBudget1(double residents, char typeResidents){
    /*
    PRE:     residents - the number of residents in the house
             typeResidents - the type of residency, apartment, condo, or
                             single family homes
    POST:    returns the total budget of gallons of water to the main function
    Purpose: TotalBudget1 collects the residents and the typeResidents input from the user,
             and does the first part of the calculation which is to calculate until the
             outdoor landscape budget is added in. */
    
    double semitotal;
    double total;
    
    semitotal = GALLONSPERPERSON*residents*30/748;

    total = totalBudget2(semitotal, typeResidents);
    return total;
    
}
 
 double totalBudget2(double semitotal, char typeResidents){
     /*
      PRE:     semitotal- the total that does not count for the landscape
                          budget yet
               typeResidents - the type of residency, apartment, condo, or
                               single family homes
      
      POST:    Returns the total calculated value to totalBudget1 for it to
               return the total value back to the main function.
      
      Purpose: The point of totalBudget2 is to finish the calculations for the
               totalBudget by adding the landscape budget. Depending on the type of
               residence that the user lives in,the if, else if statements will
               determine which of the landscape budgets to add and then finally
               return the total.*/
     double total;
     
     double singleFamily = 2.30;
     double condo = 0.75;
     double apartment = 0.00;
     
     if (typeResidents == 'S'){
         total = semitotal + singleFamily;
     }
     else if(typeResidents == 'C'){
         total = semitotal + condo;
     }
     else{
         total = semitotal+apartment;
     }
    
     return total;
 }

double totalcost(double totalBudget, double actualCCFUsed){
    /*
     PRE:     totalBudget -  the total budget of water that has been calculated
              actualCCFUsed - the actual amount of water being used
     
     POST:    returns the total cost
     
     Purpose: The point of this function is to calculate the final cost of the water bill
              taking in account the total budget we already calculated and the actualCCFUsed input
              that we first got from the user.*/
    double cost;
    double difference;
    
    difference = actualCCFUsed - totalBudget;
    

    if (difference < 0){
        cost = 1.65*(totalBudget);
    }
    else{
        cost = 1.65*(totalBudget) + 4.83 * (difference);
    }
    
    return cost;
    
    
}

void output(double budget, double total){
    /*
     PRE: budget- the total budget
          total - the total cost
     POST: Prints the totalBudget and the cost
     PURPOSE: Prints all the calculated information
     */
    cout << "Budget for people and landscape: " << budget << endl;
    cout << "Total Cost: $" << total << endl;
    cout << "\n\nCreated by Arvind Kumar, ID#: 18274348" << endl;
}


/*
 *********************************************************************
 SAMPLE TEST 1
 *********************************************************************
 Enter number of people in household: 4
 Enter type of residence ('S' for single family, 'C' for condo, or 'A' for apartment: s
 Enter Actual CCF used: 12.0
 Budget for people and landscape: 10.32
 Total Cost: $25.14


 Created by Arvind Kumar, ID#: 18274348
 Program ended with exit code: 0
 *********************************************************************
 SAMPLE TEST 2
 *********************************************************************
 Enter number of people in household: 3
 Enter type of residence ('S' for single family, 'C' for condo, or 'A' for apartment: s
 Enter Actual CCF used: 12.0
 Budget for people and landscape: 8.32
 Total Cost: $31.51


 Created by Arvind Kumar, ID#: 18274348
 Program ended with exit code: 0
 
 ***********************************************************************
 SAMPLE TEST 3: NEGATIVE RESIDENTS
 ***********************************************************************
 Enter number of people in household: -8
 Enter type of residence ('S' for single family, 'C' for condo, or 'A' for apartment: s
 Enter Actual CCF used: 5
 Please restart the program and enter a valid number of resident.
 Program ended with exit code: 0
 
 ***********************************************************************
 SAMPLE TEST 4: INVALID RESIDENTS TYPE
 ***********************************************************************
 Enter number of people in household: 5
 Enter type of residence ('S' for single family, 'C' for condo, or 'A' for apartment: b
 Enter Actual CCF used: 78
 Please restart the program and enter a valid residence type.
 Program ended with exit code: 0
 */
