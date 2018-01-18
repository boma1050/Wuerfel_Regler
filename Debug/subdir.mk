################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../AComponentBase.cpp \
../Assertion.cpp \
../CADC.cpp \
../CBBBHardware.cpp \
../CBinarySemaphore.cpp \
../CBrake.cpp \
../CComm_BB.cpp \
../CContainer.cpp \
../CControl_BB.cpp \
../CMPU6050.cpp \
../CMotor.cpp \
../CMutex.cpp \
../CServer.cpp \
../CThread.cpp \
../main.cpp 

OBJS += \
./AComponentBase.o \
./Assertion.o \
./CADC.o \
./CBBBHardware.o \
./CBinarySemaphore.o \
./CBrake.o \
./CComm_BB.o \
./CContainer.o \
./CControl_BB.o \
./CMPU6050.o \
./CMotor.o \
./CMutex.o \
./CServer.o \
./CThread.o \
./main.o 

CPP_DEPS += \
./AComponentBase.d \
./Assertion.d \
./CADC.d \
./CBBBHardware.d \
./CBinarySemaphore.d \
./CBrake.d \
./CComm_BB.d \
./CContainer.d \
./CControl_BB.d \
./CMPU6050.d \
./CMotor.d \
./CMutex.d \
./CServer.d \
./CThread.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	arm-linux-gnueabihf-g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


