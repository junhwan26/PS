#include <iostream>
#include <cstring>

using namespace std;


int dp[10000][16];
string s;

int manager_to_int(char manager) {
   if (manager == 'A')
      return 1;
   
   else if (manager == 'B')
      return 2;
   
   else if (manager == 'C')
      return 4;
   
   else
      return 8;
   
}


int DFS(int index, int before) {
    
   if (index >= s.length()) {
      return 1;
   }

   int manager = manager_to_int(s[index]);

   int ret = 0;
   for (int member = 1; member < 16; member++) {
      if ((member & manager) && (member & before)) {
         if (dp[index][member] == 0) {
            dp[index][member] = DFS(index + 1, member) % 1000000007;
         }
         
         ret += dp[index][member];
         ret %= 1000000007;
      }
   }

   return ret % 1000000007;
}

int main() {
   int T;
   cin >> T;

   for (int tc = 1; tc <= T; tc++) {
      memset(dp, 0, sizeof(dp));

      cin >> s;

      int member = 1;
      int ans = DFS(0, member);

      cout << "#" << tc << " " << ans << "\n";
   }

   return 0;
}
