################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Число\ единиц.c 

OBJS += \
./src/Число\ единиц.o 

C_DEPS += \
./src/Число\ единиц.d 


# Each subdirectory must supply rules for building sources it contributes
src/Число\ единиц.o: ../src/Число\ единиц.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Число единиц.d" -MT"src/Число\ единиц.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


