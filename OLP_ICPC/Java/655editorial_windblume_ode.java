//stan hu tao
//come to K-expo!!!
//watch me get carried in nct ridin
import static java.lang.Math.max;
import static java.lang.Math.min;
import static java.lang.Math.abs;
import static java.lang.System.out;
import java.util.*;
import java.io.*;
import java.math.*;

public class WindblumeOdeModel {
    public static void main(String hi[]) throws Exception {
        BufferedReader infile = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(infile.readLine());
        int T = Integer.parseInt(st.nextToken());
        StringBuilder sb = new StringBuilder();
        outer: while (T-- > 0) {
            st = new StringTokenizer(infile.readLine());
            int N = Integer.parseInt(st.nextToken());
            int[] arr = readArr(N, infile, st);
            long sum = 0L;
            int odd = -1;
            for (int x : arr) {
                sum += x;
                if (x % 2 == 1)
                    odd = x;
            }
            if (isPrime(sum)) {
                sb.append((N - 1) + "\n");
                for (int i = 1; i <= N; i++)
                    if (arr[i - 1] != odd)
                        sb.append(i + " ");
                sb.append("\n");
            } else {
                sb.append(N + "\n");
                for (int i = 1; i <= N; i++)
                    sb.append(i + " ");
                sb.append("\n");
            }
        }
        System.out.print(sb);
    }
    public static int[] readArr(int N, BufferedReader infile, StringTokenizer st) throws Exception {
        int[] arr = new int[N];
        st = new StringTokenizer(infile.readLine());
        for (int i = 0; i < N; i++)
            arr[i] = Integer.parseInt(st.nextToken());
        return arr;
    }
    public static boolean isPrime(long n) {
        if (n < 2) return false;
        if (n == 2 || n == 3) return true;
        if (n % 2 == 0 || n % 3 == 0) return false;
        long sqrtN = (long)Math.sqrt(n) + 1;
        for (long i = 6L; i <= sqrtN; i += 6) {
            if (n % (i - 1) == 0 || n % (i + 1) == 0) return false;
        }
        return true;
    }
}