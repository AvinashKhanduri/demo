// All commented lines of code is here for future updation.
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>

// void upload_questions(){
    // This function is used to creat a new txt file and it will write a new question on it.
    // FILE *file;
    // file = fopen("demo_question.txt","w");
    // handling exception if file does not created
    // if(file==NULL){
        // printf("error occured  while creating the file. Type of eror is unkown at this time\n");
    // }
    // else{
        // printf("file created succcessfully\n");
        // fclose(file);
    // }
// 
// }

int start_test(char subject,int unit){
    //This function will read a pre existing file.
    char subject_name[30];
    char unit_name[30];
    char file_path[100];
    char show_answers;
    FILE *file;
    if(subject=='a'){
        strcpy(subject_name,"promming_in_c");
        switch (unit)
        {
            case 1:
                strcpy(unit_name,"Introduction");
            break;
            case 2:
                strcpy(unit_name,"variables_and_keywords");
                break;
            case 3:
                strcpy(unit_name,"operators");
                break;
            case 4:
                strcpy(unit_name,"conditional_instructions");
                break;
            case 5:
                strcpy(unit_name,"loop_control_instruction");
                break;
            case 6:
                strcpy(unit_name,"function_and_recursion");
                break;
            case 7:
                strcpy(unit_name,"arrays");
                break;
            case 8:
                strcpy(unit_name,"string");
                break;
            case 9:
                strcpy(unit_name,"structures");
                break;
        }
    }
    else{
        strcpy(subject_name,"software_engineering");
        switch (unit)
        {
            case 1:
                strcpy(unit_name,"Introduction");
                break;
            case 2:
                strcpy(unit_name,"Agile_methodology");
                break;
            case 3:
                strcpy(unit_name,"Software_design");
                break;
            case 4:
                strcpy(unit_name,"Software_quality_assurance");
                break;
            case 5:
                strcpy(unit_name,"Software_project_managment");
                break;

     }
    }
    sprintf(file_path,"E:\\c lanuage\\mini_projects\\question_paper_genrator\\%s\\%s.txt",subject_name,unit_name); // formating file path and storing it inside file_path array.
    file = fopen(file_path,"r");
    // handling exception if file does not exist.
    if(file==NULL){
        printf("file does not exit.\n");
    }
    else{
        int u_c;
        char line[256];
        char answer[256];

        while (fgets(line, sizeof(line), file)) {
            if (strstr(line, "Question") != NULL) {
                printf("%s", line); // Print the question number
                char question[256];
                fgets(question, sizeof(question), file); // Read the question
                printf("%s", question); // Print the question

                char options[4][256];
                for (int i = 0; i < 4; i++) {
                    fgets(options[i], sizeof(options[i]), file); // Read each option
                    printf("%s", options[i]); // Print each option
                }
                printf("\n\npress 1 to show answer 2 to next question 3 to home 4 to exit\n\n");
                scanf("%d",&u_c);
                switch(u_c){
                    case 1:
                        fgets(line, sizeof(line), file);
                        if (strstr(line, "Answer: ") != NULL) {
                        // If the line contains "Answer: " (with the space), extract the answer
                        sscanf(line, "Answer: %[^\n]", answer);
                        printf("Answer: %s\n\n", answer);
                        } else {
                        // If the line contains "Answer:" (without the space), extract the answer
                        fgets(answer, sizeof(answer), file);
                        printf("Answer: %s\n\n", answer);
                        }
                        break;
                    case 2:
                        continue;
                        break;
                    case 3:
                        return 0;
                        break;
                    case 4:
                        exit(0);
                    default:
                        printf("i will do it letter\n");
                }
                
            }
        }
         
    
        fclose(file);
        }

}
int main(){
    char user_choice,after_choice,subject;
    int unit,num;
    do{
       user_choice = 'b';
    //    printf("\nselect (a) to exit (b) to start test\n");
    //    scanf(" %c",&user_choice);
    //    if(user_choice=='A'){
    //         user_choice='a';
    //     }
    //     else if (user_choice=='B')
    //     {
    //             user_choice='b';
    //     }
    //     else{
    //         user_choice=user_choice;
    //     }
        
        switch (user_choice)
        {   
            case 'b':
                num = 1;
                while (num<2)// creating a infinite while loop to continiue test
                {
                     printf("______[Available subjects are..]______\na) for programming in c\nb) for software engineering\nc) to exit\n");
                    scanf(" %c",&subject);
                    if(subject=='a'){
                        printf("1) Introduction\n2) variables\n3) Operators\n4) Conditionals instructions\n5) Loop controlls\n6) Functions\n7) Array\n8) String\n8)Structures\n____[select option for your unit]____\n");
                        scanf(" %d",&unit);
                        printf("________________[YOUR QUESTIONS ARE]_______________\n");
                        start_test(subject,unit);
                        }
                    else if(subject=='b'){
                        printf("1)unit 1:Introduction\n2)unit 2:Agile Methodology\n3)unit 3:Software Design\n4)unit 4:Software Quality Assurance\n5)unit 5:Software Project Management\n____[Select option for your unit]____\n");
                        scanf(" %d",&unit);
                        printf("________________[YOUR QUESTIONS ARE]_______________\n");
                        start_test(subject,unit);
                    }
                    else{
                        printf("THANKS FOR USING OUR PROGRAM");
                        exit(0);
                    }
                
            }
            break;
            default:
                printf("pls select a valid option\nPress 'y'to continiue or any key to exit\n");
                scanf(" %c",&after_choice);
            }
            
    }while(after_choice=='y'|| after_choice=='Y');

    printf("thanks for using our programm");
    getch();
    
    
    return 0;
}