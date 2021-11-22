#include "fsl_crc.h"

// copied from examples.
static void InitCrc32(CRC_Type *base, uint32_t seed)
{
    crc_config_t config;

    config.polynomial    = 0xedb88320;
    config.reverseIn     = true;
    config.complementIn  = false;
    config.reverseOut    = true;
    config.complementOut = true;
    config.seed          = seed;

    CRC_Init(base, &config);
}

uint32_t accel_crc32(uint32_t start, uint32_t *data, int length) {
	InitCrc32(CRC_ENGINE, start);
	// length is in bytes.
    CRC_WriteData(CRC_ENGINE, (uint8_t *)data, length * 4);
    uint32_t checksum = CRC_Get32bitResult(CRC_ENGINE);
    return checksum;
}
