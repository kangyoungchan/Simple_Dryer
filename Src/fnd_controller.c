#include "fnd_controller.h"

static void TM1637_Start(void);
static void TM1637_Stop(void);
static void TM1637_WriteByte(uint8_t byte);
static void TM1637_Delay(void);

// 숫자를 세그먼트 데이터로 변환 (0-9, 공백 지원)
static const uint8_t segmentMap[16] = { 0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D,
		0x7D, 0x07, 0x7F, 0x6F, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00 };

void TM1637_Init(void) {
	TM1637_SetBrightness(TM1637_BRIGHTNESS_MAX | TM1637_DISPLAY_ON);
}

void TM1637_SetBrightness(uint8_t brightness) {
	TM1637_Start();
	TM1637_WriteByte(TM1637_CMD_SET_CTRL | (brightness & 0x0F));
	TM1637_Stop();
}

void TM1637_DisplayDigits(uint8_t digits[]) {


	TM1637_Start();
	TM1637_WriteByte(TM1637_CMD_SET_DATA);
	TM1637_Stop();

	TM1637_Start();
	TM1637_WriteByte(TM1637_CMD_SET_ADDR);


	for (int i = 0; i < 4; i++) {

		TM1637_WriteByte(segmentMap[digits[i] & 0x0F]);


	}

	TM1637_Stop();
}

void TM1637_Temperature(uint8_t *digits, double tmp )
{

	if(tmp<100){
		digits[2]= Underbar;
		if(tmp>=10) digits[0]= (int)((tmp * 10) / 100) ; //10의자리
		if(tmp>=1) {

			if(tmp<10){
			digits[0]= Led_off;
			}

			digits[1]= (int) (tmp * 10) % 100 / 10 ; // 1의자리
		}

	    if(tmp>=0){
	    	digits[3]= (int)(tmp * 10) % 10; // .1의자리
	    }




	TM1637_DisplayDigits(digits);

	}
	else
	{
		return; //100도가 넘어갈시 함수종료
	}
}

void TM1637_Clear(void) {
	uint8_t blank[4] = { 0x00, 0x00, 0x00, 0x00 };
	TM1637_DisplayDigits(blank);
}

static void TM1637_Start(void) {
	TM1637_CLK_HIGH();
	TM1637_DIO_HIGH();
	TM1637_Delay();
	TM1637_DIO_LOW();
}

static void TM1637_Stop(void) {
	TM1637_CLK_LOW();
	TM1637_DIO_LOW();
	TM1637_Delay();
	TM1637_CLK_HIGH();
	TM1637_Delay();
	TM1637_DIO_HIGH();
}

static void TM1637_WriteByte(uint8_t byte) {
	for (int i = 0; i < 8; i++) {
		TM1637_CLK_LOW();
		if (byte & 0x01) {
			TM1637_DIO_HIGH();
		} else {
			TM1637_DIO_LOW();
		}
		TM1637_Delay();
		TM1637_CLK_HIGH();
		TM1637_Delay();
		byte >>= 1;
	}

	// ACK 비트 처리
	TM1637_CLK_LOW();
	TM1637_DIO_HIGH();
	TM1637_Delay();
	TM1637_CLK_HIGH();
	TM1637_Delay();
	TM1637_CLK_LOW();
}

static void TM1637_Delay(void) {
	// 간단한 소프트웨어 지연 (타이밍 요구 사항에 맞게 조정 가능)
	for (volatile int i = 0; i < 70; i++)
		;
}



