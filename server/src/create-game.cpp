#include "../deps/json.hpp"
#include "../headers/database.h"

using json = nlohmann::json;

int main() {
  json game = create_game();
  write_database(game);

  std::cout << game.dump(2) << std::endl;

  return 0;
}
