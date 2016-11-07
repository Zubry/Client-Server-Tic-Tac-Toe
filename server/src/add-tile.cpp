#include "../deps/json.hpp"
#include "../headers/database.h"
#include <stdlib.h>

using json = nlohmann::json;

std::string get_tile(int turn) {
  if (turn % 2 == 0) {
    return "x";
  } else {
    return "o";
  }
}

bool winner(json board) {
  // There are tricks. But it's 3x3 so let's be lazy
  // Hopefully this includes every possibility

  // Rows
  for (int i = 0; i < 3; i++) {
    if (board["board"][i][0] == board["board"][i][1] && board["board"][i][1] == board["board"][i][2]) {
      if (board["board"][i][0] != " ") {
        return true;
      }
    }
  }

  // Columns
  for (int i = 0; i < 3; i++) {
    if (board["board"][0][i] == board["board"][1][i] && board["board"][1][i] == board["board"][2][i]) {
      if (board["board"][0][i] != " ") {
        return true;
      }
    }
  }

  if (board["board"][0][0] == board["board"][1][1] && board["board"][1][1] == board["board"][2][2]) {
    if (board["board"][0][0] != " ") {
      return true;
    }
  }

  if (board["board"][2][0] == board["board"][1][1] && board["board"][1][1] == board["board"][0][2]) {
    if (board["board"][2][0] != " ") {
      return true;
    }
  }

  return false;
}

bool draw(json board) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board["board"][i][j] == " ") {
        return false;
      }
    }
  }

  return true;
}

int main( int argc, char *argv[] ) {
  if (argc < 3) {
    std::cerr << "{ \"error\": \"Missing move\" }" << std::endl;
    return 1;
  }

  int x = atoi(argv[1]);
  int y = atoi(argv[2]);

  json game = read_database();

  std::string tile = game["board"][y][x];

  if (tile != " ") {
    std::cerr << "{ \"error\": \"Tile already placed\" }" << std::endl;
    return 1;
  }

  int turn = game["turn"];

  game["board"][y][x] = get_tile(turn);
  game["turn"] = turn + 1;

  if (winner(game)) {
    game["winner"] = get_tile(turn);
  }

  if (draw(game)) {
    game["winner"] = "draw";
    std::cerr << "{ \"error\": \"Game over!\" }" << std::endl;
  }

  write_database(game);

  std::cout << game.dump(2) << std::endl;

  return 0;
}
