#include"setup.h"
#include"canbus_lib.c"

/*

Her mesaja özgü bir ID numarası vardır. Mesajlar çerçeveler ile iletilirler.
Her çerçeve SOF (Start Of Frame) sinyali ile başlar.Bu sinyal 1 bitliktir dominanttır.
Denetim alanındaki son bit RTR diye adlandırılır ve özel anlamı vardır.Bu bit 0 (dominant) ise gönderilen çerçeve veri çerçevesidir ve veri alanında, ID alanında tanımlanan mesaja ait veri vardır.
ID extension biti çerçevenin 11 bitlik ID alanına sahip 2.0A çerçevesi olduğunu belirten dominant bir bittir.
Bu bitin ardından bir bitlik kullanılmayan rezerve alan gelmektedir.
Daha sonra 4 bitlik DLC diye isimlendirilen bir alan gelir.DLC alanı gönderilen verinin kaç byte olduğunu söyler.
Veri alanı en fazla 8byte olabilmektedir.
Veri alanını CRC alanı takip eder.Bu alan 16 bitliktir ve 15 bitlik CRC (Cyclic Redundancy Check) bilgisi ile resesif CRC Delimiter bitinden oluşmaktadır.
CRC alanı gönderilen SOF alanından CRC alanına kadar gönderilen verinin doğru olup olmadığının anlaşılması için bir değerdir.
Veriyi gönderen düğüm veri üzerinde bir takıp işlemler yaparak 15 bitlik CRC değerini hesaplar ve çerçeveye ekler.
Alan düğüm veriyi aldığında göndericinin yaptığı işlemler ile aynı işlemleri yapar ve CRC yi tekrar hesaplar.
Alınan ve gönderilen CRC tutarlı ise veri doğru gönderilmiştir.
CRC alanını ACK alanı takip eder.Bu alan 2 bitliktir.
İlk bitini gönderici resesif olarak gönderir.Eğer veri en az bir alıcı tarafından doğru alınmışsa alıcı yola domniant biti yazar.
Eğer gönderici dominant biti okuyamassa ACK işaretinden kaynaklı bir hata olduğuna kanaat getirir ve veriyi tekrar yollar.
Bu alanın ikinci biti ise ACK delimiter olarak adlandırılır ve resesiftir.
Daha sonra çerçevenin sonlandırıldığını belirten 7 bitlik EOF alanı gelir. Bu alandaki bitler resesiftir.
Daha sonra ise çerçeveler arasında boşluk bırakmak amacıyla 3 bitlik INT alanı gelmektedir ve bitleri resesiftir.

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
