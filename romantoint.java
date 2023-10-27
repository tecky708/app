public class romantoint {
    public static void main(String[] args) {
        String s = "MXLM" ;
        int ans = 0;
        int av = 0;
        int bv = 0;
        char a = 'a';
        char b ='b';
        int i;
       
        
        for( i =0;i<s.length();i++){
             a = s.charAt(i);
            
            if (i!=s.length()-1) {
                b = s.charAt(i+1);
                
                
            }
            
            
            
           
            

            switch(a){
                case 'I':
                 av = 1;
                 break;
                case 'V':
                 av = 5;
                 break;
                case 'X':
                 av = 10;
                 break;
                case 'L':
                 av = 50;
                 break;
                case 'C': 
                 av = 100;
                 break;
                case 'D':
                 av = 500;
                 break;
                case 'M':
                 av = 1000;
                 break;

            }
            
            switch(b){
                case 'I':
                 bv = 1;
                 break;
                case 'V':
                 bv = 5;
                 break;
                case 'X':
                 bv = 10;
                 break;
                case 'L':
                 bv = 50;
                 break;
                case 'C': 
                 bv = 100;
                 break;
                case 'D':
                 bv = 500;
                 break;
                case 'M':
                 bv = 1000;
                 break;

            }
            if(av<bv){
                ans = ans -av;


            }
            else if (av>=bv){
                ans = ans +av;

            }
            




        }
        System.out.println(ans);
        System.out.println(s.length());
        

    }
    
}
