#include"setup.h"
#include"canbus_lib.c"

/*

Her mesaja �zg� bir ID numaras� vard�r. Mesajlar �er�eveler ile iletilirler.
Her �er�eve SOF (Start Of Frame) sinyali ile ba�lar.Bu sinyal 1 bitliktir dominantt�r.
Denetim alan�ndaki son bit RTR diye adland�r�l�r ve �zel anlam� vard�r.Bu bit 0 (dominant) ise g�nderilen �er�eve veri �er�evesidir ve veri alan�nda, ID alan�nda tan�mlanan mesaja ait veri vard�r.
ID extension biti �er�evenin 11 bitlik ID alan�na sahip 2.0A �er�evesi oldu�unu belirten dominant bir bittir.
Bu bitin ard�ndan bir bitlik kullan�lmayan rezerve alan gelmektedir.
Daha sonra 4 bitlik DLC diye isimlendirilen bir alan gelir.DLC alan� g�nderilen verinin ka� byte oldu�unu s�yler.
Veri alan� en fazla 8byte olabilmektedir.
Veri alan�n� CRC alan� takip eder.Bu alan 16 bitliktir ve 15 bitlik CRC (Cyclic Redundancy Check) bilgisi ile resesif CRC Delimiter bitinden olu�maktad�r.
CRC alan� g�nderilen SOF alan�ndan CRC alan�na kadar g�nderilen verinin do�ru olup olmad���n�n anla��lmas� i�in bir de�erdir.
Veriyi g�nderen d���m veri �zerinde bir tak�p i�lemler yaparak 15 bitlik CRC de�erini hesaplar ve �er�eveye ekler.
Alan d���m veriyi ald���nda g�ndericinin yapt��� i�lemler ile ayn� i�lemleri yapar ve CRC yi tekrar hesaplar.
Al�nan ve g�nderilen CRC tutarl� ise veri do�ru g�nderilmi�tir.
CRC alan�n� ACK alan� takip eder.Bu alan 2 bitliktir.
�lk bitini g�nderici resesif olarak g�nderir.E�er veri en az bir al�c� taraf�ndan do�ru al�nm��sa al�c� yola domniant biti yazar.
E�er g�nderici dominant biti okuyamassa ACK i�aretinden kaynakl� bir hata oldu�una kanaat getirir ve veriyi tekrar yollar.
Bu alan�n ikinci biti ise ACK delimiter olarak adland�r�l�r ve resesiftir.
Daha sonra �er�evenin sonland�r�ld���n� belirten 7 bitlik EOF alan� gelir. Bu alandaki bitler resesiftir.
Daha sonra ise �er�eveler aras�nda bo�luk b�rakmak amac�yla 3 bitlik INT alan� gelmektedir ve bitleri resesiftir.

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
