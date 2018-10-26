//
//  list.c
//  Link_List
//
//  Created by 王振 on 2018/10/25.
//  Copyright © 2018 curefun. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

static void CopyToNode(Item item, Node * pnode);

/* 把列表设置为空列表 */
void InitializeList(List * plist)
{
    * plist = NULL;
}

/* 如果列表为空返回真 */
bool ListIsEmpty(const List * plist)
{
    if (* plist == NULL) {
        return true;
    } else {
        return false;
    }
}

/* 确认列表是否已满 */
bool ListIsFull(const List * plist)
{
    Node * pt;
    bool full;
    
    pt = (Node *)malloc(sizeof(Node));
    if (pt == NULL) {
        full = true;
    } else {
        full = false;
    }
    free(pt);
    return full;
}

/* 确认列表中项目的个数 */
unsigned int ListItemCount(const List * plist)
{
    unsigned int count = 0;
    Node * pnode = *plist;
    
    while (pnode != NULL) {
        ++count;
        pnode = pnode->next;
    }
    return count;
}

/* 在列表尾部添加一个项目 */
bool AddItem(Item item, List * plist)
{
    Node * pnew;
    Node * scan = *plist;
    
    pnew = (Node *)malloc(sizeof(Node));
    if (pnew == NULL) {
        return false;
    }
    
    CopyToNode(item, pnew);
    pnew->next = NULL;
    
    if (scan == NULL) { //空列表
        * plist = pnew;
    } else {
        while (scan->next != NULL) {
            scan = scan->next; //找到列表结尾
        }
        scan->next = pnew; //把pnew添加到结尾处
    }
    return true;
}

/* 把一个函数作用于列表中的每个项目 */
void Traverse(const List * plist, void (* pfun)(Item item))
{
    Node * pnode = *plist;
    while (pnode != NULL) {
        (* pfun)(pnode->item);
        pnode = pnode->next;
    }
}

/* 释放已分配的内存 */
void EmptyTheList(List * plist)
{
    Node * psave;
    while (*plist != NULL) {
        psave = (*plist)->next; //保存下一个节点的位置
        free(*plist); //释放当前节点
        *plist = psave; //前进到下一个节点
    }
}

/* 把一个项目复制到一个节点中 */
static void CopyToNode(Item item, Node * pnode)
{
    pnode->item = item;
}
