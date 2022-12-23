#ifndef CANBUS_LIB_
#define CANBUS_LIB_

#define PIN_CANRX             PIN_D3
#define PIN_CANTX             PIN_D2

#define DELAY                 delay_us(1)

#define CANRX_HIGH            output_high(PIN_CANRX)
#define CANRX_LOW             output_low(PIN_CANRX)

#define CANTX_HIGH            output_high(PIN_CANTX)
#define CANTX_LOW             output_low(PIN_CANTX)

void can_send(int1 data)
{   
   if (data) CANTX_HIGH;
   else CANTX_LOW;      
   DELAY;   
}

void can_write(void)
{
   can_send(0);  //1 SOF 1  Bit
   
   can_send(0);  //2 IDENTIFIER 11 Bit
   can_send(0);  //3
   can_send(0);  //4
   can_send(0);  //5
   can_send(0);  //6
   can_send(0);  //7
   can_send(0);  //8
   can_send(0);  //9
   can_send(0);  //10
   can_send(0);  //11
   can_send(0);  //12
   
   can_send(0);  //13 RTR 1 Bit
   
   can_send(0);  //14 IDE 1 Bit
   
   can_send(0);  //15 RB0 1 Bit
   
   can_send(0);  //16 DLC 4 Bit
   can_send(0);  //17
   can_send(0);  //18
   can_send(1);  //19
   
   can_send(0);  //20 DATA 8 Bit
   can_send(0);  //21
   can_send(0);  //22
   can_send(0);  //23
   can_send(0);  //24
   can_send(0);  //25
   can_send(0);  //26
   can_send(1);  //27
}

#endif
