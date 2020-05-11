#include "std_types.h"
#include "Delay_interface.h"

#include "PORT_register.h"

/* define t1 = 3.5991667 */
/* define t2 = 317.9166*/
/* define t3 = 2.656667 */
/* define t4 = 1.56667 */

#define tm (322.0f)
#define t1 3.5991667

void delay_ms(u32 t_ms)
{
  u32 i=0;
  u32 count = (u32)((float)(t_ms*1000) - (tm))/(t1);
  for(;i < count;i++)
  {
	  asm("NOP");
  }
}
