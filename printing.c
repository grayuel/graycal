#include <stdio.h>
#include <stdlib.h>

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
    int startDay;
    int today;
    char *title;
    char *todayColor;
    char *future;
    char *reset;
};

//Creates the struct that holds all print settings
struct printSettings *createSettings(int count, int initDay, int outType)
{
    struct printSettings *temp = malloc(sizeof(struct printSettings));

    temp->startDay = count;
    temp->today = initDay;
    if(!outType){
        temp->title = GRAY;
        temp->todayColor = HL;
        temp->future = WHITE;
        temp->reset = RESET;
    }
    else {
        temp->title = CGRAY;
        temp->todayColor = CHL;
        temp->future = CWHITE;
        temp->reset = CRESET;
    }

    return temp;
}

//Destroys the struct that holds all print settings
void destroySettings(struct printSettings *temp)
{
    free(temp);
}




void printHeading(char *titleColor)
{
    printf("%sSun Mon Tue Wed Thu Fri Sat\n", titleColor);
}

void printWeeks(struct printSettings *a)
{
    int i;
    int todayReached = 0;
    int count = a->startDay;

    for(i = 0; i < 35; i++) {
        if(!todayReached && dow(a->today) == dow(count)) {
            printf("%s %2d %s", a->todayColor, num2day(a->today), a->future);
            todayReached = 1;
        }
        else
            printf(" %2d ", num2day(count));

        if(dow(count++) == 6)
            printf("\n");
    }
    printf("%s", a->reset);
}

void print(int count, int initDay, int outType)
{
    struct printSettings *setPrint = createSettings(count, initDay, outType);

    printHeading(setPrint->title);
    printWeeks(setPrint);
    destroySettings(setPrint);
}
