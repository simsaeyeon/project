//
//  ifs_element.c
//  InfestPath
//
//  Created by Juyeop Kim on 2020/10/20.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "ifct_element.h"

typedef enum place {
    Seoul,          //0
    Jeju,           //1
    Tokyo,          //2
    LosAngeles,     //3
    NewYork,        //4
    Texas,          //5
    Toronto,        //6
    Paris,          //7
    Nice,           //8
    Rome,           //9
    Milan,          //10
    London,         //11
    Manchester,     //12
    Basel,          //13
    Luzern,         //14
    Munich,         //15
    Frankfurt,      //16
    Berlin,         //17
    Barcelona,      //18
    Madrid,         //19
    Amsterdam,      //20
    Stockholm,      //21
    Oslo,           //22
    Hanoi,          //23
    Bangkok,        //24
    KualaLumpur,    //25
    Singapore,      //26
    Sydney,         //27
    SaoPaulo,       //28
    Cairo,          //29
    Beijing,        //30
    Nairobi,        //31
    Cancun,         //32
    BuenosAires,    //33
    Reykjavik,      //34
    Glasgow,        //35
    Warsow,         //36
    Istanbul,       //37
    Dubai,          //38
    CapeTown        //39
} place_t;

char countryName[N_PLACE+1][MAX_PLACENAME] =
{   "Seoul",
    "Jeju",
    "Tokyo",
    "LosAngeles",
    "NewYork",
    "Texas",
    "Toronto",
    "Paris",
    "Nice",
    "Rome",
    "Milan",
    "London",
    "Manchester",
    "Basel",
    "Luzern",
    "Munich",
    "Frankfurt",
    "Berlin",
    "Barcelona",
    "Madrid",
    "Amsterdam",
    "Stockholm",
    "Oslo",
    "Hanoi",
    "Bangkok",
    "KualaLumpur",
    "Singapore",
    "Sydney",
    "SaoPaulo",
    "Cairo",
    "Beijing",
    "Nairobi",
    "Cancun",
    "BuenosAires",
    "Reykjavik",
    "Glasgow",
    "Warsow",
    "Istanbul",
    "Dubai",
    "CapeTown",
    "Unrecognized"
};

typedef struct ifs_ele{

	int Index;
	int age;
	int inf_detected_time;
	place_t place[N_HISTORY]; 
	
} ifs_ele_t;

int ifctele_getAge(void* obj){
	ifs_ele_t *strPtr = (ifs_ele_t *)obj;
	
	return (strPtr->age);   
	//구조체 안에서 나이의 값을 뽑아주는 역할
} 

char* ifctele_getPlaceName(int placeIndex){
	
	return countryName[placeIndex];
}

void* ifctele_genElement(int index, int age, unsigned int detected_time, int history_place[]){
	//fscanf가 갖고 있는 정보로 element 생성하는 함수 
	 
	ifs_ele_t *strPtr;
	int i;
	int Place_[N_HISTORY];
	strPtr = malloc(sizeof(struct ifs_ele));
	strPtr->Index=index;
	strPtr->age=age;
	strPtr->inf_detected_time=detected_time;

	for(i=0;i<N_HISTORY;i++)
		strPtr-> place[i]=history_place[i];
		
	return strPtr;
}

void ifctele_printElement(void* obj){
		int i,j;
		ifs_ele_t *strPtr = (ifs_ele_t *)obj;
		
		printf("--------------------------------------------\n");
		printf("Patient index : %i\n",strPtr->Index);
		printf("Age : %i\n",strPtr->age);
		printf("Detected time : %i\n",strPtr->inf_detected_time);
		printf("Path History :");
		for(i=0;i<5;i++){
			printf("%s (%d) " ,ifctele_getPlaceName(strPtr->place[i]),ifctele_getinfestedTime(obj)-(4-i));
			if(i!=4)
				printf("-> ");
		}
		printf("\n");
		printf("--------------------------------------------");
		printf("\n");
		
			
		//print elements
}

int ifctele_getHistPlaceIndex(void* obj , int index){
	ifs_ele_t *strPtr = (ifs_ele_t *)obj;
	
}

unsigned int ifctele_getinfestedTime(void* obj){
	ifs_ele_t *strPtr = (ifs_ele_t *)obj;
	
	
	return ((strPtr -> inf_detected_time));
}

