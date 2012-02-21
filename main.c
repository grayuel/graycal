#include <stdio.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include "cal.h"


int main(int argc, char *argv[])
{
    const char name[] = "graycal";

    struct tm *t;
    time_t now;
    time(&now);
    t=localtime(&now);

    int year = t->tm_year +1900;
    int day = t->tm_mday; /* 1 to 31 */
    int month = t-> tm_mon; /* 0 to 11 */
    int wday = t->tm_wday; /* 0 to 6 */

    char colors[4][LENGTH] = {GRAY, WHITE, GREEN, RESET};

    char *optString = "m::c?h";




//    extern int opterr;

    opterr = 0;

    int cflag = 0;
    int mflag = 0;
    int hflag = 0;
    int errflag = 0;

    int howMany = 0;

    int opt;
    while((opt = getopt(argc, argv, optString)) != -1)
        switch(opt) {
            case 'm':
                mflag++;
                if(optarg != NULL)
                    howMany = atoi(optarg);
                break;
            case 'c':
                cflag++;
                break;
            case 'h':
                hflag++;
                break;
            default:
                errflag++;
                break;
        }

    if(errflag == 0 && cflag + mflag + hflag == 1) {
        if(mflag)
            calculateMonth(year, month, day, howMany);
        else if(cflag) {
            strcpy(colors[0], CDGRAY);
            strcpy(colors[1], CLGRAY);
            strcpy(colors[2], CHIGHLIGHT);
            strcpy(colors[3], CDGRAY);
            makeOutput(year, wday, month, day);
        }
        else if(hflag) {
            //printHelp();
            printf("Help will be here\n");
        }
    }
    else if(cflag + mflag + hflag + errflag == 0)
        makeOutput(year, wday, month, day);
    else
        printf("Ivalid options, use %s -h for help\n",name);



    printOutput(&colors[0][0], wday, day);
    return 0;
}
