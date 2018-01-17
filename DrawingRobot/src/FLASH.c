#include "stm32f7xx_hal.h"
#include "stm32f7xx_hal_flash.h"
#include "main.h"

void Save_to_Flash(uint16_t data1, uint16_t data2) {
	HAL_StatusTypeDef status;

	status = HAL_FLASH_Unlock();
	if (status != HAL_OK) {
		printf("Flash unlock error!\n");
		return;
	} else {
		printf("Flash unlock ok!\n");
	}

    __HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_EOP | FLASH_FLAG_OPERR | FLASH_FLAG_WRPERR | FLASH_FLAG_PGAERR | FLASH_FLAG_PGPERR);
    printf("Flash flags cleared!\n");
    FLASH_Erase_Sector(FLASH_SECTOR_3, VOLTAGE_RANGE_3);
    printf("Flash erasing ok!\n");

	status = HAL_FLASH_Program(FLASH_TYPEPROGRAM_HALFWORD, 0x08018000, data1);
	status = HAL_FLASH_Program(FLASH_TYPEPROGRAM_HALFWORD, 0x08018002, data2);
	if (status != HAL_OK) {
		printf("Flash write error!\n");
		return;
	} else {
		printf("Flash write ok!\n");
	}

	HAL_FLASH_Lock();
	if (status != HAL_OK) {
		printf("Flash lock error!\n");
		return;
	}
}

void Read_from_Flash(/*uint16_t* data1, uint16_t* data2*/) {
	//*data1 = *(__IO uint16_t *)0x0800000;
	//*data2 = *(__IO uint16_t *)0x0800002;
	printf("Value: %d - %d\n", *(__IO uint16_t *)0x08018000, *(__IO uint16_t *)0x08018002);
}
