let ic = open_in("./examples/mnist.giss");

let source = really_input_string(ic, in_channel_length(ic));

let tokens = Lexer.tokenize(source);

let nodes = Parser.parse(tokens);
/* TODO: print nodes. */
