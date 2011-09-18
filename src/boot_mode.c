/*
 *  boot_mode - Detects if an iDevice is in DFU or Recovery Mode.
 *
 *  Created by Manuel Gebele on 18.09.11.
 *  Copyright 2011 Manuel Gebele. All rights reserved.
 */

#include "MobileDevice.h"

static void dfu_mode_detected(struct am_recovery_device *dev)
{
    printf("[boot_mode] - Device entered DFU Mode…\n");
    CFRunLoopStop(CFRunLoopGetCurrent());
}

static void recovery_mode_detected(struct am_recovery_device *dev)
{
    printf("[boot_mode] - Device entered Recovery Mode…\n");
    CFRunLoopStop(CFRunLoopGetCurrent());
}

int main(int arc __unused, char **argv __unused)
{
    AMRestoreRegisterForDeviceNotifications(
        dfu_mode_detected,
        recovery_mode_detected,
        NULL,
        NULL,
        0,
        NULL);
    printf("[boot_mode] - Listening for Boot Mode…\n");
    CFRunLoopRun();
    return 0;
}

