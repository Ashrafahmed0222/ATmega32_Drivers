################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/PORT_Driver/subdir.mk
-include MCAL/EXTI_Driver/subdir.mk
-include MCAL/DIO_Driver/subdir.mk
-include HAL/SWITCH_Driver/subdir.mk
-include HAL/SSD_Driver/subdir.mk
-include HAL/LED_Driver/subdir.mk
-include HAL/KEY_PAD_Driver/subdir.mk
-include HAL/CLCD_Driver/subdir.mk
-include HAL/BUZZER_Driver/subdir.mk
-include APP/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
ATmega32_COTS.lss \

SIZEDUMMY += \
sizedummy \


# All Target
all: ATmega32_COTS.elf secondary-outputs

# Tool invocations
ATmega32_COTS.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,ATmega32_COTS.map -mmcu=atmega32 -o "ATmega32_COTS.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

ATmega32_COTS.lss: ATmega32_COTS.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S ATmega32_COTS.elf  >"ATmega32_COTS.lss"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: ATmega32_COTS.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 ATmega32_COTS.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) ATmega32_COTS.elf
	-@echo ' '

secondary-outputs: $(LSS) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
