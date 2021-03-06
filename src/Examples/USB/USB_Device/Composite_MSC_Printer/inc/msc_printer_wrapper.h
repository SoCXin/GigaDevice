/*!
    \file  msc_printer_wrapper.h
    \brief header file for the msc_printer_wrapper.c file
    

    \version 2016-08-15, V1.0.0, firmware for GD32F4xx
    \version 2018-12-12, V2.0.0, firmware for GD32F4xx
*/

/*
    Copyright (c) 2018, GigaDevice Semiconductor Inc.

    All rights reserved.

    Redistribution and use in source and binary forms, with or without modification, 
are permitted provided that the following conditions are met:

    1. Redistributions of source code must retain the above copyright notice, this 
       list of conditions and the following disclaimer.
    2. Redistributions in binary form must reproduce the above copyright notice, 
       this list of conditions and the following disclaimer in the documentation 
       and/or other materials provided with the distribution.
    3. Neither the name of the copyright holder nor the names of its contributors 
       may be used to endorse or promote products derived from this software without 
       specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED 
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. 
IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, 
INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT 
NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR 
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, 
WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY 
OF SUCH DAMAGE.
*/

#ifndef MSC_PRINTER_WRAPPER_H
#define MSC_PRINTER_WRAPPER_H

#include "usbd_msc_core.h"
#include "printer_core.h"

#define MSC_INTERFACE                    0x00
#define PRINTER_INTERFACE                0x01
#define MSC_PRINTER_CONFIG_DESC_SIZE     0x37

typedef struct
{
    usb_descriptor_configuration_struct               Config;
    usb_descriptor_interface_struct                   MSC_Interface;
    usb_descriptor_endpoint_struct                    MSC_DataInEndpoint;
    usb_descriptor_endpoint_struct                    MSC_DataOutEndpoint;
    usb_descriptor_interface_struct                   Printer_interface;
    usb_descriptor_endpoint_struct                    Printer_DataInEndpoint;
    usb_descriptor_endpoint_struct                    Printer_DataOutEndpoint;
} usb_msc_printer_descriptor_configuration_set_struct;

extern const usb_descriptor_device_struct device_descripter;
extern const usb_msc_printer_descriptor_configuration_set_struct msc_printer_configuration_descriptor;
extern uint8_t* usbd_strings[];

/* function declarations */
/* initialize the HID/CDC device */
uint8_t msc_printer_init (void *pudev, uint8_t config_index);
/* de-initialize the HID/CDC device */
uint8_t msc_printer_deinit (void *pudev, uint8_t config_index);
/* handle the custom HID/CDC class-specific and standard requests */
uint8_t msc_printer_req_handler (void *pudev, usb_device_req_struct *req);
/* handle data stage */
uint8_t msc_printer_data_handler (void *pudev, usb_dir_enum rx_tx, uint8_t ep_id);

#endif  /* MSC_PRINTER_WRAPPER_H */
