/*
 *  method (example):
 *  48 = 2^4 * 3^1
 *  10 = 2^1 * 5^1
 *  45 = 3^2 * 5^1
 *  
 *  lcm = take each of the distinct factors from all the numbers with their highest powers and multiply them
 *  so, lcm = 2^4 * 3^2 * 5^1   
 */
import java.util.ArrayList;
import java.lang.Math;
import java.util.HashSet;
import java.util.Scanner;

public class Lcm {
    public static void main(String ...args) {
        System.out.println(findLcm(45, 10, 48));
    }

    // This function finds the prime factors and their occurrences, of a number and packs the two values in a Factor Object
    static ArrayList<Factor> findPrimeFactors(int n) {
        int divisor = 2;
        ArrayList<Factor> factors = new ArrayList<>();
        Factor f = new Factor();

        while(n != 1) {
            if(n % divisor == 0) {
                n /= divisor;
                f.value = divisor;
                f.occurrene++;
            } else {
                if(f.value != 0) {
                    factors.add(f);
                    f = new Factor();
                }

                divisor++;
            }
        }
        factors.add(f);

        return factors;
    }

    static int findLcm(int ...nums) {
        ArrayList<Factor> f;
        ArrayList<Factor> g = new ArrayList<>();
        boolean flag = false;


        for(int i=0; i<nums.length; i++) {
            f = findPrimeFactors(nums[i]);      // find the prime factors and their occurrences of each number

            for(int j=0; j<f.size(); j++) {
                for(int k=0; k<g.size(); k++) {
                    if(g.get(k).value == f.get(j).value) {
                        if(g.get(k).occurrene < f.get(j).occurrene)
                            g.get(k).occurrene = f.get(j).occurrene;

                        flag = true;
                    }
                }

                if(!flag)
                    g.add(f.get(j));
                else
                    flag = false;
            }
        }

        int lcm = 1;

        for(Factor k: g) {
            //System.out.println(k);    // for debugging purposes
            lcm *= Math.pow(k.value, k.occurrene);
        }

        return lcm;
    }
}

class Factor {
    int value;
    int occurrene;

    // public String toString() {       // for debugging purposes
    //     return "value: " + value + " occurrence: " + occurrene;
    // }
}
