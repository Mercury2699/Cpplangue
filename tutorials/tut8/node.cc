struct Node{
  ...
  static int inc;
  static void setinc(int val){ inc = val; }
  void increment(){ ++inc; }
  ...
};

