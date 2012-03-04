#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define CGRAY "${color2}"
#define CWHITE "${color0}"
#define CHL "${color1}"
#define CRESET "${color0}"

#define GRAY "\033[0;37m"
#define WHITE "\033[0;97m"
#define HL "\033[0;32m"
#define RESET "\033[0m"




//Settings for printing
struct printSettings {
    int today;
    int howMany;
    char *title;
    char *todayColor;
    char *future;
    char *reset;
};

//Creates the struct that holds all print settings
struct printSettings *createSettings(int initDay)
{
    struct printSettings *temp = malloc(sizeof(struct printSettings));

    temp->howMany = 5;
    temp->today = initDay;

    return temp;
}

//Destroys the struct that holds all print settings
void destroySettings(struct printSettings *temp)
{
    free(temp);
}









//print the day names
void printHeading(char *titleColor)
{
    printf("%sSun Mon Tue Wed Thu Fri Sat\n", titleColor);
}


//print the next 5 weeks
void printWeeks(struct printSettings *a)
{
    int todayReached = 0;
    int count = a->today - dow(a->today);

    int i;
    for(i = 0; i < 7*a->howMany; i++) {
        if(!todayReached && dow(a->today) == dow(count)) {
            printf("%s %2d %s", a->todayColor, num2day(count), a->future);
            todayReached = 1;
        }
        else
            printf(" %2d ", num2day(count));

        if(dow(count++) == 6)
            printf("\n");
    }
    printf("%s", a->reset);
}


//print the current month
//or
//print any number of months
void printMonth(struct printSettings *a)
{
    int count = a->today - num2day(a->today) + 1;
    int todayReached = 0;

    int monthCounter = 0;

    int i;

    for(i = 0; i < dow(count); i++)
        printf("    ");

    int now = num2day(count);
    int then = 0;

    while(monthCounter < a->howMany) {
        if(!todayReached && count == a->today) {
            printf("%s %2d %s", a->todayColor, now, a->future);
            todayReached = 1;
        }
        else
            printf(" %2d ", now);

        if(dow(count) == 6)
            printf("\n");

        then = now;
        now = num2day(++count);

        if(now < then)
            monthCounter++;
    }
    printf("\n");
}






int print(int initDay, int argc, char **argv)
{
    char *conkyHL = CHL;
    char *conkyTitle = CGRAY;
    char *conkyFuture = CWHITE;
    char *conkyReset = CRESET;

    char *hl = HL;
    char *title = GRAY;
    char *future = WHITE;
    char *reset = RESET;


    struct printSettings *setPrint = createSettings(initDay);

    int output = 0;
    int typeflag = 0;

    int colorsAssigned = 0;
    int c;

    while((c = getopt (argc, argv, "cm::w:d:")) != -1)
        switch (c)
        {
        case 'c':
            if(colorsAssigned == 0)
            {
                setPrint->todayColor = conkyHL;
                setPrint->title = conkyTitle;
                setPrint->future = conkyFuture;
                setPrint->reset= conkyReset;
                colorsAssigned = 1;
            }
            break;
        case 'm':
            output = 1;
            typeflag++;
            printf("%d\n", typeflag);
            if(optarg != NULL)
                setPrint->howMany = atoi(optarg);
            else
                setPrint->howMany = 1;
            break;
        case 'w':
            typeflag++;
            printf("%d\n",typeflag);
            if(optarg != NULL)
                setPrint->howMany = atoi(optarg);
            break;
        case 'd':
            if(optarg != NULL)
                setPrint->today = atoi(optarg);
            break;
        }

    if(colorsAssigned == 0)
    {
        setPrint->todayColor = hl;
        setPrint->title = title;
        setPrint->future = future;
        setPrint->reset= reset;
    }


    if(typeflag > 1) {
        printf("Bad input\n");
        return 1;
    }

    printHeading(setPrint->title);
    if(output == 0)
        printWeeks(setPrint);
    else if(output == 1)
        printMonth(setPrint);

    destroySettings(setPrint);
    return 0;
}
