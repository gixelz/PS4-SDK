#include "module.h"

#include "usb.h"

int (*sceUsbdInit)(void);
void (*sceUsbdExit)(void);

ssize_t (*sceUsbdGetDeviceList)(libusb_device ***list);
void (*sceUsbdFreeDeviceList)(libusb_device **list, int unrefDevices);

int (*sceUsbdGetDeviceDescriptor)(libusb_device *device, libusb_device_descriptor *desc);

int (*sceUsbdOpen)(libusb_device *dev, libusb_device_handle **devh);
libusb_device_handle *(*sceUsbdOpenDeviceWithVidPid)(unsigned short vendorId, unsigned short productId);

int (*sceUsbdControlTransfer)(libusb_device_handle *devh, uint8_t bmRequestType, uint8_t bRequest, uint16_t wValue, uint16_t wIndex, unsigned char *data, uint16_t wLength, unsigned int timeout);
int (*sceUsbdBulkTransfer)(struct libusb_device_handle *devh, unsigned char endpoint, unsigned char *data, int length, int *transferred, unsigned int timeout);
int (*sceUsbdInterruptTransfer)(struct libusb_device_handle *devh, unsigned char endpoint, unsigned char *data, int length, int *transferred,  unsigned int timeout);

int (*sceUsbdGetActiveConfigDescriptor)(libusb_device *dev, struct libusb_config_descriptor **config);
int (*sceUsbdGetConfigDescriptor)(libusb_device *dev, uint8_t config_index, struct libusb_config_descriptor **config);
int (*sceUsbdGetConfigDescriptorByValue)(libusb_device *dev, uint8_t bConfigurationValue, struct libusb_config_descriptor **config);
void (*sceUsbdFreeConfigDescriptor)(struct libusb_config_descriptor *config);

void initUsb(void) {
	int libUsb;
	loadModule("libSceUsbd.sprx", &libUsb);

	RESOLVE(libUsb, sceUsbdInit);
	RESOLVE(libUsb, sceUsbdExit);

	RESOLVE(libUsb, sceUsbdGetDeviceList);
	RESOLVE(libUsb, sceUsbdFreeDeviceList);

	RESOLVE(libUsb, sceUsbdGetDeviceDescriptor);

	RESOLVE(libUsb, sceUsbdOpen);
	RESOLVE(libUsb, sceUsbdOpenDeviceWithVidPid);

	RESOLVE(libUsb, sceUsbdControlTransfer);
	RESOLVE(libUsb, sceUsbdBulkTransfer);
	RESOLVE(libUsb, sceUsbdInterruptTransfer);

	RESOLVE(libUsb, sceUsbdGetActiveConfigDescriptor);
	RESOLVE(libUsb, sceUsbdGetConfigDescriptor);
	RESOLVE(libUsb, sceUsbdGetConfigDescriptorByValue);
	RESOLVE(libUsb, sceUsbdFreeConfigDescriptor);
}
