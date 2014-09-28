################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Quikest\ sort.cpp 

OBJS += \
./src/Quikest\ sort.o 

CPP_DEPS += \
./src/Quikest\ sort.d 


# Each subdirectory must supply rules for building sources it contributes
src/Quikest\ sort.o: ../src/Quikest\ sort.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Quikest sort.d" -MT"src/Quikest\ sort.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


