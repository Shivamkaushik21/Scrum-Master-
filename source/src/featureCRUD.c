#include <stdio.h>
#include <string.h>
#include <feature.h>
#include <task.h>
#include <userStory.h>
#include <main.h>
#include <stdlib.h>
#define LINE_SIZE 500
feature *f1=NULL;
void printFeatures(){
	printf("\n------------------------------------------------Feature Details------------------------------------------------\n");
	printf("\nFeature ID:\tCompletion Status:\tFeature Name:\t\t\tFeature Info:");
	printf("\n\t%d",f1->featureId);
	printf("\t\t%lf",f1->completionStatus);
	printf("\t%s",f1->featureName);
	printf("\t\t\t%s\n",f1->featureDesc);
	printf("\n--------------------------------------------END of Feature Details---------------------------------------------\n");

}

void loadFeatures(){
	feature *temp;
    temp=(feature *)malloc(sizeof(feature));
    FILE *feature_file=fopen("../external/features.csv","r");
    if (feature_file==NULL){
        printf("Feature File not found");
        exit(0);
    }
	else{
		char featureFileData[LINE_SIZE];
		fgets(featureFileData,LINE_SIZE,feature_file);
		char* data;
		data=strtok(featureFileData,",");
		if ( data != NULL )
    	{
			temp->featureId=atoi(data);
    	}
		data=strtok(NULL,",");
		if ( data != NULL )
    	{
			temp->completionStatus=atoi(data);
    	}
		data=strtok(NULL,",");
		if ( data != NULL )
    	{
			strcpy(temp->featureName,data);
    	}
		data=strtok(NULL,",");
		if ( data != NULL )
    	{
			strcpy(temp->featureDesc,data);
    	}
	}
	fclose(feature_file);
	f1=temp;
}
void freeFeatures(){
	free(f1);
}