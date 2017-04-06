/*---------------------------------------------------------------------
                  Driver program to test the Queue class.
  ----------------------------------------------------------------------*/

#include <iostream>
#include "LQueue.h"
using namespace std;
	

void print(Queue q)
{ q.display(cout); }

int main(void)
{
   Queue q1;
   cout << "Queue created.  Empty? " << boolalpha << q1.empty() << endl;

   cout << "How many elements to add to the queue? ";
   int numItems;
   cin >> numItems;
   for (int i = 1; i <= numItems; i++) 
      q1.enqueue(100*i);

   cout << "Contents of queue q1 (via  print):\n";
   print(q1); 
   cout << endl;




   Queue q2;
   q2 = q1;
    q1.merge_two_queues(q2);
    print(q1);
   cout << "Contents of queue q2 after q2 = q1 (via  print):\n";
   print(q2); 
   cout << endl;

   cout << "Queue q2 empty? " << q2.empty() << endl;

   cout << "Front value in q2: " << q2.front() << endl;

    q1.merge_two_queues(q2);

   while (!q2.empty())
   {
     cout << "Remove front -- Queue contents: ";
     q2.dequeue();
     q2.display(cout);
   }
   cout << "Queue q2 empty? " << q2.empty() << endl;
   cout << "Front value in q2?" << endl << q2.front() << endl;
   cout << "Trying to remove front of q2: " << endl;
   q2.dequeue();


    int ltime;
    cout<< "Time for a plane to land(in minutes): " << ltime ;
    cin>>ltime;

    int ttime;
    cout<< "Time for a plane to takeOff(in minutes): "<< ttime ;
    cin>>ttime;

    int lrate;
    cout<< "Landing rate (planes per hour): "<< lrate ;
    cin>> lrate;

    int trate;
    cout<<"TakeOff rate (planes per hour): "<< trate ;
    cin>> trate;

    int totalt;
    cout <<"How long run the total simulation(in minutes) "<< totalt;
    cin>> totalt;

    q1.simulate(lrate,trate,ltime,ttime,totalt);

   //system("PAUSE");
   return 0;
}
