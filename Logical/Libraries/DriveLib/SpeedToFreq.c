
#include <bur/plctypes.h>
#ifdef __cplusplus
	extern "C"
	{
#endif
	#include "DriveLib.h"
#ifdef __cplusplus
	};
#endif
/* TODO: Add your comment here */
unsigned char SpeedToFreq(signed short speed)
{
	return maxFreq * (speed > 0 ? speed : -speed) / maxSpeed;
}
