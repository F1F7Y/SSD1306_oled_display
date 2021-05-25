/*
 * SSD1306.h
 *
 * Created: 16.02.2021 12:19:50
 *  Author: Filip
 */ 


#ifndef SSD1306_H_
#define SSD1306_H_

#ifdef __cplusplus
extern "C"{
#endif

#define WIDTH 128
#define HEIGHT 64

#define ADDRESS 0x78

void SSD1306_init();

void SSD1306_cmd(uint8_t cmd);
void SSD1306_data(uint8_t data);
void SSD1306_set_col_address();
void SSD1306_set_page_address();

#ifdef __cplusplus
}
#endif

#endif /* SSD1306_H_ */