################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Сортировка\ строк.cpp 

OBJS += \
./src/Сортировка\ строк.o 

CPP_DEPS += \
./src/Сортировка\ строк.d 


# Each subdirectory must supply rules for building sources it contributes
src/Сортировка\ строк.o: ../src/Сортировка\ строк.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Сортировка строк.d" -MT"src/Сортировка\ строк.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


