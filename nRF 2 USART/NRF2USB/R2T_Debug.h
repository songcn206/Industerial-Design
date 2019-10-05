#ifndef __R2TDebug_h_included__
#define __R2TDebug_h_included__

#include <stdio.h>
#include <string.h>
#define DebugChannel 1

void SendDataNF(char str[])
{
        char i;   
        char len = strlen(str);
        for(i=0;i<len;i++)
         {
         putchar(str[i]);   
         }        
         putchar('#');            
}
void SendDataNFixed(char str[],char fixedlen)
{
        char i;   
        char len = fixedlen;
        for(i=0;i<len;i++)
         {
         putchar(str[i]);   
         }                 
}

void SendData(char flash str[])
{
  char i;  
  char len = strlenf(str);
  for(i=0;i<len;i++)
  {
   putchar(str[i]); 
   delay_ms(1);
  }           
  putchar('#');         
}
void PcDbg(char flash str[])
{
  putchar('/');
  putchar('/');    
  SendData(str);   
  delay_ms(10);
}

#endif 