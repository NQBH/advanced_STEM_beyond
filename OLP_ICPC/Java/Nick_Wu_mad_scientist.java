import java.io.*;
import java.util.*;
public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("breedflip.in"));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("breedflip.out")));
        int n = Integer.parseInt(br.readLine());
        char[] a = br.readLine().toCharArray();
        char[] b = br.readLine().toCharArray();
        int ret = 0;
        while (!new String(a).equals(new String(b))) {
            ret++;
            int lhs = 0;
            while (a[lhs] == b[lhs]) lhs++;
            int rhs = n - 1;
            while (a[rhs] == b[rhs]) rhs--;
            for (int i = lhs; i <= rhs; i++) {
                if (a[i] == 'G') a[i] = 'H';
                else a[i] = 'G';
            }
        }
        pw.println(ret);
        pw.close();
    }
}