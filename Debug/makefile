################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
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
TrafficLightWith7segmetnsLEDS.lss \

FLASH_IMAGE += \
TrafficLightWith7segmetnsLEDS.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: TrafficLightWith7segmetnsLEDS.elf secondary-outputs

# Tool invocations
TrafficLightWith7segmetnsLEDS.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,TrafficLightWith7segmetnsLEDS.map -mmcu=atmega32 -o "TrafficLightWith7segmetnsLEDS.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

TrafficLightWith7segmetnsLEDS.lss: TrafficLightWith7segmetnsLEDS.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S TrafficLightWith7segmetnsLEDS.elf  >"TrafficLightWith7segmetnsLEDS.lss"
	@echo 'Finished building: $@'
	@echo ' '

TrafficLightWith7segmetnsLEDS.hex: TrafficLightWith7segmetnsLEDS.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex TrafficLightWith7segmetnsLEDS.elf  "TrafficLightWith7segmetnsLEDS.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: TrafficLightWith7segmetnsLEDS.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 TrafficLightWith7segmetnsLEDS.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) TrafficLightWith7segmetnsLEDS.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
