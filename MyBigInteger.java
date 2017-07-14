/* 
 In this program I've implemented a way to store and manipulate integers larger than the 'long' type can hold.
 Put differently, I tried to emulate the java.math.BigInteger class.

 Im storing the numbers in strings.
 
 For addition, Im convertig one digit at a time from each number to 'int', performing their addition and storing the result
 back in another string, while keeping track of any carry. At the end, reversing that string yields the addition.
 
 The multiplication is done in a similar way.
 */  

class Main {
    public static void main(String ...args) {
        long t = System.currentTimeMillis();

        MyBigInteger mb = new MyBigInteger("13495834098542499032843209403294324393048035803495834133501821918265914");
        System.out.println("Addition: " + mb.add("3495834098542498417604525618093048035803495349857934875987349347589776045256180204324090") + "\n");

        mb = new MyBigInteger("234038476327469274328947389470932840932840983209483209483209");
        System.out.println("Multiplication: " + mb.multiply("2372346846326483278764873264873267864873232894728937927387342") + "\n");

        System.out.println("factorial of 100: " + factorial(100) + "\n");
        System.out.println("Total time taken for calculation: " + (System.currentTimeMillis() - t));

    }

    static String factorial(int n) {
        MyBigInteger fact = new MyBigInteger("1");

        for(int i=2; i<=n; i++) {
            fact.setValue(fact.multiply(i + ""));
        }

        return fact.getValue();
    }
}

class MyBigInteger {
    private String number;

    MyBigInteger(String number) {
        this.number = number;
    }

    void setValue(String number) {
        this.number = number;
    }

    String getValue() {
        return number;
    }

    String add(String num) {
        StringBuilder addition = new StringBuilder("");
        StringBuilder num2 = new StringBuilder(num);
        StringBuilder number2 = new StringBuilder(number);
        StringBuilder smaller = number2.length() > num2.length() ? num2 : number2;
        int carry = 0;
        int diff = Math.abs(num2.length() - number.length());

        for(int i=0; i<diff; i++)
            smaller.insert(0, 0);   // insert 0's at the begining of the smaller number to avoid StringIndexOutOfBoundsException when String.charAt(index) is used

        for(int i=number2.length()-1; i>=0; i--) {
            String sum = (number2.charAt(i) + num2.charAt(i) + carry - 96) + ""; // subtracting 48 from each char

            if(sum.length() == 2) {
                carry = sum.charAt(0) - 48;
                addition.append(sum.charAt(1) - 48);
            } else {
                carry = 0;
                addition.append(sum.charAt(0) - 48);
            }
        }

        if(carry > 0)
            addition.append(carry);

        return addition.reverse().toString();
    }

    String multiply(String num) {
        MyBigInteger mb = new MyBigInteger("0");
        int carry = 0;
        int pos = 0;

        for(int i=number.length()-1; i>=0; i--) {
            StringBuilder tmp = new StringBuilder("");

            for(int j=num.length()-1; j>=0; j--) {
                String pdt = ((number.charAt(i) - 48) * (num.charAt(j) - 48) + carry) + "";

                if(pdt.length() == 2) {
                    tmp.append(pdt.charAt(1));
                    carry = pdt.charAt(0) - 48;
                } else {
                    tmp.append(pdt.charAt(0));
                    carry = 0;
                }
            }

            if(carry > 0) {
                tmp.append(carry);
                carry = 0;
            }

            for(int j=0; j<pos; j++)
                tmp.insert(0, 0);

            mb.setValue(mb.add(tmp.reverse().toString()));
            pos++;
        }

        return mb.getValue();
    }
}
