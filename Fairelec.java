/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;
import java.util.Arrays;
import java.util.stream.IntStream; 
import java.util.Collections;


/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
	Scanner scn = new Scanner(System.in);
	int t = scn.nextInt();
	while(t-- != 0){
	int n = scn.nextInt();
	int m = scn.nextInt();
	int[] arr1 = new int[n];
	int[] arr2 = new int[m];
	int sum1 =0, sum2 = 0;
	for(int i=0;i<arr1.length; i++){
	    arr1[i] = scn.nextInt();
	    sum1 += arr1[i];
	}
	for(int i=0;i<arr2.length; i++){
	    arr2[i] = scn.nextInt();
	    sum2 += arr2[i];
	}
	if(sum1 > sum2){
    System.out.println(0);
    continue;
	}
	Arrays.sort(arr1);
	Arrays.sort(arr2);
	
	int swap  = 0;
	int k = arr2.length-1;
	for(int i=0;i<arr1.length; i++){
	    sum1 = sum1-arr1[i];
	    sum2 = sum2-arr2[i];
	    sum1 = sum1+arr2[i];
	    sum2 = sum2+arr1[i];
	    swap++;
	    k--;
	    if(sum1>sum2 || k<0){
	        break;
	    }
}
	
	if(sum1 < sum2){
	    System.out.println(-1);
	}
	else{
	   System.out.println(swap);
	}
	  }
	 
	}
}
