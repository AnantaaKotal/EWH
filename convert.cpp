#include<iostream>
using namespace std;
 
int convert(int num)
{
     
    int dec = 0, rem, base = 1;
 
    while (num > 0)
    {
        rem = num % 10;
        dec = dec + rem * base;
        base = base * 2;
        num = num / 10;
    }
    
    return dec;
}
