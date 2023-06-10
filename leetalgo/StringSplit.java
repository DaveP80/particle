public class StringSplit {
    //Codewars problem
    //Complete the solution so that it splits the string into pairs of two characters. If the
    // string contains an odd number of characters then it should replace the missing second
    // character of the final pair with an underscore ('_').
    public static String[] solution(String s) {
        int count = 0;
        int arrlength = 0;
        boolean flag = s.length() % 2 == 1;
        if (flag) arrlength = ((int) s.length()/2) + 1;

        else arrlength = s.length()/2;

        String[] sol = new String[arrlength];
        for (int i = 0; i<s.length(); i++) {

            if (i%2 == 1) {
                sol[count] = s.substring(i-1, i+1);
                count++;
            }
        }

        if (flag) sol[count] = s.substring(s.length()-1) + "_";
        return sol;
    }

    public static void main(String[] args) {
        String[] response = solution("fatkingsongreen");

        for (String r : response) System.out.println(r);
        //fa
        //tk
        //in
        //gs
        //on
        //gr
        //ee
        //n_
    }
}