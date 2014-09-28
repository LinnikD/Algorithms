################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Сортировка\ вставками.cpp 

OBJS += \
./src/Сортировка\ вставками.o 

CPP_DEPS += \
./src/Сортировка\ вставками.d 


# Each subdirectory must supply rules for building sources it contributes
src/Сортировка\ вставками.o: ../src/Сортировка\ вставками.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Сортировка вставками.d" -MT"src/Сортировка\ вставками.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


