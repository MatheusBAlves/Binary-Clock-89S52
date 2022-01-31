#include<at89x52.h>
#include<delay.h>
void interrupcaoTimer0() interrupt 1;
void recarregaTimer();
void atualizaLCD();
void colunas();
unsigned char tictac;
int us=0, ds=1, um=1, dm=1, uh=1, dh=1;
int tempo=30;
bit b1=0, b2=0, b3=0;
int coluna = 0;
#define stop P3_0
#define colum P3_1
#define add P3_2
//*********************************
void main()
{
    EA=1;
    ET0=1;
    TMOD=1;
    TR0=1;

    while(1)
    {
        P0_0 = 1;
        P0_1 = 1;
        P0_2 = 1;
        P0_3 = 1;
        P0_4 = 1;

        P2_0 = 1;
        P2_1 = 1;
        P2_2 = 1;
        P2_3 = 1;
        P2_4 = 1;
        P2_5 = 1;

        if(stop==0)
        {
            TR0=0;
            colunas();

        }
        if(stop==1)
        {
            TR0=1;

        }

        atualizaLCD();
    }
}
//*********************************
void interrupcaoTimer0() interrupt 1
{
    recarregaTimer();
    tictac++;
    if(tictac==100)
    {
        tictac=0;
        us++;
        if(us==10)
        {
            us=0;
            ds++;
        }
        if(ds==6)
        {
            ds=0;
            um++;
        }


        if(um==10)
        {
            um=0;
            dm++;
        }
        if(dm==6)
        {
            dm=0;
            uh++;
        }


        if(uh==10)
        {
            uh=0;
            dh++;
        }
        if(dh==2 && uh==4)
        {
            dh=0;
            uh=0;
        }
    }
}
//*********************************
void recarregaTimer()
{
    TR0=0;
    TH0=216;
    TL0=239;
    TR0=1;
}
//*********************************
void atualizaLCD()
{
    switch(us)
    {
        case 0:
            P0_1 = 1;
            P0_2 = 1;
            P0_3 = 1;
            P0_4 = 1;
            break;

        case 1:
            P0_1 = 0;
            P0_2 = 1;
            P0_3 = 1;
            P0_4 = 1;
            break;

        case 2:
            P0_1 = 1;
            P0_2 = 0;
            P0_3 = 1;
            P0_4 = 1;
            break;

        case 3:
            P0_1 = 0;
            P0_2 = 0;
            P0_3 = 1;
            P0_4 = 1;
            break;

        case 4:
            P0_1 = 1;
            P0_2 = 1;
            P0_3 = 0;
            P0_4 = 1;
            break;

        case 5:
            P0_1 = 0;
            P0_2 = 1;
            P0_3 = 0;
            P0_4 = 1;
            break;

        case 6:
            P0_1 = 1;
            P0_2 = 0;
            P0_3 = 0;
            P0_4 = 1;
            break;

        case 7:
            P0_1 = 0;
            P0_2 = 0;
            P0_3 = 0;
            P0_4 = 1;
            break;

        case 8:
            P0_1 = 1;
            P0_2 = 1;
            P0_3 = 1;
            P0_4 = 0;
            break;

        case 9:
            P0_1 = 0;
            P0_2 = 1;
            P0_3 = 1;
            P0_4 = 0;
            break;
    }
    if(stop==0 && coluna==0)P0_0=0;
    else P0_0=1;
    P2_0 = 0;
    delay_ms(tempo);
    P2_0 = 1;

    switch(ds)
    {
        case 0:
            P0_1 = 1;
            P0_2 = 1;
            P0_3 = 1;
            P0_4 = 1;
            break;

        case 1:
            P0_1 = 0;
            P0_2 = 1;
            P0_3 = 1;
            P0_4 = 1;
            break;

        case 2:
            P0_1 = 1;
            P0_2 = 0;
            P0_3 = 1;
            P0_4 = 1;
            break;

        case 3:
            P0_1 = 0;
            P0_2 = 0;
            P0_3 = 1;
            P0_4 = 1;
            break;

        case 4:
            P0_1 = 1;
            P0_2 = 1;
            P0_3 = 0;
            P0_4 = 1;
            break;

        case 5:
            P0_1 = 0;
            P0_2 = 1;
            P0_3 = 0;
            P0_4 = 1;
            break;
    }
    if(stop==0 && coluna==1)P0_0=0;
    else P0_0=1;
    P2_1 = 0;
    delay_ms(tempo);
    P2_1 = 1;

    switch(um)
    {
        case 0:
            P0_1 = 1;
            P0_2 = 1;
            P0_3 = 1;
            P0_4 = 1;
            break;

        case 1:
            P0_1 = 0;
            P0_2 = 1;
            P0_3 = 1;
            P0_4 = 1;
            break;

        case 2:
            P0_1 = 1;
            P0_2 = 0;
            P0_3 = 1;
            P0_4 = 1;
            break;

        case 3:
            P0_1 = 0;
            P0_2 = 0;
            P0_3 = 1;
            P0_4 = 1;
            break;

        case 4:
            P0_1 = 1;
            P0_2 = 1;
            P0_3 = 0;
            P0_4 = 1;
            break;

        case 5:
            P0_1 = 0;
            P0_2 = 1;
            P0_3 = 0;
            P0_4 = 1;
            break;

        case 6:
            P0_1 = 1;
            P0_2 = 0;
            P0_3 = 0;
            P0_4 = 1;
            break;

        case 7:
            P0_1 = 0;
            P0_2 = 0;
            P0_3 = 0;
            P0_4 = 1;
            break;

        case 8:
            P0_1 = 1;
            P0_2 = 1;
            P0_3 = 1;
            P0_4 = 0;
            break;

        case 9:
            P0_1 = 0;
            P0_2 = 1;
            P0_3 = 1;
            P0_4 = 0;
            break;
    }
    if(stop==0 && coluna==2)P0_0=0;
    else P0_0=1;
    P2_2 = 0;
    delay_ms(tempo);
    P2_2 = 1;

    switch(dm)
    {
        case 0:
            P0_1 = 1;
            P0_2 = 1;
            P0_3 = 1;
            P0_4 = 1;
            break;

        case 1:
            P0_1 = 0;
            P0_2 = 1;
            P0_3 = 1;
            P0_4 = 1;
            break;

        case 2:
            P0_1 = 1;
            P0_2 = 0;
            P0_3 = 1;
            P0_4 = 1;
            break;

        case 3:
            P0_1 = 0;
            P0_2 = 0;
            P0_3 = 1;
            P0_4 = 1;
            break;

        case 4:
            P0_1 = 1;
            P0_2 = 1;
            P0_3 = 0;
            P0_4 = 1;
            break;

        case 5:
            P0_1 = 0;
            P0_2 = 1;
            P0_3 = 0;
            P0_4 = 1;
            break;


    }
    if(stop==0 && coluna==3)P0_0=0;
    else P0_0=1;
    P2_3 = 0;
    delay_ms(tempo);
    P2_3 = 1;

    switch(uh)
    {
        case 0:
            P0_1 = 1;
            P0_2 = 1;
            P0_3 = 1;
            P0_4 = 1;
            break;

        case 1:
            P0_1 = 0;
            P0_2 = 1;
            P0_3 = 1;
            P0_4 = 1;
            break;

        case 2:
            P0_1 = 1;
            P0_2 = 0;
            P0_3 = 1;
            P0_4 = 1;
            break;

        case 3:
            P0_1 = 0;
            P0_2 = 0;
            P0_3 = 1;
            P0_4 = 1;
            break;

        case 4:
            P0_1 = 1;
            P0_2 = 1;
            P0_3 = 0;
            P0_4 = 1;
            break;

        case 5:
            P0_1 = 0;
            P0_2 = 1;
            P0_3 = 0;
            P0_4 = 1;
            break;

        case 6:
            P0_1 = 1;
            P0_2 = 0;
            P0_3 = 0;
            P0_4 = 1;
            break;

        case 7:
            P0_1 = 0;
            P0_2 = 0;
            P0_3 = 0;
            P0_4 = 1;
            break;

        case 8:
            P0_1 = 1;
            P0_2 = 1;
            P0_3 = 1;
            P0_4 = 0;
            break;

        case 9:
            P0_1 = 0;
            P0_2 = 1;
            P0_3 = 1;
            P0_4 = 0;
            break;
    }
    if(stop==0 && coluna==4)P0_0=0;
    else P0_0=1;
    P2_4 = 0;
    delay_ms(tempo);
    P2_4 = 1;

    switch(dh)
    {
        case 0:
            P0_1 = 1;
            P0_2 = 1;
            P0_3 = 1;
            P0_4 = 1;
            break;

        case 1:
            P0_1 = 0;
            P0_2 = 1;
            P0_3 = 1;
            P0_4 = 1;
            break;

        case 2:
            P0_1 = 1;
            P0_2 = 0;
            P0_3 = 1;
            P0_4 = 1;
            break;

    }
    if(stop==0 && coluna==5)P0_0=0;
    else P0_0=1;
    P2_5 = 0;
    delay_ms(tempo);
    P2_5 = 1;
}
//*********************************

void colunas()
{

    if(colum==0 && b2==0)
    {

        coluna++;
        b2=1;
        if(coluna==6)coluna=0;
    }

    if(colum==1 && b2==1)b2=0;

    switch (coluna)
    {

        case 0:
            if(add==0 && b3==0)
            {
                us++;
                b3=1;
                if(us==10)us=0;
            }
            if(add==1 && b3==1)b3=0;
            break;

        case 1:
            if(add==0 && b3==0)
            {
                ds++;
                b3=1;
                if(ds==6)ds=0;
            }
            if(add==1 && b3==1)b3=0;
            break;

        case 2:
            if(add==0 && b3==0)
            {
                um++;
                b3=1;
                if(um==10)um=0;
            }
            if(add==1 && b3==1)b3=0;
            break;

        case 3:
            if(add==0 && b3==0)
            {
                dm++;
                b3=1;
                if(dm==6)dm=0;
            }
            if(add==1 && b3==1)b3=0;
            break;

        case 4:
            if(add==0 && b3==0)
            {
                uh++;
                b3=1;
                if(uh==10)uh=0;
            }
            if(add==1 && b3==1)b3=0;
            break;

        case 5:
            if(add==0 && b3==0)
            {
                dh++;
                b3=1;
                if(dh==3)dh=0;
            }
            if(add==1 && b3==1)b3=0;
            break;

    }
    atualizaLCD();



}



