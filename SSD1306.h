/***************************************
* Name: SSD1306.h                      *
* Author: Filip Bartoš                 *
*                                      *
* Contains the main functions used to  *
* communicate with the SSD1306 driver  *
***************************************/


#ifndef SSD1306_H_
#define SSD1306_H_


#define WIDTH 128
#define HEIGHT 64

#define ADDRESS 0x78

void SSD1306_init();

void SSD1306_cmd(uint8_t cmd);
void SSD1306_data(uint8_t data);
void SSD1306_set_col_address();
void SSD1306_set_page_address();


#endif /* SSD1306_H_ */
