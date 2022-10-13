#include<pic18.h>
#include <pic18f4580.h>
void delay(int a)
{
	int i,j;
	for(i=0;i<a;i++)
	{for(j=0;j<500;j++);}
}
void cantx(char a)
{
TXB0SIDL=0x00;						//Select Standard Identifier.
TXB0SIDH=0;							//Set standard ID bits 10-3
TXB0SIDL=0xE0;//7
TXB0D0=a;							//Set Data field (upto 8 bytes)
TXB0DLC=0x01;						//Set data length as 1 byte
CANCONbits.REQOP2=0; 				//Normal mode
while(CANSTATbits.OPMODE2==1);
TXB0CON=0x08;				//Requests sending a message
while((TXB0CON&0x08)==0x08);		//Wait for transmission to be complete
}

void main()
{
	char a=5;					
    TRISBbits.TRISB2=0;
    TRISBbits.RB3=1;
LATB3=0;					//CAN RX clear
    

////////////////CAN Config/////////////////

CANCONbits.REQOP2=1; 			//CAN Request Configuration mode
CANCONbits.ABAT=1;					//Abort All Pending Transmissions
while(CANSTATbits.OPMODE2==0);		//CAN wait for configuration mode
ECANCONbits.MDSEL0=0;
ECANCONbits.MDSEL1=0;	//Legacy mode
	//Legacy mode

BRGCON1=0x42;						//Baud rate 125KHz with 20Mhz Crystal(Tq=0.5uS; Tbit=8uS ; n=16)
BRGCON2=0x12;						//Baud rate
BRGCON3=0x02;						//Baud rate

ENDRHI=1;				//Enable Drive High bit			
cantx('a');
delay(100);

while(1)
{


}
}