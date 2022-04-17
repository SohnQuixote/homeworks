#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define TRAIN_SAMPLES  4
void main()
{
    //AND pattern
    //input :x
    double x[TRAIN_SAMPLES][2] = {

        0,0,
        0,1,
        1,0,
        1,1
    };
    //target = y
    double y [TRAIN_SAMPLES] =
    {
        0,0,0,1
    };
    double w[3];

    //training

    //w

    for(int i=0;i<3;i++)
    {
        w[i] = ((double) rand() / RAND_MAX) *0.5 - 0.25;

    }
    unsigned int epoch = 0;
    unsigned int MAX_EPOCH = 500;
    double Etha = 0.05; //학습률

    double yhat;
    double x1,x2;
    double target;
    while (epoch ++ < MAX_EPOCH)
    {
        //모든트레이닝 샘플 훈련 1epoch
        double deltaw[3] = {0};
        double loss;
        double cost = 0.0; 
        for (int i=0;i<TRAIN_SAMPLES; i++)
        {
            x1 = x[i][0];
            x2 = x[i][1];
            target = y[i];

            yhat = w[0] + w[1]*x1 + w[2] *x2;

            deltaw[0] += (target - yhat);
            deltaw[1] += (target - yhat) *x1;
            deltaw[2] += (target -yhat) *x2;
            // w[i] = w[i] +etha * deltaw[0]; -> stochastic gradient descent
            loss += (target - yhat) *(target - yhat);


        }
        loss = 0.5 *loss /TRAIN_SAMPLES;
        printf("%0.5d : loss = %10.91f \n" , epoch, loss);
        w[0] = w[0] + Etha * (deltaw[0] / TRAIN_SAMPLES);
        w[1] = w[1] + Etha * (deltaw[1] / TRAIN_SAMPLES);
        w[2] = w[2] + Etha * (deltaw[2] / TRAIN_SAMPLES);
        

    }
    printf("TRAINING DONE\n"); 
    for(int i = 0; i<TRAIN_SAMPLES;i++)
    {
        x1 = x[i][0];
        x2 = x[i][1];
        target = y[i];
        yhat = w[0] + w[1]*x1 + w[2] *x2;

        printf("%2.1lf %2.1lf (%d) %2.1lf\n" , x1,x2,(int)target , yhat);

    }
    printf("TRAININGTEST DONE\n");

    x1 = 0.8;
    x2 = 0.7;
    double treshold = 0.5;
    yhat = w[0] + w[1]*x1 + w[2] *x2;
    int output_class = (yhat >treshold) ?1 :0;
    printf ("%2.1lf %2.1lf (%d) %2.1lf\n" , x1,x2,output_class , yhat);


}
