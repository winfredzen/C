//
//  list.h
//  Link_List
//
//  Created by 王振 on 2018/10/24.
//  Copyright © 2018 curefun. All rights reserved.
//

#ifndef list_h
#define list_h

#include <stdbool.h> /* C99特性 */

#define TSIZE 45 /* 存放片名的数组大小 */
struct file {
    char title[TSIZE];
    int rating;
};

typedef struct file Item;

typedef struct node {
    Item item;
    struct node * next;
} Node;

/* List为指向Node类型的指针名称 */
typedef Node * List;


/**
 初始化一个列表
 该列表被初始化为空列表
 @param plist plist指向一个列表
 */
void InitializeList(List * plist);


/**
 确认列表是否为空

 @param plist plist指向一个已初始化的列表
 @return 如果列表为空返回true，否则返回false
 */
bool ListIsEmpty(const List * plist);


/**
 确认列表是否已满

 @param plist plist指向一个已初始化的列表
 @return 如果列表已满返回true，否则返回false
 */
bool ListIsFull(const List * plist);


/**
 确认列表中项目的个数

 @param plist plist指向一个已初始化的列表
 @return 列表中项目的个数
 */
unsigned int ListItemCount(const List * plist);


/**
 在列表尾部添加一个项目

 @param item 被增加到列表中的项目
 @param plist plist指向一个已初始化的列表
 @return 添加成功返回true，否则返回false
 */
bool AddItem(Item item, List * plist);


/**
 把一个函数作用于列表中的每个项目

 @param plist plist指向一个已初始化的列表
 @param pfun 指向一个函数，该函数接收一个Item参数并且无返回值
 */
void Traverse(const List * plist, void (* pfun)(Item item));


/**
 释放已分配的内存

 @param plist plist指向一个已初始化的列表
 */
void EmptyTheList(List * plist);

#endif /* list_h */
