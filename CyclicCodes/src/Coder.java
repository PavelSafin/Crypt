public class Coder {

    private int n;
    private int k;
    private int polynomial;

    public Coder(int n, int k, int polynomial) {
        this.n = n;
        this.k = k;
        this.polynomial = polynomial;
    }

    public int getShift(int a) {
        return (int) (Math.log(a) / Math.log(2)) + 1;
    }

    private Pair getDivideAndMod(int a, int b, int k) {
        int dd = 0;
        while (a / b != 0) {
            int shift = (getShift(a) - k);
            dd += 1 << shift;
            a ^= b << shift;
        }

        return new Pair(dd, a);
    }

    public int divide(int a, int b, int k) {
        return getDivideAndMod(a, b, k).getDiv();
    }

    public int module(int a, int b, int k) {
        return getDivideAndMod(a, b, k).getMod();
    }

    public String encode(int data) {
        int r = this.n - this.k;
        StringBuilder s = new StringBuilder(Integer.toBinaryString(data));
        StringBuilder s1 = new StringBuilder(Integer.toBinaryString(module(data * (1 << r), this.polynomial, this.k)));

        for (int i = s.length(); i < k; ++i)
            s.append("0");

        for (int i = s1.length(); i < r; ++i)
            s1.append("0");

        return s.reverse().append(s1.reverse()).toString();
    }

    public boolean decode(int data) {
        return module(data * (1 << (this.n - this.k)), this.polynomial, this.k) == 0;
    }

    class Pair {
        private int div;
        private int mod;

        public Pair(int div, int mod) {
            this.div = div;
            this.mod = mod;
        }

        public int getDiv() {
            return div;
        }

        public void setDiv(int div) {
            this.div = div;
        }

        public int getMod() {
            return mod;
        }

        public void setMod(int mod) {
            this.mod = mod;
        }
    }

}
