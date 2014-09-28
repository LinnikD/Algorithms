################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Лес\ и\ Деревни.cpp 

OBJS += \
./src/Лес\ и\ Деревни.o 

CPP_DEPS += \
./src/Лес\ и\ Деревни.d 


# Each subdirectory must supply rules for building sources it contributes
src/Лес\ и\ Деревни.o: ../src/Лес\ и\ Деревни.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Лес и Деревни.d" -MT"src/Лес\ и\ Деревни.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


