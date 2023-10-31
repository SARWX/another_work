//���������� ����� main.c
 #include <MDR32FxQI_port.h>
 #include <MDR32FxQI_rst_clk.h>

#define LED_Pin PORT_Pin_2
#define LED_Port MDR_PORTC


 // �������� ������� ��������, ������������� ����
 void Delay(int waitTicks);

 // ����� �����, ������ ���������� ���������� ���������
 int main()
 {
	 
   // ������� ��������� ������������ ������(-��) ����� GPIO
   PORT_InitTypeDef GPIOInitStruct;

   // �������� ������������ ����� C
   RST_CLK_PCLKcmd (RST_CLK_PCLK_PORTC, ENABLE);

   // �������������� ��������� ������������ ������(-��) ����� ���������� �� ���������
   PORT_StructInit(&GPIOInitStruct);

   // �������� �������� �� ��������� �� ����������� ��� ���������
   GPIOInitStruct.PORT_Pin = LED_Pin;
   GPIOInitStruct.PORT_OE = PORT_OE_OUT;
   GPIOInitStruct.PORT_SPEED = PORT_SPEED_MAXFAST;
   GPIOInitStruct.PORT_MODE = PORT_MODE_DIGITAL;

   // ��������� ����������� ���� ��������� ��� PORTC.
   PORT_Init(LED_Port, &GPIOInitStruct);

   // ��������� ����������� ���� ��������� - �������� ����
   while (1)
   {
    // ��������� ��������� ������ PD7
    // ���� �� ������ ���������� "0", �� ���������� ����� � ���������� "1"
    if (PORT_ReadInputDataBit (LED_Port, LED_Pin) == 0)
    {
        PORT_SetBits(LED_Port, LED_Pin); // LED
    }
    // ��������
    Delay(100000);

    // ��������� ��������� ������ PD7
    // ���� �� ������ = "1", �� ���������� "0"
    if (PORT_ReadInputDataBit (LED_Port, LED_Pin) == 1)
    {
        PORT_ResetBits(LED_Port, LED_Pin);
    };


    // ��������
    Delay(1000000);
    }
 }

 // ���������� ������� ��������, ������� �� ������� �� �� ���������� ����� ������
 void Delay(int waitTicks)
 {
   int i;
   for (i = 0; i < waitTicks; i++)
  {
   __NOP();
  }
 }