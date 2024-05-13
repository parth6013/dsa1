import java.io.*;
public class inp1{
    public static void main(String args[]){
        try{
            pp object1=new pp("A",-5,3.4e1);
            System.out.println(object1);
            FileOutputStream fs=new FileOutputStream("serial");
            ObjectOutputStream os =new ObjectOutputStream(fs);
            os.writeObject(object1);
            os.flush();
            os.close();
        }catch(Exception e){
            System.out.println("");
            System.exit(0);    
        }
    }
}

class pp implements Serializable{

    String str1;
    int ii;
    double d;
    public pp(String str1,int ii,double d){
        this.str1=str1;
        this.ii=ii+1;
        this.d=d+1.5;
    }
    public String toString(){
        return "" + ++ii +--d; 
    }


}