public class maxPow2 {
    public double myPow(double x, int n) {
        
        long power = n;
        double result = 1.0;

        if (power < 0) {
            x = 1.0 / x;
            power = -power;
        }

        while (power > 0) {
            if (power % 2 != 0) {
                result = result * x;
            }
     
            x = x * x;
            power = power / 2;
        }

        return result;
    }
    
}
