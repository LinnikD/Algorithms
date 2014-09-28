################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Большой\ файл.c 

OBJS += \
./src/Большой\ файл.o 

C_DEPS += \
./src/Большой\ файл.d 


# Each subdirectory must supply rules for building sources it contributes
src/Большой\ файл.o: ../src/Большой\ файл.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -std=c99 -MMD -MP -MF"src/Большой файл.d" -MT"src/Большой\ файл.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


