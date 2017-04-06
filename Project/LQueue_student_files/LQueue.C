/*--- LQueue.cpp ----------------------------------------------------------
  This file implements LQueue member functions.
  From:  "ADTs, Data Structures, and Problem Solving with C++", 2nd edition
         by Larry Nyhoff
-------------------------------------------------------------------------*/
 
#include <iostream>
using namespace std;
#include <math.h>       /* modf */

#include "LQueue.h"

//--- Definition of Queue constructor
Queue::Queue()
: myFront(0), myBack(0)
{}

//--- Definition of Queue copy constructor
Queue::Queue(const Queue & original)
{
   myFront = myBack = 0;
   if (!original.empty())
   {
      // Copy first node
      myFront = myBack = new Queue::Node(original.front());

      // Set pointer to run through original's linked list
      Queue::NodePointer origPtr = original.myFront->next;
      while (origPtr != 0)
      {
         myBack->next = new Queue::Node(origPtr->data);
         myBack = myBack->next;
         origPtr = origPtr->next;
      }
   }
}

//--- Definition of Queue destructor
Queue::~Queue()
{ 
  // Set pointer to run through the queue
  Queue::NodePointer prev = myFront,
                     ptr;
  while (prev != 0)
    {
      ptr = prev->next;
      delete prev;
      prev = ptr;
    }
}

//--- Definition of assignment operator
const Queue & Queue::operator=(const Queue & rightHandSide)
{
   if (this != &rightHandSide)         // check that not q = q
   {
      this->~Queue();                  // destroy current linked list
      if (rightHandSide.empty())       // empty queue
         myFront = myBack = 0;
      else
      {                                // copy rightHandSide's list
         // Copy first node
         myFront = myBack = new Queue::Node(rightHandSide.front());

         // Set pointer to run through rightHandSide's linked list
         Queue::NodePointer rhsPtr = rightHandSide.myFront->next;
         while (rhsPtr != 0)
         {
           myBack->next = new Queue::Node(rhsPtr->data);
           myBack = myBack->next;
           rhsPtr = rhsPtr->next;
         }
      }
   }
   return *this;
}

//--- Definition of empty()
bool Queue::empty() const
{ 
   return (myFront == 0); 
}

//--- Definition of enqueue()
void Queue::enqueue(const QueueElement & value)
{
   Queue::NodePointer newptr = new Queue::Node(value);
   if (empty())
      myFront = myBack = newptr;
   else
   {
      myBack->next = newptr;
      myBack = newptr;
   }
}

//--- Definition of display()
void Queue::display(ostream & out) const
{
   Queue::NodePointer ptr;
   for (ptr = myFront; ptr != 0; ptr = ptr->next)
     out << ptr->data << "  ";
   out << endl;
}

//--- Definition of front()
QueueElement Queue::front() const
{
   if (!empty())
      return (myFront->data);
   else
   {
	return 0;
   }
}

//--- Definition of dequeue()
void Queue::dequeue()
{
   if (!empty())
   {
      Queue::NodePointer ptr = myFront;
      myFront = myFront->next;
      delete ptr;
      if (myFront == 0)     // queue is now empty
         myBack = 0;
   }   
   else
      cerr << "*** Queue is empty -- can't remove a value ***\n";
}

//--- Definition of move_to_front()
void Queue::move_to_front(int val){
    if(empty()){
        return ;
    }else{
        Queue :: NodePointer pf = myFront ->next;
        Queue :: NodePointer temp = myFront;
        Queue :: NodePointer curr = new Queue::Node(val);
        while(pf->next != 0 ){
            if(pf->data == val){
                curr->next = myFront;
                myFront = curr;
                temp->next = pf ->next;
                delete(pf);
                return ;
            }
            temp = temp ->next;
            pf = pf -> next;
        }
        return ;
    }

}

void Queue::merge_two_queues(Queue q2) {
    if (q2.empty()) return;
    while (q2.myFront != 0) {
        bool check = true;
        Queue::NodePointer h2 = q2.myFront;
        cout << q2.front()<< endl;
        Queue::NodePointer hs = myFront;
        Queue::NodePointer h1 = myFront->next;
        Queue::NodePointer curr = new Queue::Node(h2->data);

        if (h2->data < hs->data) {
            curr->next = myFront;
            curr=myFront;
            q2.dequeue();
            check = false;
        }

        while (h1 != 0 && check) {
            if (h2->data < h1->data) {
                curr->next = h1;
                hs->next = curr;
                check = false;
                q2.dequeue();
            } else {
                hs = hs->next;
                h1 = h1->next;
            }
        }

        if(check){
            myBack->next = curr;
            myBack = curr;
            q2.dequeue();
        }

    }
    return ;
}
/*
void Queue::similation(int lt, int tt, int lr, int tr, int total) {
    double k = 0;                      // Tracking the each plan's number
    double  sumT = 0;                  // Total waiting time for taking off
    double  sumL = 0;                  // Total waiting time for landing
    int  l = -1;                       // Time for landing in runway
    int  t = -1;                       // Time for takeoff in runway
    Queue q1;                       // Queue for landing
    Queue q2;                       // Queue for takeoff
    int Maxl = 0 ;                      // Maximum number of planes in landing
    int MaxT = 0;                      // Maximum number of planes in takeoff
    int m = 0;                        // Total number of planes for landing
    int n = 0;                        //Total numbre of planes for takingoff



    for(int i = 1; i < total +1 ; i++){
        srand(i);
        l --;
        t --;

        int a = rand()%60 +1;
        int b = rand()%60 +1;
        cout << " Time "<< i << endl;

        if (a < lr){
            k = k + 0.001;
            q1.enqueue(k+i);
            cout << " Plane " << k*1000 +1000 << " wants to land; added landing queue; "<< q1.size()<<" in queue" <<endl;
            Maxl = max(q1.size(),Maxl);
        }

        if (b < tr){
            k = k+ 0.001;
            q2.enqueue(k+i);
            cout << " Plane "<< k* 1000 +1000 << " wants to takeoff; added to takeoff queue; "<< q2.size()<<" in queue "<< endl;
            MaxT = max(q2.size(),MaxT);
        }


        if(l == 0) cout << "Landing complete "<< q1.size()<< " in queue "<< endl;
        if(t == 0) cout << "Takeoff complete "<< q2.size() << " in queue "<< endl;

        if(q1.empty() && !q2.empty()&& l <= 0 && t <= 0){
            double fractpart, intpart;
            fractpart = modf(q2.front(), &intpart);
            n++;
            sumT = sumT + i - intpart;
            cout << " Takeoff:  Plane "<< fractpart* 1000 +1000<<  ";  "<< q2.size()<< " in queue "<< endl;
            q2.dequeue();
            t =tt;
        }

        if(!q1.empty() && l<= 0 && t <= 0) {
            double fractpart, intpart;
            fractpart = modf(q1.front(), &intpart);
            sumL = sumL + i - intpart;
            m++;
            cout << " Landing: Plane " << fractpart * 1000 + 1000 << ";  " << q1.size() << " in queue " << endl;
            q1.dequeue();
            l = lt;
        }

    }

    cout << " No new takeoffs or landings will be generated "<<endl;

    if(l <0) l=0;
    if(t< 0) t=0;

    int c = total + q1.size()*lt + q2.size() * tt + l + t + 1;

    for(int i = total +1 ; i < c ; i++){
        cout << " Time "<< i << endl;
        if(l >0 || t> 0){
            l --;
            t --;
        }

        if (l == 0 ) cout << "Landing complete; "<< q1.size()<< " in queue "<< endl;
        if (t == 0) cout << "Takeoff complete; "<<q2.size()<< " in queue "<< endl;

        while( q1.front() != 0 && l <= 0 && t <= 0){
            double fracpart, intpart;
            fracpart = modf(q1.front(), &intpart);
            m ++;
            sumL = sumL + i - intpart;
            cout << " Landing:  Plane "<< fracpart* 1000 +1000<< ";  "<< q1.size()<< " in queue " << endl;
            q1.dequeue();
            l =lt;
        }

        while(q2.front() != 0 && l <= 0 && t <= 0){
            double fractpart, intpart;
            fractpart = modf(q2.front(), &intpart);
            n ++;
            sumT = sumT + i - intpart;
            cout << " Takeoff:  Plane "<< fractpart* 1000 +1000<< ";  "<<q2.size()<< " in queue " << endl;
            q2.dequeue();
            t = tt;
        }

    }
    cout << " STATISTICS "<< endl;
    cout << " Maximum number of planes in landing queue was: "<< Maxl << endl;
    cout << " Average minutes spent waiting to land: "<< sumL/m << endl;
    cout << " Maximum number of planes in takeoff queue was: "<< MaxT << endl;
    cout << " Average minutes spent waiting to takeoff: " << sumT/n << endl;

}


int Queue:: size(){
    int s =0;
    Queue:: NodePointer  head = myFront;
    while(head != 0){
        s ++;
        head = head->next;
    }
    return s;
}
*/
void Queue::simulate (int lrate, int trate, int ltime, int ttime,int totalt) {
    Queue q1 ;     //land queue
    Queue q2 ;     //takeoff queue
    int jFirst= -1;      //to monitor the takingoff time
    int lFirst= -1;      //to monitor the landing time
    int jSec= -1;      //to monitor the takingoff time
    int lSec= -1;      //to monitor the landing time
    double vessel=0;     //to show the vessel number
    double n=0;       // number of landing planel
    double m=0;       //number of takingof planes
    double suml=0;    //total waiting time of landing planes
    double sumt=0;    //total waiting time of taking off planes
    int maxLand=0; //record max waiting plances in load queue
    int maxTakeOff = 0;
    for (int i=1; i< totalt+1; i++) {

        jFirst--;
        lFirst--;
        jSec--;
        lSec--;
        int a = rand()%60 +1;
        int b = rand()%60 +1;
        int c = rand()%60 +1;
        int d = rand()%60 +1;
        cout<< "Time = " <<i<<endl;
        if (a < lrate) {
            vessel= vessel+ 0.001;
            q1.enqueue(i+vessel);
            cout<< "Plane " << vessel*1000+1000<< " wants to land; added to landing queue; "<<q1.size()<< " in queue"<<endl;
            maxLand=max(q1.size(),maxLand);
        }
        if (b < trate) {
            vessel +=0.001;
            q2.enqueue(i+vessel);
            cout<< "Plane " << vessel*1000+1000<< " wants to takeoff; added to takeoff queue; "<<q2.size()<< " in queue"<<endl;
            maxTakeOff=max(q2.size(),maxTakeOff);
        }
        if (c < lrate) {
            vessel= vessel+ 0.001;
            q1.enqueue(i+vessel);
            cout<< "Plane " << vessel*1000+1000<< " wants to land; added to landing queue; "<<q1.size()<< " in queue"<<endl;
            maxLand=max(q1.size(),maxLand);
        }
        if (d < trate) {
            vessel +=0.001;
            q2.enqueue(i+vessel);
            cout<< "Plane " << vessel*1000+1000<< " wants to takeoff; added to takeoff queue; "<<q2.size()<< " in queue"<<endl;
            maxTakeOff=max(q2.size(),maxTakeOff);
        }

        if (lFirst==0) cout<<"Landing at runway1 complete; "<< q1.size()<< " in queue"<<endl;
        if (jFirst==0) cout<<"Takeoff at runway1 complete; "<< q2.size()<< " in queue"<<endl;
        if (lSec==0) cout<<"Landing at runway2 complete; "<< q1.size()<< " in queue"<<endl;
        if (jSec==0) cout<<"Takeoff at runway2 complete; "<< q2.size()<< " in queue"<<endl;


        while (!q1.empty() && ((jSec<=0 && lSec<=0) || (jFirst<=0 && lFirst<=0))) {
            if (jFirst<=0 && lFirst<=0) {
                double fractpart, intpart;
                fractpart = modf (q1.front() , &intpart);
                suml= suml + i-intpart;
                n++;
                cout<<"Landing at runway1:  Plane " << fractpart*1000+1000<<endl;
                q1.dequeue();
                lFirst=ltime;
            }
            else{
                double fractpart, intpart;
                fractpart = modf (q1.front() , &intpart);
                suml= suml + i-intpart;
                n++;
                cout<<"Landing at runway2:  Plane " << fractpart*1000+1000<<endl;
                q1.dequeue();
                lSec=ltime;
            }
        }

        while (q1.empty() && !q2.empty() && ((jSec<=0 && lSec<=0) || (jFirst<=0 && lFirst<=0))){
            if (jFirst<=0 && lFirst<=0) {
                double fractpart, intpart;
                fractpart = modf (q2.front() , &intpart);
                sumt= sumt + i- intpart;
                m++;
                cout<<"Taking off at runway1:  Plane " << fractpart*1000+1000<<endl;
                q2.dequeue();
                jFirst=ttime;
            }
            else{
                double fractpart, intpart;
                fractpart = modf (q2.front() , &intpart);
                sumt= sumt + i- intpart;
                m++;
                cout<<"Taking off at runway2:  Plane " << fractpart*1000+1000<<endl;
                q2.dequeue();
                jSec=ttime;
            }
        }
    }
    cout << "No new takeoffs or landings will be generated."<<endl;
    if (jFirst<0) jFirst = 0;
    if (lFirst<0) lFirst = 0;
    if (jSec<0) jSec = 0;
    if (lSec<0) lSec = 0;

    int i= totalt;
    while (q1.size() !=0 || q2.size() !=0 || max (jFirst,lFirst) >0 || max (jSec,lSec) >0 ) {
        i++;
        cout<< "Time = " << i <<endl;
        if (jFirst>0 || lFirst >0 || jSec>0 || lSec >0) {
            jSec--;
            lSec--;
            jFirst--;
            lFirst--;
        }

        if (lFirst==0) cout<<"Landing at runway1 complete; "<< q1.size()<< " in queue"<<endl;
        if (jFirst==0) cout<<"Takeoff at runway1 complete; "<< q2.size()<< " in queue"<<endl;
        if (lSec==0) cout<<"Landing at runway2 complete; "<< q1.size()<< " in queue"<<endl;
        if (jSec==0) cout<<"Takeoff at runway2 complete; "<< q2.size()<< " in queue"<<endl;


        while (q1.myFront != 0 && ((jSec<=0 && lSec<=0) || (jFirst<=0 && lFirst<=0))) {
            if (jFirst<=0 && lFirst<=0) {
                double fractpart, intpart;
                fractpart = modf (q1.front() , &intpart);
                suml= suml + i-intpart;
                n++;
                cout<<"Landing at runway1:  Plane " << fractpart*1000+1000<<endl;
                q1.dequeue();
                lFirst=ltime;
            }
            else {
                double fractpart, intpart;
                fractpart = modf (q1.front() , &intpart);
                suml= suml + i-intpart;
                n++;
                cout<<"Landing at runway2:  Plane " << fractpart*1000+1000<<endl;
                q1.dequeue();
                lSec=ltime;
            }
        }
        while (q2.myFront != 0 && ((jSec<=0 && lSec<=0) || (jFirst<=0 && lFirst<=0))){
            if (jFirst <=0 && lFirst <= 0 ) {
                double fractpart, intpart;
                fractpart = modf (q2.front() , &intpart);
                sumt= sumt + i- intpart;
                m++;
                cout<<"Taking off at runway1:  Plane " << fractpart*1000+1000<<endl;
                q2.dequeue();
                jFirst=ttime;            }
            else {
                double fractpart, intpart;
                fractpart = modf (q2.front() , &intpart);
                sumt= sumt + i- intpart;
                m++;
                cout<<"Taking off at runway2:  Plane " << fractpart*1000+1000<<endl;
                q2.dequeue();
                jSec=ttime;
            }
        }
    }

    cout <<"End of program."<<endl<<endl;
    cout << "STATISTICS"<< endl;
    cout << "Maximum number of planes in landing queue was: "<< maxLand<<endl;
    cout << "Average minutes spent waiting to land: "<< suml/n<<endl;
    cout << "Maximum number of planes in takeoff queue was: "<< maxTakeOff <<endl;
    cout << "Average minutes spent waiting to takeoff: "<< sumt/m <<endl;
}

int Queue::size() {
    int i=0;
    Queue::NodePointer temp = myFront;
    while (temp !=0) {
        i++;
        temp =temp -> next;
    }
    return i;
}

















/**
Queue q1;                        //Queue list for landing;
Queue q2;                        //Queue list for takingOff;
int l = -1;                      //Tracking runway for landing time;
int t = -1;                      //Tracking runway for takeoff time;
int m = 0;                       //Total  number of planes in landing;
int n = 0;                       //Total number of planes in takeoff queue;
double sumL = 0;                    //Time waiting in the landing queue;
double sumT = 0;                    //Time waiting in the takeoff queue;
int maxload = 0;                 //Maximum number of plans in the landing queue;
int maxtakeoff =0;               //Maximum number of plans in the  takeoff queue;
double k = 0;                    //The plan start number with 1000;




for(int i =0 ; i< total +1; i ++){
    srand(i);

    cout<<"Time "<< i << endl;

    int a = rand()%60 +1;
    int b = rand()%60 +1;

    if(a < lr){
        l --;
        t --;
        k = k + 0.001;
        q1.enqueue(i+k);
        cout <<" Plane "<< k*1000 + 1000 << "wants to land; added to landing queue; "<< q1.size()<<"in queue" <<endl;
        maxload = max(q1.size(),maxload);
    }

    if(b< tr){
        l --;
        t --;
        k = k + 0.001;
        q2.enqueue(i+k);
        cout << " Plane "<< k*1000 + 1000 << "wants to takeoff; added to takeoff queue; "<<q2.size()<< "in queue"<< endl;
        maxtakeoff = max(q2.size(), maxtakeoff);
    }

    if(l == 0){
        cout <<"Landing complete; "<< q1.size() <<" in queue "<< endl;
    }
    if(t == 0){
        cout <<"Takeoff complete; "<< q2.size() <<" in queue "<<endl;
    }

    // The case for runway avaliable, and landing queue is empty but takeoff queue is not empty.
    if(q1.empty() && !q2.empty() && l <= 0 && t <=0){
        double fractpart,intpart;
        fractpart = modf(q2.front(),&intpart);
        sumT = sumT + i - intpart;
        q2.dequeue();
        n++;
        t = tt;
        cout <<" Takeoff complete; " << fractpart*1000 + 1000 << " in queue "<< endl;
    }


    // The case for the runway avaliable, and landing is not empty
    if(!q1.empty() && l<= 0 && t<=0){
        double fractpart,intpart;
        fractpart = modf(q1.front(), &intpart);
        sumL = sumL +i - intpart;
        q1.dequeue();
        m++;
        l = lt;
        cout << " Landing complete; "<< fractpart*1000 + 1000<< " in queue "<< endl;
    }
}
cout << " No new takeoffs or landings will be generated. " << endl;

int c = total + lt* q1.size() + tt* q2.size() + l + t + 1;

for(int i= total + 1; i < c; i++){

    if(l > 0 || t > 0){
        l--;
        t--;
    }

    if(l==0) cout <<" Landing complete "<< q1.size() << " in queue "<< endl;
    if(t==0) cout <<" Takeoff complete "<< q2.size() << " in queue "<< endl;
    if(q1.empty() && !q2.empty()){
        double fractpart, intpart;
        fractpart = modf(q2.front(),&intpart);
        sumT = sumT +
    }
}


}

int Queue::size() {
Queue ::NodePointer  f= myFront;
int  s =0;
while(f != 0){
    s++;
    f = f->next;
}
return s;
}
 */

/*
Queue ::NodePointer b2 = q2.myBack;
Queue ::NodePointer temp=q2.myFront;
if(!q2.empty()&& !empty()){
    while(b2->next != 0){
        enqueue(temp->data);
        temp = temp->next;
    }
    return ;
}
Queue ::NodePointer  h1 = myFront;
Queue ::NodePointer  curr =myFront ->next;

while(h1 !=0) {
    while (h1->data > curr->data && curr->next != 0) {
        curr = curr->next;
    }

    Queue::NodePointer curr2 = h1; //// how can i switch to value to curr when i find bigger value and research later
    move_to_front(curr2->data);
    delete(curr2);
    h1 = h1->next;
}
return ;
}
*/








