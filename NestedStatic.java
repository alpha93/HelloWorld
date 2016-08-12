class Outer {
	int x = 10;
	static int y = 20;

	static class Inner {
		int i = 33;
		static int j = 44;
        
        void show() {
    	//System.out.println("Outer variable x = " + x);        // This is illegal  
		System.out.println("Outer variable x = " + new Outer().x);  
		System.out.println("Outer variable y = " + y); 

        System.out.println("Inner variable i = " + i);  
		System.out.println("Inner variable j = " + j); 
	    }  
}
}

class Main {
	public static void main(String[] args) {
		Outer.Inner ob = new Outer.Inner();
		ob.show();
	}
}