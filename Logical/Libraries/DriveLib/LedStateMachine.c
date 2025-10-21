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
void LedStateMachine(struct LedStateMachine* inst)
{
	inst->count++;
	int i;
	switch (inst->state)
	{
		case ST_INIT:
			for (i = 0; i < 4; i++)
				inst->led[i] = 0;
			break;
		case ST_UNKNOWN:
			if (inst->count % (500 / cycleTime) == 0)
			{
				for (i = 0; i < 4; i++)
					inst->led[i] = !inst->led[i];
			}
			break;
		case ST_OPEN:
			for (i = 0; i < 4; i++)
				inst->led[i] = 0;
			break;
		case ST_ACC_POS:
			inst->led[3] = 0;
			inst->led[2] = 0;
			if (inst->count % (500 / (cycleTime * SpeedToFreq(inst->speed))) == 0)
				inst->led[1] = !inst->led[1];
			inst->led[0] = 1;
			break;
		case ST_POS:
			inst->led[3] = 0;
			if (inst->count % (500 / (cycleTime * SpeedToFreq(inst->speed))) == 0)
				inst->led[2] = !inst->led[2];
			inst->led[1] = 1;
			inst->led[0] = 1;
			break;
		case ST_DEC_POS:
			if (inst->count % (500 / (cycleTime * SpeedToFreq(inst->speed))) == 0)
				inst->led[3] = !inst->led[3];
			inst->led[2] = 1;
			inst->led[1] = 1;
			inst->led[0] = 1;
			break;
		case ST_CLOSE:
			for (i = 0; i < 4; i++)
				inst->led[i] = 1;
			break;
		case ST_ACC_NEG:
			inst->led[3] = 0;
			if (inst->count % (500 / (cycleTime * SpeedToFreq(inst->speed))) == 0)
				inst->led[2] = !inst->led[2];
			inst->led[1] = 1;
			inst->led[0] = 1;
			break;
		case ST_NEG:
			inst->led[3] = 0;
			inst->led[2] = 0;
			if (inst->count % (500 / (cycleTime * SpeedToFreq(inst->speed))) == 0)
				inst->led[1] = !inst->led[1];
			inst->led[0] = 1;
			break;
		case ST_DEC_NEG:
			inst->led[3] = 0;
			inst->led[2] = 0;
			inst->led[1] = 0;
			if (inst->count % (500 / (cycleTime * SpeedToFreq(inst->speed))) == 0)
				inst->led[0] = !inst->led[0];
			break;
	}
}
