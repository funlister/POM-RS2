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
void DoorStateMachine(struct DoorStateMachine* inst)
{
	switch (inst->state)
	{
		case ST_INIT:
			inst->state = ST_UNKNOWN;
			break;
		case ST_UNKNOWN:
			if (inst->direction == 1)
				inst->speed = maxSpeed / 5;
			else
				inst->speed = -maxSpeed / 5;
			
			if (inst->direction == 0 && inst->sw[0] != inst->sw_prev[0])
			{
				inst->state = ST_OPEN;
				inst->speed = 0;
			}
			else if (inst->direction == 1 && inst->sw[3] != inst->sw_prev[3])
			{
				inst->state = ST_CLOSE;
				inst->speed = 0;
			}
			break;
		case ST_OPEN:
			if (inst->direction == 1)
			{
				inst->state = ST_ACC_POS;
				inst->speed = minSpeed;
			}
			break;
		case ST_ACC_POS:
			if (inst->sw[1] != inst->sw_prev[1])
			{
				inst->state = ST_POS;
				inst->speed = maxSpeed / 2;
			}
			else if (inst->direction == 0)
			{
				inst->state = ST_DEC_NEG;
				inst->speed = -minSpeed;
			}
			break;
		case ST_POS:
			if (inst->sw[2] != inst->sw_prev[2])
			{
				inst->state = ST_DEC_POS;
				inst->speed = minSpeed;
			}
			else if (inst->direction == 0)
			{
				inst->state = ST_NEG;
				inst->speed = -maxSpeed / 2;
			}
			break;
		case ST_DEC_POS:
			if (inst->sw[3] != inst->sw_prev[3])
			{
				inst->state = ST_CLOSE;
				inst->speed = 0;
			}
			else if (inst->direction == 0)
			{
				inst->state = ST_ACC_NEG;
				inst->speed = -minSpeed;
			}
			break;
		case ST_CLOSE:
			if (inst->direction == 0)
			{
				inst->state = ST_ACC_NEG;
				inst->speed = -minSpeed;
			}
			break;
		case ST_ACC_NEG:
			if (inst->sw[2] != inst->sw_prev[2])
			{
				inst->state = ST_NEG;
				inst->speed = -maxSpeed / 2;
			}
			else if (inst->direction == 1)
			{
				inst->state = ST_DEC_POS;
				inst->speed = minSpeed;
			}
			break;
		case ST_NEG:
			if (inst->sw[1] != inst->sw_prev[1])
			{
				inst->state = ST_DEC_NEG;
				inst->speed = -minSpeed;
			}
			else if (inst->direction == 1)
			{
				inst->state = ST_POS;
				inst->speed = maxSpeed / 2;
			}
			break;
		case ST_DEC_NEG:
			if (inst->sw[0] != inst->sw_prev[0])
			{
				inst->state = ST_OPEN;
				inst->speed = 0;
			}
			else if (inst->direction == 1)
			{
				inst->state = ST_ACC_POS;
				inst->speed = minSpeed;
			}
			break;
	}
	
	//memorizing states' switch for buttons
	int i;
	for (i = 0; i < 4; i++)
	{
		inst->sw_pressed[i] = (inst->sw[i] != inst->sw_prev[i]);
		inst->sw_prev[i] = inst->sw[i];
	}
}
