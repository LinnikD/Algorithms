################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Binary\ sort.cpp 

OBJS += \
./src/Binary\ sort.o 

CPP_DEPS += \
./src/Binary\ sort.d 


# Each subdirectory must supply rules for building sources it contributes
src/Binary\ sort.o: ../src/Binary\ sort.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Binary sort.d" -MT"src/Binary\ sort.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


