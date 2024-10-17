#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n = get_int("enter amount: ");
    int note1 = n/2000;
    if(note1>0)
    {
    printf("2000=%i \n", note1);
    }
    n = n - note1*2000;

    int note2 = n/500;
    if(note2>0)
        {
    printf("500=%i \n", note2);
    }
    n = n - note2*500;

    int note3 = n/200;
    if(note3>0)
        {
    printf("2000=%i \n", note3);
    }
    n = n - note3*200;

        int note4 = n/100;
        if(note4>0)
        {
    printf("2000=%i \n", note4);
    }
    n = n - note4*100;

        int note5 = n/50;
        if(note5>0)
            {
    printf("2000=%i \n", note5);
    }
    n = n - note5*50;

    int note6 = n/20;
    if(note6>0)
        {
    printf("2000=%i \n", note6);
    }
    n = n - note6*20;

    int note7 = n/10;
    if(note7>0)
        {
    printf("2000=%i \n", note7);
    }
    n = n - note7*10;

}