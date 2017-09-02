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
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
Control_speed_Mc2.lss \

SIZEDUMMY += \
sizedummy \


# All Target
all: Control_speed_Mc2.elf secondary-outputs

# Tool invocations
Control_speed_Mc2.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Control_speed_Mc2.map -mmcu=atmega16 -o "Control_speed_Mc2.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Control_speed_Mc2.lss: Control_speed_Mc2.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Control_speed_Mc2.elf  >"Control_speed_Mc2.lss"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Control_speed_Mc2.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 Control_speed_Mc2.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(ASM_DEPS)$(ELFS)$(LSS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS) Control_speed_Mc2.elf
	-@echo ' '

secondary-outputs: $(LSS) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
