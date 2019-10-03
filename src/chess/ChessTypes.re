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
   * Whose turn it is to play.
   */
  toPlay: player,
  /*
   * If the prior move allows you to capture enPassant this will contain the
   * square you must move a pawn into to capture enPassant. In all other cases
   * thisis None.
   */
  enPassant: option(square),
  /*
   * Castling rights. Note you may have rights but can't castle. (If in or
   * through check for example.)
   */
  whiteLong: bool,
  whiteShort: bool,
  blackLong: bool,
  blackShort: bool,
};
