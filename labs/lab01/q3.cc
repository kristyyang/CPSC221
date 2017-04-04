#include<iostream>


int array[10];

void fill_array(int first, int increment);
/*
void fill_array(){
    for(int i=0; i< 10;i++){
       array[i] = i+1;

       std::cout<< array[i] << std::endl;
    }

    std::cout<<" "<<std::endl;
}

*/
void fill_array(int first, int increment){
   	for(int i=0; i <10 ; i++){
	   array[i] = first;
	   first = first +increment;

	   std::cout<< array[i]<< std::endl;
	}
}



int main(void){
	int a, b;
	std::cout<<"Entre the first value is \n";
	std::cin>> a;
	std::cout<<"Entre the increment: \n";
	std::cin>>b;
	fill_array(a,b);
	std::cout<<"count value is: \n";
	for (int i=0;i<10;++i) {
       std::cout << array[i];
       std::cout << '\n';
 }
     return 0;
}



