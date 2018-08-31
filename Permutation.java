/*
# If this algorithm is given the string in alphabetical order, the permutations will come out in
  alphabetical order as well. This algorithm also doesn't produce duplicate results, if there are repetitive
  characters in the string.

# I've divided the task of finding the permutations into two methods - the first one (permutation) sorts
 the string and records the occurrence of each distinct character in a TreeMap and then passes this TreeMap
 along with a StringBuilder and an ArrayList object (to generate and store the permutations) to the second
 method (findPermutations).
 */

import java.util.ArrayList;
import java.util.TreeMap;

public class Permutation {
    public static void main(String args[]) {
        ArrayList<String> list = permutation("ABCA");

        for(String s: list)
            System.out.println(s);
    }

    public static ArrayList<String> permutation(String s) {
        TreeMap<Character, Integer> count = new TreeMap<>();

        // count the occurrence of each character and store them lexicographically
        for(int i=0; i<s.length(); i++) {
            char ch = s.charAt(i);

            if(count.containsKey(ch)) {
                count.put(ch, count.get(ch)+1);
            } else {
                count.put(ch, 1);
            }
        }

        // Pass the resultList and result objects to the findPermutations() method
        ArrayList<String> resultList =  new ArrayList<String>();
        StringBuilder result = new StringBuilder();

        findPermutations(count, result, resultList);

        return resultList;
    }

    private static void findPermutations(TreeMap<Character, Integer> count,
                                             StringBuilder result, ArrayList<String> resultList) {
        boolean flag = false;

        for(char ch: count.keySet()) {
            if(count.get(ch) > 0) {
                result.append(ch);

                TreeMap<Character, Integer> newCount = new TreeMap<>(count);
                newCount.put(ch, newCount.get(ch) -1);

                findPermutations(newCount, result, resultList);

                flag = true;
            }
        }

        // if the count of all the characters is 0, print/store the permutation and return
        if(!flag) {
            //System.out.println(result);
            resultList.add(result.toString());
            result.deleteCharAt(result.length()-1); // delete the last character before returning to the previous call
            return;
        }

        // After printing or storing the last permutation, when the 0th depth of the recursive method returns,
        // no more characters would be left to delete. So only in that one instance there would an exception
        try {
            result.deleteCharAt(result.length() - 1); // delete the last character before returning to the previous call
        } catch(Exception e) { }
    }
}