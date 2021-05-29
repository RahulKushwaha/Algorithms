class Solution {
  private static final double PRECISION = 1e-6;
  
  public double getMinDistSum(int[][] positions) {
    return searchX(positions);
  }

  private double searchX(final int[][] positions){
    double lx = 0D, rx  = 1e2;
    for(int i = 0; i < 50; i ++){
    // while(rx - lx >= PRECISION){
      double m1 = (lx + lx + rx) / 3.0D; 
      double m2 = (lx + rx + rx) / 3.0D; 
      
      if(searchY(m1, positions) <= searchY(m2, positions)){
        rx = m2;
      } else {
        lx = m1;
      }
    }
    
    return searchY(lx, positions);
  }
  
  private double searchY(final double x, final int[][] positions){
    double ly = 0D, ry = 1e2;
    for(int i = 0; i < 50; i ++){
    // while(ry - ly >= PRECISION){
      double m1 = (ly + ly + ry) / 3.0D;
      double m2 = (ly + ry + ry) / 3.0D; 
      
      //System.out.println(m1 + " " + m2);
      
      if(distance(x, m1, positions) <= distance(x, m2, positions)){
        ry = m2;
      } else {
        ly = m1;
      }
    }
    
    return distance(x, ly, positions);
  }
  
  private double distance(double x, double y, final int[][] positions){
    double d = 0D; 
    for(int[] position : positions){
      double a = position[0];
      double b = position[1];
      
      d += Math.sqrt(Math.pow((x - a), 2) + Math.pow(y - b, 2));
    }
    
    return d;
  }
}
