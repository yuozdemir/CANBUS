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
   can_send(0);  //1 SOF 1  BÝT
   
   can_send(0);  //2 IDENTIFIER 11 BÝT
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
   
   can_send(0);  //13 RTR 1 BÝT
   
   can_send(0);  //14 IDE 1 BÝT
   
   can_send(0);  //15 RB0 1 BÝT
   
   can_send(0);  //16 DLC 4 BÝT
   can_send(0);  //17
   can_send(0);  //18
   can_send(1);  //19
   
   can_send(0);  //20 DATA 8 BÝT
   can_send(0);  //21
   can_send(0);  //22
   can_send(0);  //23
   can_send(0);  //24
   can_send(0);  //25
   can_send(0);  //26
   can_send(1);  //27
   
   /*can_send(0);  //28 CRC 15 BÝT
   can_send(0);  //29 
   can_send(1);  //30
   can_send(0);  //31
   can_send(0);  //32
   can_send(0);  //33
   can_send(0);  //34
   can_send(1);  //35
   can_send(1);  //36
   can_send(0);  //37
   can_send(0);  //38
   can_send(0);  //39
   can_send(0);  //40
   can_send(0);  //41
   can_send(0);  //42
   
   can_send(1);  //43 CRC DELÝMÝTER 1 BÝT
   
   can_send(0);  // 2 BÝT ACK BEKLE
   can_send(1);
    
   can_send(1);  //44 EOF 7 BÝT
   can_send(1);  //45
   can_send(1);  //46
   can_send(1);  //47  
   can_send(1);  //48
   can_send(1);  //49
   can_send(1);  //50
   
   can_send(1);  //51 IFS 3 BÝT
   can_send(1);  //52
   can_send(1);  //53*/
}

#endif
