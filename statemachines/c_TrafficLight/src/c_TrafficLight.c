/*
 * Example code for a very simple statemachine.
 *
 * Used in teaching C programming on embedded systems at EAL
 *
 */

#include <stdio.h>
#include <stdlib.h>

// State definitions
enum states {
	R_RY, R_G, R_Y, RY_R, G_R, Y_R, MAXSTATES
};
// Event definitions
enum events {
	TICK, MAXEVENTS
};

int State = R_RY;

// forward function declarations
void Do(int State);
void OnEnter(int State);
void OnExit(int State);
void TrafficLightSM(int event);
//------------------------------

int main() { // By sending hardcoded events to the SM, it is possible to
// simulate how it works.
	int i;
	for (i = 0; i < 12; i++) {
		TrafficLightSM(TICK);
	}

	/* In an actual system it would look more like this:
	 *
	 * while (1)
	 * {
	 * 		event = Input();
	 * 		TurnstileSM( event );
	 * }
	 *
	 */
	return 0;
}

/* The SM does not know anything about the system. This way it can be tested on a
 * different C compiler very easily.
 */
void TrafficLightSM(int event) {
	int NextState = State;
	switch (State) {
	case R_RY:
		switch (event) {
		case TICK:
			NextState = R_G;
			break;
		default:
			break;
		}
		break;
	case R_G:
		switch (event) {
		case TICK:
			NextState = R_Y;
			break;
		default:
			break;
		}
		break;
	case R_Y:
		switch (event) {
		case TICK:
			NextState = RY_R;
			break;
		default:
			break;
		}
		break;
	case RY_R:
		switch (event) {
		case TICK:
			NextState = G_R;
			break;
		default:
			break;
		}
		break;
	case G_R:
		switch (event) {
		case TICK:
			NextState = Y_R;
			break;
		default:
			break;
		}
		break;
	case Y_R:
		switch (event) {
		case TICK:
			NextState = R_RY;
			break;
		default:
			break;
		}
		break;
	default:
		break;
		// The program should never get here !
	}

	if (NextState != State) {
		OnExit(State);
		OnEnter(NextState);
		State = NextState;
	}

	Do(State);
}

/* The 3 functions OnEnter, OnExit and Do are were all the fun happens.
 * Theee functions are written specifically for this system, and must be replaced
 * if the SM is used somewhere else - say on an embedded system.
 *
 * For simulating the SM a bunch of printf statements should be put here.
 */

void OnEnter(int State) {

}

void OnExit(int State) {

}

void Do(int State) {
	switch (State) {
	case R_RY:
		printf(" RED    \t RED+yellow\n");
		break;
	case R_G:
		printf(" RED    \t green\n");
		break;
	case R_Y:
		printf(" RED    \t yellow\n");
		break;
	case RY_R:
		printf(" RED+yellow\t RED\n");
		break;
	case G_R:
		printf(" green  \t RED\n");
		break;
	case Y_R:
		printf(" yellow  \t RED\n");
		break;

	}
}

