# Tic Tac Toe w/ Client & Server Architecture

Pretty much any game of significant complexity requires a client-server architecture. Although tic-tac-toe probably isn't one of them, it does serve to show how client-server architecture works without confounding things with complex gameplay rules. A common misconception is that games must implement their client in the same environment as their server; in fact, it's possible to implement each in their own languages. Moreover, using separate languages and environments for the client and server helps ensure that the two stay entirely separate from each other.

## The server

We use a C++ server, which has two functions: create a new game and place a tile at a given location. We set up one program for each function. In both, we accept any parameters through argv and then output any results to stdout as a JSON string. These two programs are called endpoints. We can access them by running `./server/bin/create-game/` and `./server/bin/add-tile/`.

## The client

We use an Electron client, which allows you to build desktop applications using HTML, CSS, and JavaScript. In order to access the server, we call a function called `exec`, which runs a shell command and passes its stdout to a callback. That is, we can run something like:

```JavaScript
exec('./server/bin/create-game/', function(_, stdout, stderr) {
  // Process stdout
});
```

Hopefully, this should remind you of accessing a web server API, which might look like this:

```JavaScript
request('http://www.server.tld/create-game/', function(res, err) {
  // Process res
});
```

This allows us to create a client that is completely agnostic about the server. Whether it's a web server, a C++ server, a Java server, or anything else doesn't matter to our client.
