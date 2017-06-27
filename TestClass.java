import java.util.*;
import java.io.*;
class TestClass {
	
	
 	
 
    public static void main(String args[] ) throws Exception {
       

        //Scanner
        Scanner s = new Scanner(System.in);
        

        
      
        int n,b,i,j,k,z,x=0,y=0,p,q,l,m,ans=0,r;
         n =s.nextInt();
        int[] a = new int[100001];
        for(i = 1; i <= n; i++)
        	a[i] = s.nextInt();
        	a[0] = 0;
        boolean[] f = new boolean[100001];
        for(i = 0 ; i <= 100000; i++)
        f[i] = false;
        
        f[0] = f[1] = true;
 	for( i = 2; i <= 100000 ;i++)
 	{
 		if(f[i] == false)
 		{
 			for(  j = i + i; j <= n ; j = j + i)
 				f[j] = true;
 		}
 	}

           
          int[] pr = new int[100001]; 
          pr[0] = 0;
         for(i = 1;i <= n; i++)
         {
    	    if(f[a[i]] == false)
   	    	 pr[i] = pr[i - 1] + 1;
   	       else
   		    pr[i] = pr[i - 1];
          }
        
      q = s.nextInt();
      while(q > 0)
      {
      	q--;
      	l = s.nextInt();
      	r = s.nextInt();
          ans = pr[r] - pr[l - 1];
          System.out.println(ans);
      }




    }
}
