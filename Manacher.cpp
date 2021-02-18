/*
prepare two vectors d0 and d1 :
d0 - len of even palindrome centered at i. 
d1 - len of odd palindrome centered at i.

i/p : 
      abbcbba
o/p :
      0 2 0 0 2 0 0 
      1 1 1 7 1 1 1 
*/

vector<int> d0, d1;

template <typename T>
void manacher(int n, const T &s) {
  if (n == 0) {
    return ;
  }
  vector<int> res(2 * n, 0);
  int l = -1, r = -1;
  for (int z = 0; z < 2 * n - 1; z++) {
    int i = (z + 1) >> 1;
    int j = z >> 1;
    int p = (i >= r ? 0 : min(r - i, res[2 * (l + r) - z]));
    while (j + p + 1 < n && i - p - 1 >= 0) {
      if (!(s[j + p + 1] == s[i - p - 1])) {
        break;
      }
      p++;
    }
    if (j + p > r) {
      l = i - p;
      r = j + p;
    }
    res[z] = p;
  }

  for(int i = 0; i < res.size(); i ++) {
      res[i] = 2*res[i] + ((i&1) == 0);
      i&1 ? d0.push_back(res[i]) : d1.push_back(res[i]);
  }
}
 
template <typename T>
void manacher(const T &s) {
  manacher((int) s.size(), s);
}