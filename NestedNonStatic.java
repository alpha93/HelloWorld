class Outer {
	int x = 10;
	static int y = 20;

	class Inner {
		int i = 22;
		static final int j = 33; // Illegal, static variables also has to be final within a non-static nested class
        
        void show() {
        	System.out.println("Outer x = " + x);
        	System.out.println("Outer y = " + y);

        	System.out.println("Inner i = " + i);
        	System.out.println("Inner j = " + j);
        }
	} 
}

class Main{
	public static void main(String[] args) {
		Outer.Inner ob = new Outer().new Inner();    // since the inner class is a non-static member of the outer class, we must instantiate the inner class through an object of the outer class.
		ob.show();
	}
}
