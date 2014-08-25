#ifndef _ADC_CONFIG_BLOCK_H
#define _ADC_CONFIG_BLOCK_H

#include "AIOTypes.h"
#include <stdlib.h>
#include <string.h>

#ifdef __aiousb_cplusplus
namespace AIOUSB
{
#endif

typedef struct aio_usb_driver AIOUSBDevice ;


typedef struct adc_config_block {
    AIOUSBDevice *device; /**< Pointer to the device Descriptor */
    unsigned long size;
    AIOUSB_BOOL testing;          /**< For making Unit tests that don't talk to hardware */
    unsigned char registers[ AD_MAX_CONFIG_REGISTERS +1];
    int timeout;
} ADCConfigBlock;


PUBLIC_EXTERN AIORET_TYPE ADCConfigBlockInit( ADCConfigBlock *, AIOUSBDevice *deviceDesc, unsigned int );
PUBLIC_EXTERN void ADC_VerifyAndCorrectConfigBlock( ADCConfigBlock *configBlock , AIOUSBDevice *deviceDesc  );
PUBLIC_EXTERN AIORET_TYPE ADCConfigBlockSetAllGainCodeAndDiffMode(ADCConfigBlock *config, unsigned gainCode, AIOUSB_BOOL differentialMode);

PUBLIC_EXTERN unsigned char *ADCConfigBlockGetRegisters( ADCConfigBlock *config );
PUBLIC_EXTERN AIORET_TYPE ADCConfigBlockSetRegister( ADCConfigBlock *config, unsigned reg, unsigned char value );

PUBLIC_EXTERN AIORET_TYPE ADCConfigBlockGetGainCode( const  ADCConfigBlock *config, unsigned channel );
PUBLIC_EXTERN AIORET_TYPE ADCConfigBlockSetGainCode(ADCConfigBlock *config, unsigned channel, ADGainCode gainCode);



PUBLIC_EXTERN AIORET_TYPE ADCConfigBlockSetScanRange(ADCConfigBlock *config, unsigned startChannel, unsigned endChannel);


PUBLIC_EXTERN AIORET_TYPE ADCConfigBlockSetCalMode(ADCConfigBlock *config, ADCalMode calMode);
PUBLIC_EXTERN AIORET_TYPE ADCConfigBlockGetCalMode(const ADCConfigBlock *config);



PUBLIC_EXTERN AIORET_TYPE ADCConfigBlockGetStartChannel(const ADCConfigBlock *config);
PUBLIC_EXTERN AIORET_TYPE ADCConfigBlockGetEndChannel(const ADCConfigBlock *config);

PUBLIC_EXTERN AIORET_TYPE ADCConfigBlockGetOversample( const ADCConfigBlock *config );
PUBLIC_EXTERN AIORET_TYPE ADCConfigBlockSetOversample( ADCConfigBlock *config, unsigned overSample );

PUBLIC_EXTERN AIORET_TYPE ADCConfigBlockGetTriggerMode(const ADCConfigBlock *config);
PUBLIC_EXTERN AIORET_TYPE ADCConfigBlockSetTriggerMode(ADCConfigBlock *config, unsigned triggerMode);

PUBLIC_EXTERN AIORET_TYPE ADCConfigBlockSetDifferentialMode(ADCConfigBlock *config, unsigned channel, AIOUSB_BOOL differentialMode);
PUBLIC_EXTERN AIORET_TYPE ADCConfigBlockSetRangeSingle(ADCConfigBlock *config, unsigned long channel, unsigned char gainCode);


PUBLIC_EXTERN AIORET_TYPE ADCConfigBlockCopy( ADCConfigBlock *to, ADCConfigBlock *from );
PUBLIC_EXTERN AIORET_TYPE ADCConfigBlockSetDevice( ADCConfigBlock *obj, AIOUSBDevice *dev );
PUBLIC_EXTERN AIOUSBDevice *ADCConfigBlockGetAIOUSBDevice( ADCConfigBlock *obj, AIORET_TYPE *result );
PUBLIC_EXTERN AIORET_TYPE ADCConfigBlockInitialize( ADCConfigBlock *obj );

PUBLIC_EXTERN AIORET_TYPE ADCConfigBlockSetTesting( ADCConfigBlock *obj, AIOUSB_BOOL testing );
PUBLIC_EXTERN AIORET_TYPE ADCConfigBlockGetTesting( const ADCConfigBlock *obj );


#ifdef __aiousb_cplusplus
}
#endif


#endif