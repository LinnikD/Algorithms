################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Глупое\ бинарное\ дерево.cpp 

OBJS += \
./src/Глупое\ бинарное\ дерево.o 

CPP_DEPS += \
./src/Глупое\ бинарное\ дерево.d 


# Each subdirectory must supply rules for building sources it contributes
src/Глупое\ бинарное\ дерево.o: ../src/Глупое\ бинарное\ дерево.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Глупое бинарное дерево.d" -MT"src/Глупое\ бинарное\ дерево.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


