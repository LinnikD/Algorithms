################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Вычисление\ частичных\ сумм.c 

OBJS += \
./src/Вычисление\ частичных\ сумм.o 

C_DEPS += \
./src/Вычисление\ частичных\ сумм.d 


# Each subdirectory must supply rules for building sources it contributes
src/Вычисление\ частичных\ сумм.o: ../src/Вычисление\ частичных\ сумм.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Вычисление частичных сумм.d" -MT"src/Вычисление\ частичных\ сумм.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


