#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

//check if we alredy have this node
int search(struct  head, int x)
{
    while (head != NULL)
    {
        if (head->key == x)
            return 1;
        head = head->next;
    }
    return 0;
}



int *getpointer(int *ptr[],int Icurr ){
    if(*ptr[Icurr] != 0 ){
        return &ptr[Icurr];
    }
    return 0;


}


pnode build_graph_cmd(int nodeSum)
{
    char Ccurr;
    int Icurr;
    int index = 1, temp =1;
    
    pnode prev;
    int *ptr[nodeSum];
    memset(*ptr, 0, nodeSum*sizeof(*ptr[0]));

    while (nodeSum)
    {
        if(scanf("%c",&Ccurr)){//if char == n;

            while(scanf("%d",&Icurr)){//while the input isnt n;

                x = search(head,Icurr);//check if i alrady have this node
                node head = malloc(sizeof(node));//creat head for my list

                if( index ){ //creating the head of the list,only one time
                    pnode phead = &head;
                    
                    index =0 ;
                 //prev = &head;
                }

                if( temp == 1){//work on src
                //must do another input
                     if{ !x }{

                        head.node_num = Icurr;
                        head.next = NULL;
                        temp++;
                        ptr[Icurr] = &head;
                        break;
                     }

                     else{//im already have this node 
                     
                         temp++;
                         break;
                     }
                    
                }
                else if(temp == 2){//work on dis
                    node n = malloc(sizeof(node));
                    if(!x){
                         pnode pn = &n;
                         n.node_num = Icurr; 
                         n.next = prev;
                         prev = pn;
                         temp++;
                         break;
                    }
                    else{  
                        //im already have this dis
                        temp++;
                        break;
                    }
                }
                else if(temp == 3){
                    //work on weight
                    temp++;
                    break;
                }
                else if(temp == 4 ){//work on the secound node
                    if(!x){//i dont have this dis
                        pnode pn = &n;
                        n.node_num = Icurr; //need to connect the frev
                        n.next = prev;
                        prev = pn;
                        temp++;
                        break;
                 }
                    else{
                        //im already have this node
                        temp++;
                        break;
                    }
                }
                else if(temp == 5){
                     //work on last w
                     temp =1;
                     break;

                 }


                }



            }
            nodeSum--;
        }
        // if (scanf(" %c", &Ccurr)) // if  char == (n)
        // {
            // while (scanf(" %d", &Icurr)) // while the input isn't n:
            // {
            //     if (first)
            //     { // define the head node:
            //         node head = malloc(sizeof(node));
            //         pnode phead = &head;
            //         prev = &head;
            //         head.node_num = Icurr;
            //         head.next = NULL;
            //         first = 0;
            //     }
            //     else
            //     {
            //      node n = malloc(sizeof(node));
            //      pnode pn = &n;
            //      n.node_num = Icurr; //need to connect the frev
            //      n.next = prev;
            //      prev = pn;
            //     }
                
            //         int dest = Icurr;
            //         scanf(" %d", &Icurr);
            //         int weight = Icurr;
            //         edge e = malloc(sizeof(edge));
            //         e.weight = weight;
            //         //check if the dest node already exist - need to build a function..
            //         e.endpoint = dest;
                
            }

            //  scanf(" %d", &curr);
        }
        nodeSum--;
    }
    return phead;
}