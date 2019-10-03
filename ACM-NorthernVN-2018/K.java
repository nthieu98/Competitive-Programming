import java.io.*;
import java.util.*;
import java.math.*;

public class K {
    static int n, m;
    static BigInteger[] a = new BigInteger[1002], b = new BigInteger[1002];
    static BigInteger c, p, q;
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        n = in.nextInt();
        m = in.nextInt();
        c = in.nextBigInteger();
        for (int i = 0; i < n; ++i) {
            a[i] = in.nextBigInteger();
        }
        for (int i = 0; i < m; ++i) {
            b[i] = in.nextBigInteger();
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                BigInteger foo = a[i].gcd(b[j]);
                //System.out.println(foo);
                a[i] = a[i].divide(foo);
                b[j] = b[j].divide(foo);
            }
        }
        p = new BigInteger("1");
        q = new BigInteger("1");
        for (int i = 0; i < n; ++i)
            p = p.multiply(a[i]).mod(c);
        for (int i = 0; i < m; ++i)
            q = q.multiply(b[i]).mod(c);
        System.out.println(p);
        System.out.println(q);
        in.close();
    }
}