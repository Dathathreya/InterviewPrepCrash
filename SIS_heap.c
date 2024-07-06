#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

// Samllest Integer in Infinite Set 
// memory expensive approach 

typedef struct {
    int heap[1000];    
    int hmap[1001];   
    int size; 
} SmallestInfiniteSet;

typedef void    (*swap_self_t)(const void*,int,int);
typedef int (*compare_self_t)(const void*,int,int);

void swap_self_SIS(const void* obj,int f,int s){
    SmallestInfiniteSet* temp_obj = (SmallestInfiniteSet*)obj;
    int t = temp_obj->heap[f];temp_obj->heap[f]=temp_obj->heap[s],temp_obj->heap[s]=t;
    return;
}
int compare_self_SIS(const void* obj,int f,int s){
    SmallestInfiniteSet* temp_obj = (SmallestInfiniteSet*)obj;
    return temp_obj->heap[f]<=temp_obj->heap[s];
}
void down_heapify(const void* obj,int root,int size,swap_self_t swapfn,compare_self_t compfn){
    int leftChild=((root*2)+1),rightChild=((root*2)+2),least=root;

    if((leftChild<size)&&(compfn(obj,leftChild,least))){  /* lchild  <= parent */       
        least = leftChild; // leftChild is new_least
    }
    if((rightChild<size)&&(compfn(obj,rightChild,least))){ /* rchild <= currleast */
        least = rightChild; // rightChild is new_least
    }
    if(least!=root){
        swapfn(obj,least,root); /* swapping of values only at respective indices*/
        down_heapify(obj,least,size,swapfn,compfn);
    }
    return;
}

void up_heapify(const void* obj,int curr,swap_self_t swapfn,compare_self_t compfn){
    if((curr==0)||(compfn(obj,(curr-1)>>1,curr))){ /* parent <= child */
            return;  // parent node is having a value already lesser than child so return
    }
    else{
        swapfn(obj,curr,(curr-1)>>1);
        up_heapify(obj,(curr-1)>>1,swapfn,compfn);
    }
}

SmallestInfiniteSet* smallestInfiniteSetCreate() {
SmallestInfiniteSet* newSet = (SmallestInfiniteSet*)malloc(sizeof(SmallestInfiniteSet));
    newSet->size=1000;
    for(int i=0;i<1001;i++){
        newSet->heap[i]= (i+1);
        if(i) newSet->hmap[i]= 1;
    }
    return newSet;
}

int smallestInfiniteSetPopSmallest(SmallestInfiniteSet* obj) {
    if(obj->size==0){
        return 1001;
    }
    else{
        int firsthead = obj->heap[0];
        obj->hmap[firsthead]--; /*poped_out_root_node*/
        swap_self_SIS(obj,0,obj->size-1);
        obj->heap[obj->size-1] = 1001;
        int prev=obj->size;
        //printf("prev:%d ",prev);
        obj->size--;
        
        down_heapify(obj,0,prev,swap_self_SIS,compare_self_SIS);
        return firsthead;   
    }
}

void smallestInfiniteSetAddBack(SmallestInfiniteSet* obj, int num) {
    if((obj->hmap[num])==0){
            // override largest value placed at end of array/heap with current value  and reduce  maximum
            obj->heap[obj->size] = num;
            obj->hmap[num]++;    
            up_heapify(obj,obj->size,swap_self_SIS,compare_self_SIS); /*upheapify*/
            (obj->size)=(obj->size)+1;
    }
    return;
}

void smallestInfiniteSetFree(SmallestInfiniteSet* obj) {
    free(obj); /* release */
}


void solve(){
  // Your SmallestInfiniteSet struct will be instantiated and called as such:
  
  //SmallestInfiniteSet* obj = smallestInfiniteSetCreate();

  char list[][19] = {"SmallestInfiniteSet","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest","popSmallest"};  

  int n1 = (sizeof(list) / sizeof(list[0])),i=0,num;                   

  // for(int i=0;i<((sizeof(list)/sizeof(list[0])));i++){
  //   printf("string with value - %s starts with character:%c\n",list[i],list[i][0]);
  // }
  i=0;
 SmallestInfiniteSet* obj = NULL; 
 while(n1--)
 {
    
      switch(list[i++][0])
      {
          case 'S':{
                obj = smallestInfiniteSetCreate(); 
                break;
          } 
          case 'a':{
                scanf("%d",&num);
                smallestInfiniteSetAddBack(obj, num);
                break;
          }
          case 'p':{
                 int param_1 = smallestInfiniteSetPopSmallest(obj);
                 //printf("Smallest Number:%d\n",param_1);
                 break;
          }
          default:{
                 break;  
          }
      }
  }    
  smallestInfiniteSetFree(obj);   
}

int main(){
    int tC=1;
    // assert(fscanf(stdin,"%d",&tC)>0);
    while(tC--){
        solve();
    }
}