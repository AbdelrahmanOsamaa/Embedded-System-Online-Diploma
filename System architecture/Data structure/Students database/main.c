#include"Functions.h"

int main()
{
    char temp_txt [40];
    char option_8 [100];
    int n; // option number 8 
    while(1)
    {
        printf("\n ====================================");
        printf("\n \t Choose from the following options \n");
         printf("\n 1: Add Student ");
        printf("\n 2: Delete Student ");
        printf("\n 3: View all Students ");
        printf("\n 4: Delete all Students ");
        printf("\n 5: choose node to view it's information ");
        printf("\n 6: Length of Students list(iterative) ");
        // printf("\n 7: Length of Students list(recursive) ");
        printf("\n 8: information for the n-th node from the end ");
        printf("\n 9: information for the middle node ");
        printf("\n Enter option number : ");

        gets(temp_txt);
        printf("\n ===================================");

        switch(atoi(temp_txt))
        {
            case 1:
                Add_student();
                break;
            case 2:
                Delete_student();
                break;
            case 3:
                view_all_students();
                break;
            case 4:
                Delete_all();
                break;
            case 5:
                node_index_info();
                break;
            case 6:
                length_of_list_iterative();
                break;
            // case 7:
            //     length_of_list_recursive(gpFirstStudent);
            //     break;
            case 8:
                printf("\n Enter the node number u want to check from the end :");
                gets(option_8);
                n = atoi(option_8);
                n_th_node_info(n);
                break;
            case 9:
                middle_of_list();
                break;
            default:
                printf("\n Wrong option !!");
         }
    }
}