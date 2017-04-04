#include <iostream>


int main () {
     int x = 5;
     int y = 15;         // 5 15 uninit uninit
     int * p1, *p2;      // value of x y p1 p2
     p1 = &x;
     std::cout<<"Initial value of x is "<< x << std::endl; //x initial value is 5
     std::cout<<"Initial value of y is "<< y << std::endl; //y initial value is 15
     std::cout<<"Address of x is "<< p1<<std::endl;        //p1 contains address of x
     

     p2 = &y;
     std::cout<<"Address of y is "<< p2<< std::endl;  // p2 contains address of y


     *p1 = 6;   // x value = 6, y value = 15 ;
                // p1 contains address of x, p2 conatains address of y
     
     *p1 = *p2; // x value = 15, y value = 15;
                //p1 contains address of x, p2 contains address of y

     p2 = p1;   // x value =15, y contains 15;
                //p1 contains address of x, p2 contains address of x
 
     *p1 = *p2+10;  //x value is 25, y value is 15;
                    //p1 contains addresss of x, p2 contains address of x
//
return 0;
}