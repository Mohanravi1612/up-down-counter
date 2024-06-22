#include <xc.h>
#include <pic.h>
#define SegOne 0x01
#define SegTwo 0x02
void DELAY_ms(unsigned int ms_Count)
{
unsigned int i,j;
for(i=0;i<ms_Count;i++)
{
for(j=0;j<1000;j++);
}
}
int main() {
char seg_code[]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x02,0xF8,0x00,0x10};
int cnt, num, temp,i;
TRISB = 0x00;
TRISD = 0x00;
while (1)
{
for (cnt = 0x00; cnt <= 99; cnt++)
{
for (i = 0; i < 100; i++)
{
num = cnt;
temp = num / 10; // Tens digit
PORTD = SegOne;
PORTB = seg_code[temp];
DELAY_ms(1);
temp = num % 10; // Units digit
PORTD = SegTwo;
PORTB = seg_code[temp];
DELAY_ms(1);
}
}
for (cnt =99; cnt >=0; cnt--)
{
for (i = 0; i < 100; i++)
{
num = cnt;
temp = num / 10; // Tens digit
PORTD = SegOne;
PORTB = seg_code[temp];
DELAY_ms(1);
temp = num % 10; // Units digit
PORTD = SegTwo;
PORTB = seg_code[temp];
DELAY_ms(1);
}
}
}
}
