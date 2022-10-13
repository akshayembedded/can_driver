#include<pic18.h>
void delay(int a)
{
	int i,j;
	for(i=0;i<a;i++)
	{for(j=0;j<500;j++);}
}

void main()
{

char a;	
TXSTA=0x24;
RCSTA=0x90;
SPBRG=129;				
TRISB=0x08;						 //CAN RX as input,CAN TX as output
TRISC=0x80;						//TX as output
LATB3=0;						//CAN RX clear

CANCON=0x80;
CANCONbits.REQOP2=1; 						//CAN Request Configuration mode

//ABAT=1;						//Abort All Pending Transmissions
while(CANSTATbits.OPMODE2==0);					//CAN wait for configuration mode
MDSEL1=0;						//Legacy mode
MDSEL0=0;						//Legacy mode
BRGCON1=0x42;						//Baud rate 125KHz with 20Mhz Crystal(Tq=0.5uS; Tbit=8uS ; n=16)
BRGCON2=0x12;						//Baud rate
BRGCON3=0x02;						//Baud rate
ENDRHI=1;						//Enable Drive High bit			
CANCONbits.REQOP2=0;						//Normal mode

while(CANSTATbits.OPMODE2==1);
//////////////RX Part///////////////
RXB0CON=0x60;//Receive all messages; Acceptance filter is ignored 
while((RXB0CON&0x80) ==0x80);//Receive buffer contains a message
while(TXIF==0);
TXREG=RXB0D0;
delay(20);
while(1)
{

}

}
