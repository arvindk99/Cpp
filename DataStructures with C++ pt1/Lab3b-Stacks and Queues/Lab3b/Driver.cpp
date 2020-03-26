/*
PARTNER 1: Arvind Kumar ID: 20372024
PARTNER 2: Kevin Lam ID: 20290826
*/

#include <iostream>
#include <cstdlib>
#include <string>
#include "Rupee.h"
#include "Stack.h"
#include "Queue.h"

using namespace std;

int main()
{
	Stack<int> intStack;
	Stack<string> strStack;
	Stack<Rupee> rupeeStack;

	Queue<int> intQueue;
	Queue<string> strQueue;
	Queue<Rupee> rupeeQueue;

	Rupee rupee1(200, 85);
	Rupee rupee2(85, 98);
	Rupee rupee3(65, 20);
	Rupee rupee4(1000, 30);
	Rupee rupee5(500, 45);

	bool quit = false;
	int options;

	while (quit == false)
	{
		cout << "Press 1 to display stacks, 2 to display queues, or 3 to quit!" << endl;
		cin >> options;

		if (options == 1)
		{
			//*********************STACK CONTAINING INTEGERS*************************
			cout << "*********************STACK CONTAINING INTEGERS*************************" << endl;

			//PUSHING ELEMENTS TO INTEGER STACK AND PRINTING AFTER EACH STEP

			cout << "Pushed 5" << endl;
			intStack.push(5);
			intStack.printItems();
			cout << endl;



			cout << "Pushed 8" << endl;
			intStack.push(8);
			intStack.printItems();
			cout << endl;



			cout << "Pushed 10" << endl;
			intStack.push(10);
			intStack.printItems();
			cout << endl;



			cout << "Pushed 15" << endl;
			intStack.push(15);
			intStack.printItems();
			cout << endl;



			cout << "Pushed 17" << endl;
			intStack.push(17);
			intStack.printItems();
			cout << endl;


			//POPPING ELEMENTS FROM THE STACK
			cout << "POP" << endl;
			intStack.pop();
			intStack.printItems();
			cout << endl;


			cout << "POP" << endl;
			intStack.pop();
			intStack.printItems();
			cout << endl;

			//OUPUTING THE TOP USING PEEK
			cout << "Top is :" << intStack.peek() << endl;

			//EMPTYING STACK
			cout << "Stack has been emptied!" << endl;
			intStack.empty();


			//*********************STACK CONTAINING STRINGS*************************
			cout << "*********************STACK CONTAINING STRINGS*************************" << endl;

			//PUSHING ELEMENTS TO STRING STACK AND PRINTING AFTER EACH STEP

			cout << "Pushed alpha" << endl;
			strStack.push("alpha");
			strStack.printItems();
			cout << endl;



			cout << "Pushed beta" << endl;
			strStack.push("beta");
			strStack.printItems();
			cout << endl;



			cout << "Pushed gamma" << endl;
			strStack.push("gamma");
			strStack.printItems();
			cout << endl;



			cout << "Pushed delta" << endl;
			strStack.push("delta");
			strStack.printItems();
			cout << endl;



			cout << "Pushed lambda" << endl;
			strStack.push("lambda");
			strStack.printItems();
			cout << endl;


			//POPPING ELEMENTS FROM THE STACK
			cout << "POP" << endl;
			strStack.pop();
			strStack.printItems();
			cout << endl;


			cout << "POP" << endl;
			strStack.pop();
			strStack.printItems();
			cout << endl;

			//OUPUTING THE TOP USING PEEK
			cout << "Top is :" << strStack.peek() << endl;

			//EMPTYING STACK
			cout << "Stack has been emptied!" << endl;
			strStack.empty();

			//*********************STACK CONTAINING RUPEES*************************
			cout << "*********************STACK CONTAINING RUPEES*************************" << endl;

			//PUSHING ELEMENTS TO RUPEES STACK AND PRINTING AFTER EACH STEP

			cout << "Pushed rupee1" << endl;
			rupeeStack.push(rupee1);
			rupeeStack.printItems();
			cout << endl;



			cout << "Pushed rupee2" << endl;
			rupeeStack.push(rupee2);
			rupeeStack.printItems();
			cout << endl;



			cout << "Pushed rupee3" << endl;
			rupeeStack.push(rupee3);
			rupeeStack.printItems();
			cout << endl;



			cout << "Pushed rupee4" << endl;
			rupeeStack.push(rupee4);
			rupeeStack.printItems();
			cout << endl;



			cout << "Pushed rupee5" << endl;
			rupeeStack.push(rupee5);
			rupeeStack.printItems();
			cout << endl;


			//POPPING ELEMENTS FROM THE STACK
			cout << "POP" << endl;
			rupeeStack.pop();
			rupeeStack.printItems();
			cout << endl;


			cout << "POP" << endl;
			rupeeStack.pop();
			rupeeStack.printItems();
			cout << endl;

			//OUPUTING THE TOP USING PEEK
			cout << "Top is :" << rupeeStack.peek() << endl;
			
			//EMPTYING STACK
			cout << "Stack has been emptied!" << endl;
			rupeeStack.empty();
		}

		else if (options == 2)
		{
			cout << endl;
			cout << endl;
			/***************************QUEUE CONTAINING INTEGERS**********************/
			cout << "*********************QUEUE CONTAINING INTEGERS*************************" << endl;

			//ENQUEUE ELEMENTS TO INT QUEUE AND PRINTING AFTER EACH STEP
			cout << "Enqueued 5" << endl;
			intQueue.enqueue(5);
			intQueue.printItems();
			cout << endl;

			cout << "Enqueued 8" << endl;
			intQueue.enqueue(8);
			intQueue.printItems();
			cout << endl;

			cout << "Enqueued 10" << endl;
			intQueue.enqueue(10);
			intQueue.printItems();
			cout << endl;

			cout << "Enqueued 15" << endl;
			intQueue.enqueue(15);
			intQueue.printItems();
			cout << endl;

			cout << "Enqueued 17" << endl;
			intQueue.enqueue(17);
			intQueue.printItems();
			cout << endl;


			//DEQUEUE ELEMENTS TO INT QUEUE AND PRINTING AFTER EACH STEP

			cout << "DEQUEUE" << endl;
			intQueue.dequeue();
			intQueue.printItems();
			cout << endl;

			cout << "DEQUEUE" << endl;
			intQueue.dequeue();
			intQueue.printItems();
			cout << endl;

			// Print out the front of the queue
			cout << "Front is : " << intQueue.front() << endl;

			// Print out the rear of the queue
			cout << "Rear is : " << intQueue.rear() << endl;

			cout << "Queue is being emptied" << endl;
			intQueue.empty();

		
			/***************************QUEUE CONTAINING STRINGS**********************/
			cout << "*********************QUEUE CONTAINING STRINGS*************************" << endl;

			//ENQUEUE ELEMENTS TO STRING QUEUE AND PRINTING AFTER EACH STEP
			cout << "Enqueued 5" << endl;
			strQueue.enqueue("alpha");
			strQueue.printItems();
			cout << endl;

			cout << "Enqueued 8" << endl;
			strQueue.enqueue("beta");
			strQueue.printItems();
			cout << endl;

			cout << "Enqueued 10" << endl;
			strQueue.enqueue("gamma");
			strQueue.printItems();
			cout << endl;

			cout << "Enqueued 15" << endl;
			strQueue.enqueue("delta");
			strQueue.printItems();
			cout << endl;

			cout << "Enqueued 17" << endl;
			strQueue.enqueue("lambda");
			strQueue.printItems();
			cout << endl;


			//DEQUEUE ELEMENTS TO String QUEUE AND PRINTING AFTER EACH STEP

			cout << "DEQUEUE" << endl;
			strQueue.dequeue();
			strQueue.printItems();
			cout << endl;

			cout << "DEQUEUE" << endl;
			strQueue.dequeue();
			strQueue.printItems();
			cout << endl;

			// PRINT front of string queue
			cout << "Front is : " << strQueue.front() << endl;

			// Print rear ofstring queue
			cout << "Rear is : " << strQueue.rear() << endl;

			cout << "Queue is being emptied" << endl;
			strQueue.empty();

			/***************************QUEUE CONTAINING RUPEES**********************/
			cout << "*********************QUEUE CONTAINING RUPEES*************************" << endl;


			//ENQUEUE ELEMENTS TO RUPEE QUEUE AND PRINTING AFTER EACH STEP

			cout << "Enqueued 5" << endl;
			rupeeQueue.enqueue(rupee1);
			rupeeQueue.printItems();
			cout << endl;

			cout << "Enqueued 8" << endl;
			rupeeQueue.enqueue(rupee2);
			rupeeQueue.printItems();
			cout << endl;

			cout << "Enqueued 10" << endl;
			rupeeQueue.enqueue(rupee3);
			rupeeQueue.printItems();
			cout << endl;

			cout << "Enqueued 15" << endl;
			rupeeQueue.enqueue(rupee4);
			rupeeQueue.printItems();
			cout << endl;

			cout << "Enqueued 17" << endl;
			rupeeQueue.enqueue(rupee5);
			rupeeQueue.printItems();
			cout << endl;

			//DEQUEUE ELEMENTS TO RUPEE QUEUE AND PRINTING AFTER EACH STEP

			cout << "DEQUEUE" << endl;
			rupeeQueue.dequeue();
			rupeeQueue.printItems();
			cout << endl;

			cout << "DEQUEUE" << endl;
			rupeeQueue.dequeue();
			rupeeQueue.printItems();
			cout << endl;

			// Print out the front of th queue
			cout << "Front is : " << rupeeQueue.front() << endl;

			// Print out the rear of  the queue
			cout << "Rear is : " << rupeeQueue.rear() << endl;

			cout << "Queue is being emptied" << endl;
			rupeeQueue.empty();
		}
		else if(options == 3)
		{
			// If user enters 3 then print message
			cout << endl << endl << "GOODBYE" << endl;
			quit = true;
		}
	}

	system("pause");
	return 0;
}