exception InvalidSyntax(string);

type datasetType =
  | Mnist;

type hyperparametersParams = {
  batchSize: int,
  epochs: int,
  numClasses: int
};

type denseLayerParams = {
  inputDim: int,
  units: int,
  activation: string
};

type dropoutLayerParams = {rate: float};

type trainParams = {
  loss: string,
  optimizer: string,
  metris: list(string)
};

type layer =
  | Dense(denseLayerParams)
  | Dropout(dropoutLayerParams);

type node =
  | Hyperparameters(hyperparametersParams)
  | Dataset(datasetType)
  | SequentialModel(list(layer))
  | Train(trainParams);

let consumeOpenBrace = (s: Stream.t(Lexer.token)) =>
  switch (Stream.peek(s)) {
  | Some(Lexer.OpenBrace) =>
    Stream.junk(s);
    ();
  | Some(_)
  | None => raise(InvalidSyntax("Expected opening bracket"))
  };

let consumeFloat = (s: Stream.t(Lexer.token)) : float =>
  switch (Stream.peek(s)) {
  | Some(Lexer.Float(f)) =>
    Stream.junk(s);
    f;
  | Some(_)
  | None => raise(InvalidSyntax("Expected float"))
  };

let consumeInt = (s: Stream.t(Lexer.token)) : int =>
  switch (Stream.peek(s)) {
  | Some(Lexer.Int(i)) =>
    Stream.junk(s);
    i;
  | Some(_)
  | None => raise(InvalidSyntax("Expected int"))
  };

let parse = (tokens: list(Lexer.token)) : list(node) => [];
