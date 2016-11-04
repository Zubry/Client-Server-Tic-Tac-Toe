#include <fstream>
#include <iostream>
#include <sstream>

#include "../headers/database.h"
#include "../deps/json.hpp"

using json = nlohmann::json;

json read_database() {
  std::ifstream inFile;
  inFile.open("server/datastore/game.json");

  std::stringstream strStream;
  strStream << inFile.rdbuf();
  std::string str = strStream.str();

  // json j = "{ \"happy\": true, \"pi\": 3.141 }"_json;
  json j = json::parse(str);

  return j;
}

void write_database(json input) {
  std::ofstream out("server/datastore/game.json");
  out << input.dump(2);
  out.flush();
  out.close();
}

json create_game() {
  json j = {
    {"board", {
      {" ", " ", " "},
      {" ", " ", " "},
      {" ", " ", " "}
    }},
    {"turn", 0}
  };

  write_database(j);

  return j;
}
