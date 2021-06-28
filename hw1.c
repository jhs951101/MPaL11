void MyLcdTest()
{
 u32 index = 0;
 gExNum = (unsigned int) MyLcdTest;
 rRCC_APB2ENR = rRCC_APB2ENR | (1<<3);

 rEXTI_IMR = rEXTI_IMR | (1<<9);

 rEXTI_FTSR = rEXTI_FTSR | (1<<9);
 rAFIO_EXTICR3 = rAFIO_EXTICR3 & ~(0xf << 4);
 rAFIO_EXTICR3 = rAFIO_EXTICR3 | (0x1 << 4);
 *(unsigned int *) 0xE000E100 |= (0x1 << 23);

 LCD_Setup();
 STM3210B_LCD_Init();
 LCD_WriteRAM_Prepare();

 gColor = Red
 while(1)
 {
 if(gExti[9])
 {
 LCD_Clear(gColor);
 gExti[9] = 0;
 }

 if(Uart_GetKey())
 break;
 }
 gExNum = 0;
}
void EXTI9_5_IRQHandler(void)
{
 if(rEXTI_PR & (1<<5))
 {
 rEXTI_PR = (1<<5);
 gExti[5] = 1;
 }
 else if(rEXTI_PR & (1<<6))
 {
 rEXTI_PR = (1<<6);
 gExti[6] = 1;
 }
 else if(rEXTI_PR & (1<<7))
 {
 rEXTI_PR = (1<<7);
 gExti[7] = 1;
 }
 else if(rEXTI_PR & (1<<8))
 {
 rEXTI_PR = (1<<8);
 gExti[8] = 1;
 }
 else if(rEXTI_PR & (1<<9))
 {
 rEXTI_PR = (1<<9);
 gExti[9] = 1;
 }
 if(gExNum == (unsigned int) MyLcdTest)
 {
 if(gExti[9] == 1)
 {
 if(gColor == Red)
 gColor = Blue;
 else if(gColor == Blue)
 gColor = Green;
 else if(gColor == Green)
 gColor = Red;
 }
 }
}
