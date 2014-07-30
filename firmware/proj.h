#ifndef __PROJ_H__
#define __PROJ_H__

#include <msp430.h>
#include <stdlib.h>
#include "config.h"

// msp430's stdlib.h is missing these
#ifndef EXIT_SUCCESS
#define EXIT_SUCCESS    0
#endif
#ifndef EXIT_FAILURE
#define EXIT_FAILURE    1
#endif

#define true            1
#define false           0

#define LED_SWITCH      P1OUT ^= BIT2
#define LED_ON          P1OUT |= BIT2
#define LED_OFF         P1OUT &= ~BIT2

#define STR_LEN 64
char str_temp[STR_LEN];

#define VERSION             1   // must be incremented if struct settings_t changes
#define FLASH_ADDR          SEGMENT_B

void main_init(void);
void check_events(void);
void settings_init(uint8_t * addr);

struct tracy_settings_t {
    uint8_t ver;                // firmware version
    uint8_t ctrl_phone_len;
    char ctrl_phone[16];
    uint8_t apn_len;
    char apn[20];
    uint8_t user_len;
    char user[20];
    uint8_t pass_len;
    char pass[20];
    uint8_t server_len;
    char server[20];
    uint8_t port_len;
    char port[5];
};

struct tracy_settings_t s;

static const struct tracy_settings_t defaults = {
    VERSION,                    // ver
    12,
    "+40721580040",
    17,
    "live.vodafone.com",
    4,
    "live",
    8,
    "vodafone",
    14,
    "www.simplex.ro",
    2,
    "80"
};

#endif
