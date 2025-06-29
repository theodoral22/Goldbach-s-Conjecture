#include <stdio.h>

int main()
{
    int N,p,q; //N:the number that the user gives, p:prime number, q=N-p: prime number
    //primep: flag used to check if p is prime number. Used as boolean, 1 means prime, 0 means not prime
    //primeq: flag used to ckeck if q is prime number. Used as boolean, 1 means prime, 0 means not prime
    char primep,primeq,flag;
    
    /**************************************************************************
    read the number from the user. This number must be an even integer greater 
    than 2. If is isn't, the program asks the user to enter the number again, 
    mentioning the error.
    **************************************************************************/
    do {
        printf ("Give me an even integer greater than 2\n");
        scanf ("%d",&N);
        if (N%2!=0) //if the number is not even
            printf ("The number you gave me is not even. Try again.\n");
        else if (N<=2) //if the number is not greater than 2
            printf ("The number you gave me is not greater than 2. Try again.\n");
    } while (N%2!=0 || N<=2);
    //repeat the loop until the user enters an even number greater than 2
    
    
   p=2; //start checking from the first prime number 2
   primeq=0;
   
   //find two prime numbers p and q such that p+q=N
   while (p<=N-2 && primeq==0)
   {
        primep=1; //assume p is prime
        
        //check if p is prime. Loop from 2 up to p-1 to see if p is divisible by any number
        for (int i=2;i<p-1;i++)
        {
            if (p%i==0 && p!=i) //if p is divisible by i (other than itself)
                primep=0; //p is not prime
        } 
        
        //if p is prime, check if q=N-p is also prime
        if (primep==1)
        {
            q=N-p;
            primeq=1; //assume q is prime
            for (int j=2;j<q-1;j++) 
            {
                if (q%j==0) //if q is divisible by j
                    primeq=0; //q is not prime
            }
        }
        
        p++; //try the next p
   }
   
   //once we find two prime numbers p and q, print the result
   //p-1 because p was incremented after the last check
   printf ("%d+%d=%d",p-1,q,N);

    return 0;
}