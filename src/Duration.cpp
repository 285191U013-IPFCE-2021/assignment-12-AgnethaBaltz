#include "Duration.hpp"
#include <assert.h>

int Duration::getDuration()
{
    return time; //Time in seconds that have elapsed
}

Duration::Duration()
{
    int time = 0; //Setting the time to zero
}

Duration::~Duration(){} // Destructor

Duration::Duration(int t) //Takes one integer argument
{
    //Precondition
    assert(time >= 0); //Elapsed time can't be negative

    time = t; //The integer argument set the time attribute
    alarm = 0; //Alarm is initialised to zero
}

bool Duration::tick()
{
    time++; //Incrementing the time

    return checkAndUpdateAlarm(); //Returning a boolean
}

bool Duration::tick(int dt) //Takes one integer argument
{
    assert(dt > 0); //The integer should be greater than zero

    time = time + dt; // Adding the integer to time, in other words we update time
    return checkAndUpdateAlarm(); // Returning a boolean

}  

void Duration::setAlarm(int t)
{
    assert(t > time); // The alarm should always be greater than the current time
    alarm = t; // Initialise the alarm
}

bool Duration::checkAndUpdateAlarm() 
{
    //Checking if the alarm has been exceeded by the time
    if(time >= alarm){
        alarmHasBeenSet = true; // Alarm has been exceeded
        alarm = 0; //Resetting the alarm
    } else {
        alarmHasBeenSet = false;
    }

    return alarmHasBeenSet; 
}