#ifndef BELSE_CIRC_SHIFT_H_
#define BELSE_CIRC_SHIFT_H_

#include <stdint.h>
#include <limits.h>

inline uint8_t rotl8(uint8_t value, int shift)
{
    unsigned int u_shift = (sizeof(value)*CHAR_BIT) + (shift%(sizeof(value)*8));
    return (value<<u_shift) | (value>>((sizeof(value)*CHAR_BIT)-u_shift));
}

inline uint8_t rotr8(uint8_t value, int shift)
{
    unsigned int u_shift = (sizeof(value)*CHAR_BIT) + (shift%(sizeof(value)*8));
    return (value>>u_shift) | (value<<((sizeof(value)*CHAR_BIT)-u_shift));
}

inline uint16_t rotl16(uint16_t value, int shift)
{
    unsigned int u_shift = (sizeof(value)*CHAR_BIT) + (shift%(sizeof(value)*8));
    return (value<<u_shift) | (value>>((sizeof(value)*CHAR_BIT)-u_shift));
}

inline uint16_t rotr16(uint16_t value, int shift)
{
    unsigned int u_shift = (sizeof(value)*CHAR_BIT) + (shift%(sizeof(value)*8));
    return (value>>u_shift) | (value<<((sizeof(value)*CHAR_BIT)-u_shift));
}

inline uint32_t rotl32(uint32_t value, int shift)
{
    unsigned int u_shift = (sizeof(value)*CHAR_BIT) + (shift%(sizeof(value)*8));
    return (value<<u_shift) | (value>>((sizeof(value)*CHAR_BIT)-u_shift));
}

inline uint32_t rotr32(uint32_t value, int shift)
{
    unsigned int u_shift = (sizeof(value)*CHAR_BIT) + (shift%(sizeof(value)*8));
    return (value>>u_shift) | (value<<((sizeof(value)*CHAR_BIT)-u_shift));
}

#endif /* BELSE_CIRC_SHIFT_H_ */
