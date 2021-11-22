################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include utilities/subdir.mk
-include startup/subdir.mk
-include source/xiahouzouxin_fft/subdir.mk
-include source/xbarin02_uFFT_2/subdir.mk
-include source/xbarin02_uFFT/subdir.mk
-include source/tasimon_FFT/subdir.mk
-include source/omnister_fftp/subdir.mk
-include source/mozanunal_SimpleDSP/subdir.mk
-include source/mborgerding_kissfft/subdir.mk
-include source/marton78_pffft/subdir.mk
-include source/liscio_fft_2/subdir.mk
-include source/liscio_fft/subdir.mk
-include source/jtfell_c-fft/subdir.mk
-include source/gregfjohnson_fft/subdir.mk
-include source/dlinyj_fft/subdir.mk
-include source/crc32/gityf_crc/subdir.mk
-include source/crc32/subdir.mk
-include source/cpuimage_cpuFFT/subdir.mk
-include source/cpuimage_StockhamFFT/subdir.mk
-include source/cpuimage_FFTResampler/subdir.mk
-include source/clib/fft_synth/subdir.mk
-include source/clib/subdir.mk
-include source/akw0088_fft/subdir.mk
-include source/MiBench_MiBench/subdir.mk
-include source/JodiTheTigger_meow_fft/subdir.mk
-include source/subdir.mk
-include drivers/subdir.mk
-include device/subdir.mk
-include component/uart/subdir.mk
-include component/serial_manager/subdir.mk
-include component/lists/subdir.mk
-include board/subdir.mk
-include LPC55S69/drivers/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: LPC55S69_Project.axf

# Tool invocations
LPC55S69_Project.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -L"C:\Users\woodr\mcuexpresso\LPC55S69_Project\LPC55S69\mcuxpresso" -L"C:\Users\woodr\mcuexpresso\LPC55S69_Project\CMSIS\DSP" -Xlinker -Map="LPC55S69_Project.map" -Xlinker --gc-sections -Xlinker -print-memory-usage -Xlinker --sort-section=alignment -Xlinker --cref -mcpu=cortex-m33 -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -T LPC55S69_Project_Debug.ld -o "LPC55S69_Project.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) LPC55S69_Project.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "LPC55S69_Project.axf"; # arm-none-eabi-objcopy -v -O binary "LPC55S69_Project.axf" "LPC55S69_Project.bin" ; # checksum -p LPC55S69 -d "LPC55S69_Project.bin";
	-@echo ' '

.PHONY: all clean dependents post-build

-include ../makefile.targets
