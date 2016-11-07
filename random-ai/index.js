const exec = require('child_process').exec;
const argv = require('process').argv;

const boardWatcher = exec('server/bin/watch-board');

const player = parseInt(argv[2], 10) - 1;

exec('touch server/datastore/game.json');
exec('server/bin/create-game');

boardWatcher.stdout.on('data', (res) => {
  const data = JSON.parse(res);

  if (data.winner) {
    console.log(data);
    return 0;
  }

  if (data.turn % 2 === player) {
    const tiles = [[0, 0], [0, 1], [1, 0], [1, 1], [1, 2], [2, 1], [2, 2], [0, 2], [2, 0]]
      .filter(([x, y]) => {
        return data.board[y][x] == ' ';
      });

    const [x, y] = tiles[Math.floor(Math.random()*tiles.length)];

    console.log('Placing a tile at ' + x + ' ' + y);

    exec('server/bin/add-tile ' + x + ' ' + y, function(_, out, err) {
      if (err) console.log(err);
      console.log(out);
    });


  }
})
