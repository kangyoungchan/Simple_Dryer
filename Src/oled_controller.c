/*
 * oled_controller.c
 *
 *  Created on: Dec 16, 2024
 *      Author: sooju
 */
#include "oled_controller.h"
#include <stdio.h>

void opening() {

	SSD1306_GotoXY(5, 0);
	SSD1306_Puts("Start!", &Font_11x18, 1);
	SSD1306_GotoXY(10, 30);
	SSD1306_Puts("  Dryer :)", &Font_11x18, 1);
	SSD1306_UpdateScreen(); //display
	HAL_Delay(3000);

}

void pirnt_inform() {

	SSD1306_Clear();
	SSD1306_GotoXY(1, 0);
	SSD1306_Puts("Temper Work", &Font_11x18, 1);
	SSD1306_GotoXY(0, 15);
	SSD1306_Puts("------------", &Font_11x18, 1);
	SSD1306_GotoXY(14, 38);
	SSD1306_Puts("30.0", &Font_11x18, 1);
	SSD1306_GotoXY(81, 38);
    SSD1306_Puts("off", &Font_11x18, 1);
	SSD1306_UpdateScreen();
}

void print_temper(int temper)
{
	SSD1306_GotoXY(14, 38);
	char temper_str[10] = "";
	sprintf(temper_str, "%2d.0",temper);
	SSD1306_Puts(temper_str, &Font_11x18, 1);
	SSD1306_UpdateScreen();


}


void work_on_change()
{
	SSD1306_GotoXY(81, 38);
	SSD1306_Puts(" on ", &Font_11x18, 1);
	SSD1306_UpdateScreen();
}

void work_off_change()
{
	SSD1306_GotoXY(81, 38);
	SSD1306_Puts("off", &Font_11x18, 1);
	SSD1306_UpdateScreen();
}

void succession_display(int temper)
{
	SSD1306_Clear();
	SSD1306_GotoXY(20, 25);
	SSD1306_Puts("Complete!", &Font_11x18, 1);
	SSD1306_UpdateScreen();
	HAL_Delay(1500);
	SSD1306_Clear();
	pirnt_inform();
	print_temper(temper);

}
