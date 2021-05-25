/*
 * SSD1306.c
 *
 * Created: 16.02.2021 12:19:38
 *  Author: Filip
 */

#include "s_TWI.h"
#include "SSD1306.h"

void SSD1306_init()
{
	TWI_start(ADDRESS);
	
	//Specify that we are sending a command
	TWI_write(0x00);
	
	//Set display off
	TWI_write(0xAE);
	//Set display clock divide ratio/Oscillator frequency
	TWI_write(0xD5);
	TWI_write(0x80);
	//Set multiplex ratio
	TWI_write(0xA8);
	TWI_write(0x3F);
	//Set display offset
	TWI_write(0xD3);
	TWI_write(0x00);
	//Set display start line
	TWI_write(0x40 | 0x00);
	//Set charge pump
	TWI_write(0x8D);
	TWI_write(0x14); //0x10 / 0x14
	//??
	TWI_write(0x20);
	TWI_write(0x00);
	//Set segment re-map
	TWI_write(0xA1 | 0x1);
	//Set TWI_write output scan direction
	TWI_write(0xC8);
	//Set COM pins hardware configuration
	TWI_write(0xDA);
	TWI_write(0x12);
	//Set contrast control
	TWI_write(0x81);
	TWI_write(0xCF); //0x9F / 0xCF
	//Set pre-charge period
	TWI_write(0xD9);
	TWI_write(0xF1); //0x22 / 0xF1
	//Set VCOMH deselect level
	TWI_write(0xDB);
	TWI_write(0x40);
	//Set Entire Display on/off
	TWI_write(0xA4);
	//Set normal/inverse display
	TWI_write(0xA6);
	//??
	//SSD1306_cmd(0x2E);
	//Set display on
	TWI_write(0xAF);
	
	TWI_stop();
}

void SSD1306_cmd(uint8_t cmd)
{
	TWI_start(ADDRESS); //Start
	TWI_write(0x00); //Specify that we are sending a COMMAND(0x00 or 0x80)
	TWI_write(cmd); //Send COMMAND
	TWI_stop(); //Stop
}

void SSD1306_data(uint8_t data)
{
	TWI_start(ADDRESS); //Start
	TWI_write(0x40); //Specify that we are sending DATA(0x40)
	TWI_write(data); //Send DATA
	TWI_stop(); //Stop
}

void SSD1306_set_col_address()
{
	SSD1306_cmd(0x21);
	SSD1306_cmd(0);
	SSD1306_cmd(WIDTH-1);
}

void SSD1306_set_page_address()
{
	SSD1306_cmd(0x22);
	SSD1306_cmd(0);
	SSD1306_cmd((HEIGHT/8)-1);
}
