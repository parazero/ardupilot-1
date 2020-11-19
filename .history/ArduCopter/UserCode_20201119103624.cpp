#include "Copter.h"

#ifdef USERHOOK_INIT
void Copter::userhook_init()
{
    // put your initialisation code here
    // this will be called once at start-up
    hal.console->printf("UID: %lu - %lu - %lu\r\n", (*(unsigned long*)0x1FF0F420),(*(unsigned long*)0x1FF0F424),(*(unsigned long*)0x1FF0F428));
    motors->set_update_rate(490);
    motors->init(AP_Motors::MOTOR_FRAME_QUAD, AP_Motors::MOTOR_FRAME_TYPE_X);
    motors->output_min();
}
#endif

#ifdef USERHOOK_FASTLOOP
void Copter::userhook_FastLoop()
{
    // put your 100Hz code here
}
#endif

#ifdef USERHOOK_50HZLOOP
void Copter::userhook_50Hz()
{
    // put your 50Hz code here
}
#endif

#ifdef USERHOOK_MEDIUMLOOP
void Copter::userhook_MediumLoop()
{
    // put your 10Hz code here
}
#endif

#ifdef USERHOOK_SLOWLOOP
void Copter::userhook_SlowLoop()
{
    // put your 3.3Hz code here
    // hal.console->printf("hello?\r\n");

    double localRoll = (double)ToDeg(ahrs.roll);
    double localPitch = (double)ToDeg(ahrs.pitch);
    hal.console->printf("Roll: %6.3f, Pitch: %6.3f\r\n", localRoll,localPitch);
    if (fabs(localRoll) > 45.0)
    {
        hal.console->printf("I am great!\r\n");
        motors->armed(false);
        copter.failsafe_enable();
    }
    else
    {
        hal.console->printf("I am small!\r\n");
        copter.failsafe_disable();
        motors->armed(true);
    }
    
}
#endif

#ifdef USERHOOK_SUPERSLOWLOOP
void Copter::userhook_SuperSlowLoop()
{
    // put your 1Hz code here
}
#endif

#ifdef USERHOOK_AUXSWITCH
void Copter::userhook_auxSwitch1(uint8_t ch_flag)
{
    // put your aux switch #1 handler here (CHx_OPT = 47)
}

void Copter::userhook_auxSwitch2(uint8_t ch_flag)
{
    // put your aux switch #2 handler here (CHx_OPT = 48)
}

void Copter::userhook_auxSwitch3(uint8_t ch_flag)
{
    // put your aux switch #3 handler here (CHx_OPT = 49)
}
#endif
