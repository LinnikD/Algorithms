################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Художник\ и\ фотограф.cpp 

OBJS += \
./src/Художник\ и\ фотограф.o 

CPP_DEPS += \
./src/Художник\ и\ фотограф.d 


# Each subdirectory must supply rules for building sources it contributes
src/Художник\ и\ фотограф.o: ../src/Художник\ и\ фотограф.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Художник и фотограф.d" -MT"src/Художник\ и\ фотограф.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


