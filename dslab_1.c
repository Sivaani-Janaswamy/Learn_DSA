/*
 Develop a Program in C for the following: a) Declare a
 calendar as an array of 7 elements (A dynamically Created
 array) to represent7 days of a week. Each Element of the
 array is a structure having three fields. The first field is the
 name of the Day (A dynamically allocated String), The
 second field is the date of the Day (A integer), the third
 field is the description of the activity for a particular day (A
 dynamically allocated String).
 b) Write functions create(), read() and display(); to create
 the calendar, to read the data from the keyboard and to
 print weeks activity details report on screen
*/#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct 
{
    char* dayname;
    int date;
    char* activity;
    /* data */
}DayInfo;
DayInfo* create(){
    DayInfo* day = (DayInfo*)malloc(sizeof(DayInfo));
    if (day == NULL) 
    {
    fprintf(stderr, "Memory allocation failed!\n");
    exit(EXIT_FAILURE); 
    }
    day->dayname = NULL;
    day->activity = NULL;
    return day;
}

DayInfo* read(DayInfo* day){
     char temp[100];
     printf("Enter day name: \n ");
     fgets(temp, sizeof(temp),stdin);
     temp[strcspn(temp,"\n")] = '\0';
     day->dayname = strdup(temp);

     printf("Enter date: \n");
     scanf("%d",&day->date);
     getchar();

     printf("Enter activity name: \n ");
     fgets(temp, sizeof(temp),stdin);
     temp[strcspn(temp,"\n")] = '\0';
     day->activity = strdup(temp);

}
DayInfo* display(DayInfo* week,int numDays){
     printf("Weeks activity details \n ");
     for(int i = 0; i<numDays;i++){
        printf("Day %d name: %s date: %d activity: %s \n",i+1,week[i].dayname,week[i].date,week[i].activity);
     }
}
int main(){
    int numDays = 7;
    DayInfo* week = (DayInfo*)malloc(sizeof(DayInfo));
    if(week == NULL){
    fprintf(stderr, "Memory allocation failed!\n");
    exit(EXIT_FAILURE); 
    }
    for(int i = 0; i<numDays;i++){
        week[i]=*create();
        read(&week[i]);
    }
    display(week,numDays);
    
    for(int i = 0;i<numDays;i++){
        free(week[i].dayname);
        free(week[i].activity);
    }
    free(week);
    return 0;

}