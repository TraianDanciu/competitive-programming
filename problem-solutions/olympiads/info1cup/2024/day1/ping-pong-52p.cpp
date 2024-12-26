// Pentru limc > 0: dp[a][b][c][player] = numarul de jocuri in care
// player este cel care se uita la ultima runda, A castiga de a ori, B
// castiga de b ori si C castiga de c ori

// Pentru limc = 0: La primul meci impart in trei cazuri si de acolo
// va fi regulat
// Cazul 1. Joaca cineva cu C
// Cazul 2. Castiga A contra B
// Cazul 3. Castiga B contra A

#include "ping-pong.h"

const int MAXVAL = 100;
const int NUM_PLAYERS = 3;
const int MOD = 1'000'000'007;
const int PLAYER_A = 0;
const int PLAYER_B = 1;
const int PLAYER_C = 2;

int dp[MAXVAL + 1][MAXVAL + 1][MAXVAL + 1][NUM_PLAYERS];

void addSelf(int &a, int b) {
  a += b;
  if(a >= MOD) {
    a -= MOD;
  }
}

int solve(int lima, int limb, int limc) {
  int i, a, b, c;
  long long answer;

  if(limc == 0) {
    lima /= 2;
    limb /= 2;

    answer = combinations(lima + limb, lima); // Cazul 1
    if(lima > 0) {
      answer += combinations(lima + limb - 1, limb); // Cazul 2
    }
    if(limb > 0) {
      answer += combinations(lima + limb - 1, lima); // Cazul 3
    }
  } else {
    for(i = 0; i < NUM_PLAYERS; i++) {
      dp[0][0][0][i] = 1;
    }
    
    for(a = 0; a <= lima; a++) {
      for(b = 0; b <= limb; b++) {
        for(c = 0; c <= limc; c++) {
          if(a > 0) {
            // A castiga cu B
            addSelf(dp[a][b][c][PLAYER_B], dp[a - 1][b][c][PLAYER_C]);

            // A castiga cu C
            addSelf(dp[a][b][c][PLAYER_C], dp[a - 1][b][c][PLAYER_B]);
          }

          if(b > 0) {
            // B castiga cu A
            addSelf(dp[a][b][c][PLAYER_A], dp[a][b - 1][c][PLAYER_C]);

            // B castiga cu C
            addSelf(dp[a][b][c][PLAYER_C], dp[a][b - 1][c][PLAYER_A]);
          }

          if(c > 0) {
            // C castiga cu A
            addSelf(dp[a][b][c][PLAYER_A], dp[a][b][c - 1][PLAYER_B]);

            // C castiga cu B
            addSelf(dp[a][b][c][PLAYER_B], dp[a][b][c - 1][PLAYER_A]);
          }
        }
      }
    }

    answer = 0;
    for(i = 0; i < NUM_PLAYERS; i++) {
      answer += dp[lima][limb][limc][i];
    }
  }

  return answer % MOD;
}
