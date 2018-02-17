#include <stdio.h>
#include <stdlib.h>

int main()
{
    //First create kernal and checking conditions
    //using FCFS(First come first serve)

    while(1) //infinity loop
    {
      //read the input command based on the FCFS

      if(command == compression)//condition satisfied for compression
      {
          //call to compression function
          compression();
      }
      else if(command == encryption)//condition satisfied for encryption
      {
          //call to encryption function
          encryption();
      }
      else if(command == decryption)//condition satisfied for decryption
      {
           //call to decryption function
          decryption();
      }
      else if(command == decompression)//condition satisfied for decompression
      {
          //call to decompression function
          decompression();
      }
      else{
          //nothing
      }
    } //while close

    return 0;
} //main close

//write all functions here
compression()
{

}
encryption()
{

}
decryption()
{

}
decompression()
{

}
