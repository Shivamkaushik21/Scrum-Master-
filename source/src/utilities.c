#include <stdio.h>
#include <string.h>
#include <feature.h>
#include <task.h>
#include <userStory.h>
#include <main.h>
#include <stdlib.h>
int checkLogin(int userId,char password[]){
    int userResult=-1;
    char* data;
    FILE *usersDataFile=fopen("../external/usersData.csv","r");
    if (usersDataFile==NULL){
        printf("Feature File not found");
        exit(0);
    }
    char userData[500];
    while(fgets(userData,500,usersDataFile)!=NULL){
        data=strtok(userData,",");
        data=strtok(NULL,",");
        int data2;
        data2=atoi(data);
        if (userId==data2){
            data=strtok(NULL,",");
            if(strcmp(data,password)==0){
                data=strtok(NULL,",");
                userResult=atoi(data);
                break;
            }
        }
    }
    fclose(usersDataFile);
    return userResult;
}

void freeStructures(){
    freeUserStoriesLL();
	freeTasksLL();
    freeFeatures();
}