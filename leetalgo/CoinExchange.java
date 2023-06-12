import java.util.HashMap;
import java.util.Map;

class CoinExchange {
    //CodeWars
//    Given coins value n, we want to make change for n cents, and we have different types of coin
//    type, how many ways can we make change from n coins to type?
//    Given n = 5 and type = [1,2,3] should return 5
//            5 = 1 + 1 + 1 + 1 + 1
//            5 = 1 + 2 + 2
//            5 = 1 + 1 + 3
//            5 = 2 + 3
//            5 = 1 + 1 + 1 + 2
    public static long exchange(int type[], int n) {
        Map<Integer, Integer> map = findNum(type);
        long found = 0;
        for (int i = 1; i <= n; i++) {
            if (map.containsKey(i)) found = (long) map.get(i);
        }

        if (n > type[type.length - 1]) {
            int factor = n / type[type.length - 1];
            int lookup = 0;
            int remainder = n % type[type.length - 1];
            if (map.containsKey(remainder)) lookup = map.get(remainder);

            found = (long) (Math.pow(found, factor) + lookup);
        }
        return found;
    }
    private static Map<Integer, Integer> findNum(int[] arr) {

        int n = arr.length;
        int[] dp = new int[arr[n - 1] + 1];
        Map<Integer, Integer> keyValueMap = new HashMap<>();

        dp[0] = 1;

        for (int k : arr) {
            for (int j = k; j <= arr[n - 1]; j++) {
                dp[j] += dp[j - k];
            }
            keyValueMap.put(k, dp[k]);
        }
        return keyValueMap;
    }

    public static void main(String[] args) {
        long ans = exchange(new int[]{1, 5, 10, 50, 100}, 11);
        System.out.println(ans);
        //4
    }
}