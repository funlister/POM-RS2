
#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif

void _INIT ProgramInit(void)
{
	doorSM.state = ST_INIT;
	
	int i;
	for (i = 0; i < 4; i++)
		doorSM.sw_prev[i] = doorSM.sw[i];
}

void _CYCLIC ProgramCyclic(void)
{
	doorSM.direction = !doorSM.direction;
	
	DoorStateMachine(&doorSM);
	
	driveSM.enable = 1;
	driveSM.speed = doorSM.speed;
	DriveStateMachine(&driveSM);
	
	ledSM.state = doorSM.state;
	ledSM.speed = doorSM.speed;
	LedStateMachine(&ledSM);
}

void _EXIT ProgramExit(void)
{

}

