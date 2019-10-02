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

/* Rank and file */
type rf = (int, int);

type position = {
  /* 1D Arrays are for nerds. */
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

let squareToRankAndFile = square => {
  switch (square) {
  | A1 => (0, 0)
  | A2 => (1, 0)
  | A3 => (2, 0)
  | A4 => (3, 0)
  | A5 => (4, 0)
  | A6 => (5, 0)
  | A7 => (6, 0)
  | A8 => (7, 0)
  | B1 => (0, 1)
  | B2 => (1, 1)
  | B3 => (2, 1)
  | B4 => (3, 1)
  | B5 => (4, 1)
  | B6 => (5, 1)
  | B7 => (6, 1)
  | B8 => (7, 1)
  | C1 => (0, 2)
  | C2 => (1, 2)
  | C3 => (2, 2)
  | C4 => (3, 2)
  | C5 => (4, 2)
  | C6 => (5, 2)
  | C7 => (6, 2)
  | C8 => (7, 2)
  | D1 => (0, 3)
  | D2 => (1, 3)
  | D3 => (2, 3)
  | D4 => (3, 3)
  | D5 => (4, 3)
  | D6 => (5, 3)
  | D7 => (6, 3)
  | D8 => (7, 3)
  | E1 => (0, 4)
  | E2 => (1, 4)
  | E3 => (2, 4)
  | E4 => (3, 4)
  | E5 => (4, 4)
  | E6 => (5, 4)
  | E7 => (6, 4)
  | E8 => (7, 4)
  | F1 => (0, 5)
  | F2 => (1, 5)
  | F3 => (2, 5)
  | F4 => (3, 5)
  | F5 => (4, 5)
  | F6 => (5, 5)
  | F7 => (6, 5)
  | F8 => (7, 5)
  | G1 => (0, 6)
  | G2 => (1, 6)
  | G3 => (2, 6)
  | G4 => (3, 6)
  | G5 => (4, 6)
  | G6 => (5, 6)
  | G7 => (6, 6)
  | G8 => (7, 6)
  | H1 => (0, 7)
  | H2 => (1, 7)
  | H3 => (2, 7)
  | H4 => (3, 7)
  | H5 => (4, 7)
  | H6 => (5, 7)
  | H7 => (6, 7)
  | H8 => (7, 7)
  };
};

let rankAndFileToSquare = square => {
  switch (square) {
  | (0, 0) => A1
  | (1, 0) => A2
  | (2, 0) => A3
  | (3, 0) => A4
  | (4, 0) => A5
  | (5, 0) => A6
  | (6, 0) => A7
  | (7, 0) => A8
  | (0, 1) => B1
  | (1, 1) => B2
  | (2, 1) => B3
  | (3, 1) => B4
  | (4, 1) => B5
  | (5, 1) => B6
  | (6, 1) => B7
  | (7, 1) => B8
  | (0, 2) => C1
  | (1, 2) => C2
  | (2, 2) => C3
  | (3, 2) => C4
  | (4, 2) => C5
  | (5, 2) => C6
  | (6, 2) => C7
  | (7, 2) => C8
  | (0, 3) => D1
  | (1, 3) => D2
  | (2, 3) => D3
  | (3, 3) => D4
  | (4, 3) => D5
  | (5, 3) => D6
  | (6, 3) => D7
  | (7, 3) => D8
  | (0, 4) => E1
  | (1, 4) => E2
  | (2, 4) => E3
  | (3, 4) => E4
  | (4, 4) => E5
  | (5, 4) => E6
  | (6, 4) => E7
  | (7, 4) => E8
  | (0, 5) => F1
  | (1, 5) => F2
  | (2, 5) => F3
  | (3, 5) => F4
  | (4, 5) => F5
  | (5, 5) => F6
  | (6, 5) => F7
  | (7, 5) => F8
  | (0, 6) => G1
  | (1, 6) => G2
  | (2, 6) => G3
  | (3, 6) => G4
  | (4, 6) => G5
  | (5, 6) => G6
  | (6, 6) => G7
  | (7, 6) => G8
  | (0, 7) => H1
  | (1, 7) => H2
  | (2, 7) => H3
  | (3, 7) => H4
  | (4, 7) => H5
  | (5, 7) => H6
  | (6, 7) => H7
  | (7, 7) => H8
  /* What is the revery way to raise exceptions? */
  | _ => failwith("Invalid rank or file")
  };
};

let squareToFile = square => {
  let (_, file) = squareToRankAndFile(square);
  file;
};

let squareToRank = square => {
  let (rank, _) = squareToRankAndFile(square);
  rank;
};
