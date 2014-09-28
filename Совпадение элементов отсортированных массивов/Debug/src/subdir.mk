################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Совпадение\ элементов\ отсортированных\ массивов.c 

OBJS += \
./src/Совпадение\ элементов\ отсортированных\ массивов.o 

C_DEPS += \
./src/Совпадение\ элементов\ отсортированных\ массивов.d 


# Each subdirectory must supply rules for building sources it contributes
src/Совпадение\ элементов\ отсортированных\ массивов.o: ../src/Совпадение\ элементов\ отсортированных\ массивов.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -std=c99 -MMD -MP -MF"src/Совпадение элементов отсортированных массивов.d" -MT"src/Совпадение\ элементов\ отсортированных\ массивов.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


