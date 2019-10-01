type player =
  | Black
  | White;

type piece =
  | NoPiece
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
  a1: piece,
  a2: piece,
  a3: piece,
  a4: piece,
  a5: piece,
  a6: piece,
  a7: piece,
  a8: piece,
  b1: piece,
  b2: piece,
  b3: piece,
  b4: piece,
  b5: piece,
  b6: piece,
  b7: piece,
  b8: piece,
  c1: piece,
  c2: piece,
  c3: piece,
  c4: piece,
  c5: piece,
  c6: piece,
  c7: piece,
  c8: piece,
  d1: piece,
  d2: piece,
  d3: piece,
  d4: piece,
  d5: piece,
  d6: piece,
  d7: piece,
  d8: piece,
  e1: piece,
  e2: piece,
  e3: piece,
  e4: piece,
  e5: piece,
  e6: piece,
  e7: piece,
  e8: piece,
  f1: piece,
  f2: piece,
  f3: piece,
  f4: piece,
  f5: piece,
  f6: piece,
  f7: piece,
  f8: piece,
  g1: piece,
  g2: piece,
  g3: piece,
  g4: piece,
  g5: piece,
  g6: piece,
  g7: piece,
  g8: piece,
  h1: piece,
  h2: piece,
  h3: piece,
  h4: piece,
  h5: piece,
  h6: piece,
  h7: piece,
  h8: piece,
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
  a1: NoPiece,
  a2: NoPiece,
  a3: NoPiece,
  a4: NoPiece,
  a5: NoPiece,
  a6: NoPiece,
  a7: NoPiece,
  a8: NoPiece,
  b1: NoPiece,
  b2: NoPiece,
  b3: NoPiece,
  b4: NoPiece,
  b5: NoPiece,
  b6: NoPiece,
  b7: NoPiece,
  b8: NoPiece,
  c1: NoPiece,
  c2: NoPiece,
  c3: NoPiece,
  c4: NoPiece,
  c5: NoPiece,
  c6: NoPiece,
  c7: NoPiece,
  c8: NoPiece,
  d1: NoPiece,
  d2: NoPiece,
  d3: NoPiece,
  d4: NoPiece,
  d5: NoPiece,
  d6: NoPiece,
  d7: NoPiece,
  d8: NoPiece,
  e1: NoPiece,
  e2: NoPiece,
  e3: NoPiece,
  e4: NoPiece,
  e5: NoPiece,
  e6: NoPiece,
  e7: NoPiece,
  e8: NoPiece,
  f1: NoPiece,
  f2: NoPiece,
  f3: NoPiece,
  f4: NoPiece,
  f5: NoPiece,
  f6: NoPiece,
  f7: NoPiece,
  f8: NoPiece,
  g1: NoPiece,
  g2: NoPiece,
  g3: NoPiece,
  g4: NoPiece,
  g5: NoPiece,
  g6: NoPiece,
  g7: NoPiece,
  g8: NoPiece,
  h1: NoPiece,
  h2: NoPiece,
  h3: NoPiece,
  h4: NoPiece,
  h5: NoPiece,
  h6: NoPiece,
  h7: NoPiece,
  h8: NoPiece,
  lastMove: None,
  whiteLong: true,
  whiteShort: true,
  blackLong: true,
  blackShort: true,
};

let start: position = {
  ...empty,
  a1: WhiteRook,
  b1: WhiteKnight,
  c1: WhiteBishop,
  d1: WhiteQueen,
  e1: WhiteKing,
  f1: WhiteBishop,
  g1: WhiteKnight,
  h1: WhiteRook,
  a2: WhitePawn,
  b2: WhitePawn,
  c2: WhitePawn,
  d2: WhitePawn,
  e2: WhitePawn,
  f2: WhitePawn,
  g2: WhitePawn,
  h2: WhitePawn,
  a7: BlackPawn,
  b7: BlackPawn,
  c7: BlackPawn,
  d7: BlackPawn,
  e7: BlackPawn,
  f7: BlackPawn,
  g7: BlackPawn,
  h7: BlackPawn,
  a8: BlackRook,
  b8: BlackKnight,
  c8: BlackBishop,
  d8: BlackQueen,
  e8: BlackKing,
  f8: BlackBishop,
  g8: BlackKnight,
  h8: BlackRook,
};
