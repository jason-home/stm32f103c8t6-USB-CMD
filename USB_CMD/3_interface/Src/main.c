/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "usb_device.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
 #include "usbd_hid.h"
/* USER CODE END Includes */
#include <string.h>
#define Page_Up	"PageUp"
#define Page_Down	"PageDown"
/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
UART_HandleTypeDef huart2;
/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/*int fputc(int ch, FILE *f)
{
	HAL_UART_Transmit(&huart2, (uint8_t *)&ch, 1, 0xFFFF);
	return ch;
}*/
/* USER CODE BEGIN PV */
/*int fgetc( FILE *f)
{       
	  int ret ;
    HAL_UART_Receive(&huart2, (uint8_t *)&ret, 1, 0xFFFF);
    return ret;
}*/

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);
//uint8_t Key_Scan(uint8_t GPIO_Pin);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
	MX_USART2_UART_Init();
  MX_GPIO_Init();
  MX_USB_DEVICE_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */
 
  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {     
		    char c[]="Page__Up";
		    char *d="PageDown";
		    char *e="-       ";
		    char a[8];
		    HAL_UART_Receive(&huart2,(uint8_t *)&a, 8 , 0xFFFF);
				//printf("a:%s \r\n",a);
			if(strcmp(a,c) == 0)
			{
			uint8_t report[8];
			report[0]= 0x00;
			report[1]= 0x00;
			report[2]= 0x4b;
			report[3]= 0x00;
			report[4]= 0x00;
			report[5]= 0x00;
			report[6]= 0x00;
			report[7]= 0x00;
			USBD_HID_SendReport_EP1(&hUsbDeviceFS,report, 8 , 0x81); 		
			HAL_Delay(40);		
			report[0]= 0x00;
			report[1]= 0x00;
			report[2]= 0x00;
			report[3]= 0x00;
			report[4]= 0x00;
			report[5]= 0x00;
			report[6]= 0x00;
			report[7]= 0x00;
			USBD_HID_SendReport_EP1(&hUsbDeviceFS,report, 8 , 0x81); 
		  HAL_Delay(40);	
			for(int i = 0;i<8;i++)
			a[i]=0;
			
			//printf("a: %s \r\n",a);
			}
			
			else if(strcmp(a,d) == 0)
			{
			uint8_t report[8];
			report[0]= 0x00;
			report[1]= 0x00;
			report[2]= 0x4e;
			report[3]= 0x00;
			report[4]= 0x00;
			report[5]= 0x00;
			report[6]= 0x00;
			report[7]= 0x00;
			USBD_HID_SendReport_EP1(&hUsbDeviceFS,report, 8 , 0x81); 		
			HAL_Delay(40);		
			report[0]= 0x00;
			report[1]= 0x00;
			report[2]= 0x00;
			report[3]= 0x00;
			report[4]= 0x00;
			report[5]= 0x00;
			report[6]= 0x00;
			report[7]= 0x00;
			USBD_HID_SendReport_EP1(&hUsbDeviceFS,report, 8 , 0x81); 
      HAL_Delay(40);	
		  for(int i = 0;i<8;i++)
			a[i]=0;
			
			//printf("s: %s \r\n",a);
			}
			else if(strcmp(a,e) == 0)
			{
			uint8_t report[8];
			report[0]= 0x00;
			report[1]= 0x00;
			report[2]= 0x56;
			report[3]= 0x00;
			report[4]= 0x00;
			report[5]= 0x00;
			report[6]= 0x00;
			report[7]= 0x00;
			USBD_HID_SendReport_EP1(&hUsbDeviceFS,report, 8 , 0x81); 		
			HAL_Delay(40);		
			report[0]= 0x00;
			report[1]= 0x00;
			report[2]= 0x00;
			report[3]= 0x00;
			report[4]= 0x00;
			report[5]= 0x00;
			report[6]= 0x00;
			report[7]= 0x00;
			USBD_HID_SendReport_EP1(&hUsbDeviceFS,report, 8 , 0x81); 
      HAL_Delay(40);	
		  for(int i = 0;i<8;i++)
			a[i]=0;
			}
    else
		  {
			for(int i = 0;i<8;i++)
			a[i]=0;
		  }
    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}


static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 9600;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
}
/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL6;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USB;
  PeriphClkInit.UsbClockSelection = RCC_USBCLKSOURCE_PLL;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIOx;
  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

	GPIOx.Pin   = GPIO_PIN_0;
	GPIOx.Mode  = GPIO_MODE_INPUT;
  GPIOx.Pull  = GPIO_NOPULL;
	GPIOx.Speed = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(GPIOA,&GPIOx);
	
}

/* USER CODE BEGIN 4 */
/*uint8_t Key_Scan(uint8_t GPIO_Pin)

{			

	
	if(GPIO_Pin == KEY_ON )  
	{	 

		printf("key: %d \r\n",GPIO_Pin);
		uint8_t report[8];
    report[0]= 0x00;
    report[1]= 0x00;
    report[2]= 0x04;
		report[3]= 0x00;
		report[4]= 0x00;
		report[5]= 0x00;
		report[6]= 0x00;
		report[7]= 0x00;
    USBD_HID_SendReport_EP1(&hUsbDeviceFS,report, 8 , 0x81); 		
    HAL_Delay(30);		
    key = 0;		
		while(GPIO_Pin == KEY_ON)
		{
	
		}
		  
			return 	KEY_ON;	
			
	}
	else
	{
		key = 0;
		return KEY_OFF;
	}
}*/
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
