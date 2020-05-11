#ifndef STD_TYPES_H
#define STD_TYPES_H

typedef	signed char					  s8,		sint8_t;
typedef	unsigned char				  u8,		uint8_t;

typedef	signed short int		  s16,	sint16_t;
typedef	unsigned short int	  u16,	uint16_t;

typedef	signed long int				s32,	sint32_t;
typedef	unsigned long int			u32,	uint32_t;

typedef	signed long long			s64,	sint64_t;
typedef	unsigned long long			u64,	uint64_t;

typedef	float									f32;
typedef	double								f64;
typedef	long double						f96;

typedef enum Error
{
	OK,
	NOK,
	NULLPOINTER,
	TIMEOUT,
	INVALID_INPUT,
	BUSY
	
}ErrorStatus;


#define		ENABLED						1

#define		DISABLED					0

#define		NULL						(void*)0

#endif
