#ifndef DURATION_CLASS_H
#define DURATION_CLASS_H

class Duration
{
    private: //Attributes and methods cannot be accessed or viewed from outside the class
        int time = 0;
        int alarm;
        bool alarmHasBeenSet;
        bool checkAndUpdateAlarm();
    public: //Attributes and methods are accessible from outside the class
        int getDuration();
        Duration(); //Constructor
        ~Duration(); //Destructor
        Duration(int t);
        bool tick();
        bool tick(int dt);
        void setAlarm(int t); 
        
};

#endif