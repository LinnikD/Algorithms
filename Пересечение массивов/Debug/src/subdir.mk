################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Пересечение\ массивов.c 

OBJS += \
./src/Пересечение\ массивов.o 

C_DEPS += \
./src/Пересечение\ массивов.d 


# Each subdirectory must supply rules for building sources it contributes
src/Пересечение\ массивов.o: ../src/Пересечение\ массивов.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Пересечение массивов.d" -MT"src/Пересечение\ массивов.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


