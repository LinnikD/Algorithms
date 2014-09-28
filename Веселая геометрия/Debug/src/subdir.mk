################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Веселая\ геометрия.c 

OBJS += \
./src/Веселая\ геометрия.o 

C_DEPS += \
./src/Веселая\ геометрия.d 


# Each subdirectory must supply rules for building sources it contributes
src/Веселая\ геометрия.o: ../src/Веселая\ геометрия.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Веселая геометрия.d" -MT"src/Веселая\ геометрия.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


