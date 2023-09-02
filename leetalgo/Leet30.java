// You are given a string s and an array of strings words. All the strings of words are of the same length.

// A concatenated substring in s is a substring that contains all the strings of any permutation of words concatenated.

// For example, if words = ["ab","cd","ef"], then "abcdef", "abefcd", "cdabef", "cdefab", "efabcd", and "efcdab" are 
// all concatenated strings. "acdbef" is not a concatenated substring because it is not the concatenation of any permutation of words.
// Return the starting indices of all the concatenated substrings in s. You can return the answer in any order.
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

class Leet30 {
    public static List<Integer> findSubstring(String s, String[] words) {
        List<Integer> result = new ArrayList<>();
        if (s == null || s.isEmpty() || words == null || words.length == 0) {
            return result;
        }
        int wordLength = words[0].length();
        int totalWords = words.length;
        HashMap<String, Integer> wordCount = new HashMap<>();
        // Count occurrences of each word in the input words array
        for (String word : words) {
            wordCount.put(word, wordCount.getOrDefault(word, 0) + 1);
        }
        for (int i = 0; i < wordLength; i++) {
            int left = i;
            int count = 0;
            HashMap<String, Integer> currentWordCount = new HashMap<>();
            for (int j = i; j <= s.length() - wordLength; j += wordLength) {
                String currentWord = s.substring(j, j + wordLength);
                System.out.println(currentWord);
                if (wordCount.containsKey(currentWord)) {

                    currentWordCount.put(currentWord, currentWordCount.getOrDefault(currentWord, 0) + 1);
                    count++;
                    while (currentWordCount.getOrDefault(currentWord, 0) > wordCount.getOrDefault(currentWord, 0)) {
                        String leftWord = s.substring(left, left + wordLength);
                        currentWordCount.put(leftWord, currentWordCount.get(leftWord) - 1);
                        count--;
                        left += wordLength;
                    }
                    if (count == totalWords) {
                        result.add(left);
                        String leftWord = s.substring(left, left + wordLength);
                        currentWordCount.put(leftWord, currentWordCount.get(leftWord) - 1);
                        count--;
                        left += wordLength;
                    }
                } else {
                    currentWordCount.clear();
                    count = 0;
                    left = j + wordLength;
                }
            }
        }
        return result;
    }
    public static void main(String[] args) {
        System.out.println(findSubstring("frveebwrcrcabobveeobrcakewrcrcaveebobwrcogjeepyobobrcaveewrcbbobveeobveercakewrcitewrcbobveebobrcawrcrcakeveerzoo",
                new String[]{"bob", "vee", "rca", "wrc"}));
                //[6, 48, 25, 28, 89]
    }
}