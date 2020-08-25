/*
 * main.c
 *
 *  Created on: Sep 3, 2019
 *      Author: Kamal
 */
#include<avr/io.h>
#include<util/delay.h>



#define LCD_DATA PORTB
#define ctrl   PORTA
#define  rs PD7
#define rw PD6
#define en PD5
#define t 10

void LCD_cmd(unsigned char cmd);
void init_LCD(void);
void LCD_write(unsigned char data);
void LCD_arabic(unsigned char *pattern,const char location);
void LCD_firstadd(void);
void LCD_secondadd(void);
void LeftMotor(void);
void RightMotor(void);
void sevenseg(void);
int main()
{

	DDRB=0b11111111;
	DDRA=0b11111111;
	DDRC=0b11111111;
	DDRD=0b11111111;
	init_LCD();
	_delay_ms(1);
// Modern Academy
	unsigned char Pattern1 [ ] = {0x9, 0x9, 0x9, 0x9, 0x1f, 0x0, 0x0, 0x0} ;
	unsigned char Pattern2 [ ] = { 0x0, 0x14, 0x1, 0x1, 0x1f, 0x0, 0x0, 0x0} ;
	unsigned char Pattern3 [ ] = { 0x0, 0xe, 0x8, 0x8, 0x1f, 0x0, 0x0, 0x0} ;
	unsigned char Pattern4 [ ] = { 0x4, 0x4, 0x4, 0x4, 0x1f, 0x0, 0x0, 0x0 } ;
    unsigned char Pattern5 [ ]= {0x0, 0x0, 0x1, 0x1, 0x1f, 0x0, 0xa, 0x0};
    unsigned char Pattern6 [ ]= {0x0, 0x0, 0x0, 0x0, 0xf, 0xa, 0x1e, 0x10};
LCD_arabic(Pattern1,1);
LCD_arabic(Pattern2,2);
LCD_arabic(Pattern3,3);
LCD_arabic(Pattern4,4);
LCD_arabic(Pattern5,5);
LCD_arabic(Pattern6,6);
while(1)
{
PORTD |=(1<<0); // turn on green led
LCD_firstadd();
PORTA=0b00000010; // 1st sevenseg print 6
PORTC=0b01000000;  // 2nd seven seg print 0
_delay_ms(100);
PORTA=0b00010010; // print 5
sevenseg(); // count from 9 to 0

LCD_secondadd();
PORTA=0b00011001; // print 4 on 1st segm
sevenseg();

LCD_firstadd();
PORTA=0b00110000; //print 3 on 1st segm
sevenseg();

LCD_secondadd();
PORTA=0b00100100; //print 2 on 1st segm
sevenseg();

LCD_firstadd();
PORTA=0b11111001; //print 1 on 1st segm
sevenseg();

LCD_secondadd();
PORTA=0b01000000;//print 0 on 1st segm
sevenseg();

PORTD&=~(1<<0);
LCD_firstadd();

PORTD |=(1<<1);  // TURN YELLOW on LED
LeftMotor();        // Turn Motor to left

PORTA=0b01111001; //1
PORTC=0b01000000; //0
_delay_ms(10);
PORTA=0b01000000;//0
sevenseg();
PORTD &=~(1<<3); // close the motor
PORTD &=~(1<<1); //turn yellow of
LCD_secondadd();

LCD_secondadd();
PORTD |=(1<<2); // red led on
PORTA=0b00000010;
PORTC=0b01000000;
_delay_ms(10);

PORTA=0b00010010;
sevenseg();

LCD_firstadd();
PORTA=0b00011001;
sevenseg();

LCD_secondadd();
PORTA=0b00110000;
sevenseg();

LCD_firstadd();
PORTA=0b00100100;
sevenseg();

LCD_secondadd();
PORTA=0b01111001;
sevenseg();

LCD_firstadd();
PORTA=0b01000000;
sevenseg();



PORTD &=~(1<<2);  // Turn red led off

LCD_secondadd();
PORTD |=(1<<1); // Turn yellow led on
RightMotor(); // MOTOR

PORTA=0b01111001;
PORTC=0b01000000;
_delay_ms(10);
PORTA=0b01000000;
_delay_ms(10);
sevenseg();
PORTD &=~(1<<4); // close the motor
PORTD &=~(1<<1) ; // close yellow led


  }
return 0;

}
void sevenseg(void)
{
	PORTC=0b00010000; // number 9 left seg
	 _delay_ms(150);
	 PORTC=0b00000000;// number 8 left seg
	 _delay_ms(150);
	 PORTC=0b01111000;// number 7 left seg
	 _delay_ms(150);
	 PORTC=0b00000010;// number 6 left seg
	 _delay_ms(150);
	 PORTC=0b00010010;// number 5 left seg
	 _delay_ms(150);
	 PORTC=0b00011001;// number 4 left seg
	 _delay_ms(150);
	 PORTC=0b00110000;// number 3 left seg
	 _delay_ms(150);
	 PORTC=0b00100100;// number 2 left seg
	 _delay_ms(150);
	 PORTC=0b01111001;// number 1 left seg
	 _delay_ms(150);
	 PORTC=0b01000000;// number 0 left seg
	 _delay_ms(150);
	 return ;
	}


void LCD_firstadd()
{
	LCD_cmd(0x1);
	LCD_cmd(0x80);
	LCD_write('M');
	_delay_ms(10);
	LCD_write('o');
	_delay_ms(10);
	LCD_write('d');
	_delay_ms(10);
	LCD_write('e');
	_delay_ms(10);
	LCD_write('r');
	_delay_ms(10);
	LCD_write('n');
	_delay_ms(10);
	LCD_write(' ');
	_delay_ms(10);
	LCD_write('A');
	_delay_ms(10);
	LCD_write('c');
	_delay_ms(10);
	LCD_write('a');
	_delay_ms(10);
	LCD_write('d');
	_delay_ms(10);
	LCD_write('e');
	_delay_ms(10);
	LCD_write('m');
	_delay_ms(10);
	LCD_write('y');
	_delay_ms(10);
	LCD_cmd(0xC0);
	_delay_ms(10);
	LCD_write('F');
	_delay_ms(10);
	LCD_write('o');
	_delay_ms(10);
	LCD_write('r');
	LCD_write(' ');
	_delay_ms(10);
	LCD_write('E');
	_delay_ms(10);
	LCD_write('n');
	_delay_ms(10);
	LCD_write('g');
	_delay_ms(10);
	LCD_write('i');
	_delay_ms(10);
	LCD_write('n');
	_delay_ms(10);
	LCD_write('e');
	_delay_ms(10);
	LCD_write('e');
	_delay_ms(10);
	LCD_write('r');
	_delay_ms(10);
	LCD_write('i');
	_delay_ms(10);
	LCD_write('n');
	_delay_ms(10);
	LCD_write('g');
	_delay_ms(10);

}

void LCD_secondadd()
{
	LCD_cmd(0x1);
	LCD_cmd(0x80);
	LCD_write(' ');
	LCD_write(' ');
	LCD_write(' ');
	LCD_write(' ');
	LCD_write(' ');
	LCD_write('I');
	_delay_ms(10);
	LCD_write('M');
	_delay_ms(10);
	LCD_write('T');
	_delay_ms(10);
	LCD_cmd(0xC8);
	LCD_write(1);
	_delay_ms(10);
	LCD_cmd(0xC7);
	LCD_write(2);
	_delay_ms(10);
	LCD_cmd(0xC6);
	LCD_write(3);
	_delay_ms(10);
	LCD_cmd(0xC5);
	LCD_write(4);
	_delay_ms(10);
	LCD_cmd(0xC4);
	LCD_write(5);
	_delay_ms(10);
	LCD_cmd(0xC3);
	LCD_write(6);
	_delay_ms(10);


}

void LeftMotor(void)
{
	PORTD |=(1<<3);
	_delay_ms(1);
	PORTD&=~(1<<4);
}
void RightMotor(void)
{
	PORTD |=(1<<4);
	_delay_ms(1);
	PORTD&=~(1<<3);
}

void LCD_arabic(unsigned char *pattern,const char location)
{
	int i=0;
	LCD_cmd(0x40 + (location*8));
	for(i=0;i<7;i++)
	{
		LCD_write(pattern[i]);
	}
}


void init_LCD(void)
{
	LCD_cmd(0x38);
	_delay_ms(t);
	LCD_cmd(0x01);
	_delay_ms(t);
	LCD_cmd(0x02);
	_delay_ms(t);
	LCD_cmd(0x06);
	_delay_ms(t);
	LCD_cmd(0x80);
	_delay_ms(t);
	LCD_cmd(0x0C);
}


void LCD_cmd(unsigned char cmd)
{
	LCD_DATA=cmd;
	PORTD &=~(1<<rs);
	PORTD &=~(1<<rw);
	PORTD|=(1<<en);
	_delay_ms(1);
	PORTD &=~(1<<en);
	PORTD |=(1<<en);

}

void LCD_write(unsigned char data)
{
	LCD_DATA=data;
	PORTD|=(1<<rs);
	PORTD &=~(1<<rw);
	PORTD |=(1<<en);
		_delay_ms(1);
		PORTD &=~(1<<en);
		PORTD |=(1<<en);
}










