/*******************************************************
This program was created by the
CodeWizardAVR V3.12 Advanced
Automatic Program Generator
� Copyright 1998-2014 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : TeethRadiology Project
Version : 5.1
Date    : 7/7/2017
Author  : Ehsan Shaghaei
Company : EHP
Comments: 


Chip type               : ATmega64A
Program type            : Application
AVR Core Clock frequency: 8.000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 1024
*******************************************************/

#include <mega64a.h>
#include <delay.h>

#define Buzzer     PORTB.0
#define Ssr        PORTB.2
#define Timer_LED  PORTB.1

#define Expose_LED_ON  PORTG|=(1<<4)
#define Expose_LED_OFF PORTG&= ~(1<<4)

#define A0         PORTB.3
#define A1         PORTB.4
#define A2         PORTB.5
#define A3         PORTB.6
#define A4         PORTB.7           
#define A5         PORTE.0
#define A6         PORTE.1
#define A7         PORTE.2

#define D0         PIND.7
#define D1         PIND.6
#define D2         PIND.5
#define D3         PIND.4

#define RVG_SW       PINE.6
#define Timer_SW     PINE.7
#define Expose_SW    PIND.2
#define Up_SW        PINE.4
#define Down_SW      PIND.0

#define Set_Segments PORTF


// Declare your global variables here
//flash int  time [16] = {800,750,700,600,550,500,450,400,350,400,450,550,650,700,800,800};      
flash char no   [13] = {0b00000011,0b10011111,0b00100101,0b00001101,0b10011001,0b01001001,0b01000001,0b00011111,0b00000001,0b00001001,0xff,0b11111101,0b10010001};
eeprom unsigned int l = 800; 
int digit [4] = {10,10,10,10};
unsigned int k = 0,z=0;
unsigned int q,p=0 ;
int j;
char timer_flag = 0;
void beep ();
void Display_Number (unsigned int arg);
// Timer 0 overflow interrupt service routine
interrupt [TIM0_OVF] void timer0_ovf_isr(void)
{
// Place your code here
   
    z = k%4; 
     k++;
    switch(z)
    { 
    case 0:       
    PORTG &=~(1<<1);PORTG &=~(1<<2);PORTG &=~(1<<3);   
    Set_Segments =  no[digit[0]] & 0xfe;
    PORTG|=(1<<0);                                                
    //delay_ms(1);
    break;
    case 1:       
    PORTG &=~(1<<0);PORTG &=~(1<<2);PORTG &=~(1<<3);
    Set_Segments =  no[digit[1]] ;
    PORTG|=(1<<1);                                
    //delay_ms(1);
    break;
    case 2:      
    PORTG &=~(1<<1);PORTG &=~(1<<0);PORTG &=~(1<<3);
    Set_Segments = no[digit[2]];
    PORTG|=(1<<2);              
    //delay_ms(1);
    break;
    case 3:     
    PORTG &=~(1<<1);PORTG &=~(1<<2);PORTG &=~(1<<0);
    Set_Segments = no[digit[3]];
    PORTG|=(1<<3);              
    k=0;
    //delay_ms(1);
    break;
    } 
         
   
      //  #asm ("sei")

}

void main(void)
{
// Declare your local variables here
{
// Input/Output Ports initialization
// Port A initialization
// Function: Bit7=Out Bit6=Out Bit5=Out Bit4=Out Bit3=Out Bit2=Out Bit1=Out Bit0=Out 
DDRA=(1<<DDA7) | (1<<DDA6) | (1<<DDA5) | (1<<DDA4) | (1<<DDA3) | (1<<DDA2) | (1<<DDA1) | (1<<DDA0);
// State: Bit7=1 Bit6=1 Bit5=1 Bit4=1 Bit3=1 Bit2=1 Bit1=1 Bit0=1 
PORTA=(1<<PORTA7) | (1<<PORTA6) | (1<<PORTA5) | (1<<PORTA4) | (1<<PORTA3) | (1<<PORTA2) | (1<<PORTA1) | (1<<PORTA0);

// Port B initialization
// Function: Bit7=Out Bit6=Out Bit5=Out Bit4=Out Bit3=Out Bit2=Out Bit1=Out Bit0=Out 
DDRB=(1<<DDB7) | (1<<DDB6) | (1<<DDB5) | (1<<DDB4) | (1<<DDB3) | (1<<DDB2) | (1<<DDB1) | (1<<DDB0);
// State: Bit7=0 Bit6=0 Bit5=0 Bit4=0 Bit3=0 Bit2=0 Bit1=0 Bit0=0 
PORTB=(0<<PORTB7) | (0<<PORTB6) | (0<<PORTB5) | (0<<PORTB4) | (0<<PORTB3) | (0<<PORTB2) | (0<<PORTB1) | (0<<PORTB0);

// Port C initialization
// Function: Bit7=Out Bit6=Out Bit5=Out Bit4=Out Bit3=Out Bit2=Out Bit1=Out Bit0=Out 
DDRC=(1<<DDC7) | (1<<DDC6) | (1<<DDC5) | (1<<DDC4) | (1<<DDC3) | (1<<DDC2) | (1<<DDC1) | (1<<DDC0);
// State: Bit7=1 Bit6=1 Bit5=1 Bit4=1 Bit3=1 Bit2=1 Bit1=1 Bit0=1 
PORTC=(1<<PORTC7) | (1<<PORTC6) | (1<<PORTC5) | (1<<PORTC4) | (1<<PORTC3) | (1<<PORTC2) | (1<<PORTC1) | (1<<PORTC0);

// Port D initialization
// Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=In Bit2=In Bit1=In Bit0=In 
DDRD=(0<<DDD7) | (0<<DDD6) | (0<<DDD5) | (0<<DDD4) | (0<<DDD3) | (0<<DDD2) | (0<<DDD1) | (0<<DDD0);
// State: Bit7=T Bit6=T Bit5=T Bit4=T Bit3=P Bit2=P Bit1=P Bit0=P 
PORTD=(0<<PORTD7) | (0<<PORTD6) | (0<<PORTD5) | (0<<PORTD4) | (1<<PORTD3) | (1<<PORTD2) | (1<<PORTD1) | (1<<PORTD0);

// Port E initialization
// Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=In Bit2=Out Bit1=Out Bit0=Out 
DDRE=(0<<DDE7) | (0<<DDE6) | (0<<DDE5) | (0<<DDE4) | (0<<DDE3) | (1<<DDE2) | (1<<DDE1) | (1<<DDE0);
// State: Bit7=P Bit6=P Bit5=P Bit4=P Bit3=T Bit2=0 Bit1=0 Bit0=0 
PORTE=(1<<PORTE7) | (1<<PORTE6) | (1<<PORTE5) | (1<<PORTE4) | (0<<PORTE3) | (0<<PORTE2) | (0<<PORTE1) | (0<<PORTE0);

// Port F initialization
// Function: Bit7=Out Bit6=Out Bit5=Out Bit4=Out Bit3=Out Bit2=Out Bit1=Out Bit0=Out 
DDRF=(1<<DDF7) | (1<<DDF6) | (1<<DDF5) | (1<<DDF4) | (1<<DDF3) | (1<<DDF2) | (1<<DDF1) | (1<<DDF0);
// State: Bit7=0 Bit6=0 Bit5=0 Bit4=0 Bit3=0 Bit2=0 Bit1=0 Bit0=0 
PORTF=(0<<PORTF7) | (0<<PORTF6) | (0<<PORTF5) | (0<<PORTF4) | (0<<PORTF3) | (0<<PORTF2) | (0<<PORTF1) | (0<<PORTF0);

// Port G initialization
// Function: Bit4=Out Bit3=Out Bit2=Out Bit1=Out Bit0=Out 
DDRG=(1<<DDG4) | (1<<DDG3) | (1<<DDG2) | (1<<DDG1) | (1<<DDG0);
// State: Bit4=0 Bit3=0 Bit2=0 Bit1=0 Bit0=0 
PORTG=(0<<PORTG4) | (0<<PORTG3) | (0<<PORTG2) | (0<<PORTG1) | (0<<PORTG0);

// Timer/Counter 0 initialization
// Clock source: System Clock
// Clock value: 125.000 kHz
// Mode: Normal top=0xFF
// OC0 output: Disconnected
// Timer Period: 2.048 ms
//ASSR=0<<AS0;
//TCCR0=(0<<WGM00) | (0<<COM01) | (0<<COM00) | (0<<WGM01) | (1<<CS02) | (0<<CS01) | (0<<CS00);
//TCNT0=0x00;
//OCR0=0x00;
  // Timer/Counter 0 initialization
// Clock source: System Clock
// Clock value: 250.000 kHz
// Mode: Normal top=0xFF
// OC0 output: Disconnected
// Timer Period: 1.024 ms
ASSR=0<<AS0;
TCCR0=(0<<WGM00) | (0<<COM01) | (0<<COM00) | (0<<WGM01) | (0<<CS02) | (1<<CS01) | (1<<CS00);
TCNT0=0x00;
OCR0=0x00;
// Timer/Counter 1 initialization
// Clock source: System Clock
// Clock value: Timer1 Stopped
// Mode: Normal top=0xFFFF
// OC1A output: Disconnected
// OC1B output: Disconnected
// OC1C output: Disconnected
// Noise Canceler: Off
// Input Capture on Falling Edge
// Timer1 Overflow Interrupt: Off
// Input Capture Interrupt: Off
// Compare A Match Interrupt: Off
// Compare B Match Interrupt: Off
// Compare C Match Interrupt: Off
TCCR1A=(0<<COM1A1) | (0<<COM1A0) | (0<<COM1B1) | (0<<COM1B0) | (0<<COM1C1) | (0<<COM1C0) | (0<<WGM11) | (0<<WGM10);
TCCR1B=(0<<ICNC1) | (0<<ICES1) | (0<<WGM13) | (0<<WGM12) | (0<<CS12) | (0<<CS11) | (0<<CS10);
TCNT1H=0x00;
TCNT1L=0x00;
ICR1H=0x00;
ICR1L=0x00;
OCR1AH=0x00;
OCR1AL=0x00;
OCR1BH=0x00;
OCR1BL=0x00;
OCR1CH=0x00;
OCR1CL=0x00;

// Timer/Counter 2 initialization
// Clock source: System Clock
// Clock value: Timer2 Stopped
// Mode: Normal top=0xFF
// OC2 output: Disconnected
TCCR2=(0<<WGM20) | (0<<COM21) | (0<<COM20) | (0<<WGM21) | (0<<CS22) | (0<<CS21) | (0<<CS20);
TCNT2=0x00;
OCR2=0x00;

// Timer/Counter 3 initialization
// Clock source: System Clock
// Clock value: Timer3 Stopped
// Mode: Normal top=0xFFFF
// OC3A output: Disconnected
// OC3B output: Disconnected
// OC3C output: Disconnected
// Noise Canceler: Off
// Input Capture on Falling Edge
// Timer3 Overflow Interrupt: Off
// Input Capture Interrupt: Off
// Compare A Match Interrupt: Off
// Compare B Match Interrupt: Off
// Compare C Match Interrupt: Off
TCCR3A=(0<<COM3A1) | (0<<COM3A0) | (0<<COM3B1) | (0<<COM3B0) | (0<<COM3C1) | (0<<COM3C0) | (0<<WGM31) | (0<<WGM30);
TCCR3B=(0<<ICNC3) | (0<<ICES3) | (0<<WGM33) | (0<<WGM32) | (0<<CS32) | (0<<CS31) | (0<<CS30);
TCNT3H=0x00;
TCNT3L=0x00;
ICR3H=0x00;
ICR3L=0x00;
OCR3AH=0x00;
OCR3AL=0x00;
OCR3BH=0x00;
OCR3BL=0x00;
OCR3CH=0x00;
OCR3CL=0x00;

// Timer(s)/Counter(s) Interrupt(s) initialization
TIMSK=(0<<OCIE2) | (0<<TOIE2) | (0<<TICIE1) | (0<<OCIE1A) | (0<<OCIE1B) | (0<<TOIE1) | (0<<OCIE0) | (1<<TOIE0);
ETIMSK=(0<<TICIE3) | (0<<OCIE3A) | (0<<OCIE3B) | (0<<TOIE3) | (0<<OCIE3C) | (0<<OCIE1C);

// External Interrupt(s) initialization
// INT0: Off
// INT1: Off
// INT2: Off
// INT3: Off
// INT4: Off
// INT5: Off
// INT6: Off
// INT7: Off
EICRA=(0<<ISC31) | (0<<ISC30) | (0<<ISC21) | (0<<ISC20) | (0<<ISC11) | (0<<ISC10) | (0<<ISC01) | (0<<ISC00);
EICRB=(0<<ISC71) | (0<<ISC70) | (0<<ISC61) | (0<<ISC60) | (0<<ISC51) | (0<<ISC50) | (0<<ISC41) | (0<<ISC40);
EIMSK=(0<<INT7) | (0<<INT6) | (0<<INT5) | (0<<INT4) | (0<<INT3) | (0<<INT2) | (0<<INT1) | (0<<INT0);

// USART0 initialization
// USART0 disabled
UCSR0B=(0<<RXCIE0) | (0<<TXCIE0) | (0<<UDRIE0) | (0<<RXEN0) | (0<<TXEN0) | (0<<UCSZ02) | (0<<RXB80) | (0<<TXB80);

// USART1 initialization
// USART1 disabled
UCSR1B=(0<<RXCIE1) | (0<<TXCIE1) | (0<<UDRIE1) | (0<<RXEN1) | (0<<TXEN1) | (0<<UCSZ12) | (0<<RXB81) | (0<<TXB81);

// Analog Comparator initialization
// Analog Comparator: Off
// The Analog Comparator's positive input is
// connected to the AIN0 pin
// The Analog Comparator's negative input is
// connected to the AIN1 pin
ACSR=(1<<ACD) | (0<<ACBG) | (0<<ACO) | (0<<ACI) | (0<<ACIE) | (0<<ACIC) | (0<<ACIS1) | (0<<ACIS0);
SFIOR=(0<<ACME);

// ADC initialization
// ADC disabled
ADCSRA=(0<<ADEN) | (0<<ADSC) | (0<<ADFR) | (0<<ADIF) | (0<<ADIE) | (0<<ADPS2) | (0<<ADPS1) | (0<<ADPS0);

// SPI initialization
// SPI disabled
SPCR=(0<<SPIE) | (0<<SPE) | (0<<DORD) | (0<<MSTR) | (0<<CPOL) | (0<<CPHA) | (0<<SPR1) | (0<<SPR0);

// TWI initialization
// TWI disabled
TWCR=(0<<TWEA) | (0<<TWSTA) | (0<<TWSTO) | (0<<TWEN) | (0<<TWIE);
     
 }
// Global enable interrupts
#asm("sei")


digit [0] = 11;
digit [1] = 12;
digit [2] = 1;
digit [3] = 11;
PORTA = 0x00;
PORTC = 0x00;
beep();
delay_ms(200);
beep();
delay_ms(200);
beep();

//PORTA.0 = 1;
delay_ms(1000);


//         q=1543;
//        for (j=3;j>=0;j--)
//        {
//        digit [j] = q%10;
//        q = q/10;
//        }     
//        for (j=3;j>=0;j--)
//        {
//        digit [j] = q%10;
//        q = q/10;
//        } 
//            j=3;
//            q=6543;
//            while (j >= 0 && j <= 3)
//            {
//               digit [j] = q%10;
//               q = q/10;
//               j--;
//            }
        A0 = A1 = A2 = A3 = A4 = A5 = A6 = A7 = 1;
        while (1)
           {    
                 Display_Number(l);
                /*if(D0 == 1)
                {
                delay_ms(500);
                Timer_LED  = ~ Timer_LED;
                timer_flag = ~ timer_flag;
                } 
                if(D1 == 1)
                {
                delay_ms(500);         //up
                if (l>=3000){l=3000;beep();}
                else if (l <100){l = l+10;}
                else if (l>=100){l=l+50;}
                }   
                } 
                if(D3 == 1)
                {
                delay_ms(500);
                if(timer_flag)
                {       
                Display_Number(8888);
                Buzzer = 1;  
               
                for(p=0;p<9;p++)
                {
                delay_ms(500);
                Buzzer = ~ Buzzer;
                }           
                Buzzer = 0; 
                delay_ms (500);                
                }              
                Expose_LED_ON;
                digit[0]= digit [1] = digit [2] = digit [3] = 11;
                Buzzer = 1;
                Ssr    = 1;
                delay_ms(l);
                Ssr    = 0;
                Buzzer = 0;                                
                Expose_LED_OFF;
                digit[0]= digit [1] = digit [2] = digit [3] = 12;
                delay_ms(15000);                
                Display_Number(l);
                } 
                if(D2 == 1)
                {
                
                delay_ms(500);
                if (l<=30){l=30;beep();} 
                else if (l<=100){l=l-10;}
                else if (l>100) {l=l-50;}
                }
                else{};*/
                if(Expose_SW == 0)
                {
                delay_ms(500);
                if(timer_flag)
                {       
                Display_Number(8888);
                Buzzer = 1;  
               
                for(p=0;p<9;p++)
                {
                delay_ms(500);
                Buzzer = ~ Buzzer;
                }           
                Buzzer = 0; 
                delay_ms (500);                
                }              
                Expose_LED_ON;
                digit[0]= digit [1] = digit [2] = digit [3] = 11;
                Buzzer = 1;
                Ssr    = 1;
                delay_ms(l);
                Ssr    = 0;
                Buzzer = 0;                                
                Expose_LED_OFF;
                digit[0]= digit [1] = digit [2] = digit [3] = 12;
                delay_ms(15000);                
                Display_Number(l);
                }
                if(Down_SW == 0){
                delay_ms(500);
                if (l<=30){l=30;beep();} 
                else if (l<=100){l=l-10;}
                else if (l>100) {l=l-50;}
                }
                else{
             
                   } ;
                if(Up_SW == 0){
                delay_ms(500);
                if (l>=3000){l=3000;beep();}
                else if (l <100){l = l+10;}
                else if (l>=100){l=l+50;}
                }   
                if (RVG_SW == 0 )
                {      
                delay_ms(500);
                l = 30;
                }
                else{};  
                if(Timer_SW == 0)
                {
                delay_ms(500);
                Timer_LED  = ~ Timer_LED;
                timer_flag = ~ timer_flag;
                }
                PORTA = 0x00;
                PORTC = 0x00;      
                switch(l)
                {
                case 800 :
                PORTA.0 = 1;
                PORTC.0 = 1;
                PORTC.1 = 1;
                break; 
                case 750 :
                PORTA.1 = 1;
                break; 
                case 700 :
                PORTA.2 = 1;
                PORTC.2 = 1;
                break; 
                case 650 :
                PORTC.3 = 1;
                break;
                case 600 :
                PORTA.3 = 1;
                break; 
                case 550 :
                PORTC.4 = 1;
                PORTA.4 = 1;
                break; 
                case 500 :
                PORTA.5 = 1;
                break; 
                case 450 :
                PORTA.6 = 1;
                PORTC.5 = 1;
                break;      
                case 400 :
                PORTA.7 = 1;
                PORTC.6 = 1;
                break; 
                case 350 :
                PORTC.7 = 1;
                break; 
                default :
                PORTA = 0x00;
                PORTC = 0x00;
                break;
                } 
                if(D3 == 1) Buzzer = 1;
                else{};
                
           }

void Display_Number (unsigned int arg)
{
      j=3;
            q= arg;
            while (j >= 0 && j <= 3)
            {
               digit [j] = q%10;
               q = q/10;
               j--;
            }
}
void beep ()
{
Buzzer = 1;
delay_ms(200);
Buzzer= 0;
}