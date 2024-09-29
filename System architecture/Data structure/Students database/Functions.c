#include "Functions.h"



void fill_record(struct Sstudent* new_record)
{
    char temp_data[40];
    printf("\n Enter your ID :");
    gets(temp_data);
    new_record->student.ID = atoi(temp_data);
    printf("\n Enter your name :");
    gets(new_record->student.name);
    printf("\n Enter your hight :");
    gets(temp_data);
    new_record->student.hight = atof(temp_data);
}

void Add_student()
{
    struct Sstudent * pLaststudent ;
    struct Sstudent * pNewstudent ;

        // if the list is empty
    if(gpFirstStudent == NULL)
    {
        //create new record
       pNewstudent = (struct Sstudent*) malloc(sizeof(struct Sstudent));
       gpFirstStudent = pNewstudent;
    }
        // if the list is not empty
    else
    {
        pLaststudent = gpFirstStudent ;
        while(pLaststudent->PNextStudent)
        {
            pLaststudent = pLaststudent->PNextStudent;  
        }
         //create new record
       pNewstudent = (struct Sstudent*) malloc(sizeof(struct Sstudent));
       pLaststudent->PNextStudent = pNewstudent ;
    }

    fill_record(pNewstudent);
    pNewstudent->PNextStudent = NULL ;
}

int Delete_student()
{
    char temp_txt[40];
    int selected_ID;
    struct Sstudent * pselectedStudent;
    struct Sstudent * pPreviousStudent;
    //checking if the list is empty befor trying to delete
    if(gpFirstStudent)
    {
        printf("\n Enter the student ID to delete the record :");
        gets(temp_txt);
        selected_ID = atoi(temp_txt);
        //looping on the list
        pPreviousStudent = NULL;
        pselectedStudent = gpFirstStudent;
        while (pselectedStudent)
        {
            if(pselectedStudent->student.ID == selected_ID)
            {   
                if(pPreviousStudent)
                {
                    pPreviousStudent->PNextStudent = pselectedStudent->PNextStudent ;
                }
                else
                {
                    gpFirstStudent = pselectedStudent->PNextStudent;
                }
                free(pselectedStudent);
                printf("\n Record has been deleted !!");
                return 1 ; // the record has been found
            }
            // store previous pointer record
            pPreviousStudent = pselectedStudent;
            pselectedStudent = pselectedStudent->PNextStudent;
        }
    }
    // else
    // {
    //     printf("\n The list is empty !!");
    // }
    printf("\n No student with same ID !!");
    return 0 ; // couldn't find the student in the list

}
void view_all_students()
{
    struct Sstudent * pCurrentstudent;
    pCurrentstudent = gpFirstStudent ;
    if(gpFirstStudent)
    {
        int record_number = 0;
        while(pCurrentstudent)
        {
        printf("\n Record number :%d",record_number+1);
        printf("\n Student ID :%d",pCurrentstudent->student.ID);
        printf("\n Student Name :%s",pCurrentstudent->student.name);
        printf("\n Student Hight :%.2f",pCurrentstudent->student.hight);
        printf("\n ###################################");
        pCurrentstudent = pCurrentstudent->PNextStudent;
        record_number++;
        }
    }
    else
    {
        printf("\n The list is empty !!");
    }
}
void Delete_all()
{
    struct Sstudent * pDeleteStudnet ;
    struct Sstudent * pForward ;
    pForward = gpFirstStudent ;
    if(gpFirstStudent)
    {
        while(pForward)
        {
            pDeleteStudnet = pForward ;
            pForward = pForward->PNextStudent ;
            free(pDeleteStudnet);
        }
        gpFirstStudent = NULL ;
        printf("\nAll records got deleted !!");
    }
    else
    {
        printf("\n The list is empty !!");
    }
}
void node_index_info()
{
    char temp_txt[10];
    int index = 0 , count;
    struct Sstudent* pIndexCounter;
    printf("\nEnter the node number u wanna search for : ");
    gets(temp_txt);
    index = atoi(temp_txt);

    if(gpFirstStudent)
    {
        pIndexCounter = gpFirstStudent ;
        while(pIndexCounter)
        {   
            if(index != count)
            {
                pIndexCounter = pIndexCounter->PNextStudent ;         
                count++;
            }
            else
            {
                printf("\n =====The node information===== ");
                printf("\nstudent ID : %d",pIndexCounter->student.ID);
                printf("\nstudent name : %s",pIndexCounter->student.name);
                printf("\nstudent hight : %f",pIndexCounter->student.hight);
                break;
            } 
        } 
    }
    else
    {
        printf("\n the list is empty!!");
    }  
}
void length_of_list_iterative()
{
    int count;
    struct Sstudent* pListCounter;

    if(gpFirstStudent)
    {
        pListCounter = gpFirstStudent ;
        while(pListCounter)
        {   
            pListCounter = pListCounter->PNextStudent ;         
            count++;   
        }
        printf("\n The length of the list is : %d",count);
        
    }
    else
    {
        printf("\n the list is empty!!");
    }
}
// int length_of_list_recursive(struct Sstudent* pNode)
// {
    
//     if (pNode == NULL) {
//         printf("\nThe list is empty or end of the list is reached!!\n");
//         return 0;
//     }

//     return 1 + length_of_list_recursive(pNode->PNextStudent);
// }
void n_th_node_info(int n) 
{
    struct Sstudent *pnode1 = gpFirstStudent, *pnode2 = gpFirstStudent;
    int count = 0;

    // Check if list is empty
    if (!gpFirstStudent) 
    {
        printf("\n The list is empty !!");
        return;
    }

    // Move pnode1 n nodes ahead
    for (count = 0; count < n; count++) 
    {
        if (!pnode1) 
        {
            printf("\nInvalid value of n!");
            return;
        }
        pnode1 = pnode1->PNextStudent;
    }

    // Move pnode1 and pnode2 until pnode1 reaches the end
    while (pnode1) {
        pnode1 = pnode1->PNextStudent;
        pnode2 = pnode2->PNextStudent;
    }

    // pnode2 now points to the n-th node from the end
    printf("\n =====The node information===== ");
    printf("\nstudent ID : %d", pnode2->student.ID);
    printf("\nstudent name : %s", pnode2->student.name);
    printf("\nstudent height : %f", pnode2->student.hight);
}
void middle_of_list()
{
    int count , i;
    struct Sstudent* pListCounter;
    struct Sstudent* pMiddle;
    pListCounter = gpFirstStudent ;
    pMiddle = gpFirstStudent ;

    if(gpFirstStudent)
    {
        pListCounter = gpFirstStudent ;
        while(pListCounter)
        {   
            pListCounter = pListCounter->PNextStudent ;         
            count++;   
        }
        if(count % 2 != 0)
        {
            for(i = 1 ; i < (count + 1)/2 ; i++)
            {
                pMiddle = pMiddle->PNextStudent ;
            }
                printf("\n =====The middle node information===== ");
                printf("\nstudent ID : %d", pMiddle->student.ID);
                printf("\nstudent name : %s", pMiddle->student.name);
                printf("\nstudent height : %f", pMiddle->student.hight);
        }
        else
        {
              for(i = 1 ; i < (count/2) + 1 ; i++)
            {
                pMiddle = pMiddle->PNextStudent ;
            }
                printf("\n =====The middle node information===== ");
                printf("\nstudent ID : %d", pMiddle->student.ID);
                printf("\nstudent name : %s", pMiddle->student.name);
                printf("\nstudent height : %f", pMiddle->student.hight);
        }
    }
    else
    {
        printf("\n The list is empty !!");
    }
}

