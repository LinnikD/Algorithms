################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Наибольшая\ высота\ треугольника.c 

OBJS += \
./src/Наибольшая\ высота\ треугольника.o 

C_DEPS += \
./src/Наибольшая\ высота\ треугольника.d 


# Each subdirectory must supply rules for building sources it contributes
src/Наибольшая\ высота\ треугольника.o: ../src/Наибольшая\ высота\ треугольника.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Наибольшая высота треугольника.d" -MT"src/Наибольшая\ высота\ треугольника.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


