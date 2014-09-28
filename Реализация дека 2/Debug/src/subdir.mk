################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Реализация\ дека\ 2.cpp 

OBJS += \
./src/Реализация\ дека\ 2.o 

CPP_DEPS += \
./src/Реализация\ дека\ 2.d 


# Each subdirectory must supply rules for building sources it contributes
src/Реализация\ дека\ 2.o: ../src/Реализация\ дека\ 2.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Реализация дека 2.d" -MT"src/Реализация\ дека\ 2.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


