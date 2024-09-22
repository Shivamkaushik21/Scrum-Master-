#include <stdio.h>
#include <string.h>
#include <feature.h>
#include <task.h>
#include <userStory.h>
#include <main.h>
#include <stdlib.h>
int main()
{
	loadFeatures();
	loadUserStories();
	loadTasks();
	printf("\n\t####################################################");
    printf("\n\t###     Welcome to Scrum Sprint Management      ###");
    printf("\n\t###################################################");
	int ch=1;
	while(ch!=0)
	{
		printf("\n1 to Login as Scrum Master:");
		printf("\n2 to Login as Team Member:\n");
		scanf("%d",&ch);
		if (ch==1)
		{
			int userId;
			char userPassword[50];
			printf("\nEnter User ID:");
			scanf("%d",&userId);
			printf("\nEnter User Password:");
			scanf("%s",userPassword);
			int userBelonging;
			userBelonging=checkLogin(userId,userPassword);
			if (userBelonging==-1)
			{
				printf("\nEither userid or password is incorrect!");
				freeStructures();
				exit(0);
			}
			else if(userBelonging==1)
			{
				printf("\nLogged in as Scrum Master!\n");
				int tlChoice1=1;
				while(tlChoice1!=0)
				{
					printf("\n1. To Print all Features, User Stories and Tasks:");
					printf("\n2. To Add New User Story:");
					printf("\n3. To Add New Task:\n");
					scanf("%d",&tlChoice1);
					if (tlChoice1==1)
					{
						// printFeatures(f1);
						printFeatures();
						printf("\n");
						displayUserStoryLL();
						printf("\n");
						displayTaskLL();
					}
					else if(tlChoice1==2)
					{
						int storyId,featureId;
						double completionStatus;
						char storyName[STORY_NAME_LEN];
						char storyDesc[STORY_DESC_LEN];
						printf("\nEnter User Story Details:");
						printf("\nEnter Story ID:");
						scanf("%d",&storyId);
						printf("\nEnter Feature ID:");
						scanf("%d",&featureId);
						printf("\nEnter Completion Status:");
						scanf("%lf",&completionStatus);
						printf("\nEnter Story Name:");
						scanf("%s",storyName);
						printf("\nEnter Story Description:");
						scanf("%s",storyDesc);
						insert_end(storyId,featureId,completionStatus,storyName,storyDesc);
						appendUserStoryCSV(storyId,featureId,completionStatus,storyName,storyDesc);
						displayUserStoryLL();
					}
					else if(tlChoice1==3)
					{
						int taskId,storyId,completionStatusTask,userId;
						char taskName[TASK_NAME_LEN];
						char taskDesc[TASK_DESC_LEN];
						printf("\nEnter Task Details:");
						printf("\nEnter Task ID:");
						scanf("%d",&taskId);
						printf("\nEnter Story ID:");
						scanf("%d",&storyId);
						printf("\nEnter Completion Status:");
						scanf("%d",&completionStatusTask);
						printf("\nEnter User ID:");
						scanf("%d",&userId);
						printf("\nEnter Task Name:");
						scanf("%s",taskName);
						printf("\nEnter Task Description:");
						scanf("%s",taskDesc);
						appendTaskLL(taskId,storyId,completionStatusTask,userId,taskName,taskDesc);
						appendTasksCSV(taskId,storyId,completionStatusTask,userId,taskName,taskDesc);
						displayTaskLL();
					}
				}
				freeStructures();
				exit(0);
			}
			else
			{
				printf("\nYou cannot login as Scrum Master from here!");
				freeStructures();
				exit(0);
			}
		}
		if (ch==2)
		{
			int userId;
			char userPassword[50];
			printf("\nEnter User ID:");
			scanf("%d",&userId);
			printf("\nEnter User Password:");
			scanf("%s",userPassword);
			int userBelonging;
			userBelonging=checkLogin(userId,userPassword);
			if (userBelonging==-1)
			{
				printf("\nEither userid or password is incorrect!");
				freeStructures();
				exit(0);
			}
			else if(userBelonging==0)
			{
				printf("\nLogged in as team Member!\n");
				int tlchoice2=1;
				while(tlchoice2!=0)
				{
					printf("\n1. To print My Assigned Tasks:");
					printf("\n2. To Update Task:\n");
					scanf("%d",&tlchoice2);
					if (tlchoice2==1)
					{
						displayUserTasks(userId);
						continue;
					}
					else if (tlchoice2==2)
					{
						int taskId,completionStatus;
						printf("\n Enter Task ID to Update:");
						scanf("%d",&taskId);
						printf("\n Enter New Completion Status:");
						scanf("%d",&completionStatus);
						updateCompletionStatus(taskId,completionStatus);
						calculations();
						continue;
					}
					else
					{
						freeStructures();
						exit(0);
					}
				}
				freeStructures();
				exit(0);
			}
			else
			{
				printf("\nYou cannot login as Scrum Master from here!");
				freeStructures();
				exit(0);
			}
		}
	}
	freeStructures();
	printf("\nExiting...!");
	exit(0);
}
