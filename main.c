#include <stdio.h>
#include <time.h>
#include <string.h>
#include "cal.h"


int main(int argc, char *argv[])
{
    struct tm *t;
    time_t now;
    time(&now);
    t=localtime(&now);

    int year = t->tm_year +1900;
    int day = t->tm_mday; /* 1 to 31 */
    int month = t-> tm_mon; /* 0 to 11 */
    int wday = t->tm_wday; /* 0 to 6 */

    int i;
    char colors[4][LENGTH] = {GRAY, WHITE, GREEN, RESET};

    char *optString = "mc?h";

    if(argc == 1)
        makeOutput(year, wday, month, day);


    int opt = getopt(argc, argv, optString);
    while(opt != -1) {
        switch(opt) {
            case 'm':
                monthlyOutput(year, wday, month, day);
                break;
            case 'c':
                strcpy(colors[0], CDGRAY);
                strcpy(colors[1], CLGRAY);
                strcpy(colors[2], CHIGHLIGHT);
                strcpy(colors[3], CDGRAY);
                makeOutput(year, wday, month, day);
                break;
            case '?': case 'h':
                //printUsage();
                printf("Help will be here");
                break;
            default:
                printf("This shouldn't happen");
                break;
        }
        opt = getopt(argc, argv, optString);
    }

    printOutput(&colors[0][0], wday, day);

    return 0;
}
