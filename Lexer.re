type token =
  | Unknown
  | OpenBrace /* Punctuations */
  | CloseBrace
  | OpenBracket
  | CloseBracket
  | String(string) /* Literals */
  | Variable(string)
  | Float(float)
  | Int(int);

let commentsRegexp = Str.regexp("\\(#.+\\)$");

let whitespaceRegexp = Str.regexp("\\([\r\n|\r|\n|\t|  ]+\\)");

let spaceRegexp = Str.regexp(" ");

let floatRegexp = Str.regexp("^[0-9]+\\.[0-9]+$");

let intRegexp = Str.regexp("^[0-9]+$");

let variableRegexp = Str.regexp("^\\$[A-Za-z]+$");

let stringRegexp = Str.regexp("^[A-Za-z]+$");

let isFloat = value => Str.string_match(floatRegexp, value, 0);

let isInt = value => Str.string_match(intRegexp, value, 0);

let isVariable = value => Str.string_match(variableRegexp, value, 0);

let isString = value => Str.string_match(stringRegexp, value, 0);

let tokenize = (source: string) : list(token) =>
  source
  |> Str.global_replace(commentsRegexp, "")
  |> Str.global_replace(whitespaceRegexp, " ")
  |> Str.split(spaceRegexp)
  |> List.map(s =>
       switch s {
       | "{" => OpenBrace
       | "}" => CloseBrace
       | "[" => OpenBracket
       | "]" => CloseBracket
       | _ when isInt(s) => Int(int_of_string(s))
       | _ when isFloat(s) => Float(float_of_string(s))
       | _ when isVariable(s) =>
         Variable(String.sub(s, 1, String.length(s) - 1))
       | _ when isString(s) => String(s)
       | _ => Unknown
       }
     );
