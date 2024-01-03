  /* USER CODE BEGIN 1 */
	volatile short encoder_cnt = 0, encoder_cnt_pre = 0, rpm = 0;
	int speed = 0;
  /* USER CODE END 1 */

  /* USER CODE BEGIN 2 */
  HAL_TIM_Encoder_Start(&htim2, TIM_CHANNEL_1 | TIM_CHANNEL_2);
  HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
  /* USER CODE END 2 */

    /* USER CODE BEGIN 3 */
	for (speed = 0; speed < 100; speed = speed + 10) {
	  HAL_Delay(1000);
	  __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_1, 20); // xuat xung PWM
	  encoder_cnt = __HAL_TIM_GET_COUNTER(&htim2);
	  rpm = (encoder_cnt - encoder_cnt_pre) / 1200; // uoc luong 20(dpg) * 60(s)
	  encoder_cnt_pre = encoder_cnt;
	}
