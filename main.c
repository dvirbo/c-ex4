#include <stdio.h>
#include "algo.h"

int main()
{
    char input = '\0';

    //    A 4 n 0 2 5 3 3 n 2 0 4 1 1 n 1 3 7 0 2
    printf("enter\n");

    while (scanf("%c", &input) != EOF)
    switch (input)
    {
    case 'A':
        build_graph_cmd();
        break;
    case 'B':
        insert_node_cmd();
        break;

    case 'D':
        delete_node_cmd();
        break;

    case 'F':
        print_graph();
        break;


 //   case 'S':
      //  shortsPath_cmd();
     //   break;

        // case 'T':
        // TSP_cmd();
        //   break;

    }

    return 0;
}