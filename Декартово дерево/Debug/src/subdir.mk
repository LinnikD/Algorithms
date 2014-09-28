################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Декартово\ дерево.cpp 

OBJS += \
./src/Декартово\ дерево.o 

CPP_DEPS += \
./src/Декартово\ дерево.d 


# Each subdirectory must supply rules for building sources it contributes
src/Декартово\ дерево.o: ../src/Декартово\ дерево.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Декартово дерево.d" -MT"src/Декартово\ дерево.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


