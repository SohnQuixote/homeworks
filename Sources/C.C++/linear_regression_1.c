c#include <stdio.h>
#include <conio.h>

void main()
{
    double a,b;
    double X[] = {0,1,2};
    double Y[] = {1,3,2};
    double lr = 0.1; //learning rate
   double yHat = 0.0;
    a = 0.1;
    b = 0.0;

    double delta_a;
    double delta_b;

    int n = 0;

    double previous_error = 999.0;

    while(1)
    {
        delta_a = 0;
        delta_b = 0;
        for(int i=0;i<3;i++)
        {
            double y;
            yHat = a*X[i] +b;
            delta_a += (Y[i] -yHat) *X[i];
            delta_b += (Y[i] - yHat);


        }
        a = a+lr*delta_a;
        b = b+lr *delta_b;

        double error;
        error = 0.0;

        for(int i=0;i<3;i++)
        {
            double d;
            yHat = a*X[i] +b;
            d = (Y[i] - yHat) *(Y[i] - yHat);
            error +=d;

        }
        error = error/3.0;
        n++;
        printf("%d \t %1.6f \t %1.2f \t %1.2f \n" , n , error,a,b);

        if((previous_error - error) < 0.000001) break;

        previous_error = error;

    }





}