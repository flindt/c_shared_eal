/*
 * Example code for a very simple statemachine.
 *
 * Used in teaching C programming on embedded systems at EAL
 *
 */

#include <stdio.h>
#include <stdlib.h>

// State definitions
enum states { LOCKED, UNLOCKED, MAXSTATES };
// Event definitions
enum events { PAYED, PERSONPASSED, TICK, MAXEVENTS };

int TS_State = LOCKED;

// forward function declarations
void Do( int State );
void OnEnter( int State);
void OnExit( int State);
void TurnstileSM(int event);
//------------------------------

int main()
{	// By sending hardcoded events to the SM, it is possible to
	// simulate how it works.
    TurnstileSM( PAYED );

    TurnstileSM( PAYED );
    int i;
    for(i=0; i<4; i++)
		{
    	TurnstileSM( TICK );
		}
    TurnstileSM( PERSONPASSED );
    TurnstileSM( PAYED );

    for(i=0; i<5; i++)
    		{
        	TurnstileSM( TICK );
    		}
        TurnstileSM( PAYED );
        TurnstileSM( PERSONPASSED );
        for(i=0; i<20; i++)
        		{
            	TurnstileSM( TICK );
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
void TurnstileSM( int event )
{
    int NextState = TS_State;
    static int Timeout,Count = 0, t = 5;
    switch( TS_State )
    {
        case LOCKED:
            switch (event )
            {
			case PAYED:
				NextState = UNLOCKED;
				Count++;
				printf("You can enter\n");
				break;
			default:
				break;
            }
            break;
        case UNLOCKED:
        	switch (event )
			{
			case PAYED:
				Count++;
				Timeout  = Count*t;
				printf("Persons Payed for %i\n",Count);
				NextState = UNLOCKED;
				break;

			case PERSONPASSED:
				Count--;
				printf("Persons entered\n");
				printf("%i Persons can stil enter\n",Count);
				Timeout = Count*t;
				if(Count <= 0)
				{
					NextState = LOCKED;
					Count = 0;
					Timeout = 5;
				}
				break;

			case TICK:
				printf("Ticks = %i\n",Timeout);
				Timeout--;
				if(Timeout <= 0)
					{
						NextState = LOCKED;
						printf("You didnt make it - ");
						Timeout = t;
						Count = 0;
					}
				break;
			default:
				break;
			}
            break;

        default:
            break;
            // The program should never get here !
    }

    if (NextState != TS_State)
    {
        OnExit(TS_State);
        OnEnter(NextState);
        TS_State = NextState;
    }

    Do( TS_State );
}

/* The 3 functions OnEnter, OnExit and Do are were all the fun happens.
 * Theee functions are written specifically for this system, and must be replaced
 * if the SM is used somewhere else - say on an embedded system.
 *
 * For simulating the SM a bunch of printf statements should be put here.
 */

void OnEnter( int State )
{

}

void OnExit( int State)
{

}

void Do( int State)
{
    switch (State)
    {
        case LOCKED:
            printf("Door is Locked!\n");
            break;
        case UNLOCKED:
            printf("Door is unlocked.\n");
            break;
    }
}

