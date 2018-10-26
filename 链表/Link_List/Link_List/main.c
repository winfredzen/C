//
//  main.c
//  Link_List
//
//  Created by 王振 on 2018/10/24.
//  Copyright © 2018 curefun. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void showMovies(Item item);

int main(int argc, const char * argv[]) {
  
    List movies;
    Item temp;
    
    //初始化
    InitializeList(&movies);
    if (ListIsFull(&movies)) {
        fprintf(stderr, "No memory available! Bye!\n");
        exit(1);
    }
    
    puts("Enter first movie title: ");
    while (gets(temp.title) != NULL && temp.title[0] != '\0') {
        puts("Enter your rating<0-10>: ");
        scanf("%d", &temp.rating);
        
        while (getchar() != '\n') {
            continue;
        }
        
        if (AddItem(temp, &movies) == false) {
            fprintf(stderr, "Problem allocating memory\n");
            break;
        }
        
        if (ListIsFull(&movies)) {
            puts("The list is now full.");
            break;
        }
        
        puts("Enter next movie title (empty line to stop): ");
        
    }
    
    //显示
    if (ListIsEmpty(&movies)) {
        printf("No data entered. ");
    } else {
        printf("Here is the movie list: \n");
        Traverse(&movies, showMovies);
    }
    
    printf("Your entered %d movies.\n", ListItemCount(&movies));
    
    //清除
    EmptyTheList(&movies);
    printf("Bye!\n");
    
    
    return 0;
}


void showMovies(Item item)
{
    printf("Movie %s Rating: %d\n", item.title, item.rating);
}
