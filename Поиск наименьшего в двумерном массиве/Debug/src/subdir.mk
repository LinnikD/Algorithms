################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Поиск\ наименьшего\ в\ двумерном\ массиве.c 

OBJS += \
./src/Поиск\ наименьшего\ в\ двумерном\ массиве.o 

C_DEPS += \
./src/Поиск\ наименьшего\ в\ двумерном\ массиве.d 


# Each subdirectory must supply rules for building sources it contributes
src/Поиск\ наименьшего\ в\ двумерном\ массиве.o: ../src/Поиск\ наименьшего\ в\ двумерном\ массиве.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -std=c99 -MMD -MP -MF"src/Поиск наименьшего в двумерном массиве.d" -MT"src/Поиск\ наименьшего\ в\ двумерном\ массиве.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


