class Groupingproblem {
//    There are n cities. Some of them are connected, while some are not. If city a is
//    connected directly with city b, and city b is connected directly with city c, then
//    city a is connected indirectly with city c.
//
//    A province is a group of directly or indirectly connected cities and no other
//    cities outside of the group.
//
//    You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the
//    ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.
//
//    Return the total number of provinces.
    //Leet No.547 
    static class Solution {
        public int findCircleNum(int[][] isConnected) {
            int v = isConnected.length;
            int[] visited = new int[v];
            int cnt = 0;
            for(int i = 0; i<v; i++)
            {
                if(visited[i] == 0)
                {
                    cnt++;
                    dfs(i, isConnected, visited);
                }
            }
            return cnt;
        }
        public void dfs(int start, int[][] isConnected, int[] visited)
        {
            visited[start] = 1;
            for(int j = 0; j<isConnected.length; j++)
            {
                if(isConnected[start][j] == 1 && visited[j] == 0)
                {
                    dfs(j, isConnected, visited);
                }
            }
        }
    }
    public static void main(String[] args) {

        Solution sol = new Solution();
        int[][] testarray = {{1,0,0,1},{0,0,0,0},{0,0,0,0},{1,0,0,1}};

        int result = sol.findCircleNum(testarray);

        System.out.println(result);
        //3
        
    }
}