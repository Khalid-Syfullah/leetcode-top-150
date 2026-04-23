public class TrappingRainWater {

    public static int trap(int[] h) {
        int l = 0, r = h.length - 1, lMax = 0, rMax = 0, water = 0;
        while (l < r) {
            if (h[l] < h[r]) {
                if (h[l] >= lMax) lMax = h[l];
                else water += lMax - h[l];
                l++;
            } else {
                if (h[r] >= rMax) rMax = h[r];
                else water += rMax - h[r];
                r--;
            }
        }
        return water;
    }

    public static void main(String[] args) {
        System.out.println(trap(new int[]{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1})); // 6
        System.out.println(trap(new int[]{4, 2, 0, 3, 2, 5}));                   // 9
    }
}
