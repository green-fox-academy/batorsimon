 /**
  ******************************************************************************
  * @file    Templates/Src/main.c
  * @author  MCD Application Team
  * @version V1.0.3
  * @date    22-April-2016
  * @brief   STM32F7xx HAL API Template project
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT(c) 2016 STMicroelectronics</center></h2>
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/** @addtogroup STM32F7xx_HAL_Examples
  * @{
  */

/** @addtogroup Templates
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
static void SystemClock_Config(void);
static void Error_Handler(void);
static void MPU_Config(void);
static void CPU_CACHE_Enable(void);

/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Main program
  * @param  None
  * @retval None
  */

int main(void)
{

  /* This project template calls firstly two functions in order to configure MPU feature
     and to enable the CPU Cache, respectively MPU_Config() and CPU_CACHE_Enable().
     These functions are provided as template implementation that User may integrate
     in his application, to enhance the performance in case of use of AXI interface
     with several masters. */

  /* Configure the MPU attributes as Write Through */
  MPU_Config();

  /* Enable the CPU Cache */
  CPU_CACHE_Enable();

  /* STM32F7xx HAL library initialization:
       - Configure the Flash ART accelerator on ITCM interface
       - Configure the Systick to generate an interrupt each 1 msec
       - Set NVIC Group Priority to 4
       - Low Level Initialization
     */
  HAL_Init();

  /* Configure the System clock to have a frequency of 216 MHz */
  SystemClock_Config();


  /* Add your application code here     */
 // BSP_LED_Init(LED_GREEN);
 // BSP_LED_On(LED_GREEN);

		  __HAL_RCC_GPIOA_CLK_ENABLE();    // we need to enable the GPIOA port's clock first

		  GPIO_InitTypeDef tda;            // create a config structure
		  tda.Pin = GPIO_PIN_0;            // this is about PIN 0
		  tda.Mode = GPIO_MODE_OUTPUT_PP;  // Configure as output with push-up-down enabled
		  tda.Pull = GPIO_PULLDOWN;        // the push-up-down should work as pulldown
		  tda.Speed = GPIO_SPEED_HIGH;     // we need a high-speed output

		  HAL_GPIO_Init(GPIOA, &tda);      // initialize the pin on GPIOA port with HAL

		  __HAL_RCC_GPIOF_CLK_ENABLE();    //  GPIOF port's first use so we need to declare
		  GPIO_InitTypeDef tda1;
		   tda1.Pin = GPIO_PIN_10;
		   tda1.Mode = GPIO_MODE_OUTPUT_PP;
		   tda1.Pull = GPIO_PULLDOWN;
		   tda1.Speed = GPIO_SPEED_HIGH;

   	   	   HAL_GPIO_Init(GPIOF, &tda1);

   	   	  GPIO_InitTypeDef tda2;
   	   	  tda2.Pin = GPIO_PIN_9;
   	   	  tda2.Mode = GPIO_MODE_OUTPUT_PP;
      	  tda2.Pull = GPIO_PULLDOWN;
      	  tda2.Speed = GPIO_SPEED_HIGH;

      	  HAL_GPIO_Init(GPIOF, &tda2);

      	   GPIO_InitTypeDef tda3;
       	   tda3.Pin = GPIO_PIN_8;
       	   tda3.Mode = GPIO_MODE_OUTPUT_PP;
       	   tda3.Pull = GPIO_PULLDOWN;
       	   tda3.Speed = GPIO_SPEED_HIGH;

       	   HAL_GPIO_Init(GPIOF, &tda3);

       	   GPIO_InitTypeDef tda4;
       	   tda4.Pin = GPIO_PIN_7;
       	   tda4.Mode = GPIO_MODE_OUTPUT_PP;
       	   tda4.Pull = GPIO_PULLDOWN;
       	   tda4.Speed = GPIO_SPEED_HIGH;

       	  HAL_GPIO_Init(GPIOF, &tda4);

      	  GPIO_InitTypeDef tda5;
      	  tda5.Pin = GPIO_PIN_6;
      	  tda5.Mode = GPIO_MODE_OUTPUT_PP;
      	  tda5.Pull = GPIO_PULLDOWN;
      	  tda5.Speed = GPIO_SPEED_HIGH;

      	  HAL_GPIO_Init(GPIOF, &tda5);
      	  BSP_PB_Init(BUTTON_KEY, BUTTON_MODE_GPIO);

       // for the button,   button is in D00 -> pc7
       __HAL_RCC_GPIOC_CLK_ENABLE();

       	 GPIO_InitTypeDef tda6;
         tda6.Pin = GPIO_PIN_7;
         tda6.Mode = GPIO_MODE_INPUT;
         tda6.Pull = GPIO_PULLUP;
         tda6.Speed = GPIO_SPEED_HIGH;

         HAL_GPIO_Init(GPIOC, &tda6);

         GPIO_InitTypeDef tda7;
         tda7.Pin = GPIO_PIN_6;
         tda7.Mode = GPIO_MODE_INPUT;
         tda7.Pull = GPIO_PULLUP;
         tda7.Speed = GPIO_SPEED_HIGH;

        HAL_GPIO_Init(GPIOC, &tda7);

        __HAL_RCC_GPIOG_CLK_ENABLE();

        GPIO_InitTypeDef tda8;
        tda8.Pin = GPIO_PIN_6;
        tda8.Mode = GPIO_MODE_INPUT;
        tda8.Pull = GPIO_PULLUP;
        tda8.Speed = GPIO_SPEED_HIGH;

        HAL_GPIO_Init(GPIOG, &tda8);

        __HAL_RCC_GPIOB_CLK_ENABLE();

              GPIO_InitTypeDef tda9;
              tda9.Pin = GPIO_PIN_4;
              tda9.Mode = GPIO_MODE_INPUT;
              tda9.Pull = GPIO_PULLUP;
              tda9.Speed = GPIO_SPEED_HIGH;

              HAL_GPIO_Init(GPIOG, &tda9);

              //matrix     rows
              GPIO_InitTypeDef tda10;
              tda10.Pin = GPIO_PIN_8;
              tda10.Mode = GPIO_MODE_OUTPUT_PP;
              tda10.Pull = GPIO_PULLDOWN;
              tda10.Speed = GPIO_SPEED_HIGH;

              HAL_GPIO_Init(GPIOB, &tda10);

              GPIO_InitTypeDef tda11;
              tda11.Pin = GPIO_PIN_9;
              tda11.Mode = GPIO_MODE_OUTPUT_PP;
              tda11.Pull = GPIO_PULLDOWN;
              tda11.Speed = GPIO_SPEED_HIGH;

              HAL_GPIO_Init(GPIOB, &tda11);

             GPIO_InitTypeDef tda12;
             tda12.Pin = GPIO_PIN_14;
             tda12.Mode = GPIO_MODE_OUTPUT_PP;
             tda12.Pull = GPIO_PULLDOWN;
             tda12.Speed = GPIO_SPEED_HIGH;

             HAL_GPIO_Init(GPIOB, &tda12);

             __HAL_RCC_GPIOI_CLK_ENABLE();

             GPIO_InitTypeDef tda13;
             tda13.Pin = GPIO_PIN_1;
             tda13.Mode = GPIO_MODE_OUTPUT_PP;
             tda13.Pull = GPIO_PULLDOWN;
             tda13.Speed = GPIO_SPEED_HIGH;

             HAL_GPIO_Init(GPIOI, &tda13);

             GPIO_InitTypeDef tda14;
             tda14.Pin = GPIO_PIN_15;
             tda14.Mode = GPIO_MODE_OUTPUT_PP;
             tda14.Pull = GPIO_PULLDOWN;
              tda14.Speed = GPIO_SPEED_HIGH;

              HAL_GPIO_Init(GPIOB, &tda14);




              //matrix     columns
              GPIO_InitTypeDef tda15;
              tda15.Pin = GPIO_PIN_8;      // D10    PA8
          tda15.Mode = GPIO_MODE_OUTPUT_PP;
             tda15.Pull = GPIO_PULLDOWN;
             tda15.Speed = GPIO_SPEED_HIGH;

              HAL_GPIO_Init(GPIOA, &tda15);

                            GPIO_InitTypeDef tda16;
                       tda16.Pin = GPIO_PIN_15;    // D9   PA15
                   tda16.Mode = GPIO_MODE_OUTPUT_PP;
                    tda16.Pull = GPIO_PULLDOWN;
                       tda16.Speed = GPIO_SPEED_HIGH;

                     HAL_GPIO_Init(GPIOA, &tda16);


                         GPIO_InitTypeDef tda17;
                           tda17.Pin = GPIO_PIN_2;       // D8    PI2
                          tda17.Mode = GPIO_MODE_OUTPUT_PP;
                            tda17.Pull = GPIO_PULLDOWN;
                        tda17.Speed = GPIO_SPEED_HIGH;

                      HAL_GPIO_Init(GPIOI, &tda17);


                       GPIO_InitTypeDef tda18;
                           tda18.Pin = GPIO_PIN_3;     // D7    PI3
                           tda18.Mode = GPIO_MODE_OUTPUT_PP;
                         tda18.Pull = GPIO_PULLDOWN;
                         tda18.Speed = GPIO_SPEED_HIGH;

                          HAL_GPIO_Init(GPIOI, &tda18);

                          __HAL_RCC_GPIOH_CLK_ENABLE();

                         GPIO_InitTypeDef tda19;
                      tda19.Pin = GPIO_PIN_6;  // D6    PH6
                      tda19.Mode = GPIO_MODE_OUTPUT_PP;
                      tda19.Pull = GPIO_PULLDOWN;
                      tda19.Speed = GPIO_SPEED_HIGH;

                  HAL_GPIO_Init(GPIOH, &tda19);


                   GPIO_InitTypeDef tda20;
                   tda20.Pin = GPIO_PIN_0;   //  D5   PI0
                 tda20.Mode = GPIO_MODE_OUTPUT_PP;
                 tda20.Pull = GPIO_PULLDOWN;
              tda20.Speed = GPIO_SPEED_HIGH;

              HAL_GPIO_Init(GPIOI, &tda20);


              GPIO_InitTypeDef tda21;
             tda21.Pin = GPIO_PIN_7;    // D4    PG7
              tda21.Mode = GPIO_MODE_OUTPUT_PP;
              tda21.Pull = GPIO_PULLDOWN;
             tda21.Speed = GPIO_SPEED_HIGH;

                HAL_GPIO_Init(GPIOG, &tda21);


typedef struct{
	    GPIO_TypeDef *port;
		uint32_t pin;
} matrix;

         const matrix rows[] = {
              		{GPIOA, GPIO_PIN_8},     //row[0]
              		{GPIOA, GPIO_PIN_15},     //row[1]
					{GPIOI, GPIO_PIN_2},     //row[2]
					{GPIOI, GPIO_PIN_3},     //row[3]
              		{GPIOH, GPIO_PIN_6},     //row[4]
              		{GPIOI, GPIO_PIN_0},     //row[5]
              		{GPIOG, GPIO_PIN_7}      //row[6]
              };

           const matrix cols[] = {
              		{GPIOB, GPIO_PIN_14},    //col[0]
              		{GPIOB, GPIO_PIN_8},    //col[1]
              		{GPIOB, GPIO_PIN_9},     //col[2]
              		{GPIOB, GPIO_PIN_15},    //col[3]
              		{GPIOI, GPIO_PIN_1}      //col[4]
              };


                int one[5][7] = {
                   {0, 0, 0, 0, 0, 0, 1} ,
                   {0, 0, 0, 0, 0, 1, 1} ,
                   {0, 0, 0, 0, 1, 0, 1},
                   {0, 0, 0, 0, 0, 0, 1},
                   {0, 0, 0, 0, 0, 0, 1}
               };

                int two[5][7] = {
				   {0, 0, 0, 0, 1, 1, 1} ,
				   {0, 0, 0, 0, 0, 0, 1} ,
				   {0, 0, 0, 0, 1, 1, 1},
				   {0, 0, 0, 0, 1, 0, 0},
				   {0, 0, 0, 0, 1, 1, 1}
			   };


  /* Infinite loop */
  while (1)
  {

	  	  	  	  for(int i = 0; i < 13;  ){

	  	  	  		  if(i == 0){
	  	  	  			  	  for(int j = 0; j < 400;){

	  	  	  			  	//   number 0
	  	  	  			    				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_SET);   // 1.sor
	  	  	  			    				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_RESET);   // 2. SOR
	  	  	  			    				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_RESET);  // 3. sor
	  	  	  			    				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_RESET);  // 4. sor
	  	  	  			    				HAL_GPIO_WritePin(GPIOI, GPIO_PIN_1, GPIO_PIN_SET);     // 5. sor

	  	  	  			    				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET);   //   1. oszlop
	  	  	  			    				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);  //  2. oszlop
	  	  	  			    				HAL_GPIO_WritePin(GPIOI, GPIO_PIN_2, GPIO_PIN_SET);   //   3. oszlop
	  	  	  			    				HAL_GPIO_WritePin(GPIOI, GPIO_PIN_3, GPIO_PIN_SET);     //   4. oszlop
	  	  	  			    				HAL_GPIO_WritePin(GPIOH, GPIO_PIN_6, GPIO_PIN_RESET);  //   5. oszlop
	  	  	  			    				HAL_GPIO_WritePin(GPIOI, GPIO_PIN_0, GPIO_PIN_RESET);   //   6. oszlop
	  	  	  			    				HAL_GPIO_WritePin(GPIOG, GPIO_PIN_7, GPIO_PIN_RESET);   //   7. oszlop
	  	  	  			    				HAL_Delay(1);

	  	  	  			    				// 2 other leds
	  	  	  			    				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_SET);   // 1.sor
	  	  	  			  				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_SET);   // 2. SOR
	  	  	  			  				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_SET);  // 3. sor
	  	  	  			  				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_SET);  // 4. sor
	  	  	  			  				HAL_GPIO_WritePin(GPIOI, GPIO_PIN_1, GPIO_PIN_SET);     // 5. sor

	  	  	  			  				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET);   //   1. oszlop
	  	  	  			  				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);  //  2. oszlop
	  	  	  			  				HAL_GPIO_WritePin(GPIOI, GPIO_PIN_2, GPIO_PIN_SET);   //   3. oszlop
	  	  	  			  				HAL_GPIO_WritePin(GPIOI, GPIO_PIN_3, GPIO_PIN_SET);     //   4. oszlop
	  	  	  			  				HAL_GPIO_WritePin(GPIOH, GPIO_PIN_6, GPIO_PIN_RESET);  //   5. oszlop
	  	  	  			  				HAL_GPIO_WritePin(GPIOI, GPIO_PIN_0, GPIO_PIN_SET);   //   6. oszlop
	  	  	  			  				HAL_GPIO_WritePin(GPIOG, GPIO_PIN_7, GPIO_PIN_RESET);   //   7. oszlop
	  	  	  			  				HAL_Delay(1);

	  	  	  			  		  		  				j++;
	  	  	  		  	  	  	  	  	  	  	  }

	  	  	  			  		i++;
	  	  	  		  } else{
	  	  	  			  //continue;
	  	  	  			  break;
	  	  	  		  }

	  	  	  		  if(i==1){
	  	  	  			  	  for(int j = 0; j < 400;){

	  	  	  			  		  	  // 3 rows lighting
	  	  	  			  		  				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_SET);   // 1.sor
	  	  	  			  		  				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_SET);   // 2. SOR
	  	  	  			  		  				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_SET);  // 3. sor
	  	  	  			  		  				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_SET);  // 4. sor
	  	  	  			  		  				HAL_GPIO_WritePin(GPIOI, GPIO_PIN_1, GPIO_PIN_SET);     // 5. sor

	  	  	  			  		  				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET);   //   1. oszlop
	  	  	  			  		  				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);  //  2. oszlop
	  	  	  			  		  				HAL_GPIO_WritePin(GPIOI, GPIO_PIN_2, GPIO_PIN_SET);   //   3. oszlop
	  	  	  			  		  				HAL_GPIO_WritePin(GPIOI, GPIO_PIN_3, GPIO_PIN_SET);     //   4. oszlop
	  	  	  			  		  				HAL_GPIO_WritePin(GPIOH, GPIO_PIN_6, GPIO_PIN_SET);  //   5. oszlop
	  	  	  			  		  				HAL_GPIO_WritePin(GPIOI, GPIO_PIN_0, GPIO_PIN_SET);   //   6. oszlop
	  	  	  			  		  				HAL_GPIO_WritePin(GPIOG, GPIO_PIN_7, GPIO_PIN_RESET);   //   7. oszlop
	  	  	  			  		  				HAL_Delay(1);

	  	  	  			  		  				//other led
	  	  	  			  		  				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET);   // 1.sor
	  	  	  			  						HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_RESET);   // 2. SOR
	  	  	  			  						HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_RESET);  // 3. sor
	  	  	  			  						HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_SET);  // 4. sor
	  	  	  			  						HAL_GPIO_WritePin(GPIOI, GPIO_PIN_1, GPIO_PIN_RESET);     // 5. sor

	  	  	  			  						HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET);   //   1. oszlop
	  	  	  			  						HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);  //  2. oszlop
	  	  	  			  						HAL_GPIO_WritePin(GPIOI, GPIO_PIN_2, GPIO_PIN_SET);   //   3. oszlop
	  	  	  			  						HAL_GPIO_WritePin(GPIOI, GPIO_PIN_3, GPIO_PIN_SET);     //   4. oszlop
	  	  	  			  						HAL_GPIO_WritePin(GPIOH, GPIO_PIN_6, GPIO_PIN_SET);  //   5. oszlop
	  	  	  			  						HAL_GPIO_WritePin(GPIOI, GPIO_PIN_0, GPIO_PIN_RESET);   //   6. oszlop
	  	  	  			  						HAL_GPIO_WritePin(GPIOG, GPIO_PIN_7, GPIO_PIN_SET);   //   7. oszlop
	  	  	  			  						HAL_Delay(1);

	  	  	  			  						//other led2
	  	  	  			  		  				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET);   // 1.sor
	  	  	  			  						HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_RESET);   // 2. SOR
	  	  	  			  						HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_SET);  // 3. sor
	  	  	  			  						HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_RESET);  // 4. sor
	  	  	  			  						HAL_GPIO_WritePin(GPIOI, GPIO_PIN_1, GPIO_PIN_RESET);     // 5. sor

	  	  	  			  						HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET);   //   1. oszlop
	  	  	  			  						HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);  //  2. oszlop
	  	  	  			  						HAL_GPIO_WritePin(GPIOI, GPIO_PIN_2, GPIO_PIN_SET);   //   3. oszlop
	  	  	  			  						HAL_GPIO_WritePin(GPIOI, GPIO_PIN_3, GPIO_PIN_SET);     //   4. oszlop
	  	  	  			  						HAL_GPIO_WritePin(GPIOH, GPIO_PIN_6, GPIO_PIN_RESET);  //   5. oszlop
	  	  	  			  						HAL_GPIO_WritePin(GPIOI, GPIO_PIN_0, GPIO_PIN_SET);   //   6. oszlop
	  	  	  			  						HAL_GPIO_WritePin(GPIOG, GPIO_PIN_7, GPIO_PIN_SET);   //   7. oszlop
	  	  	  			  						HAL_Delay(1);

	  	  	  			  			  					j++;
	  	  	  			  	  }
	  	  	  			  	i++;
	  	  	  		  } else{
	  	  	  			  continue;
	  	  	  		  }

	  	  	  		  if(i==2){
	  	  	  			  	  for(int j = 0; j < 400;){

	  	  	  			  		  	  // 3 rows lighting
										HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_SET);   // 1.sor
										HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_RESET);   // 2. SOR
										HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_SET);  // 3. sor
										HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_RESET);  // 4. sor
										HAL_GPIO_WritePin(GPIOI, GPIO_PIN_1, GPIO_PIN_SET);     // 5. sor

										HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET);   //   1. oszlop
										HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);  //  2. oszlop
										HAL_GPIO_WritePin(GPIOI, GPIO_PIN_2, GPIO_PIN_SET);   //   3. oszlop
										HAL_GPIO_WritePin(GPIOI, GPIO_PIN_3, GPIO_PIN_SET);     //   4. oszlop
										HAL_GPIO_WritePin(GPIOH, GPIO_PIN_6, GPIO_PIN_RESET);  //   5. oszlop
										HAL_GPIO_WritePin(GPIOI, GPIO_PIN_0, GPIO_PIN_RESET);   //   6. oszlop
										HAL_GPIO_WritePin(GPIOG, GPIO_PIN_7, GPIO_PIN_RESET);   //   7. oszlop
										HAL_Delay(1);

	  	  	  			    				// 2 other leds
	  	  	  			    			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET);   // 1.sor
	  	  	  			  				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_SET);   // 2. SOR
	  	  	  			  				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_RESET);  // 3. sor
	  	  	  			  				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_RESET);  // 4. sor
	  	  	  			  				HAL_GPIO_WritePin(GPIOI, GPIO_PIN_1, GPIO_PIN_RESET);     // 5. sor

	  	  	  			  				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET);   //   1. oszlop
	  	  	  			  				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);  //  2. oszlop
	  	  	  			  				HAL_GPIO_WritePin(GPIOI, GPIO_PIN_2, GPIO_PIN_SET);   //   3. oszlop
	  	  	  			  				HAL_GPIO_WritePin(GPIOI, GPIO_PIN_3, GPIO_PIN_SET);     //   4. oszlop
	  	  	  			  				HAL_GPIO_WritePin(GPIOH, GPIO_PIN_6, GPIO_PIN_RESET);  //   5. oszlop
	  	  	  			  				HAL_GPIO_WritePin(GPIOI, GPIO_PIN_0, GPIO_PIN_SET);   //   6. oszlop
	  	  	  			  				HAL_GPIO_WritePin(GPIOG, GPIO_PIN_7, GPIO_PIN_SET);   //   7. oszlop
	  	  	  			  				HAL_Delay(1);

	  	  	  			  				//3.rd part
	  	  	  			  				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET);   // 1.sor
										HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_RESET);   // 2. SOR
										HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_RESET);  // 3. sor
										HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_SET);  // 4. sor
										HAL_GPIO_WritePin(GPIOI, GPIO_PIN_1, GPIO_PIN_RESET);     // 5. sor

										HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET);   //   1. oszlop
										HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);  //  2. oszlop
										HAL_GPIO_WritePin(GPIOI, GPIO_PIN_2, GPIO_PIN_SET);   //   3. oszlop
										HAL_GPIO_WritePin(GPIOI, GPIO_PIN_3, GPIO_PIN_SET);     //   4. oszlop
										HAL_GPIO_WritePin(GPIOH, GPIO_PIN_6, GPIO_PIN_SET);  //   5. oszlop
										HAL_GPIO_WritePin(GPIOI, GPIO_PIN_0, GPIO_PIN_SET);   //   6. oszlop
										HAL_GPIO_WritePin(GPIOG, GPIO_PIN_7, GPIO_PIN_RESET);   //   7. oszlop
										HAL_Delay(1);

	  	  	  			  	  	  			j++;
	  	  	  		  	  	    	  }
	  	  	  		  			 	 i++;

	  	  	  		  } else{
	  	  	  			  continue;
	  	  	  		  }

	  	  	  		  if(i == 3){
	  	  	  			  	  for(int j = 0; j < 400;){

	  	  	  			  	//   number 3 : 1.led
	  	  	  			    // 3 rows lighting
	  	  	  			  	  				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_SET);   // 1.sor
	  	  	  			  	  				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_RESET);   // 2. SOR
	  	  	  			  	  				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_SET);  // 3. sor
	  	  	  			  	  				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_RESET);  // 4. sor
	  	  	  			  	  				HAL_GPIO_WritePin(GPIOI, GPIO_PIN_1, GPIO_PIN_SET);     // 5. sor

	  	  	  			  	  				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET);   //   1. oszlop
	  	  	  			  	  				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);  //  2. oszlop
	  	  	  			  	  				HAL_GPIO_WritePin(GPIOI, GPIO_PIN_2, GPIO_PIN_SET);   //   3. oszlop
	  	  	  			  	  				HAL_GPIO_WritePin(GPIOI, GPIO_PIN_3, GPIO_PIN_SET);     //   4. oszlop
	  	  	  			  	  				HAL_GPIO_WritePin(GPIOH, GPIO_PIN_6, GPIO_PIN_RESET);  //   5. oszlop
	  	  	  			  	  				HAL_GPIO_WritePin(GPIOI, GPIO_PIN_0, GPIO_PIN_RESET);   //   6. oszlop
	  	  	  			  	  				HAL_GPIO_WritePin(GPIOG, GPIO_PIN_7, GPIO_PIN_RESET);   //   7. oszlop
	  	  	  			  	  				HAL_Delay(1);

	  	  	  			  	  				// 2 other leds
	  	  	  			  	  				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET);   // 1.sor
	  	  	  			  					HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_SET);   // 2. SOR
	  	  	  			  					HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_RESET);  // 3. sor
	  	  	  			  					HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_SET);  // 4. sor
	  	  	  			  					HAL_GPIO_WritePin(GPIOI, GPIO_PIN_1, GPIO_PIN_RESET);     // 5. sor

	  	  	  			  					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET);   //   1. oszlop
	  	  	  			  					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);  //  2. oszlop
	  	  	  			  					HAL_GPIO_WritePin(GPIOI, GPIO_PIN_2, GPIO_PIN_SET);   //   3. oszlop
	  	  	  			  					HAL_GPIO_WritePin(GPIOI, GPIO_PIN_3, GPIO_PIN_SET);     //   4. oszlop
	  	  	  			  					HAL_GPIO_WritePin(GPIOH, GPIO_PIN_6, GPIO_PIN_SET);  //   5. oszlop
	  	  	  			  					HAL_GPIO_WritePin(GPIOI, GPIO_PIN_0, GPIO_PIN_SET);   //   6. oszlop
	  	  	  			  					HAL_GPIO_WritePin(GPIOG, GPIO_PIN_7, GPIO_PIN_RESET);   //   7. oszlop
	  	  	  			  					HAL_Delay(1);


	  	  	  			  	  	  	j++;
	  	  	  		  	  	  	  }
	  	  	  			  	  i++;

	  	  	  		  } else{
	  	  	  			  continue;
	  	  	  		  }

	  	  	  		  if(i==4){
	  	  	  			  	  for(int j = 0; j < 400;){

	  	  	  			  		  	  	  	  // 3 rows lighting
	  	  	  			  		  				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_SET);   // 1.sor
	  	  	  			  		  				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_SET);   // 2. SOR
	  	  	  			  		  				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_SET);  // 3. sor
	  	  	  			  		  				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_SET);  // 4. sor
	  	  	  			  		  				HAL_GPIO_WritePin(GPIOI, GPIO_PIN_1, GPIO_PIN_SET);     // 5. sor

	  	  	  			  		  				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET);   //   1. oszlop
	  	  	  			  		  				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);  //  2. oszlop
	  	  	  			  		  				HAL_GPIO_WritePin(GPIOI, GPIO_PIN_2, GPIO_PIN_SET);   //   3. oszlop
	  	  	  			  		  				HAL_GPIO_WritePin(GPIOI, GPIO_PIN_3, GPIO_PIN_SET);     //   4. oszlop
	  	  	  			  		  				HAL_GPIO_WritePin(GPIOH, GPIO_PIN_6, GPIO_PIN_SET);  //   5. oszlop
	  	  	  			  		  				HAL_GPIO_WritePin(GPIOI, GPIO_PIN_0, GPIO_PIN_SET);   //   6. oszlop
	  	  	  			  		  				HAL_GPIO_WritePin(GPIOG, GPIO_PIN_7, GPIO_PIN_RESET);   //   7. oszlop
	  	  	  			  		  				HAL_Delay(1);

	  	  	  			  		  				//other led
	  	  	  			  		  				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET);   // 1.sor
	  	  	  			  						HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_RESET);   // 2. SOR
	  	  	  			  						HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_SET);  // 3. sor
	  	  	  			  						HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_SET);  // 4. sor
	  	  	  			  						HAL_GPIO_WritePin(GPIOI, GPIO_PIN_1, GPIO_PIN_SET);     // 5. sor

	  	  	  			  						HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET);   //   1. oszlop
	  	  	  			  						HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);  //  2. oszlop
	  	  	  			  						HAL_GPIO_WritePin(GPIOI, GPIO_PIN_2, GPIO_PIN_SET);   //   3. oszlop
	  	  	  			  						HAL_GPIO_WritePin(GPIOI, GPIO_PIN_3, GPIO_PIN_SET);     //   4. oszlop
	  	  	  			  						HAL_GPIO_WritePin(GPIOH, GPIO_PIN_6, GPIO_PIN_RESET);  //   5. oszlop
	  	  	  			  						HAL_GPIO_WritePin(GPIOI, GPIO_PIN_0, GPIO_PIN_SET);   //   6. oszlop
	  	  	  			  						HAL_GPIO_WritePin(GPIOG, GPIO_PIN_7, GPIO_PIN_SET);   //   7. oszlop
	  	  	  			  						HAL_Delay(1);

	  	  	  			  						//other led2
	  	  	  			  		  				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET);   // 1.sor
	  	  	  			  						HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_RESET);   // 2. SOR
	  	  	  			  						HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_SET);  // 3. sor
	  	  	  			  						HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_RESET);  // 4. sor
	  	  	  			  						HAL_GPIO_WritePin(GPIOI, GPIO_PIN_1, GPIO_PIN_RESET);     // 5. sor

	  	  	  			  						HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET);   //   1. oszlop
	  	  	  			  						HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);  //  2. oszlop
	  	  	  			  						HAL_GPIO_WritePin(GPIOI, GPIO_PIN_2, GPIO_PIN_SET);   //   3. oszlop
	  	  	  			  						HAL_GPIO_WritePin(GPIOI, GPIO_PIN_3, GPIO_PIN_SET);     //   4. oszlop
	  	  	  			  						HAL_GPIO_WritePin(GPIOH, GPIO_PIN_6, GPIO_PIN_SET);  //   5. oszlop
	  	  	  			  						HAL_GPIO_WritePin(GPIOI, GPIO_PIN_0, GPIO_PIN_RESET);   //   6. oszlop
	  	  	  			  						HAL_GPIO_WritePin(GPIOG, GPIO_PIN_7, GPIO_PIN_SET);   //   7. oszlop
	  	  	  			  						HAL_Delay(1);

	  	  	  			  	  	  j++;
	  	  	  		  	  	  	  }
	  	  	  			  	  i++;

	  	  	  		  } else{
	  	  	  			  continue;
	  	  	  		  }

	  	  	  		  if(i==5){
  	  	  			  	  for(int j = 0; j < 400;){

  	  	  	  	  	  	  // 3 rows lighting
  	  	  				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_SET);   // 1.sor
  	  	  				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_RESET);   // 2. SOR
  	  	  				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_SET);  // 3. sor
  	  	  				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_RESET);  // 4. sor
  	  	  				HAL_GPIO_WritePin(GPIOI, GPIO_PIN_1, GPIO_PIN_SET);     // 5. sor

  	  	  				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET);   //   1. oszlop
  	  	  				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);  //  2. oszlop
  	  	  				HAL_GPIO_WritePin(GPIOI, GPIO_PIN_2, GPIO_PIN_SET);   //   3. oszlop
  	  	  				HAL_GPIO_WritePin(GPIOI, GPIO_PIN_3, GPIO_PIN_SET);     //   4. oszlop
  	  	  				HAL_GPIO_WritePin(GPIOH, GPIO_PIN_6, GPIO_PIN_RESET);  //   5. oszlop
  	  	  				HAL_GPIO_WritePin(GPIOI, GPIO_PIN_0, GPIO_PIN_RESET);   //   6. oszlop
  	  	  				HAL_GPIO_WritePin(GPIOG, GPIO_PIN_7, GPIO_PIN_RESET);   //   7. oszlop
  	  	  				HAL_Delay(1);

  	  	  				// 2 other leds
  	  	  				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET);   // 1.sor
  	  					HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_RESET);   // 2. SOR
  	  					HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_RESET);  // 3. sor
  	  					HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_SET);  // 4. sor
  	  					HAL_GPIO_WritePin(GPIOI, GPIO_PIN_1, GPIO_PIN_RESET);     // 5. sor

  	  					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET);   //   1. oszlop
  	  					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);  //  2. oszlop
  	  					HAL_GPIO_WritePin(GPIOI, GPIO_PIN_2, GPIO_PIN_SET);   //   3. oszlop
  	  					HAL_GPIO_WritePin(GPIOI, GPIO_PIN_3, GPIO_PIN_SET);     //   4. oszlop
  	  					HAL_GPIO_WritePin(GPIOH, GPIO_PIN_6, GPIO_PIN_RESET);  //   5. oszlop
  	  					HAL_GPIO_WritePin(GPIOI, GPIO_PIN_0, GPIO_PIN_SET);   //   6. oszlop
  	  					HAL_GPIO_WritePin(GPIOG, GPIO_PIN_7, GPIO_PIN_SET);   //   7. oszlop
  	  					HAL_Delay(1);

  	  					//3.rd part
  	  					HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET);   // 1.sor
  	  									HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_SET);   // 2. SOR
  	  									HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_RESET);  // 3. sor
  	  									HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_RESET);  // 4. sor
  	  									HAL_GPIO_WritePin(GPIOI, GPIO_PIN_1, GPIO_PIN_RESET);     // 5. sor

  	  									HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET);   //   1. oszlop
  	  									HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);  //  2. oszlop
  	  									HAL_GPIO_WritePin(GPIOI, GPIO_PIN_2, GPIO_PIN_SET);   //   3. oszlop
  	  									HAL_GPIO_WritePin(GPIOI, GPIO_PIN_3, GPIO_PIN_SET);     //   4. oszlop
  	  									HAL_GPIO_WritePin(GPIOH, GPIO_PIN_6, GPIO_PIN_SET);  //   5. oszlop
  	  									HAL_GPIO_WritePin(GPIOI, GPIO_PIN_0, GPIO_PIN_SET);   //   6. oszlop
  	  									HAL_GPIO_WritePin(GPIOG, GPIO_PIN_7, GPIO_PIN_RESET);   //   7. oszlop
  	  									HAL_Delay(1);

  	  	  			  	  	  j++;
  	  	  		  	  	  	  }
  	  	  			  	  	  i++;

	  	  	  		  } else{
	  	  	  			  continue;
	  	  	  		  }

	  	  	  		  if(i==6){
  	  	  			  	  for(int j = 0; j < 400;){

  	  	  			    // 3 rows lighting
  	  	  			  	  				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_SET);   // 1.sor
  	  	  			  	  				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_RESET);   // 2. SOR
  	  	  			  	  				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_SET);  // 3. sor
  	  	  			  	  				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_RESET);  // 4. sor
  	  	  			  	  				HAL_GPIO_WritePin(GPIOI, GPIO_PIN_1, GPIO_PIN_SET);     // 5. sor

  	  	  			  	  				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET);   //   1. oszlop
  	  	  			  	  				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);  //  2. oszlop
  	  	  			  	  				HAL_GPIO_WritePin(GPIOI, GPIO_PIN_2, GPIO_PIN_SET);   //   3. oszlop
  	  	  			  	  				HAL_GPIO_WritePin(GPIOI, GPIO_PIN_3, GPIO_PIN_SET);     //   4. oszlop
  	  	  			  	  				HAL_GPIO_WritePin(GPIOH, GPIO_PIN_6, GPIO_PIN_RESET);  //   5. oszlop
  	  	  			  	  				HAL_GPIO_WritePin(GPIOI, GPIO_PIN_0, GPIO_PIN_RESET);   //   6. oszlop
  	  	  			  	  				HAL_GPIO_WritePin(GPIOG, GPIO_PIN_7, GPIO_PIN_RESET);   //   7. oszlop
  	  	  			  	  				HAL_Delay(1);

  	  	  			  	  				// 2 other leds
  	  	  			  	  				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET);   // 1.sor
  	  	  			  					HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_RESET);   // 2. SOR
  	  	  			  					HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_RESET);  // 3. sor
  	  	  			  					HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_SET);  // 4. sor
  	  	  			  					HAL_GPIO_WritePin(GPIOI, GPIO_PIN_1, GPIO_PIN_RESET);     // 5. sor

  	  	  			  					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET);   //   1. oszlop
  	  	  			  					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);  //  2. oszlop
  	  	  			  					HAL_GPIO_WritePin(GPIOI, GPIO_PIN_2, GPIO_PIN_SET);   //   3. oszlop
  	  	  			  					HAL_GPIO_WritePin(GPIOI, GPIO_PIN_3, GPIO_PIN_SET);     //   4. oszlop
  	  	  			  					HAL_GPIO_WritePin(GPIOH, GPIO_PIN_6, GPIO_PIN_RESET);  //   5. oszlop
  	  	  			  					HAL_GPIO_WritePin(GPIOI, GPIO_PIN_0, GPIO_PIN_SET);   //   6. oszlop
  	  	  			  					HAL_GPIO_WritePin(GPIOG, GPIO_PIN_7, GPIO_PIN_SET);   //   7. oszlop
  	  	  			  					HAL_Delay(1);

  	  	  			  					//3.rd part
  	  	  			  					HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET);   // 1.sor
  	  	  			  									HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_SET);   // 2. SOR
  	  	  			  									HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_RESET);  // 3. sor
  	  	  			  									HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_RESET);  // 4. sor
  	  	  			  									HAL_GPIO_WritePin(GPIOI, GPIO_PIN_1, GPIO_PIN_RESET);     // 5. sor

  	  	  			  									HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET);   //   1. oszlop
  	  	  			  									HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);  //  2. oszlop
  	  	  			  									HAL_GPIO_WritePin(GPIOI, GPIO_PIN_2, GPIO_PIN_SET);   //   3. oszlop
  	  	  			  									HAL_GPIO_WritePin(GPIOI, GPIO_PIN_3, GPIO_PIN_SET);     //   4. oszlop
  	  	  			  									HAL_GPIO_WritePin(GPIOH, GPIO_PIN_6, GPIO_PIN_RESET);  //   5. oszlop
  	  	  			  									HAL_GPIO_WritePin(GPIOI, GPIO_PIN_0, GPIO_PIN_SET);   //   6. oszlop
  	  	  			  									HAL_GPIO_WritePin(GPIOG, GPIO_PIN_7, GPIO_PIN_RESET);   //   7. oszlop
  	  	  			  									HAL_Delay(1);


  	  	  			  	  	  j++;
  	  	  		  	  	  	  }
  	  	  			  	  	  i++;

	  	  	  		  } else{
	  	  	  			  continue;
	  	  	  		  }

	  	  	  		  if(i==7){
  	  	  			  	  for(int j = 0; j < 400;){

  	  	  			  	  // 3 rows lighting
  	  	  				  				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_SET);   // 1.sor
  	  	  				  				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_SET);   // 2. SOR
  	  	  				  				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_SET);  // 3. sor
  	  	  				  				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_SET);  // 4. sor
  	  	  				  				HAL_GPIO_WritePin(GPIOI, GPIO_PIN_1, GPIO_PIN_SET);     // 5. sor

  	  	  				  				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET);   //   1. oszlop
  	  	  				  				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);  //  2. oszlop
  	  	  				  				HAL_GPIO_WritePin(GPIOI, GPIO_PIN_2, GPIO_PIN_SET);   //   3. oszlop
  	  	  				  				HAL_GPIO_WritePin(GPIOI, GPIO_PIN_3, GPIO_PIN_SET);     //   4. oszlop
  	  	  				  				HAL_GPIO_WritePin(GPIOH, GPIO_PIN_6, GPIO_PIN_SET);  //   5. oszlop
  	  	  				  				HAL_GPIO_WritePin(GPIOI, GPIO_PIN_0, GPIO_PIN_SET);   //   6. oszlop
  	  	  				  				HAL_GPIO_WritePin(GPIOG, GPIO_PIN_7, GPIO_PIN_RESET);   //   7. oszlop
  	  	  				  				HAL_Delay(1);

  	  	  				  				//other led
  	  	  				  				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET);   // 1.sor
  	  	  								HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_RESET);   // 2. SOR
  	  	  								HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_SET);  // 3. sor
  	  	  								HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_SET);  // 4. sor
  	  	  								HAL_GPIO_WritePin(GPIOI, GPIO_PIN_1, GPIO_PIN_SET);     // 5. sor

  	  	  								HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET);   //   1. oszlop
  	  	  								HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);  //  2. oszlop
  	  	  								HAL_GPIO_WritePin(GPIOI, GPIO_PIN_2, GPIO_PIN_SET);   //   3. oszlop
  	  	  								HAL_GPIO_WritePin(GPIOI, GPIO_PIN_3, GPIO_PIN_SET);     //   4. oszlop
  	  	  								HAL_GPIO_WritePin(GPIOH, GPIO_PIN_6, GPIO_PIN_RESET);  //   5. oszlop
  	  	  								HAL_GPIO_WritePin(GPIOI, GPIO_PIN_0, GPIO_PIN_SET);   //   6. oszlop
  	  	  								HAL_GPIO_WritePin(GPIOG, GPIO_PIN_7, GPIO_PIN_SET);   //   7. oszlop
  	  	  								HAL_Delay(1);

  	  	  								//other led2
  	  	  				  				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET);   // 1.sor
  	  	  								HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_RESET);   // 2. SOR
  	  	  								HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_RESET);  // 3. sor
  	  	  								HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_RESET);  // 4. sor
  	  	  								HAL_GPIO_WritePin(GPIOI, GPIO_PIN_1, GPIO_PIN_SET);     // 5. sor

  	  	  								HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET);   //   1. oszlop
  	  	  								HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);  //  2. oszlop
  	  	  								HAL_GPIO_WritePin(GPIOI, GPIO_PIN_2, GPIO_PIN_SET);   //   3. oszlop
  	  	  								HAL_GPIO_WritePin(GPIOI, GPIO_PIN_3, GPIO_PIN_SET);     //   4. oszlop
  	  	  								HAL_GPIO_WritePin(GPIOH, GPIO_PIN_6, GPIO_PIN_SET);  //   5. oszlop
  	  	  								HAL_GPIO_WritePin(GPIOI, GPIO_PIN_0, GPIO_PIN_RESET);   //   6. oszlop
  	  	  								HAL_GPIO_WritePin(GPIOG, GPIO_PIN_7, GPIO_PIN_SET);   //   7. oszlop
  	  	  								HAL_Delay(1);

  	  	  			  	  	  j++;
  	  	  		  	  	  	  }
  	  	  			  	  	  i++;

	  	  	  		  } else{
	  	  	  			  continue;
	  	  	  		  }

	  	  	  		  if(i==8){
  	  	  			  	  for(int j = 0; j < 400;){

  	  	  			  	 // 3 rows lighting
  	  	  			  	  				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_SET);   // 1.sor
  	  	  			  	  				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_RESET);   // 2. SOR
  	  	  			  	  				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_SET);  // 3. sor
  	  	  			  	  				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_RESET);  // 4. sor
  	  	  			  	  				HAL_GPIO_WritePin(GPIOI, GPIO_PIN_1, GPIO_PIN_SET);     // 5. sor

  	  	  			  	  				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET);   //   1. oszlop
  	  	  			  	  				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);  //  2. oszlop
  	  	  			  	  				HAL_GPIO_WritePin(GPIOI, GPIO_PIN_2, GPIO_PIN_SET);   //   3. oszlop
  	  	  			  	  				HAL_GPIO_WritePin(GPIOI, GPIO_PIN_3, GPIO_PIN_SET);     //   4. oszlop
  	  	  			  	  				HAL_GPIO_WritePin(GPIOH, GPIO_PIN_6, GPIO_PIN_RESET);  //   5. oszlop
  	  	  			  	  				HAL_GPIO_WritePin(GPIOI, GPIO_PIN_0, GPIO_PIN_RESET);   //   6. oszlop
  	  	  			  	  				HAL_GPIO_WritePin(GPIOG, GPIO_PIN_7, GPIO_PIN_RESET);   //   7. oszlop
  	  	  			  	  				HAL_Delay(1);

  	  	  			  	  				// 2 other leds
  	  	  			  	  				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET);   // 1.sor
  	  	  			  					HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_SET);   // 2. SOR
  	  	  			  					HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_RESET);  // 3. sor
  	  	  			  					HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_SET);  // 4. sor
  	  	  			  					HAL_GPIO_WritePin(GPIOI, GPIO_PIN_1, GPIO_PIN_RESET);     // 5. sor

  	  	  			  					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET);   //   1. oszlop
  	  	  			  					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);  //  2. oszlop
  	  	  			  					HAL_GPIO_WritePin(GPIOI, GPIO_PIN_2, GPIO_PIN_SET);   //   3. oszlop
  	  	  			  					HAL_GPIO_WritePin(GPIOI, GPIO_PIN_3, GPIO_PIN_SET);     //   4. oszlop
  	  	  			  					HAL_GPIO_WritePin(GPIOH, GPIO_PIN_6, GPIO_PIN_RESET);  //   5. oszlop
  	  	  			  					HAL_GPIO_WritePin(GPIOI, GPIO_PIN_0, GPIO_PIN_SET);   //   6. oszlop
  	  	  			  					HAL_GPIO_WritePin(GPIOG, GPIO_PIN_7, GPIO_PIN_RESET);   //   7. oszlop
  	  	  			  					HAL_Delay(1);

  	  	  			  					j++;
  	  	  		  	  	  	  }
  	  	  			  	  	  i++;

	  	  	  		  } else{
	  	  	  			  continue;
	  	  	  		  }

	  	  	  		  if(i==9){
  	  	  			  	  for(int j = 0; j < 400;){
  	  	  				  // 3 rows lighting
  	  	  				  				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_SET);   // 1.sor
  	  	  				  				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_RESET);   // 2. SOR
  	  	  				  				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_SET);  // 3. sor
  	  	  				  				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_RESET);  // 4. sor
  	  	  				  				HAL_GPIO_WritePin(GPIOI, GPIO_PIN_1, GPIO_PIN_SET);     // 5. sor

  	  	  				  				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET);   //   1. oszlop
  	  	  				  				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);  //  2. oszlop
  	  	  				  				HAL_GPIO_WritePin(GPIOI, GPIO_PIN_2, GPIO_PIN_SET);   //   3. oszlop
  	  	  				  				HAL_GPIO_WritePin(GPIOI, GPIO_PIN_3, GPIO_PIN_SET);     //   4. oszlop
  	  	  				  				HAL_GPIO_WritePin(GPIOH, GPIO_PIN_6, GPIO_PIN_RESET);  //   5. oszlop
  	  	  				  				HAL_GPIO_WritePin(GPIOI, GPIO_PIN_0, GPIO_PIN_RESET);   //   6. oszlop
  	  	  				  				HAL_GPIO_WritePin(GPIOG, GPIO_PIN_7, GPIO_PIN_RESET);   //   7. oszlop
  	  	  				  				HAL_Delay(1);

  	  	  				  				// 2 other leds
  	  	  				  				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET);   // 1.sor
  	  	  								HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_SET);   // 2. SOR
  	  	  								HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_RESET);  // 3. sor
  	  	  								HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_RESET);  // 4. sor
  	  	  								HAL_GPIO_WritePin(GPIOI, GPIO_PIN_1, GPIO_PIN_RESET);     // 5. sor

  	  	  								HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET);   //   1. oszlop
  	  	  								HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);  //  2. oszlop
  	  	  								HAL_GPIO_WritePin(GPIOI, GPIO_PIN_2, GPIO_PIN_SET);   //   3. oszlop
  	  	  								HAL_GPIO_WritePin(GPIOI, GPIO_PIN_3, GPIO_PIN_SET);     //   4. oszlop
  	  	  								HAL_GPIO_WritePin(GPIOH, GPIO_PIN_6, GPIO_PIN_SET);  //   5. oszlop
  	  	  								HAL_GPIO_WritePin(GPIOI, GPIO_PIN_0, GPIO_PIN_SET);   //   6. oszlop
  	  	  								HAL_GPIO_WritePin(GPIOG, GPIO_PIN_7, GPIO_PIN_RESET);   //   7. oszlop
  	  	  								HAL_Delay(1);

  	  	  								//3.rd part
  	  	  								HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET);   // 1.sor
										HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_RESET);   // 2. SOR
										HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_RESET);  // 3. sor
										HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_SET);  // 4. sor
										HAL_GPIO_WritePin(GPIOI, GPIO_PIN_1, GPIO_PIN_RESET);     // 5. sor

										HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET);   //   1. oszlop
										HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);  //  2. oszlop
										HAL_GPIO_WritePin(GPIOI, GPIO_PIN_2, GPIO_PIN_SET);   //   3. oszlop
										HAL_GPIO_WritePin(GPIOI, GPIO_PIN_3, GPIO_PIN_SET);     //   4. oszlop
										HAL_GPIO_WritePin(GPIOH, GPIO_PIN_6, GPIO_PIN_RESET);  //   5. oszlop
										HAL_GPIO_WritePin(GPIOI, GPIO_PIN_0, GPIO_PIN_SET);   //   6. oszlop
										HAL_GPIO_WritePin(GPIOG, GPIO_PIN_7, GPIO_PIN_RESET);   //   7. oszlop
										HAL_Delay(1);


  	  	  			  	  	  j++;
  	  	  		  	  	  	  }
  	  	  			  	  	  i++;

	  	  	  		  } else{
	  	  	  			  continue;
	  	  	  		  }

	  	  	  		  if(i==10){
  	  	  			  	  for(int j = 0; j < 200;){

  	  	  			  	  //Number 10
  	  	  				  //   number 1 : 1.led
  	  	  				  	  				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_SET);   // 1.sor
  	  	  				  	  				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_SET);   // 2. SOR
  	  	  				  	  				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_SET);  // 3. sor
  	  	  				  	  				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_SET);  // 4. sor
  	  	  				  	  				HAL_GPIO_WritePin(GPIOI, GPIO_PIN_1, GPIO_PIN_SET);     // 5. sor

  	  	  				  	  				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET);   //   1. oszlop
  	  	  				  	  				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);  //  2. oszlop
  	  	  				  	  				HAL_GPIO_WritePin(GPIOI, GPIO_PIN_2, GPIO_PIN_RESET);   //   3. oszlop
  	  	  				  	  				HAL_GPIO_WritePin(GPIOI, GPIO_PIN_3, GPIO_PIN_SET);     //   4. oszlop
  	  	  				  	  				HAL_GPIO_WritePin(GPIOH, GPIO_PIN_6, GPIO_PIN_SET);  //   5. oszlop
  	  	  				  	  				HAL_GPIO_WritePin(GPIOI, GPIO_PIN_0, GPIO_PIN_SET);   //   6. oszlop
  	  	  				  	  				HAL_GPIO_WritePin(GPIOG, GPIO_PIN_7, GPIO_PIN_SET);   //   7. oszlop
  	  	  				  	  				HAL_Delay(1);

  	  	  				  	  				//other led
  	  	  				  	  				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET);   // 1.sor
  	  	  				  					HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_RESET);   // 2. SOR
  	  	  				  					HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_RESET);  // 3. sor
  	  	  				  					HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_SET);  // 4. sor
  	  	  				  					HAL_GPIO_WritePin(GPIOI, GPIO_PIN_1, GPIO_PIN_RESET);     // 5. sor

  	  	  				  					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET);   //   1. oszlop
  	  	  				  					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_RESET);  //  2. oszlop
  	  	  				  					HAL_GPIO_WritePin(GPIOI, GPIO_PIN_2, GPIO_PIN_SET);   //   3. oszlop
  	  	  				  					HAL_GPIO_WritePin(GPIOI, GPIO_PIN_3, GPIO_PIN_SET);     //   4. oszlop
  	  	  				  					HAL_GPIO_WritePin(GPIOH, GPIO_PIN_6, GPIO_PIN_SET);  //   5. oszlop
  	  	  				  					HAL_GPIO_WritePin(GPIOI, GPIO_PIN_0, GPIO_PIN_SET);   //   6. oszlop
  	  	  				  					HAL_GPIO_WritePin(GPIOG, GPIO_PIN_7, GPIO_PIN_SET);   //   7. oszlop
  	  	  				  					HAL_Delay(1);

  	  	  				  					//other led2
  	  	  				  	  				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET);   // 1.sor
  	  	  				  					HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_RESET);   // 2. SOR
  	  	  				  					HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_SET);  // 3. sor
  	  	  				  					HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_RESET);  // 4. sor
  	  	  				  					HAL_GPIO_WritePin(GPIOI, GPIO_PIN_1, GPIO_PIN_RESET);     // 5. sor

  	  	  				  					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET);   //   1. oszlop
  	  	  				  					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);  //  2. oszlop
  	  	  				  					HAL_GPIO_WritePin(GPIOI, GPIO_PIN_2, GPIO_PIN_SET);   //   3. oszlop
  	  	  				  					HAL_GPIO_WritePin(GPIOI, GPIO_PIN_3, GPIO_PIN_SET);     //   4. oszlop
  	  	  				  					HAL_GPIO_WritePin(GPIOH, GPIO_PIN_6, GPIO_PIN_SET);  //   5. oszlop
  	  	  				  					HAL_GPIO_WritePin(GPIOI, GPIO_PIN_0, GPIO_PIN_SET);   //   6. oszlop
  	  	  				  					HAL_GPIO_WritePin(GPIOG, GPIO_PIN_7, GPIO_PIN_SET);   //   7. oszlop
  	  	  				  					HAL_Delay(1);


  	  	  				  //   number 0 : 1.led

  	  	  			  // 3 rows lighting
  	  	  			  				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_SET);   // 1.sor
  	  	  			  				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_RESET);   // 2. SOR
  	  	  			  				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_RESET);  // 3. sor
  	  	  			  				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_RESET);  // 4. sor
  	  	  			  				HAL_GPIO_WritePin(GPIOI, GPIO_PIN_1, GPIO_PIN_SET);     // 5. sor

  	  	  			  				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET);   //   1. oszlop
  	  	  			  				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);  //  2. oszlop
  	  	  			  				HAL_GPIO_WritePin(GPIOI, GPIO_PIN_2, GPIO_PIN_SET);   //   3. oszlop
  	  	  			  				HAL_GPIO_WritePin(GPIOI, GPIO_PIN_3, GPIO_PIN_SET);     //   4. oszlop
  	  	  			  				HAL_GPIO_WritePin(GPIOH, GPIO_PIN_6, GPIO_PIN_RESET);  //   5. oszlop
  	  	  			  				HAL_GPIO_WritePin(GPIOI, GPIO_PIN_0, GPIO_PIN_RESET);   //   6. oszlop
  	  	  			  				HAL_GPIO_WritePin(GPIOG, GPIO_PIN_7, GPIO_PIN_RESET);   //   7. oszlop
  	  	  			  				HAL_Delay(1);

  	  	  			  				// 2 other leds
  	  	  			  				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_SET);   // 1.sor
  	  	  							HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_SET);   // 2. SOR
  	  	  							HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_SET);  // 3. sor
  	  	  							HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_SET);  // 4. sor
  	  	  							HAL_GPIO_WritePin(GPIOI, GPIO_PIN_1, GPIO_PIN_SET);     // 5. sor

  	  	  							HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET);   //   1. oszlop
  	  	  							HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);  //  2. oszlop
  	  	  							HAL_GPIO_WritePin(GPIOI, GPIO_PIN_2, GPIO_PIN_SET);   //   3. oszlop
  	  	  							HAL_GPIO_WritePin(GPIOI, GPIO_PIN_3, GPIO_PIN_SET);     //   4. oszlop
  	  	  							HAL_GPIO_WritePin(GPIOH, GPIO_PIN_6, GPIO_PIN_RESET);  //   5. oszlop
  	  	  							HAL_GPIO_WritePin(GPIOI, GPIO_PIN_0, GPIO_PIN_SET);   //   6. oszlop
  	  	  							HAL_GPIO_WritePin(GPIOG, GPIO_PIN_7, GPIO_PIN_RESET);   //   7. oszlop
  	  	  							HAL_Delay(1);





  	  	  			  	  	  j++;
  	  	  		  	  	  	  }
  	   	  	  			  	i++;

	  	  	  		  } else{
	  	  	  			  continue;
	  	  	  		  }

	  	  	  		  if(i==11){
  	  	  			  	  for(int j = 0; j < 200;){


  	  	  			  	// number 11
  	  	  			  	//   number 1 : 1.led
  	  	  			  	  	  	  				  	  				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_SET);   // 1.sor
  	  	  			  	  	  	  				  	  				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_SET);   // 2. SOR
  	  	  			  	  	  	  				  	  				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_SET);  // 3. sor
  	  	  			  	  	  	  				  	  				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_SET);  // 4. sor
  	  	  			  	  	  	  				  	  				HAL_GPIO_WritePin(GPIOI, GPIO_PIN_1, GPIO_PIN_SET);     // 5. sor

  	  	  			  	  	  	  				  	  				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET);   //   1. oszlop
  	  	  			  	  	  	  				  	  				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);  //  2. oszlop
  	  	  			  	  	  	  				  	  				HAL_GPIO_WritePin(GPIOI, GPIO_PIN_2, GPIO_PIN_RESET);   //   3. oszlop
  	  	  			  	  	  	  				  	  				HAL_GPIO_WritePin(GPIOI, GPIO_PIN_3, GPIO_PIN_SET);     //   4. oszlop
  	  	  			  	  	  	  				  	  				HAL_GPIO_WritePin(GPIOH, GPIO_PIN_6, GPIO_PIN_SET);  //   5. oszlop
  	  	  			  	  	  	  				  	  				HAL_GPIO_WritePin(GPIOI, GPIO_PIN_0, GPIO_PIN_SET);   //   6. oszlop
  	  	  			  	  	  	  				  	  				HAL_GPIO_WritePin(GPIOG, GPIO_PIN_7, GPIO_PIN_SET);   //   7. oszlop
  	  	  			  	  	  	  				  	  				HAL_Delay(1);

  	  	  			  	  	  	  				  	  				//other led
  	  	  			  	  	  	  				  	  				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET);   // 1.sor
  	  	  			  	  	  	  				  					HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_RESET);   // 2. SOR
  	  	  			  	  	  	  				  					HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_RESET);  // 3. sor
  	  	  			  	  	  	  				  					HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_SET);  // 4. sor
  	  	  			  	  	  	  				  					HAL_GPIO_WritePin(GPIOI, GPIO_PIN_1, GPIO_PIN_RESET);     // 5. sor

  	  	  			  	  	  	  				  					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET);   //   1. oszlop
  	  	  			  	  	  	  				  					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_RESET);  //  2. oszlop
  	  	  			  	  	  	  				  					HAL_GPIO_WritePin(GPIOI, GPIO_PIN_2, GPIO_PIN_SET);   //   3. oszlop
  	  	  			  	  	  	  				  					HAL_GPIO_WritePin(GPIOI, GPIO_PIN_3, GPIO_PIN_SET);     //   4. oszlop
  	  	  			  	  	  	  				  					HAL_GPIO_WritePin(GPIOH, GPIO_PIN_6, GPIO_PIN_SET);  //   5. oszlop
  	  	  			  	  	  	  				  					HAL_GPIO_WritePin(GPIOI, GPIO_PIN_0, GPIO_PIN_SET);   //   6. oszlop
  	  	  			  	  	  	  				  					HAL_GPIO_WritePin(GPIOG, GPIO_PIN_7, GPIO_PIN_SET);   //   7. oszlop
  	  	  			  	  	  	  				  					HAL_Delay(1);

  	  	  			  	  	  	  				  					//other led2
  	  	  			  	  	  	  				  	  				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET);   // 1.sor
  	  	  			  	  	  	  				  					HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_RESET);   // 2. SOR
  	  	  			  	  	  	  				  					HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_SET);  // 3. sor
  	  	  			  	  	  	  				  					HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_RESET);  // 4. sor
  	  	  			  	  	  	  				  					HAL_GPIO_WritePin(GPIOI, GPIO_PIN_1, GPIO_PIN_RESET);     // 5. sor

  	  	  			  	  	  	  				  					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET);   //   1. oszlop
  	  	  			  	  	  	  				  					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);  //  2. oszlop
  	  	  			  	  	  	  				  					HAL_GPIO_WritePin(GPIOI, GPIO_PIN_2, GPIO_PIN_SET);   //   3. oszlop
  	  	  			  	  	  	  				  					HAL_GPIO_WritePin(GPIOI, GPIO_PIN_3, GPIO_PIN_SET);     //   4. oszlop
  	  	  			  	  	  	  				  					HAL_GPIO_WritePin(GPIOH, GPIO_PIN_6, GPIO_PIN_SET);  //   5. oszlop
  	  	  			  	  	  	  				  					HAL_GPIO_WritePin(GPIOI, GPIO_PIN_0, GPIO_PIN_SET);   //   6. oszlop
  	  	  			  	  	  	  				  					HAL_GPIO_WritePin(GPIOG, GPIO_PIN_7, GPIO_PIN_SET);   //   7. oszlop
  	  	  			  	  	  	  				  					HAL_Delay(1);


  	  	  			  	//   number 1(second part) : 1.led

  	  	  			  	  	  	  				  		  				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_SET);   // 1.sor
  	  	  			  	  	  	  				  		  				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_SET);   // 2. SOR
  	  	  			  	  	  	  				  		  				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_SET);  // 3. sor
  	  	  			  	  	  	  				  		  				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_SET);  // 4. sor
  	  	  			  	  	  	  				  		  				HAL_GPIO_WritePin(GPIOI, GPIO_PIN_1, GPIO_PIN_SET);     // 5. sor

  	  	  			  	  	  	  				  		  				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET);   //   1. oszlop
  	  	  			  	  	  	  				  		  				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);  //  2. oszlop
  	  	  			  	  	  	  				  		  				HAL_GPIO_WritePin(GPIOI, GPIO_PIN_2, GPIO_PIN_SET);   //   3. oszlop
  	  	  			  	  	  	  				  		  				HAL_GPIO_WritePin(GPIOI, GPIO_PIN_3, GPIO_PIN_SET);     //   4. oszlop
  	  	  			  	  	  	  				  		  				HAL_GPIO_WritePin(GPIOH, GPIO_PIN_6, GPIO_PIN_SET);  //   5. oszlop
  	  	  			  	  	  	  				  		  				HAL_GPIO_WritePin(GPIOI, GPIO_PIN_0, GPIO_PIN_SET);   //   6. oszlop
  	  	  			  	  	  	  				  		  				HAL_GPIO_WritePin(GPIOG, GPIO_PIN_7, GPIO_PIN_RESET);   //   7. oszlop
  	  	  			  	  	  	  				  		  				HAL_Delay(1);

  	  	  			  	  	  	  				  		  				//other led
  	  	  			  	  	  	  				  		  				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET);   // 1.sor
  	  	  			  	  	  	  				  						HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_RESET);   // 2. SOR
  	  	  			  	  	  	  				  						HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_RESET);  // 3. sor
  	  	  			  	  	  	  				  						HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_SET);  // 4. sor
  	  	  			  	  	  	  				  						HAL_GPIO_WritePin(GPIOI, GPIO_PIN_1, GPIO_PIN_RESET);     // 5. sor

  	  	  			  	  	  	  				  						HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET);   //   1. oszlop
  	  	  			  	  	  	  				  						HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);  //  2. oszlop
  	  	  			  	  	  	  				  						HAL_GPIO_WritePin(GPIOI, GPIO_PIN_2, GPIO_PIN_SET);   //   3. oszlop
  	  	  			  	  	  	  				  						HAL_GPIO_WritePin(GPIOI, GPIO_PIN_3, GPIO_PIN_SET);     //   4. oszlop
  	  	  			  	  	  	  				  						HAL_GPIO_WritePin(GPIOH, GPIO_PIN_6, GPIO_PIN_SET);  //   5. oszlop
  	  	  			  	  	  	  				  						HAL_GPIO_WritePin(GPIOI, GPIO_PIN_0, GPIO_PIN_RESET);   //   6. oszlop
  	  	  			  	  	  	  				  						HAL_GPIO_WritePin(GPIOG, GPIO_PIN_7, GPIO_PIN_SET);   //   7. oszlop
  	  	  			  	  	  	  				  						HAL_Delay(1);

  	  	  			  	  	  	  				  						//other led2
  	  	  			  	  	  	  				  		  				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET);   // 1.sor
  	  	  			  	  	  	  				  						HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_RESET);   // 2. SOR
  	  	  			  	  	  	  				  						HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_SET);  // 3. sor
  	  	  			  	  	  	  				  						HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_RESET);  // 4. sor
  	  	  			  	  	  	  				  						HAL_GPIO_WritePin(GPIOI, GPIO_PIN_1, GPIO_PIN_RESET);     // 5. sor

  	  	  			  	  	  	  				  						HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET);   //   1. oszlop
  	  	  			  	  	  	  				  						HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);  //  2. oszlop
  	  	  			  	  	  	  				  						HAL_GPIO_WritePin(GPIOI, GPIO_PIN_2, GPIO_PIN_SET);   //   3. oszlop
  	  	  			  	  	  	  				  						HAL_GPIO_WritePin(GPIOI, GPIO_PIN_3, GPIO_PIN_SET);     //   4. oszlop
  	  	  			  	  	  	  				  						HAL_GPIO_WritePin(GPIOH, GPIO_PIN_6, GPIO_PIN_RESET);  //   5. oszlop
  	  	  			  	  	  	  				  						HAL_GPIO_WritePin(GPIOI, GPIO_PIN_0, GPIO_PIN_SET);   //   6. oszlop
  	  	  			  	  	  	  				  						HAL_GPIO_WritePin(GPIOG, GPIO_PIN_7, GPIO_PIN_SET);   //   7. oszlop
  	  	  			  	  	  	  				  						HAL_Delay(1);

  	  	  			  	  	  j++;
  	  	  		  	  	  	  }
  	   	  	  			  	i++;

	  	  	  		  } else{
	  	  	  			  continue;
	  	  	  		  }

	  	  	  		  if(i==12){
  	  	  			  	  for(int j = 0; j < 200;){

  	  	  			  	//  12 pattern
  	  	  			  	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_SET);   // 1.sor
  	  	  			  	  	  	  			  	  	  	  				  	  				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_SET);   // 2. SOR
  	  	  			  	  	  	  			  	  	  	  				  	  				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_SET);  // 3. sor
  	  	  			  	  	  	  			  	  	  	  				  	  				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_SET);  // 4. sor
  	  	  			  	  	  	  			  	  	  	  				  	  				HAL_GPIO_WritePin(GPIOI, GPIO_PIN_1, GPIO_PIN_SET);     // 5. sor

  	  	  			  	  	  	  			  	  	  	  				  	  				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET);   //   1. oszlop
  	  	  			  	  	  	  			  	  	  	  				  	  				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);  //  2. oszlop
  	  	  			  	  	  	  			  	  	  	  				  	  				HAL_GPIO_WritePin(GPIOI, GPIO_PIN_2, GPIO_PIN_RESET);   //   3. oszlop
  	  	  			  	  	  	  			  	  	  	  				  	  				HAL_GPIO_WritePin(GPIOI, GPIO_PIN_3, GPIO_PIN_SET);     //   4. oszlop
  	  	  			  	  	  	  			  	  	  	  				  	  				HAL_GPIO_WritePin(GPIOH, GPIO_PIN_6, GPIO_PIN_SET);  //   5. oszlop
  	  	  			  	  	  	  			  	  	  	  				  	  				HAL_GPIO_WritePin(GPIOI, GPIO_PIN_0, GPIO_PIN_SET);   //   6. oszlop
  	  	  			  	  	  	  			  	  	  	  				  	  				HAL_GPIO_WritePin(GPIOG, GPIO_PIN_7, GPIO_PIN_SET);   //   7. oszlop
  	  	  			  	  	  	  			  	  	  	  				  	  				HAL_Delay(1);

  	  	  			  	  	  	  			  	  	  	  				  	  				//other led
  	  	  			  	  	  	  			  	  	  	  				  	  				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET);   // 1.sor
  	  	  			  	  	  	  			  	  	  	  				  					HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_RESET);   // 2. SOR
  	  	  			  	  	  	  			  	  	  	  				  					HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_RESET);  // 3. sor
  	  	  			  	  	  	  			  	  	  	  				  					HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_SET);  // 4. sor
  	  	  			  	  	  	  			  	  	  	  				  					HAL_GPIO_WritePin(GPIOI, GPIO_PIN_1, GPIO_PIN_RESET);     // 5. sor

  	  	  			  	  	  	  			  	  	  	  				  					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET);   //   1. oszlop
  	  	  			  	  	  	  			  	  	  	  				  					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_RESET);  //  2. oszlop
  	  	  			  	  	  	  			  	  	  	  				  					HAL_GPIO_WritePin(GPIOI, GPIO_PIN_2, GPIO_PIN_SET);   //   3. oszlop
  	  	  			  	  	  	  			  	  	  	  				  					HAL_GPIO_WritePin(GPIOI, GPIO_PIN_3, GPIO_PIN_SET);     //   4. oszlop
  	  	  			  	  	  	  			  	  	  	  				  					HAL_GPIO_WritePin(GPIOH, GPIO_PIN_6, GPIO_PIN_SET);  //   5. oszlop
  	  	  			  	  	  	  			  	  	  	  				  					HAL_GPIO_WritePin(GPIOI, GPIO_PIN_0, GPIO_PIN_SET);   //   6. oszlop
  	  	  			  	  	  	  			  	  	  	  				  					HAL_GPIO_WritePin(GPIOG, GPIO_PIN_7, GPIO_PIN_SET);   //   7. oszlop
  	  	  			  	  	  	  			  	  	  	  				  					HAL_Delay(1);

  	  	  			  	  	  	  			  	  	  	  				  					//other led2
  	  	  			  	  	  	  			  	  	  	  				  	  				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET);   // 1.sor
  	  	  			  	  	  	  			  	  	  	  				  					HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_RESET);   // 2. SOR
  	  	  			  	  	  	  			  	  	  	  				  					HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_SET);  // 3. sor
  	  	  			  	  	  	  			  	  	  	  				  					HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_RESET);  // 4. sor
  	  	  			  	  	  	  			  	  	  	  				  					HAL_GPIO_WritePin(GPIOI, GPIO_PIN_1, GPIO_PIN_RESET);     // 5. sor

  	  	  			  	  	  	  			  	  	  	  				  					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET);   //   1. oszlop
  	  	  			  	  	  	  			  	  	  	  				  					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);  //  2. oszlop
  	  	  			  	  	  	  			  	  	  	  				  					HAL_GPIO_WritePin(GPIOI, GPIO_PIN_2, GPIO_PIN_SET);   //   3. oszlop
  	  	  			  	  	  	  			  	  	  	  				  					HAL_GPIO_WritePin(GPIOI, GPIO_PIN_3, GPIO_PIN_SET);     //   4. oszlop
  	  	  			  	  	  	  			  	  	  	  				  					HAL_GPIO_WritePin(GPIOH, GPIO_PIN_6, GPIO_PIN_SET);  //   5. oszlop
  	  	  			  	  	  	  			  	  	  	  				  					HAL_GPIO_WritePin(GPIOI, GPIO_PIN_0, GPIO_PIN_SET);   //   6. oszlop
  	  	  			  	  	  	  			  	  	  	  				  					HAL_GPIO_WritePin(GPIOG, GPIO_PIN_7, GPIO_PIN_SET);   //   7. oszlop
  	  	  			  	  	  	  			  	  	  	  				  					HAL_Delay(1);



  	  	  			  					//   number 2 : 1.led
  	  	  			  				  // 3 rows lighting
  	  	  			  				  				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_SET);   // 1.sor
  	  	  			  				  				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_RESET);   // 2. SOR
  	  	  			  				  				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_SET);  // 3. sor
  	  	  			  				  				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_RESET);  // 4. sor
  	  	  			  				  				HAL_GPIO_WritePin(GPIOI, GPIO_PIN_1, GPIO_PIN_SET);     // 5. sor

  	  	  			  				  				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET);   //   1. oszlop
  	  	  			  				  				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);  //  2. oszlop
  	  	  			  				  				HAL_GPIO_WritePin(GPIOI, GPIO_PIN_2, GPIO_PIN_SET);   //   3. oszlop
  	  	  			  				  				HAL_GPIO_WritePin(GPIOI, GPIO_PIN_3, GPIO_PIN_SET);     //   4. oszlop
  	  	  			  				  				HAL_GPIO_WritePin(GPIOH, GPIO_PIN_6, GPIO_PIN_RESET);  //   5. oszlop
  	  	  			  				  				HAL_GPIO_WritePin(GPIOI, GPIO_PIN_0, GPIO_PIN_RESET);   //   6. oszlop
  	  	  			  				  				HAL_GPIO_WritePin(GPIOG, GPIO_PIN_7, GPIO_PIN_RESET);   //   7. oszlop
  	  	  			  				  				HAL_Delay(1);

  	  	  			  				  				// 2 other leds
  	  	  			  				  				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET);   // 1.sor
  	  	  			  								HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_SET);   // 2. SOR
  	  	  			  								HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_RESET);  // 3. sor
  	  	  			  								HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_RESET);  // 4. sor
  	  	  			  								HAL_GPIO_WritePin(GPIOI, GPIO_PIN_1, GPIO_PIN_RESET);     // 5. sor

  	  	  			  								HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET);   //   1. oszlop
  	  	  			  								HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);  //  2. oszlop
  	  	  			  								HAL_GPIO_WritePin(GPIOI, GPIO_PIN_2, GPIO_PIN_SET);   //   3. oszlop
  	  	  			  								HAL_GPIO_WritePin(GPIOI, GPIO_PIN_3, GPIO_PIN_SET);     //   4. oszlop
  	  	  			  								HAL_GPIO_WritePin(GPIOH, GPIO_PIN_6, GPIO_PIN_RESET);  //   5. oszlop
  	  	  			  								HAL_GPIO_WritePin(GPIOI, GPIO_PIN_0, GPIO_PIN_SET);   //   6. oszlop
  	  	  			  								HAL_GPIO_WritePin(GPIOG, GPIO_PIN_7, GPIO_PIN_SET);   //   7. oszlop
  	  	  			  								HAL_Delay(1);

  	  	  			  								//3.rd part
  	  	  			  								HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET);   // 1.sor
  	  	  			  												HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_RESET);   // 2. SOR
  	  	  			  												HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_RESET);  // 3. sor
  	  	  			  												HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_SET);  // 4. sor
  	  	  			  												HAL_GPIO_WritePin(GPIOI, GPIO_PIN_1, GPIO_PIN_RESET);     // 5. sor

  	  	  			  												HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET);   //   1. oszlop
  	  	  			  												HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);  //  2. oszlop
  	  	  			  												HAL_GPIO_WritePin(GPIOI, GPIO_PIN_2, GPIO_PIN_SET);   //   3. oszlop
  	  	  			  												HAL_GPIO_WritePin(GPIOI, GPIO_PIN_3, GPIO_PIN_SET);     //   4. oszlop
  	  	  			  												HAL_GPIO_WritePin(GPIOH, GPIO_PIN_6, GPIO_PIN_SET);  //   5. oszlop
  	  	  			  												HAL_GPIO_WritePin(GPIOI, GPIO_PIN_0, GPIO_PIN_SET);   //   6. oszlop
  	  	  			  												HAL_GPIO_WritePin(GPIOG, GPIO_PIN_7, GPIO_PIN_RESET);   //   7. oszlop
  	  	  			  												HAL_Delay(1);


  	  	  			  	  	  j++;
  	  	  		  	  	  	  }
  	   	  	  			  	 i++;

	  	  	  		  } else{
	  	  	  			  continue;
	  	  	  		  }
	  	  	  	  }


	  	  if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_4) == 0) {
	  	  	 for(int i = 0;  i < 64; i++){
	  	  		 	 	 int remain = 0;
	  	  				int x = 0;

	  	  		         x = i / 32;
	  	  		        remain = i % 32;

	  	  		        if( x ==1 ){
	  	  		        	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8, GPIO_PIN_SET); // 1.
	  	  		        } else{
	  	  		        	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8, GPIO_PIN_RESET);
	  	  		        }

	  	  		        x = remain / 16;
	  	  		       remain = remain % 16;

	  	  		       if( x ==1 ){
	  	  		        		  HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_SET); // 2.
	  	  		      } else{
	  	  		        		  HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_RESET);
	  	  		       }

	  	  		         x = remain / 8;
	  	  		     	remain = remain % 8;

	  	  		       	if( x ==1 ){
	  	  		        	 	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_SET); // 3.
	  	  		        } else{
	  	  		             	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_RESET);
	  	  		          }

	  	  		           x = remain / 4;
	  	  		         remain = remain % 4;

	  	  		          if( x ==1 ){
	  	  		        		  	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET); // 4.
	  	  		        	   } else{
	  	  		        	         HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET);
	  	  		        	}

	  	  		          x = remain / 2;
	  	  		          remain = remain % 2;

	  	  		         if( x ==1 ){
	  	  		                 HAL_GPIO_WritePin(GPIOF, GPIO_PIN_7, GPIO_PIN_SET);  //5.
	  	  		         } else{
	  	  		                   HAL_GPIO_WritePin(GPIOF, GPIO_PIN_7, GPIO_PIN_RESET);
	  	  		      	}


	  	  		         x = remain / 1;
	  	  		       	 remain = remain % 1;

	  	  		         if( x ==1 ){
	  	  		        		HAL_GPIO_WritePin(GPIOF, GPIO_PIN_6, GPIO_PIN_SET);  //6.
	  	  		         } else{
	  	  		        	 	 HAL_GPIO_WritePin(GPIOF, GPIO_PIN_6, GPIO_PIN_RESET);
	  	  		     	}

	  	  		         HAL_Delay(500);
						 HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8, GPIO_PIN_RESET);
						 HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_RESET);
						 HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_RESET);
						 HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET);
						 HAL_GPIO_WritePin(GPIOF, GPIO_PIN_7, GPIO_PIN_RESET);
						 HAL_GPIO_WritePin(GPIOF, GPIO_PIN_6, GPIO_PIN_RESET);
	  	  	 	 }
  	  	  	}

	  	    if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_7) == 0) {
	  	  		  	  	  //when the not integrated button pressed all leds fleshes from outside to the middle
		  	  	  	  	  HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8, GPIO_PIN_SET); // 1.
		 	  			  HAL_GPIO_WritePin(GPIOF, GPIO_PIN_6, GPIO_PIN_SET);  //6.
		 	  			  HAL_Delay(300);
		 	  			  HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8, GPIO_PIN_RESET);
		 	  			  HAL_GPIO_WritePin(GPIOF, GPIO_PIN_6, GPIO_PIN_RESET);
		 	  			  HAL_Delay(300);

		 	  			  HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_SET); // 2.
		 	  			  HAL_GPIO_WritePin(GPIOF, GPIO_PIN_7, GPIO_PIN_SET);  //5.
		 	  			  HAL_Delay(300);
		 	  			  HAL_GPIO_WritePin(GPIOF, GPIO_PIN_7, GPIO_PIN_RESET);
		 	  			  HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_RESET);
		 	  			  HAL_Delay(300);

		 	  			  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET); // 4.
		 	  			  HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_SET); // 3.
		 	  			  HAL_Delay(300);
		 	  			  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET);
		 	  			  HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_RESET);
		 	  			  HAL_Delay(300);
	  	  	  }

	  	  	  if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_6) == 0) {
	  	  		  //when the not integrated button2 pressed all leds fleshes
		  	  	  HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8, GPIO_PIN_SET); // 1.
				  HAL_GPIO_WritePin(GPIOF, GPIO_PIN_6, GPIO_PIN_SET);  //6.
				  HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_SET); // 2.
				  HAL_GPIO_WritePin(GPIOF, GPIO_PIN_7, GPIO_PIN_SET);  //5.
				  HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_SET); // 3.
				  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET);  // 4.
	  	  	  } else {
				  HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(GPIOF, GPIO_PIN_6, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(GPIOF, GPIO_PIN_7, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET);
			  	}


	  	  	  if(HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_6) == 0) {
	  	  		  	  //when the not integrated button3 pressed all leds fleshes in a row
	  	  		  	 HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8, GPIO_PIN_SET); // 1.
	 			 	 HAL_Delay(100);
	 			 	 HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8, GPIO_PIN_RESET);
	 			 	 HAL_Delay(100);
	 			 	 HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_SET); // 2.
	 			 	 HAL_Delay(100);
	 			 	 HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_RESET);
	 			 	 HAL_Delay(100);
	 			 	 HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_SET); // 3.
	 			 	 HAL_Delay(100);
	 			 	 HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_RESET);
	 			 	 HAL_Delay(100);
	 			 	 HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET);  // 4.
	 			 	 HAL_Delay(100);
	 			 	 HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET);
	 			 	 HAL_Delay(100);
	 			 	 HAL_GPIO_WritePin(GPIOF, GPIO_PIN_7, GPIO_PIN_SET);  //5.
	 			 	 HAL_Delay(100);
	 			 	 HAL_GPIO_WritePin(GPIOF, GPIO_PIN_7, GPIO_PIN_RESET);
	 			 	 HAL_Delay(100);
	 			 	 HAL_GPIO_WritePin(GPIOF, GPIO_PIN_6, GPIO_PIN_SET);  //6.
	 			 	 HAL_Delay(100);
	 			 	 HAL_GPIO_WritePin(GPIOF, GPIO_PIN_6, GPIO_PIN_RESET);
	 			 	 HAL_Delay(100);

	 			 	 // backwards
	 			 	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_6, GPIO_PIN_SET);
	 			 	HAL_Delay(100);
	 			 	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_6, GPIO_PIN_RESET);
	 			 	HAL_Delay(100);
	 			 	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_7, GPIO_PIN_SET);
	 			 	HAL_Delay(100);
	 			 	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_7, GPIO_PIN_RESET);
	 			 	HAL_Delay(100);
	 			 	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET);
	 			 	HAL_Delay(100);
	 			 	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET);
	 			 	HAL_Delay(100);
	 			 	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_SET);
	 			 	HAL_Delay(100);
	 			 	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_RESET);
	 			 	HAL_Delay(100);
	 			 	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_SET);
	 			 	HAL_Delay(100);
	 			 	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_RESET);
	 			 	HAL_Delay(100);
	 			 	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8, GPIO_PIN_SET);
	 			 	HAL_Delay(100);
	 			 	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8, GPIO_PIN_RESET);
	 			 	HAL_Delay(100);
	 	  }


	  //TODO:   Flash the led with 200 ms period time
	  //BSP_LED_On(LED_GREEN);
	  //HAL_Delay(200);
	  //BSP_LED_Off(LED_GREEN); when u use toogle dont need on and of functions

	  //BSP_LED_Toggle(LED_GREEN);
	  //HAL_Delay(200);

  }
}

/**
  * @brief  System Clock Configuration
  *         The system Clock is configured as follow :
  *            System Clock source            = PLL (HSE)
  *            SYSCLK(Hz)                     = 216000000
  *            HCLK(Hz)                       = 216000000
  *            AHB Prescaler                  = 1
  *            APB1 Prescaler                 = 4
  *            APB2 Prescaler                 = 2
  *            HSE Frequency(Hz)              = 25000000
  *            PLL_M                          = 25
  *            PLL_N                          = 432
  *            PLL_P                          = 2
  *            PLL_Q                          = 9
  *            VDD(V)                         = 3.3
  *            Main regulator output voltage  = Scale1 mode
  *            Flash Latency(WS)              = 7
  * @param  None
  * @retval None
  */
static void SystemClock_Config(void)
{
  RCC_ClkInitTypeDef RCC_ClkInitStruct;
  RCC_OscInitTypeDef RCC_OscInitStruct;

  /* Enable HSE Oscillator and activate PLL with HSE as source */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSIState = RCC_HSI_OFF;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 25;
  RCC_OscInitStruct.PLL.PLLN = 432;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 9;
  if(HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /* activate the OverDrive to reach the 216 Mhz Frequency */
  if(HAL_PWREx_EnableOverDrive() != HAL_OK)
  {
    Error_Handler();
  }

  /* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2
     clocks dividers */
  RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;
  if(HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @param  None
  * @retval None
  */
static void Error_Handler(void)
{
  /* User may add here some code to deal with this error */
  while(1)
  {
  }
}

/**
  * @brief  Configure the MPU attributes as Write Through for SRAM1/2.
  * @note   The Base Address is 0x20010000 since this memory interface is the AXI.
  *         The Region Size is 256KB, it is related to SRAM1 and SRAM2  memory size.
  * @param  None
  * @retval None
  */
static void MPU_Config(void)
{
  MPU_Region_InitTypeDef MPU_InitStruct;

  /* Disable the MPU */
  HAL_MPU_Disable();

  /* Configure the MPU attributes as WT for SRAM */
  MPU_InitStruct.Enable = MPU_REGION_ENABLE;
  MPU_InitStruct.BaseAddress = 0x20010000;
  MPU_InitStruct.Size = MPU_REGION_SIZE_256KB;
  MPU_InitStruct.AccessPermission = MPU_REGION_FULL_ACCESS;
  MPU_InitStruct.IsBufferable = MPU_ACCESS_NOT_BUFFERABLE;
  MPU_InitStruct.IsCacheable = MPU_ACCESS_CACHEABLE;
  MPU_InitStruct.IsShareable = MPU_ACCESS_SHAREABLE;
  MPU_InitStruct.Number = MPU_REGION_NUMBER0;
  MPU_InitStruct.TypeExtField = MPU_TEX_LEVEL0;
  MPU_InitStruct.SubRegionDisable = 0x00;
  MPU_InitStruct.DisableExec = MPU_INSTRUCTION_ACCESS_ENABLE;

  HAL_MPU_ConfigRegion(&MPU_InitStruct);

  /* Enable the MPU */
  HAL_MPU_Enable(MPU_PRIVILEGED_DEFAULT);
}

/**
  * @brief  CPU L1-Cache enable.
  * @param  None
  * @retval None
  */
static void CPU_CACHE_Enable(void)
{
  /* Enable I-Cache */
  SCB_EnableICache();

  /* Enable D-Cache */
  SCB_EnableDCache();
}

#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
