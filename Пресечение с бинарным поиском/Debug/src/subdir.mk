################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Пресечение\ с\ бинарным\ поиском.cpp 

OBJS += \
./src/Пресечение\ с\ бинарным\ поиском.o 

CPP_DEPS += \
./src/Пресечение\ с\ бинарным\ поиском.d 


# Each subdirectory must supply rules for building sources it contributes
src/Пресечение\ с\ бинарным\ поиском.o: ../src/Пресечение\ с\ бинарным\ поиском.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Пресечение с бинарным поиском.d" -MT"src/Пресечение\ с\ бинарным\ поиском.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


