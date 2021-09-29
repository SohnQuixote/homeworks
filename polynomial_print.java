import java.util.Scanner;

class Poly{
   void printPoly(int[] arr){
       int length = arr.length;
       for (int i=0;i<length;i++)
       {
           //계수
           int temp = 0,
            if(arr[i] != 0 && arr[i]!=1 && arr[i] !=-1)
            {
                if(i == 0)
                {
                    System.out.print(arr[i]);
                }
                if(i !=0)
                {
                if(arr[i] >0)
                {
                    System.out.print(arr[i]);
                }
                else
                {
                    temp = -1 *arr[i];
                    System.out.print(temp);
                }
                }
            }
           //다항식 + 지수
            if(arr[i] != 0)
            {
                if(i==length-2)
                {
                    System.out.print("x");
                }
                else if(i < length-2)
                {
                    System.out.print("x^");
                    System.out.print(length - i - 1);
                }
            }
           //+
           if( i!= (length-1) && arr[i] != 0)
           {
           if (arr[i+1] != 0 )
           {
               if(arr[i+1] <0)
               {
                   System.out.print("-")
               }
               else if(arr[i+1] > 0)
               {
                   System.out.print("+")
               }
           }
           else if (arr[i+1] == 0 )
           {
               int flag = 0;
               for(int j = i+2;j<length;j++)
               {
                   if(arr[j] != 0)
                   {
                       flag = 1;
                       temp = arr[j];
                       break;
                   }

               }
               if(flag == 1)
               {
                   if(temp <0)
                   {
                       System.out.print("-")
                   }
                   else if (temp>0)
                   {
                       System.out.print("+")
                   }
               }
           }
        }
       }
   }
   public static void main(String[]args)
   {
       Poly item = new Poly();
       int []items = {2,0,-5,1,1};
       item.printPoly(items);
   }
}