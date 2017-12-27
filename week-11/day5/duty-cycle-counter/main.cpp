#include <iostream>
#include <string>
#include <sstream>
#include <inttypes.h>

#define MAX_RELOAD 0xFFFF

class PWMParams {
    private:
        int mPeriodCycles;
        int mPrescaler;
        int mOverflow;
        int mDuty;
    public:
        int getPeriodCycles();
        int getPrescaler();
        int getOverflow();
        int getDuty();
        void setPeriodCycles(int _periodCycles);
        void setPrescaler(int _prescaler);
        void setOverflow(int _overflow);
        void setDuty(int _duty);
        PWMParams();
        PWMParams(int _duty, int _prescaler, int _periodCycles, int _overflow);
        std::string toString();
};

PWMParams::PWMParams(): mPeriodCycles(0), mPrescaler(0), mOverflow(0), mDuty(0) {}
PWMParams::PWMParams(int _duty, int _prescaler, int _periodCycles, int _overflow): mDuty(_duty), mPrescaler(_prescaler), mPeriodCycles(_periodCycles), mOverflow(_overflow) {}
int PWMParams::getPeriodCycles(){
    return mPeriodCycles;
}

int PWMParams::getPrescaler(){
    return mPrescaler;
}

int PWMParams::getOverflow(){
    return mOverflow;
}

int PWMParams::getDuty(){
    return mDuty;
}

void PWMParams::setPeriodCycles(int _periodCycles){
    mPeriodCycles = _periodCycles;
}

void PWMParams::setPrescaler(int _prescaler){
    mPrescaler = _prescaler;
}

void PWMParams::setOverflow(int _overflow){
    mOverflow = _overflow;
}

void PWMParams::setDuty(int _duty){
    mDuty = _duty;
}

std::string PWMParams::toString(){
    std::stringstream stream;
    stream << "PWM Params: Duty: " << mDuty << ", Prescaler: " << mPrescaler << ", PeriodCycles: " << mPeriodCycles << ", Overflow: " << mOverflow;
    return stream.str();
}

class CPU {
    private:
        int mFrequency;
    public:
        CPU(int _frequency);
        int getFrequency();
        void setFrequency(int _frequency);
        std::string toString();
        PWMParams getPWMParams(int _duty, int _PWMFrequency);
};

CPU::CPU(int _frequency = 72000000): mFrequency(_frequency){}

int CPU::getFrequency(){
    return mFrequency;
}

void CPU::setFrequency(int _frequency){
    mFrequency = _frequency;
}

std::string CPU::toString(){
    std::stringstream stream;
    stream << "CPU: Frequency: " << mFrequency;
    return stream.str();
}

PWMParams CPU::getPWMParams(int _duty, int _PWMFrequency = 250) {
    uint32_t period = mFrequency / _PWMFrequency;
    uint16_t prescaler = (uint16_t)(period / (MAX_RELOAD + 1));
    uint16_t overflow = (uint16_t)((period + (prescaler / 2)) / prescaler);
    uint16_t duty = (uint16_t)(overflow / (100 / _duty));
    // duty, prescaler, period, overflow
    PWMParams params(duty, prescaler, mFrequency/_PWMFrequency, overflow);
    return params;
}

int main(){
    CPU cpu(72000000);
    std::cout << cpu.toString() << "\n";
    std::cout << cpu.getPWMParams(50).toString() << "\n";
    return 0;
}
