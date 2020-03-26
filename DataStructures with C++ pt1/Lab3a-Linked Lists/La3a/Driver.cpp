/*
PARTNER 1: Arvind Kumar ID: 20372024
PARTNER 2: Kevin Lam ID: 20290826
*/

#include <iostream>
#include <cstdlib>
#include <string>
#include "LinkedLists.h"
#include "Rupee.h"

using namespace std;

int main()
{
	LinkedList<int> intList;
	LinkedList<string> strList;
	LinkedList<Rupee> rupeeList;


	/*********************LIST CONTAINING INTEGERS*************************/
	cout << "*********************LIST CONTAINING INTEGERS*************************" << endl;

	//Setting sort type to ascending because the int types are sorted ascending
	intList.setSortType("ascending");


	//ADDING ELEMENTS TO INTEGER LIST
	intList.Add(1);
	/*intList.Add(5);
	intList.Add(8);
	intList.Add(11);
	intList.Add(15);
	intList.Add(18);
	intList.Add(20);
	intList.Add(22);
	intList.Add(25);
	intList.Add(30);*/


	//Displaying list so far
	cout << endl << "List is sorted in " << intList.getSortType() << " order." << endl << endl;
	cout << "INTEGER List after adding 10 digits" << endl;
	intList.printItems();
	cout << endl;

	//Deleting element with data value of 18 and 25
	intList.deleteFromBack();
	//intList.deleteData(11);
	//intList.deleteFromFront();

	//Display list
	cout << "INTEGER List after deleting 2 elements" << endl;
	intList.printItems();
	cout << endl;
	cout << "SIZE OF LIST = " << intList.getCount() << endl;

	//emptying list
	intList.empty();
	cout << "INTEGER List has being emptied" << endl;
	cout << "SIZE OF LIST = " << intList.getCount() << endl;

	cout << endl;
	cout << endl;

	/*********************LIST CONTAINING STRINGS*************************/
	cout << "*********************LIST CONTAINING STRINGS*************************" << endl;

	//Setting sort type to descending because the string types are sorted descending
	strList.setSortType("descending");


	//ADDING ELEMENTS TO STRING LIST
	strList.Add("zeta");
	strList.Add("yelling");
	strList.Add("washing");
	strList.Add("Venus");
	strList.Add("rolling");
	strList.Add("quarter");
	strList.Add("mother");
	strList.Add("father");
	strList.Add("beta");
	strList.Add("alpha");



	//Displaying list so far
	cout << endl << "List is sorted in " << strList.getSortType() << " order." << endl << endl;
	cout << "STRING List after adding 10 digits" << endl;
	strList.printItems();
	cout << endl;


	//Deleting element with data value of yelling and Venus
	strList.deleteData("yelling");
	strList.deleteData("Venus");

	//Display list
	cout << "STRING List after deleting 2 elements" << endl;
	strList.printItems();
	cout << endl;

	cout << "SIZE OF LIST = " << strList.getCount() << endl;


	//emptying list
	strList.empty();
	cout << "STRING List has being emptied" << endl;
	cout << "SIZE OF LIST = " << strList.getCount() << endl;

	cout << endl;
	cout << endl;

	/************************* Rupee *************************/
	cout << "************************* Rupee *************************" << endl;
	
	//Setting sort type to unsorted because the Rupee types are unsorted
	
	rupeeList.setSortType("unsorted");

	//Initializing Rupee objects
	Rupee rupee1(200, 85);
	Rupee rupee2(85, 98);
	Rupee rupee3(65, 20);
	Rupee rupee4(1000, 30);
	Rupee rupee5(500, 45);
	Rupee rupee6(53, 65);
	Rupee rupee7(98, 85);
	Rupee rupee8(2, 1);
	Rupee rupee9(7, 65);
	Rupee rupee10(21, 19);


	//ADDING ELEMENTS TO Rupee LIST
	rupeeList.Add(rupee1);
	rupeeList.Add(rupee2);
	rupeeList.Add(rupee3);
	rupeeList.Add(rupee4);
	rupeeList.Add(rupee5);
	rupeeList.Add(rupee6);
	rupeeList.Add(rupee7);
	rupeeList.Add(rupee8);
	rupeeList.Add(rupee9);
	rupeeList.Add(rupee10);


	//Displaying list so far
	cout << endl << "List is sorted in " << rupeeList.getSortType() << " order." << endl << endl;
	cout << "Rupee List after adding 10 values" << endl;
	rupeeList.printItems();
	cout << endl;


	//Deleting element with data value of rupee4 and rupee8
	rupeeList.deleteData(rupee4);
	rupeeList.deleteData(rupee5);

	//Display list
	cout << "Rupee List after deleting 2 elements" << endl;
	rupeeList.printItems();
	cout << endl;
	cout << "SIZE OF LIST = " << rupeeList.getCount() << endl;


	//emptying list
	rupeeList.empty();
	cout << "Rupee List has being emptied" << endl;
	cout << "SIZE OF LIST = " << rupeeList.getCount() << endl;


	cout << endl;
	cout << endl;


	system("pause");
}


/*
OUTPUT:

*********************LIST CONTAINING INTEGERS*************************

List is sorted in ascending order.

INTEGER List after adding 10 digits
1
5
8
11
15
18
20
22
25
30

INTEGER List after deleting 2 elements
1
5
8
11
15
20
22
30

SIZE OF LIST = 8
INTEGER List has being emptied
SIZE OF LIST = 0


*********************LIST CONTAINING STRINGS*************************

List is sorted in descending order.

STRING List after adding 10 digits
zeta
yelling
washing
Venus
rolling
quarter
mother
father
beta
alpha

STRING List after deleting 2 elements
zeta
washing
rolling
quarter
mother
father
beta
alpha

SIZE OF LIST = 8
STRING List has being emptied
SIZE OF LIST = 0


************************* Rupee *************************

List is sorted in unsorted order.

Rupee List after adding 10 values
200 Rupees and 85 paise.
85 Rupees and 98 paise.
65 Rupees and 20 paise.
1000 Rupees and 30 paise.
500 Rupees and 45 paise.
53 Rupees and 65 paise.
98 Rupees and 85 paise.
2 Rupees and 1 paise.
7 Rupees and 65 paise.
21 Rupees and 19 paise.

Rupee List after deleting 2 elements
200 Rupees and 85 paise.
85 Rupees and 98 paise.
65 Rupees and 20 paise.
53 Rupees and 65 paise.
98 Rupees and 85 paise.
2 Rupees and 1 paise.
7 Rupees and 65 paise.
21 Rupees and 19 paise.

SIZE OF LIST = 8
Rupee List has being emptied
SIZE OF LIST = 0


Press any key to continue . . .*/