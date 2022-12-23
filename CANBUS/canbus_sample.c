#include"setup.h"
#include"canbus_lib.c"

/*

Her mesaja özgü bir ID numarasý vardýr. Mesajlar çerçeveler ile iletilirler.
Her çerçeve SOF (Start Of Frame) sinyali ile baþlar.Bu sinyal 1 bitliktir dominanttýr.
Denetim alanýndaki son bit RTR diye adlandýrýlýr ve özel anlamý vardýr.Bu bit 0 (dominant) ise gönderilen çerçeve veri çerçevesidir ve veri alanýnda, ID alanýnda tanýmlanan mesaja ait veri vardýr.
ID extension biti çerçevenin 11 bitlik ID alanýna sahip 2.0A çerçevesi olduðunu belirten dominant bir bittir.
Bu bitin ardýndan bir bitlik kullanýlmayan rezerve alan gelmektedir.
Daha sonra 4 bitlik DLC diye isimlendirilen bir alan gelir.DLC alaný gönderilen verinin kaç byte olduðunu söyler.
Veri alaný en fazla 8byte olabilmektedir.
Veri alanýný CRC alaný takip eder.Bu alan 16 bitliktir ve 15 bitlik CRC (Cyclic Redundancy Check) bilgisi ile resesif CRC Delimiter bitinden oluþmaktadýr.
CRC alaný gönderilen SOF alanýndan CRC alanýna kadar gönderilen verinin doðru olup olmadýðýnýn anlaþýlmasý için bir deðerdir.
Veriyi gönderen düðüm veri üzerinde bir takýp iþlemler yaparak 15 bitlik CRC deðerini hesaplar ve çerçeveye ekler.
Alan düðüm veriyi aldýðýnda göndericinin yaptýðý iþlemler ile ayný iþlemleri yapar ve CRC yi tekrar hesaplar.
Alýnan ve gönderilen CRC tutarlý ise veri doðru gönderilmiþtir.
CRC alanýný ACK alaný takip eder.Bu alan 2 bitliktir.
Ýlk bitini gönderici resesif olarak gönderir.Eðer veri en az bir alýcý tarafýndan doðru alýnmýþsa alýcý yola domniant biti yazar.
Eðer gönderici dominant biti okuyamassa ACK iþaretinden kaynaklý bir hata olduðuna kanaat getirir ve veriyi tekrar yollar.
Bu alanýn ikinci biti ise ACK delimiter olarak adlandýrýlýr ve resesiftir.
Daha sonra çerçevenin sonlandýrýldýðýný belirten 7 bitlik EOF alaný gelir. Bu alandaki bitler resesiftir.
Daha sonra ise çerçeveler arasýnda boþluk býrakmak amacýyla 3 bitlik INT alaný gelmektedir ve bitleri resesiftir.

*/

void main()
{  
   CANTX_HIGH;
   CANRX_HIGH;
   
   while(TRUE)
   {
      can_write();
      delay_ms(100);
   }
}
