################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Перевод\ числа\ в\ систему\ счисления\ с\ переменным\ основанием.c 

OBJS += \
./src/Перевод\ числа\ в\ систему\ счисления\ с\ переменным\ основанием.o 

C_DEPS += \
./src/Перевод\ числа\ в\ систему\ счисления\ с\ переменным\ основанием.d 


# Each subdirectory must supply rules for building sources it contributes
src/Перевод\ числа\ в\ систему\ счисления\ с\ переменным\ основанием.o: ../src/Перевод\ числа\ в\ систему\ счисления\ с\ переменным\ основанием.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -std=c99 -MMD -MP -MF"src/Перевод числа в систему счисления с переменным основанием.d" -MT"src/Перевод\ числа\ в\ систему\ счисления\ с\ переменным\ основанием.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


