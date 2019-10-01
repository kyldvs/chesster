type player =
  | Black
  | White;

type piece =
  | BlackPawn
  | BlackKnight
  | BlackBishop
  | BlackRook
  | BlackQueen
  | BlackKing
  | WhitePawn
  | WhiteKnight
  | WhiteBishop
  | WhiteRook
  | WhiteQueen
  | WhiteKing;

/* All the squares on the board available for easy reference. */
type square =
  | A1
  | A2
  | A3
  | A4
  | A5
  | A6
  | A7
  | A8
  | B1
  | B2
  | B3
  | B4
  | B5
  | B6
  | B7
  | B8
  | C1
  | C2
  | C3
  | C4
  | C5
  | C6
  | C7
  | C8
  | D1
  | D2
  | D3
  | D4
  | D5
  | D6
  | D7
  | D8
  | E1
  | E2
  | E3
  | E4
  | E5
  | E6
  | E7
  | E8
  | F1
  | F2
  | F3
  | F4
  | F5
  | F6
  | F7
  | F8
  | G1
  | G2
  | G3
  | G4
  | G5
  | G6
  | G7
  | G8
  | H1
  | H2
  | H3
  | H4
  | H5
  | H6
  | H7
  | H8;

/* Castling will involve moving the king two squares. */
type move = (square, square);

type position = {
  /* 2D Arrays are for nerds. */
  a1: option(piece),
  a2: option(piece),
  a3: option(piece),
  a4: option(piece),
  a5: option(piece),
  a6: option(piece),
  a7: option(piece),
  a8: option(piece),
  b1: option(piece),
  b2: option(piece),
  b3: option(piece),
  b4: option(piece),
  b5: option(piece),
  b6: option(piece),
  b7: option(piece),
  b8: option(piece),
  c1: option(piece),
  c2: option(piece),
  c3: option(piece),
  c4: option(piece),
  c5: option(piece),
  c6: option(piece),
  c7: option(piece),
  c8: option(piece),
  d1: option(piece),
  d2: option(piece),
  d3: option(piece),
  d4: option(piece),
  d5: option(piece),
  d6: option(piece),
  d7: option(piece),
  d8: option(piece),
  e1: option(piece),
  e2: option(piece),
  e3: option(piece),
  e4: option(piece),
  e5: option(piece),
  e6: option(piece),
  e7: option(piece),
  e8: option(piece),
  f1: option(piece),
  f2: option(piece),
  f3: option(piece),
  f4: option(piece),
  f5: option(piece),
  f6: option(piece),
  f7: option(piece),
  f8: option(piece),
  g1: option(piece),
  g2: option(piece),
  g3: option(piece),
  g4: option(piece),
  g5: option(piece),
  g6: option(piece),
  g7: option(piece),
  g8: option(piece),
  h1: option(piece),
  h2: option(piece),
  h3: option(piece),
  h4: option(piece),
  h5: option(piece),
  h6: option(piece),
  h7: option(piece),
  h8: option(piece),
  /*
   * Necessary to encode in position to determine if enpassant is valid. None
   * at the start of the game.
   *
   * Also used to determine whos turn it is.
   */
  lastMove: option(move),
  /*
   * Castling rights. Note you may have rights but can't castle. (If in or
   * through check for example.)
   */
  whiteLong: bool,
  whiteShort: bool,
  blackLong: bool,
  blackShort: bool,
};

let squareToFile = square => {
  switch (square) {
  | A1 => 1
  | A2 => 1
  | A3 => 1
  | A4 => 1
  | A5 => 1
  | A6 => 1
  | A7 => 1
  | A8 => 1
  | B1 => 2
  | B2 => 2
  | B3 => 2
  | B4 => 2
  | B5 => 2
  | B6 => 2
  | B7 => 2
  | B8 => 2
  | C1 => 3
  | C2 => 3
  | C3 => 3
  | C4 => 3
  | C5 => 3
  | C6 => 3
  | C7 => 3
  | C8 => 3
  | D1 => 4
  | D2 => 4
  | D3 => 4
  | D4 => 4
  | D5 => 4
  | D6 => 4
  | D7 => 4
  | D8 => 4
  | E1 => 5
  | E2 => 5
  | E3 => 5
  | E4 => 5
  | E5 => 5
  | E6 => 5
  | E7 => 5
  | E8 => 5
  | F1 => 6
  | F2 => 6
  | F3 => 6
  | F4 => 6
  | F5 => 6
  | F6 => 6
  | F7 => 6
  | F8 => 6
  | G1 => 7
  | G2 => 7
  | G3 => 7
  | G4 => 7
  | G5 => 7
  | G6 => 7
  | G7 => 7
  | G8 => 7
  | H1 => 8
  | H2 => 8
  | H3 => 8
  | H4 => 8
  | H5 => 8
  | H6 => 8
  | H7 => 8
  | H8 => 8
  };
};

let squareToRank = square => {
  switch (square) {
  | A1 => 1
  | A2 => 2
  | A3 => 3
  | A4 => 4
  | A5 => 5
  | A6 => 6
  | A7 => 7
  | A8 => 8
  | B1 => 1
  | B2 => 2
  | B3 => 3
  | B4 => 4
  | B5 => 5
  | B6 => 6
  | B7 => 7
  | B8 => 8
  | C1 => 1
  | C2 => 2
  | C3 => 3
  | C4 => 4
  | C5 => 5
  | C6 => 6
  | C7 => 7
  | C8 => 8
  | D1 => 1
  | D2 => 2
  | D3 => 3
  | D4 => 4
  | D5 => 5
  | D6 => 6
  | D7 => 7
  | D8 => 8
  | E1 => 1
  | E2 => 2
  | E3 => 3
  | E4 => 4
  | E5 => 5
  | E6 => 6
  | E7 => 7
  | E8 => 8
  | F1 => 1
  | F2 => 2
  | F3 => 3
  | F4 => 4
  | F5 => 5
  | F6 => 6
  | F7 => 7
  | F8 => 8
  | G1 => 1
  | G2 => 2
  | G3 => 3
  | G4 => 4
  | G5 => 5
  | G6 => 6
  | G7 => 7
  | G8 => 8
  | H1 => 1
  | H2 => 2
  | H3 => 3
  | H4 => 4
  | H5 => 5
  | H6 => 6
  | H7 => 7
  | H8 => 8
  };
};

let empty: position = {
  a1: None,
  a2: None,
  a3: None,
  a4: None,
  a5: None,
  a6: None,
  a7: None,
  a8: None,
  b1: None,
  b2: None,
  b3: None,
  b4: None,
  b5: None,
  b6: None,
  b7: None,
  b8: None,
  c1: None,
  c2: None,
  c3: None,
  c4: None,
  c5: None,
  c6: None,
  c7: None,
  c8: None,
  d1: None,
  d2: None,
  d3: None,
  d4: None,
  d5: None,
  d6: None,
  d7: None,
  d8: None,
  e1: None,
  e2: None,
  e3: None,
  e4: None,
  e5: None,
  e6: None,
  e7: None,
  e8: None,
  f1: None,
  f2: None,
  f3: None,
  f4: None,
  f5: None,
  f6: None,
  f7: None,
  f8: None,
  g1: None,
  g2: None,
  g3: None,
  g4: None,
  g5: None,
  g6: None,
  g7: None,
  g8: None,
  h1: None,
  h2: None,
  h3: None,
  h4: None,
  h5: None,
  h6: None,
  h7: None,
  h8: None,
  lastMove: None,
  whiteLong: true,
  whiteShort: true,
  blackLong: true,
  blackShort: true,
};

let start: position = {
  ...empty,
  a1: Some(WhiteRook),
  b1: Some(WhiteKnight),
  c1: Some(WhiteBishop),
  d1: Some(WhiteQueen),
  e1: Some(WhiteKing),
  f1: Some(WhiteBishop),
  g1: Some(WhiteKnight),
  h1: Some(WhiteRook),
  a2: Some(WhitePawn),
  b2: Some(WhitePawn),
  c2: Some(WhitePawn),
  d2: Some(WhitePawn),
  e2: Some(WhitePawn),
  f2: Some(WhitePawn),
  g2: Some(WhitePawn),
  h2: Some(WhitePawn),
  a7: Some(BlackPawn),
  b7: Some(BlackPawn),
  c7: Some(BlackPawn),
  d7: Some(BlackPawn),
  e7: Some(BlackPawn),
  f7: Some(BlackPawn),
  g7: Some(BlackPawn),
  h7: Some(BlackPawn),
  a8: Some(BlackRook),
  b8: Some(BlackKnight),
  c8: Some(BlackBishop),
  d8: Some(BlackQueen),
  e8: Some(BlackKing),
  f8: Some(BlackBishop),
  g8: Some(BlackKnight),
  h8: Some(BlackRook),
};
