################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Минимальное\ время.cpp 

OBJS += \
./src/Минимальное\ время.o 

CPP_DEPS += \
./src/Минимальное\ время.d 


# Each subdirectory must supply rules for building sources it contributes
src/Минимальное\ время.o: ../src/Минимальное\ время.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Минимальное время.d" -MT"src/Минимальное\ время.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


