################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/dlinyj_fft/accelerated_powerquad.c \
../source/dlinyj_fft/defines.c \
../source/dlinyj_fft/input_generator.c \
../source/dlinyj_fft/self_contained_code.c \
../source/dlinyj_fft/wrapper.c 

OBJS += \
./source/dlinyj_fft/accelerated_powerquad.o \
./source/dlinyj_fft/defines.o \
./source/dlinyj_fft/input_generator.o \
./source/dlinyj_fft/self_contained_code.o \
./source/dlinyj_fft/wrapper.o 

C_DEPS += \
./source/dlinyj_fft/accelerated_powerquad.d \
./source/dlinyj_fft/defines.d \
./source/dlinyj_fft/input_generator.d \
./source/dlinyj_fft/self_contained_code.d \
./source/dlinyj_fft/wrapper.d 


# Each subdirectory must supply rules for building sources it contributes
source/dlinyj_fft/%.o: ../source/dlinyj_fft/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DCPU_LPC55S69JBD100 -DCPU_LPC55S69JBD100_cm33 -DCPU_LPC55S69JBD100_cm33_core0 -DSDK_OS_BAREMETAL -DSERIAL_PORT_TYPE_UART=1 -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -D__NEWLIB__ -I"C:\Users\woodr\mcuexpresso\LPC55S69_Project\drivers" -I"C:\Users\woodr\mcuexpresso\LPC55S69_Project\LPC55S69\drivers" -I"C:\Users\woodr\mcuexpresso\LPC55S69_Project\utilities" -I"C:\Users\woodr\mcuexpresso\LPC55S69_Project\component\uart" -I"C:\Users\woodr\mcuexpresso\LPC55S69_Project\component\serial_manager" -I"C:\Users\woodr\mcuexpresso\LPC55S69_Project\component\lists" -I"C:\Users\woodr\mcuexpresso\LPC55S69_Project\CMSIS\DSP\Include" -I"C:\Users\woodr\mcuexpresso\LPC55S69_Project\CMSIS" -I"C:\Users\woodr\mcuexpresso\LPC55S69_Project\device" -I"C:\Users\woodr\mcuexpresso\LPC55S69_Project\drivers" -I"C:\Users\woodr\mcuexpresso\LPC55S69_Project\LPC55S69\drivers" -I"C:\Users\woodr\mcuexpresso\LPC55S69_Project\utilities" -I"C:\Users\woodr\mcuexpresso\LPC55S69_Project\component\uart" -I"C:\Users\woodr\mcuexpresso\LPC55S69_Project\component\serial_manager" -I"C:\Users\woodr\mcuexpresso\LPC55S69_Project\component\lists" -I"C:\Users\woodr\mcuexpresso\LPC55S69_Project\CMSIS\DSP\Include" -I"C:\Users\woodr\mcuexpresso\LPC55S69_Project\CMSIS" -I"C:\Users\woodr\mcuexpresso\LPC55S69_Project\device" -I"C:\Users\woodr\mcuexpresso\LPC55S69_Project\board" -I"C:\Users\woodr\mcuexpresso\LPC55S69_Project\source" -I"C:\Users\woodr\mcuexpresso\LPC55S69_Project\startup" -O0 -fno-common -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m33 -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -D__NEWLIB__ -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

