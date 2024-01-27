#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
//----------------------------------------------------------------------------------
// Local Variables Definition (local to this module)
//----------------------------------------------------------------------------------
struct node
{
    Vector2 rect;
    int g;
    int h;
};

static struct node nodes[100];
static int nodeArrSize=100;
static int nodesInit=0;
static Vector2 nodeSize=(Vector2){75,75};
static Vector2 nodeDrawSize=(Vector2){25,25};

static int start=0;
static int goal=18;
//----------------------------------------------------------------------------------
// Local Functions Declaration
//----------------------------------------------------------------------------------
void generateNodes(Vector2 scrDimensions);
void drawNodes();
static void chooseNode(int currentNode);
static void closestNodes(int currentNode);
static Rectangle nodeRectangle(int node);
void updateSelected();
static void nodeAppend(int currentNode,bool type);
//----------------------------------------------------------------------------------
// Definitions
//----------------------------------------------------------------------------------
static void nodeAppend(int currentNode,bool type){
    for(int i=0;i<20;i++){
        if(searchNodes[i]==-1){
            searchNodes[i]=currentNode;
            break;
        }
    }
}
static void nodeRemove(int currentNode,bool type){
    for(int i=0;i<20;i++){
        if(searchNodes[i]==-1){
            searchNodes[i]=currentNode;
            break;
        }
    }
}
void generateNodes(Vector2 scrDimensions){
    int currentNode=0;
    bool offset=true;
    for(int u=0;u<scrDimensions.y/nodeSize.y;u++){
        for(int i=0;i<scrDimensions.x/nodeSize.x;i++){
            if(currentNode<nodeArrSize){
                int testOffset=50;
                if(offset)nodes[currentNode]=(Vector2){i*nodeSize.x+testOffset+nodeSize.x/2,u*nodeSize.y+testOffset};
                else nodes[currentNode]=(Vector2){i*nodeSize.x+testOffset,u*nodeSize.y+testOffset};
                currentNode++;
                nodesInit++;
            }
        }
        if(offset)offset=false;
        else offset=true;
    }
}
static void closestNodes(int currentNode){
    for(int i=0;i<nodesInit;i++){
        if(!searchNodes[i]){
            if(nodes[currentNode].x-nodeSize.x==nodes[i].x){
                nodeAppend(processedNodes[currentNode]+1,false);
            }
        }
    }
}
static Rectangle nodeRectangle(int node){
    return (Rectangle){nodes[node].x-nodeDrawSize.x/2,nodes[node].y-nodeDrawSize.y/2,nodeDrawSize.x,nodeDrawSize.y};
}
static void chooseNode(int currentNode){
    closestNodes(currentNode);
    Vector2 chosenVector=nodes[currentNode];
    if(IsKeyPressed(KEY_A)){
        currentNode++;
    }
}
void updateSelected(){
    for(int i=0;i<nodesInit;i++){
        if(processedNodes[i]){
            chooseNode(i);
        }
    }
    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
        for(int i=0;i<20;i++){
            if(CheckCollisionPointRec(GetMousePosition(),nodeRectangle(searchNodes[i]))){
                
                searchNodes[i]=-1;
            }
        }
    }
}
void drawNodes(){
    for(int i=0;i<nodesInit;i++){
        Color nodeColor=RED;
        if(processedNodes[i])nodeColor=WHITE;
        if(searchNodes[i])nodeColor=GREEN;
        if(i==goal)nodeColor=LIGHTGRAY;
        DrawRectangleRec(nodeRectangle(i),nodeColor);
        DrawText(TextFormat("%d",i),nodes[i].x-nodeDrawSize.x/2,nodes[i].y-nodeDrawSize.y/2+20,20,BLUE);
    }
}
