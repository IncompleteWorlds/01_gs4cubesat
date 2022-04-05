/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */

#include "CommonTypes.h"

#include "Crc.h"

/*
 * This can be used when we want to calculate a single CRC over disjoint data.
 *
 * 	crc = crc16 (region1, sizeof(region1), 0xffff);
 *	crc = crc16 (region2, sizeof(region2), crc);
 *	crc = crc16 (region3, sizeof(region3), crc);
 */
ushort crc16(uint8_t *data, uint len, ushort seed)
{
    ushort crc = seed;

    for (uint i = 0; i < len; i++)
    {
      crc = ((crc) >> 8) ^ ccitt_table[((crc) ^ data[i]) & 0xff];
    }

    return ( crc ^ 0xffff );
}

ushort crc16(VectorUint8& inBuffer, ushort inSeed)
{
    ushort crc = inSeed;

    for (uint8_t currentByte: inBuffer)
    {
      crc = ((crc) >> 8) ^ ccitt_table[((crc) ^ currentByte) & 0xff];
    }

    return ( crc ^ 0xffff );
}


