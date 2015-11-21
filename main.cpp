#include <stdlib.h>
#include <cstdio>
#include <iostream>
#include <math.h>
#include <vector>
#define ESP 0.0001
using namespace std;

//our function
double F(double x)
{    
    double fx = 6*(4+x) - (x)*sqrt(fabs(400-(x+4)*(x+4)));  
   return fx;
}


double findroot(double x1, double x2, double x3)
{
 //variable declartion
  double x4_1,x4_2,fx1,fx2,fx3,
     h1,h2,h3_1,h3_2,h4,D,d1,d2,a1,a2,a0;
  int i=1;
  int count= 0;
  
 
  

  do
  {
   
     fx1 = F(x1);      //evaluate the function at x1
     fx2 = F(x2);      //evaluate the function at x2
     fx3 = a0 = F(x3); //evaluate the function at x3 and assign a0
     h1 = x1-x3;       
     h2 = x2-x3;       
   
     d1 = fx1-fx3;   //first difference
     d2 = fx2-fx3;   //second difference
   
     D = h1*h2*(h1-h2);
   
     a1 = (d2*h1*h1 - d1*h2*h2)/D; //divided difference
     a2 = (d1*h2 - d2*h1)/D;      //divided difference
   
     h3_1 = -((2*a0)/(a1 + sqrt(fabs(a1*a1 - (4*a2*a0)))));
     h3_2 = -((2*a0)/(a1 - sqrt(fabs(a1*a1 - (4*a2*a0)))));
     
   
      if( fabs((a1 + sqrt(fabs(a1*a1 - (4*a2*a0))))) >
           fabs( (a1 - sqrt(fabs(a1*a1 - (4*a2*a0))))) )
      {
            h4 = h3_1;
      }
      else
      {
            h4 = h3_2;
      }
      
      x4_2 = x3 + h4;
      
      if(fabs(F(x4_2)) <ESP)
      {
          //if a root has been found that is less that ESP
          
          i = 0;// set i to 0 so the next loop will not run
      }
      else
      {
           x4_1=x4_2;
           x1=x2;
           x2=x3;
           x3=x4_1;
           
      }
      
      if(x1 != x1){
          //stops the loop if we have a non real number
          
          exit(1);
      }
      
      count++;
  }while(i != 0);

  return x4_2;
}



int main(){
    
    std::vector<double> myvector;
    
    //to display all root of the function
    for(int i= -31;i<15;i++){

       
        bool found = false;
        
        int size = myvector.size();
        for (int k=0 ; k < size; k++){
            
            double num = findroot(i,i+1,i+2);
            
            if(myvector.at(k) == num ){
                found = true;
                break;
            }else{
                found = false;
            }
        }
    
        
        if(!found){
            myvector.push_back(findroot(i,i+1,i+2));
       }       
    
    }
    
    
    for (int z = 0; z < myvector.size(); z ++){
          std::cout<<"root: "<<myvector.at(z)<<std::endl;
          
        }
    
    
 
    
    // it display all the approximate roots of the function
    //notice there is only 3  roots to the function
    // there are just reappearing in very close together
    //the reason why some of the are the same is because
    //although the data type of the variable is double in c++
    //it actually is different values for example
    // it shows 1.82758 a couple of time but those values
    // go even further 1.82758xxxxxx
    //roots are -23.3718, 1.8275, 14.4758
    
    return 0;
}
