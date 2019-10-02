#include "stdio.h" 
#include "stdlib.h" 
#include "locale.h" 
#include "string.h" 

#define NUM 10 
#define MAX 100 

int find(char*, char**); 
void null(char*); 

int find(char* tmp, char** arr) 
{ 
int i = 0; 
int j = 0; 
while((arr[i] != 0) && (j < NUM)) 
{ 
while(arr[i][j] == tmp[j]) 
{ 
j++; 
if(arr[j] == 0) 
return i; 
} 
j = 0; 
i++; 
} 
return -1; 
} 
void null(char* tmp) 
{ 
int i; 
for(i = 0; i < MAX; i++) 
tmp[i] = 0; 
} 


int main() 
{ 
char a = 0; 
char* arr1[NUM] = {0}; 
char* arr2[NUM] = {0}; 
int i1 = 0; 
arr1[0] = calloc(MAX, sizeof(char)); 
int j = 0; 
int x=-1; 

printf("Enter elements of 1 array\n"); 
while('\n' != (a = getchar())) 
{ 
if((a == ' ')) 
{ 
i1++; 
arr1[i1] = calloc(MAX, sizeof(char)); 
j = 0; 
} 
else 
{ 
arr1[i1][j] = a; 
j++; 
} 

} 
int i2 = 0; 
arr2[0] = calloc(MAX, sizeof(char)); 
j = 0; 
printf("Enter elements of 2 array\n"); 
while('\n' != (a = getchar())) 
{ 
if((a == ' ')) 
{ 
i2++; 
arr2[i2] = calloc(MAX, sizeof(char)); 
j = 0; 
} 
else 
{ 
arr2[i2][j] = a; 
j++; 
} 

} 

while(1){ 
printf("MENU:\n0 - add new elements\n1 - delete elemets\n2 - show all arrays\n"); 
scanf("%d", &x); 
getchar();
if (x==0){ 
printf("Enter new elements of 1 array\n"); 
j = 0; 
i1++; 
arr1[i1] = calloc(MAX, sizeof(char)); 
while('\n' != (a = getchar())) 
{ 
if(a == ' ') 
{ 
i1++; 
arr1[i1] = calloc(MAX, sizeof(char)); 
j = 0; 
} 
else 
{ 
arr1[i1][j] = a; 
j++; 
} 

} 
printf("Enter new elements of 2 array"); 
j = 0; 
i2++; 
arr2[i2] = calloc(MAX, sizeof(char)); 
while('\n' != (a = getchar())) 
{ 
if((a == '\n') || (a == ' ')) 
{ 
i2++; 
arr2[i2] = calloc(MAX, sizeof(char)); 
j = 0; 
} 
else 
{ 
arr2[i2][j] = a; 
j++; 
} 

} 
} 
else if (x==1) { 
printf("Enter elements of 1 arr to delete\n"); 
int i11 = 0; 
j = 0; 
char* tmp = calloc(MAX, sizeof(char)); 
null(tmp); 
while(a = getchar()) 
{ 
if((a == ' ') || (a == '\n')) 
{ 
i11 = find(tmp, arr1); 
if(i11 == -1) 
printf("%s elements not found\n", tmp); 
else 
{ 
free(arr1[i11]); 
arr1[i11] = arr1[i1]; 
arr1[i1] = 0; 
i1--; 
null(tmp); 
j = 0; 
} 
if(a == '\n') 
break; 
} 
else 
{ 
tmp[j] = a; 
j++; 
} 

} 
printf("Enter elements of 2 arr to delete\n"); 
int i22 = 0; 
j = 0; 
tmp = calloc(MAX, sizeof(char)); 
null(tmp); 
while(a = getchar()) 
{ 
if((a == ' ') || (a == '\n')) 
{ 
i22 = find(tmp, arr2); 
if(i22 == -1) 
printf("%s elements not found\n", tmp); 
else 
{ 
free(arr2[i22]); 
arr2[i22] = arr2[i2]; 
arr2[i2] = 0; 
i2--; 
null(tmp); 
j = 0; 
} 
if(a == '\n') 
break; 
} 
else 
{ 
tmp[j] = a; 
j++; 
} 
} 
} 
else if(x==2){ 
int k = 0; 
j = 0; 
for(j = 0; j <= i1; j++) 
{ 
printf("%s ", arr1[j]); 
} 
printf("\n"); 
for(j = 0; j <= i2; j++) 
{ 
printf("%s ", arr2[j]); 
} 
printf("\n"); 
} 

}}
