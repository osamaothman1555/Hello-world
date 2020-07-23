#include "mbed.h"
#include "C12832.h"

// Using Arduino pin notation
C12832 lcd(D11, D13, D12, D7, D10); // copy the diary classes and use tickers to update the number of seconds and lcd blah

class date{

    private:
    int day, month, year;
    public:
    date(){
        day = 0;
        month = 0;
        year = 0;
        }
    date( int d, int m, int y ){
        day = d;
        month = m;
        year = y;

        }
    void set_date(int d, int m, int y ){

        day = d;
        month = m;
        year = y;

        }
    int get_day(){ return day;}

    int get_month(){ return month;}

    int get_year(){ return year; }

    };

class time_keeper{
    private:
    int sec, min, hour;
    date mydate;

    public:

    void set_the_date( int d, int m, int y){
        mydate.set_date( d, m, y);
        }

    time_keeper(){
    sec = 0;
    min = 0;
    hour = 0;
    clock();
    }

    void clock(){
        inc_sec();
        if( (sec == 59)){
            inc_min();
            }
        if( min == 59){
            inc_hour();
            }
        wait(1);
       }

    void inc_sec(){
            sec += 1;
        if(sec == 60){
             sec = 0;
            }
    }

    void inc_min(){
        min += 1;
            if(min == 60){
                min = 0;
                    }
    }

    void inc_hour(){
     hour += 1;
        if( hour == 24){
            hour = 0;
        }
    }

   int get_sec(){ return sec; }
    int get_min(){ return min; }
    int get_hour(){ return hour; }
    int get_this_day(){ return mydate.get_day();)
    int get_this_month(){
    int get_this_year()
};


int main()
{
    int j = 0;
    lcd.cls();
    lcd.locate(0,3);
    lcd.printf("mbed application shield!");


    while( j<100 ){

    lcd.locate(8,20);
    lcd.printf("%d", j);

    wait(1);
    j++;
    }
   /* while(true) {   // this is the third thread
        lcd.locate(0,20);
        lcd.printf("Counting : %d",j);
        j++;
        wait(1.0); // very wasteful
    }*/


}
