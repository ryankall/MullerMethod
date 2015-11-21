#include <stdio.h>
#include  <iostream>
#include <math.h>
 

void primeFactors(unsigned long long int n)
{
    // Print the number of 2s that divide n
    while (n%2 == 0)
    {
        std::cout<< 2<< " ";
        n = n/2;
    }
 
    // n must be odd at this point.  So we can skip one element (Note i = i +2)
    for (unsigned long long int i = 3; i <= sqrt(n); i =i+2)
    {
        // While i divides n, print i and divide n
        while (n%i == 0)
        {
            std::cout<< i<< " ";
            n = n/i;
        }
    }
 
    // This condition is to handle the case when n is a prime number
    // greater than 2
    if (n > 2)
        std::cout<< n<< " ";
}
 

//test funtion
 int main()
{
    //very lage n
    unsigned long long int n = 987654321;
  
    std::cout<< "The factors for 987654321= "; 
    primeFactors(n);
    std::cout<<std::endl;
    
    
    //another n
    n = 11111111111;
    std::cout<< "The factors for 11111111111= "; 
    primeFactors(n);
    std::cout<<std::endl;
    return 0;
}
