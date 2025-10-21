
FUNCTION_BLOCK DoorStateMachine
	VAR_INPUT
		state : DoorStates;
		direction : BOOL;
		sw : ARRAY[0..3] OF BOOL;
	END_VAR
	VAR_OUTPUT
		speed : INT;
	END_VAR
	VAR
		sw_prev : ARRAY[0..3] OF BOOL;
		sw_pressed : ARRAY[0..3] OF BOOL;
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK DriveStateMachine
	VAR_INPUT
		state : UINT;
		enable : BOOL;
		speed : INT;
	END_VAR
	VAR_OUTPUT
		command : UINT;
		speedFeedback : INT;
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK LedStateMachine
	VAR_INPUT
		state : DoorStates;
		speed : INT;
	END_VAR
	VAR_OUTPUT
		led : ARRAY[0..3] OF BOOL;
	END_VAR
	VAR
		count : UINT;
	END_VAR
END_FUNCTION_BLOCK

{REDUND_ERROR} FUNCTION SpeedToFreq : USINT (*TODO: Add your comment here*) (*$GROUP=User,$CAT=User,$GROUPICON=User.png,$CATICON=User.png*)
	VAR_INPUT
		speed : INT;
	END_VAR
END_FUNCTION
