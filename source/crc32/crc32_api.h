static void InitCrc32(CRC_Type *base, uint32_t seed);
uint32_t accel_crc32(uint32_t start, uint32_t *data, int length);
