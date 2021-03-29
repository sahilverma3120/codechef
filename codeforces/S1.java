import java.io.*;
import java.util.*;
 
 
 
 
public class Main {
 
    public static void main(String[] args) throws Exception {
       
       Scanner scn= new Scanner(System.in);
       int n =scn.nextInt();
       if(n%2==0 && n>2)
       {
           System.out.println("Yes");
       }
       else
       {
           System.out.println("No");
       }
       
       
     }
}
