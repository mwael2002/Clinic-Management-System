#include<stdio.h>
#include"D:/C/STD.Types.h"
 struct pr{
	U8 name[100];
	U8 gender[50];
	U16 id;
	U16 age ;
}; 
struct ti{
	U8 time[5]; // variable for each slot
	U16 id2[5]; //variable for making sure that this slot of the patient
};
typedef struct ti slo;     //  data structure for every slot replaced by slo
typedef struct pr patient; //  data structure for every patient replaced by patient
patient p[20]; //array of data structure contains max. size of the clinic which is 20	
slo slot; //declaration of slot of type slo
U8 d=1; // variable for infinite loop 
U16 number; // variable for counting number of existing IDs
void add(void); // function for adding new patient
void edit(void); // function for editing patient record
void reserve(void); // function to reserve a slot
void delete(void); // function to delete a slot
void rec(void); // function to view patient's record
void res(void);  // function to view patient's reservation
void main(void){		
	 U8 m; // variable for admin or user mode
     U16 i; // variable for first for loop
     U16 n ; // password scanned from the user in the admin mode
	 U8 c=0;// mode of the admin to add or edit  patient information , reserve slot for the doctor , delete or reservation 
	 while(d==1){
    printf("Choose between User mode and Admin Mode\n");
    printf("For User Mode enter (U) and for Admin Mode enter (A)\n");
	printf("To Exit the program enter(E)\n");
	printf("Enter the letter : ");
    scanf("%c",&m);
    if(m=='A'){
       printf("Enter the password : ");
       for(i=0;i<3;i++){ // loop for entering the password  3 times
        scanf("%d",&n);
           if(n==1234){// correct password
            break ;}
            if ((n!=1234)&&(i!=2)){ // in case of incorrect password 2 times
			printf("Try again \n");
			}
           }
		   if(i!=3){
			   
			   printf("To add new patient enter (1) \n");
			   printf("To edit patient record enter(2) \n");
			   printf("To reserve a slot with a doctor enter (3) \n");
			   printf("To delete a reservation with a doctor enter (4) \n");
			   scanf("%d",&c);
			   if((c==1)&&(number<20)){ 
				   add();   
			   }
			   else if(c==2){
				edit(); 
			   }
			   else if (c==3){
				   if((slot.time[0]==1)&&(slot.time[1]==1)&&(slot.time[2]==1)&&(slot.time[3]==1)&&(slot.time[4]==1)){
				   printf("There's no available slots\n");
			   }
			   else{reserve();}
			   }
			   else if (c==4){  
			   delete();
			   }  
		       }
		    else if(i==3){
			   printf("You have tried 3 times , No more tries , The program will close "); // in case of incorrect password 3 times
			   d=0;
		   }
	}
	   else if (m=='U'){
		   U8 q;
		   printf("To view patient record enter (1) and to view patient's reservation enter(2) : ");
		   scanf("%d",&q);
		   switch(q){
			   case 1:rec();
			   break;
			   case 2:res();
		   }
	 }
	 else if(m=='E'){
		 d=0;
	 }
	 }
}
    
     void add(void){
		 U16 z ; // ID scanned from the user
		 printf("Enter the patient ID : ");
		         scanf("%d",&z);
				 fflush(stdin);
				 U8 flag=0; // variable for making sure that there's no repetiton in IDs
		         for(U16 j =0;j<number;j++){   // for loop to check if the  patient ID exists or not
		         if(z==(p[j].id)){
                 flag=1;
			     break;
		        } 
		        }
				if(flag==0){ // in case of there's no repetition
				p[number].id=z;
			     printf("Enter the name of the patient : ");
			     fgets(p[number].name,100,stdin);
                 printf("Enter the gender of the patient : ");
			     fgets(p[number].gender,50,stdin);
			     printf("Enter the age of the patient : ");
			    scanf("%d",&p[number].age);
				
				number++;
				
				}
				 else { // when the ID is repeated
				 printf("There is existing ID of that number\n");
				 }
	 }
	   void edit(void){ // for loop to check if the  patient ID exists or not 
		U16 z ; // ID scaned from the user
		printf("Enter the patient ID : ");
		scanf("%d",&z);
		fflush(stdin);
		for (U16 j=0;j<20;j++){
			if(p[j].id==z){ // when the loop finds the ID in the 20 places
		printf("Enter the new name of the patient : ");
		    fgets(p[j].name,100,stdin);
		    printf("Enter the new gender of the patient : ");
			fgets(p[j].gender,50,stdin);
			printf("Enter the new age of the patient : ");
			scanf("%d",&p[j].age);
	        break;
			}			
		else if(j==19){ // when the loop doesn't find the ID in the 20 places
		printf("There is no existing ID of that number\n");
	}
	}
	}
	   
	void reserve(void){
		U8 f ; // variable for the desired slot 
		U16 z; // ID scaned from the user
	// available slots :
			if((slot.time[0]==0))
				printf("1-From 2:00 to 2:30 is available\n");
				
			if((slot.time[1]==0))
				printf("2-From 2:30 to 3:00 is available\n");
			
		    if((slot.time[2]==0))
			printf("3-From 3:00 to 3:30 is available\n");
				
			if((slot.time[3]==0))
				printf("4-From 4:00 to 4:30 is available\n");
				
			if((slot.time[4]==0))
				printf("5-From 4:30 to 5:00 is available\n");	
		
			printf("Enter the patient ID : ");
			scanf("%d",&z);
			printf("Enter the desired slot : ");
			scanf("%d",&f);
			for(U16 i=0;i<20;i++){// for loop to check if the  patient ID exists or not
			 if((p[i].id==z)&&(slot.time[f-1]==0)){// in case ID exists and there's available slot
			slot.time[f-1]=1; // 1 means reserved and 0 not 
			slot.id2[f-1]=z;
			break;  }
			else if((p[i].id==z)&&(slot.time[f-1]==1)){// in case ID exists and there isn't available slot
				printf("This is a reserved slot\n");
				break;
			}
		    else if(i==19){// in case ID doesn't exist
			printf("There is no existing ID of that number\n");
		}
			}
	}
	 void delete(void){
		U16 i; // variable for the first loop
		U16 z;  // ID scaned from the user
		printf("Enter the patient ID : ");
			scanf("%d",&z);
			for(i=0;i<20;i++){// for loop to check if the  patient ID exists or not
			 if(p[i].id==z){// in case ID exists
		    for(U16 m=0;m<5;m++){ // for loop to search in the 5 slots
			if((slot.time[m]==1)&&(slot.id2[m]==z)){ // to check that this is a reserved slot and it's the patient's slot
			slot.time[m]=0;
			slot.id2[m]=0;
			break;
			 }
			 else if(m==4){printf("There's no reserved slot of that ID\n");}//in case the patient doesn't have any reserved slot
			}
			 break;}
			else if(i==19){printf("There's no existing ID of that number\n");}// in case ID doesn't exist
			}
	 }
	 // functions of user mode :
	 void rec(void){
		U16 i ; 
		U16 z ;  
		 printf("Enter the patient ID : ");
		 scanf("%d",&z);
		 for(i=0;i<20;i++){
			 if(p[i].id==z){
				 printf("The name of the patient is : %s\n",p[i].name);
				 printf("The gender of the patient is : %s\n",p[i].gender);
				 printf("The age of the patient is : %d\n",p[i].age);
				 break;
			 }
			 	else if((i==19)){
		printf("There is no existing ID of that number\n");
	}
		 }
				 
	 }
	  void res(void){
	U16 z;
	printf("Enter the patient ID : ");
    scanf("%d",&z);
	for (U16 j=0;j<20;j++){
		if(p[j].id==z){
			for(U16 m ; m<5;m++){
	       if((slot.time[0]==1)&&(slot.id2[m]==z))
				printf("From 2:00 to 2:30\n");
		   
			if((slot.time[1]==1)&&(slot.id2[m]==z))
				printf("From 2:30 to 3:00\n");
			
		    if((slot.time[2]==1)&&(slot.id2[m]==z))
			printf("From 3:00 to 3:30\n");
				
			if((slot.time[3]==1)&&(slot.id2[m]==z))
				printf("From 4:00 to 4:30\n");
				
			if((slot.time[4]==1)&&(slot.id2[m]==z))
				printf("From 4:30 to 5:00\n");
			if((slot.id2[0]!=z)&&(slot.id2[1]!=z)&&(slot.id2[2]!=z)&&(slot.id2[3]!=z)&&(slot.id2[4]!=z)&&(m==4))
				printf("There's no reserved slot of that ID\n");
			}
			break;}
			else if(j==19){
			printf("There is no existing ID of that number\n");}
}
}

   
