void MyLedIntTest() {
MyLedInit();
rRCC_APB2ENR = rRCC_APB2ENR | (1<<5) | (1<<6);
*(unsigned int *) 0xE000E100 |= (0x1 << 6);
*(unsigned int *) 0xE000E100 |= (0x1 << 7);
*(unsigned int *) 0xE000E100 |= (0x1 << 23);
*(unsigned int *) 0xE000E104 |= (0x1 << 8);
rEXTI_IMR = rEXTI_IMR | (1<<12) | (1<<14) | (1<<1) | (1<<0) | (1<<8);
rEXTI_FTSR = rEXTI_FTSR | (1<<12) | (1<<14) | (1<<1) | (1<<0) | (1<<8);
rAFIO_EXTICR4 = rAFIO_EXTICR4 & ~(0xf << 0); rAFIO_EXTICR4 = rAFIO_EXTICR4 | (0x3 << 0);
rAFIO_EXTICR4 = rAFIO_EXTICR4 & ~(0xf << 8); rAFIO_EXTICR4 = rAFIO_EXTICR4 | (0x3 << 8);
rAFIO_EXTICR1 = rAFIO_EXTICR1 & ~(0xf << 4); rAFIO_EXTICR1 = rAFIO_EXTICR1 | (0x4 << 4);
rAFIO_EXTICR1 = rAFIO_EXTICR1 & ~(0xf << 0); rAFIO_EXTICR1 = rAFIO_EXTICR1 | (0x4 << 0);
rAFIO_EXTICR3 = rAFIO_EXTICR3 & ~(0xf << 0); rAFIO_EXTICR3 = rAFIO_EXTICR3 | (0x3 << 0);
while(1) {
if(gExti[0]) {
rGPIOC_ODR ^= (1<<6);
gExti[0] = 0; }
else if(gExti[1]) {
rGPIOC_ODR ^= (1<<7);
gExti[1] = 0; }
else if(gExti[8]) {
rGPIOC_ODR ^= (1<<8);
gExti[8] = 0; }
else if(gExti[14]) {
rGPIOC_ODR ^= (1<<9);
gExti[14] = 0; }
else if(gExti[12]) {
rGPIOC_ODR ^= ((1<<6) | (1<<7) | (1<<8) | (1<<9));
gExti[12] = 0; }
if(Uart_GetKey()) break;
} }
