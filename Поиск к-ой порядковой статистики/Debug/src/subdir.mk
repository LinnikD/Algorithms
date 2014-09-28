################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Поиск\ к-ой\ порядковой\ статистики.cpp 

OBJS += \
./src/Поиск\ к-ой\ порядковой\ статистики.o 

CPP_DEPS += \
./src/Поиск\ к-ой\ порядковой\ статистики.d 


# Each subdirectory must supply rules for building sources it contributes
src/Поиск\ к-ой\ порядковой\ статистики.o: ../src/Поиск\ к-ой\ порядковой\ статистики.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Поиск к-ой порядковой статистики.d" -MT"src/Поиск\ к-ой\ порядковой\ статистики.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


