################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Sort\ first\ k.cpp 

OBJS += \
./src/Sort\ first\ k.o 

CPP_DEPS += \
./src/Sort\ first\ k.d 


# Each subdirectory must supply rules for building sources it contributes
src/Sort\ first\ k.o: ../src/Sort\ first\ k.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Sort first k.d" -MT"src/Sort\ first\ k.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


