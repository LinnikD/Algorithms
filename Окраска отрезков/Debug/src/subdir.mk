################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Окраска\ отрезков.cpp 

OBJS += \
./src/Окраска\ отрезков.o 

CPP_DEPS += \
./src/Окраска\ отрезков.d 


# Each subdirectory must supply rules for building sources it contributes
src/Окраска\ отрезков.o: ../src/Окраска\ отрезков.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Окраска отрезков.d" -MT"src/Окраска\ отрезков.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


