module Types = {
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

  type promotion =
    | Queen
    | Rook
    | Bishop
    | Knight;

  type result =
    | WhiteWon
    | BlackWon
    | Draw;

  type resultReason =
    | Checkmate
    | Stalemate
    | Resignation
    | Timeout
    | Agreement
    | InsufficientMaterial
    | ThreeFoldRepetition
    | FiftyMoveRule;

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

  exception IllegalMove(square, square, string);
};

open Types;

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

/**
 * Comparison function useful to sort squares. Order: A1, A2, ..., H7, H8.
 */
let compareSquares = (s1, s2) => {
  let (r1, f1) = squareToRankAndFile(s1);
  let (r2, f2) = squareToRankAndFile(s2);
  let fileComparison = compare(f1, f2);
  if (fileComparison === 0) {
    compare(r1, r2);
  } else {
    fileComparison;
  };
};

module SquareSet =
  Set.Make({
    type t = square;
    let compare = compareSquares;
  });

type timing = {
  timeLimit: option(int),
  timeLimitPerTurn: option(int),
  increment: option(int),
  timeControlMSAfterTurn: option((int, int)),
};

type annotation =
  | Blunder
  | Mistake
  | Dubious
  | Interesting
  | Good
  | Brilliant;

type move = {
  start: square,
  stop: square,
  promotion: option(promotion),
  check: bool,
  checkMate: bool,
  castle: bool,
  annotation: option(annotation),
};

type timedMove = {
  move,
  elapsedMS: int,
};

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
  active: player,
  /*
   * If the prior move allows you to capture enPassant this will contain the
   * square you must move a pawn into to capture enPassant. In all other cases
   * thisis None.
   */
  enPassant: option(square),
  /*
   * Castling rights. Note you may have rights but can't castle. (If in or
   * through check for example.)
   *
   * This is a list of the squares of rooks that can be castled with. For a
   * standard game of chess these are always the A1, H1, A8, and H8 squares.
   * For non-standard games (Like Chess 960), the files may change.
   */
  whiteRights: list(square),
  blackRights: list(square),
  /*
   * Number of halfmoves since the last pawn move or capture.
   */
  halfmoveClock: int,
  /*
   * Which move it is. Starts at 1, incremented after black moves.
   */
  moveCount: int,
};

/*
 * Information that is derived from other parts of the position.
 */
type derivedPosition = {
  whiteThreats: SquareSet.t,
  blackThreats: SquareSet.t,
};

type fullPosition = {
  /*
   * The unique information we need to encode a position.
   */
  p: position,
  /*
   * Information that is derived from other parts of the position.
   */
  derived: derivedPosition,
};

/*
 * A bag of utils.
 */
module X = {
  let allSquares = [
    A1,
    A2,
    A3,
    A4,
    A5,
    A6,
    A7,
    A8,
    B1,
    B2,
    B3,
    B4,
    B5,
    B6,
    B7,
    B8,
    C1,
    C2,
    C3,
    C4,
    C5,
    C6,
    C7,
    C8,
    D1,
    D2,
    D3,
    D4,
    D5,
    D6,
    D7,
    D8,
    E1,
    E2,
    E3,
    E4,
    E5,
    E6,
    E7,
    E8,
    F1,
    F2,
    F3,
    F4,
    F5,
    F6,
    F7,
    F8,
    G1,
    G2,
    G3,
    G4,
    G5,
    G6,
    G7,
    G8,
    H1,
    H2,
    H3,
    H4,
    H5,
    H6,
    H7,
    H8,
  ];

  let squareToRankAndFile = squareToRankAndFile;

  let setPiece = (square, piece, position) => {
    switch (square) {
    | A1 => {...position, a1: piece}
    | A2 => {...position, a2: piece}
    | A3 => {...position, a3: piece}
    | A4 => {...position, a4: piece}
    | A5 => {...position, a5: piece}
    | A6 => {...position, a6: piece}
    | A7 => {...position, a7: piece}
    | A8 => {...position, a8: piece}
    | B1 => {...position, b1: piece}
    | B2 => {...position, b2: piece}
    | B3 => {...position, b3: piece}
    | B4 => {...position, b4: piece}
    | B5 => {...position, b5: piece}
    | B6 => {...position, b6: piece}
    | B7 => {...position, b7: piece}
    | B8 => {...position, b8: piece}
    | C1 => {...position, c1: piece}
    | C2 => {...position, c2: piece}
    | C3 => {...position, c3: piece}
    | C4 => {...position, c4: piece}
    | C5 => {...position, c5: piece}
    | C6 => {...position, c6: piece}
    | C7 => {...position, c7: piece}
    | C8 => {...position, c8: piece}
    | D1 => {...position, d1: piece}
    | D2 => {...position, d2: piece}
    | D3 => {...position, d3: piece}
    | D4 => {...position, d4: piece}
    | D5 => {...position, d5: piece}
    | D6 => {...position, d6: piece}
    | D7 => {...position, d7: piece}
    | D8 => {...position, d8: piece}
    | E1 => {...position, e1: piece}
    | E2 => {...position, e2: piece}
    | E3 => {...position, e3: piece}
    | E4 => {...position, e4: piece}
    | E5 => {...position, e5: piece}
    | E6 => {...position, e6: piece}
    | E7 => {...position, e7: piece}
    | E8 => {...position, e8: piece}
    | F1 => {...position, f1: piece}
    | F2 => {...position, f2: piece}
    | F3 => {...position, f3: piece}
    | F4 => {...position, f4: piece}
    | F5 => {...position, f5: piece}
    | F6 => {...position, f6: piece}
    | F7 => {...position, f7: piece}
    | F8 => {...position, f8: piece}
    | G1 => {...position, g1: piece}
    | G2 => {...position, g2: piece}
    | G3 => {...position, g3: piece}
    | G4 => {...position, g4: piece}
    | G5 => {...position, g5: piece}
    | G6 => {...position, g6: piece}
    | G7 => {...position, g7: piece}
    | G8 => {...position, g8: piece}
    | H1 => {...position, h1: piece}
    | H2 => {...position, h2: piece}
    | H3 => {...position, h3: piece}
    | H4 => {...position, h4: piece}
    | H5 => {...position, h5: piece}
    | H6 => {...position, h6: piece}
    | H7 => {...position, h7: piece}
    | H8 => {...position, h8: piece}
    };
  };

  let getPiece = (square, position) => {
    switch (square) {
    | A1 => position.a1
    | A2 => position.a2
    | A3 => position.a3
    | A4 => position.a4
    | A5 => position.a5
    | A6 => position.a6
    | A7 => position.a7
    | A8 => position.a8
    | B1 => position.b1
    | B2 => position.b2
    | B3 => position.b3
    | B4 => position.b4
    | B5 => position.b5
    | B6 => position.b6
    | B7 => position.b7
    | B8 => position.b8
    | C1 => position.c1
    | C2 => position.c2
    | C3 => position.c3
    | C4 => position.c4
    | C5 => position.c5
    | C6 => position.c6
    | C7 => position.c7
    | C8 => position.c8
    | D1 => position.d1
    | D2 => position.d2
    | D3 => position.d3
    | D4 => position.d4
    | D5 => position.d5
    | D6 => position.d6
    | D7 => position.d7
    | D8 => position.d8
    | E1 => position.e1
    | E2 => position.e2
    | E3 => position.e3
    | E4 => position.e4
    | E5 => position.e5
    | E6 => position.e6
    | E7 => position.e7
    | E8 => position.e8
    | F1 => position.f1
    | F2 => position.f2
    | F3 => position.f3
    | F4 => position.f4
    | F5 => position.f5
    | F6 => position.f6
    | F7 => position.f7
    | F8 => position.f8
    | G1 => position.g1
    | G2 => position.g2
    | G3 => position.g3
    | G4 => position.g4
    | G5 => position.g5
    | G6 => position.g6
    | G7 => position.g7
    | G8 => position.g8
    | H1 => position.h1
    | H2 => position.h2
    | H3 => position.h3
    | H4 => position.h4
    | H5 => position.h5
    | H6 => position.h6
    | H7 => position.h7
    | H8 => position.h8
    };
  };

  let squareToString = square => {
    switch (square) {
    | A1 => "A1"
    | A2 => "A2"
    | A3 => "A3"
    | A4 => "A4"
    | A5 => "A5"
    | A6 => "A6"
    | A7 => "A7"
    | A8 => "A8"
    | B1 => "B1"
    | B2 => "B2"
    | B3 => "B3"
    | B4 => "B4"
    | B5 => "B5"
    | B6 => "B6"
    | B7 => "B7"
    | B8 => "B8"
    | C1 => "C1"
    | C2 => "C2"
    | C3 => "C3"
    | C4 => "C4"
    | C5 => "C5"
    | C6 => "C6"
    | C7 => "C7"
    | C8 => "C8"
    | D1 => "D1"
    | D2 => "D2"
    | D3 => "D3"
    | D4 => "D4"
    | D5 => "D5"
    | D6 => "D6"
    | D7 => "D7"
    | D8 => "D8"
    | E1 => "E1"
    | E2 => "E2"
    | E3 => "E3"
    | E4 => "E4"
    | E5 => "E5"
    | E6 => "E6"
    | E7 => "E7"
    | E8 => "E8"
    | F1 => "F1"
    | F2 => "F2"
    | F3 => "F3"
    | F4 => "F4"
    | F5 => "F5"
    | F6 => "F6"
    | F7 => "F7"
    | F8 => "F8"
    | G1 => "G1"
    | G2 => "G2"
    | G3 => "G3"
    | G4 => "G4"
    | G5 => "G5"
    | G6 => "G6"
    | G7 => "G7"
    | G8 => "G8"
    | H1 => "H1"
    | H2 => "H2"
    | H3 => "H3"
    | H4 => "H4"
    | H5 => "H5"
    | H6 => "H6"
    | H7 => "H7"
    | H8 => "H8"
    };
  };

  let squaresToString = squares => {
    let inner = squares |> List.map(squareToString) |> String.concat(", ");
    "[" ++ inner ++ "]";
  };

  let setActive = (active, position) => {...position, active};

  let setEnPassant = (enPassant, position) => {...position, enPassant};

  let revokeWhiteRights = (square, position) => {
    ...position,
    whiteRights: List.filter(right => right != square, position.whiteRights),
  };

  let revokeAllWhiteRights = position => {...position, whiteRights: []};

  let revokeBlackRights = (square, position) => {
    ...position,
    blackRights: List.filter(right => right != square, position.blackRights),
  };

  let revokeAllBlackRights = position => {...position, blackRights: []};

  let compareSquares = compareSquares;

  let sort = List.sort(compareSquares);

  let rankAndFileToSquareOpt = square => {
    switch (square) {
    | (0, 0) => Some(A1)
    | (1, 0) => Some(A2)
    | (2, 0) => Some(A3)
    | (3, 0) => Some(A4)
    | (4, 0) => Some(A5)
    | (5, 0) => Some(A6)
    | (6, 0) => Some(A7)
    | (7, 0) => Some(A8)
    | (0, 1) => Some(B1)
    | (1, 1) => Some(B2)
    | (2, 1) => Some(B3)
    | (3, 1) => Some(B4)
    | (4, 1) => Some(B5)
    | (5, 1) => Some(B6)
    | (6, 1) => Some(B7)
    | (7, 1) => Some(B8)
    | (0, 2) => Some(C1)
    | (1, 2) => Some(C2)
    | (2, 2) => Some(C3)
    | (3, 2) => Some(C4)
    | (4, 2) => Some(C5)
    | (5, 2) => Some(C6)
    | (6, 2) => Some(C7)
    | (7, 2) => Some(C8)
    | (0, 3) => Some(D1)
    | (1, 3) => Some(D2)
    | (2, 3) => Some(D3)
    | (3, 3) => Some(D4)
    | (4, 3) => Some(D5)
    | (5, 3) => Some(D6)
    | (6, 3) => Some(D7)
    | (7, 3) => Some(D8)
    | (0, 4) => Some(E1)
    | (1, 4) => Some(E2)
    | (2, 4) => Some(E3)
    | (3, 4) => Some(E4)
    | (4, 4) => Some(E5)
    | (5, 4) => Some(E6)
    | (6, 4) => Some(E7)
    | (7, 4) => Some(E8)
    | (0, 5) => Some(F1)
    | (1, 5) => Some(F2)
    | (2, 5) => Some(F3)
    | (3, 5) => Some(F4)
    | (4, 5) => Some(F5)
    | (5, 5) => Some(F6)
    | (6, 5) => Some(F7)
    | (7, 5) => Some(F8)
    | (0, 6) => Some(G1)
    | (1, 6) => Some(G2)
    | (2, 6) => Some(G3)
    | (3, 6) => Some(G4)
    | (4, 6) => Some(G5)
    | (5, 6) => Some(G6)
    | (6, 6) => Some(G7)
    | (7, 6) => Some(G8)
    | (0, 7) => Some(H1)
    | (1, 7) => Some(H2)
    | (2, 7) => Some(H3)
    | (3, 7) => Some(H4)
    | (4, 7) => Some(H5)
    | (5, 7) => Some(H6)
    | (6, 7) => Some(H7)
    | (7, 7) => Some(H8)
    | _ => None
    };
  };

  let rankAndFileToSquare = square => {
    switch (rankAndFileToSquareOpt(square)) {
    | Some(result) => result
    /* TODO: What is the revery way to raise an exception? */
    | None => failwith("Invalid rank and file")
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

  let rankDownExn = square => {
    let (r, f) = squareToRankAndFile(square);
    rankAndFileToSquare((r - 1, f));
  };

  let rankUpExn = square => {
    let (r, f) = squareToRankAndFile(square);
    rankAndFileToSquare((r + 1, f));
  };

  /**
   * Gets all the pieces in the position and their square.
   */
  let getAllPieces = position => {
    allSquares
    |> List.map(sq => (sq, getPiece(sq, position)))
    |> List.filter(((_, piece)) => piece != NoPiece);
  };

  let isWhitePiece = piece => {
    switch (piece) {
    | WhitePawn
    | WhiteKnight
    | WhiteBishop
    | WhiteRook
    | WhiteQueen
    | WhiteKing => true
    | _ => false
    };
  };

  let isWhiteOrNoPiece = piece => {
    switch (piece) {
    | NoPiece => true
    | _ => isWhitePiece(piece)
    };
  };

  let isBlackPiece = piece => {
    switch (piece) {
    | BlackPawn
    | BlackKnight
    | BlackBishop
    | BlackRook
    | BlackQueen
    | BlackKing => true
    | _ => false
    };
  };

  let isBlackOrNoPiece = piece => {
    switch (piece) {
    | NoPiece => true
    | _ => isBlackPiece(piece)
    };
  };

  let notMe = player => {
    switch (player) {
    | White => isBlackOrNoPiece
    | Black => isWhiteOrNoPiece
    };
  };

  let isMe = player => {
    switch (player) {
    | White => isWhitePiece
    | Black => isBlackPiece
    };
  };

  let isOpp = player => {
    switch (player) {
    | White => isBlackPiece
    | Black => isWhitePiece
    };
  };

  let filterSeq = (player, position, seq) => {
    let isMe = isMe(player);
    let isOpp = isOpp(player);
    let getPiece = sq => getPiece(sq, position);
    let noneAllowed = square => {
      let piece = getPiece(square);
      isMe(piece);
    };
    let oneAllowed = square => {
      let piece = getPiece(square);
      isOpp(piece);
    };
    Utils.dropAfter(~noneAllowed, ~oneAllowed, seq);
  };
};

module Moves = {
  let knight = (player, square, position) => {
    let (r, f) = X.squareToRankAndFile(square);
    let moves = [
      X.rankAndFileToSquareOpt((r - 1, f - 2)),
      X.rankAndFileToSquareOpt((r - 1, f + 2)),
      X.rankAndFileToSquareOpt((r + 1, f - 2)),
      X.rankAndFileToSquareOpt((r + 1, f + 2)),
      X.rankAndFileToSquareOpt((r - 2, f - 1)),
      X.rankAndFileToSquareOpt((r - 2, f + 1)),
      X.rankAndFileToSquareOpt((r + 2, f - 1)),
      X.rankAndFileToSquareOpt((r + 2, f + 1)),
    ];

    let notMe = X.notMe(player);
    moves
    |> Utils.compact
    |> List.filter(square => {
         let piece = X.getPiece(square, position);
         notMe(piece);
       });
  };

  let bishop = (player, square, position) => {
    let (r, f) = X.squareToRankAndFile(square);
    let moveDirs = [
      /* Up-left */
      [
        X.rankAndFileToSquareOpt((r + 1, f - 1)),
        X.rankAndFileToSquareOpt((r + 2, f - 2)),
        X.rankAndFileToSquareOpt((r + 3, f - 3)),
        X.rankAndFileToSquareOpt((r + 4, f - 4)),
        X.rankAndFileToSquareOpt((r + 5, f - 5)),
        X.rankAndFileToSquareOpt((r + 6, f - 6)),
        X.rankAndFileToSquareOpt((r + 7, f - 7)),
      ],
      /* Up-Right */
      [
        X.rankAndFileToSquareOpt((r + 1, f + 1)),
        X.rankAndFileToSquareOpt((r + 2, f + 2)),
        X.rankAndFileToSquareOpt((r + 3, f + 3)),
        X.rankAndFileToSquareOpt((r + 4, f + 4)),
        X.rankAndFileToSquareOpt((r + 5, f + 5)),
        X.rankAndFileToSquareOpt((r + 6, f + 6)),
        X.rankAndFileToSquareOpt((r + 7, f + 7)),
      ],
      /* Down-Left */
      [
        X.rankAndFileToSquareOpt((r - 1, f - 1)),
        X.rankAndFileToSquareOpt((r - 2, f - 2)),
        X.rankAndFileToSquareOpt((r - 3, f - 3)),
        X.rankAndFileToSquareOpt((r - 4, f - 4)),
        X.rankAndFileToSquareOpt((r - 5, f - 5)),
        X.rankAndFileToSquareOpt((r - 6, f - 6)),
        X.rankAndFileToSquareOpt((r - 7, f - 7)),
      ],
      /* Down-Right */
      [
        X.rankAndFileToSquareOpt((r - 1, f + 1)),
        X.rankAndFileToSquareOpt((r - 2, f + 2)),
        X.rankAndFileToSquareOpt((r - 3, f + 3)),
        X.rankAndFileToSquareOpt((r - 4, f + 4)),
        X.rankAndFileToSquareOpt((r - 5, f + 5)),
        X.rankAndFileToSquareOpt((r - 6, f + 6)),
        X.rankAndFileToSquareOpt((r - 7, f + 7)),
      ],
    ];

    moveDirs
    |> List.map(Utils.compact)
    |> List.map(X.filterSeq(player, position))
    |> List.flatten;
  };

  let rook = (player, square, position) => {
    let (r, f) = X.squareToRankAndFile(square);
    let moveDirs = [
      /* Up */
      [
        X.rankAndFileToSquareOpt((r + 1, f)),
        X.rankAndFileToSquareOpt((r + 2, f)),
        X.rankAndFileToSquareOpt((r + 3, f)),
        X.rankAndFileToSquareOpt((r + 4, f)),
        X.rankAndFileToSquareOpt((r + 5, f)),
        X.rankAndFileToSquareOpt((r + 6, f)),
        X.rankAndFileToSquareOpt((r + 7, f)),
      ],
      /* Right */
      [
        X.rankAndFileToSquareOpt((r, f + 1)),
        X.rankAndFileToSquareOpt((r, f + 2)),
        X.rankAndFileToSquareOpt((r, f + 3)),
        X.rankAndFileToSquareOpt((r, f + 4)),
        X.rankAndFileToSquareOpt((r, f + 5)),
        X.rankAndFileToSquareOpt((r, f + 6)),
        X.rankAndFileToSquareOpt((r, f + 7)),
      ],
      /* Down */
      [
        X.rankAndFileToSquareOpt((r - 1, f)),
        X.rankAndFileToSquareOpt((r - 2, f)),
        X.rankAndFileToSquareOpt((r - 3, f)),
        X.rankAndFileToSquareOpt((r - 4, f)),
        X.rankAndFileToSquareOpt((r - 5, f)),
        X.rankAndFileToSquareOpt((r - 6, f)),
        X.rankAndFileToSquareOpt((r - 7, f)),
      ],
      /* Left */
      [
        X.rankAndFileToSquareOpt((r, f - 1)),
        X.rankAndFileToSquareOpt((r, f - 2)),
        X.rankAndFileToSquareOpt((r, f - 3)),
        X.rankAndFileToSquareOpt((r, f - 4)),
        X.rankAndFileToSquareOpt((r, f - 5)),
        X.rankAndFileToSquareOpt((r, f - 6)),
        X.rankAndFileToSquareOpt((r, f - 7)),
      ],
    ];

    moveDirs
    |> List.map(Utils.compact)
    |> List.map(X.filterSeq(player, position))
    |> List.flatten;
  };

  let queen = (player, square, position) => {
    rook(player, square, position) @ bishop(player, square, position);
  };

  let king = (player, square, position) => {
    let (r, f) = X.squareToRankAndFile(square);
    let moves = [
      X.rankAndFileToSquareOpt((r + 1, f + 1)),
      X.rankAndFileToSquareOpt((r, f + 1)),
      X.rankAndFileToSquareOpt((r - 1, f + 1)),
      X.rankAndFileToSquareOpt((r + 1, f)),
      X.rankAndFileToSquareOpt((r - 1, f)),
      X.rankAndFileToSquareOpt((r + 1, f - 1)),
      X.rankAndFileToSquareOpt((r, f - 1)),
      X.rankAndFileToSquareOpt((r - 1, f - 1)),
    ];

    let notMe = X.notMe(player);
    let moves =
      moves
      |> Utils.compact
      |> List.filter(square => {
           let piece = X.getPiece(square, position);
           notMe(piece);
         });

    moves;
  };

  let pawnAttacks = (player, square, position) => {
    let (r, f) = X.squareToRankAndFile(square);
    let _ = (r, f);
    [];
  };

  let pawnNonAttacks = (player, square, position) => {
    let (r, f) = X.squareToRankAndFile(square);
    let _ = (r, f);
    [];
  };

  let pawnPromotions = (player, square, position) => {
    let (r, f) = X.squareToRankAndFile(square);
    let _ = (r, f);
    [];
  };

  let pawn = (player, square, position) => {
    pawnAttacks(player, square, position)
    @ pawnNonAttacks(player, square, position)
    @ pawnPromotions(player, square, position);
  };

  /*
   * Includes all valid moves except for:
   *
   * - Castling.
   * - Moves that are illegal due to check.
   */
  let forSquareFirstPass = (square, position): list(square) => {
    let piece = X.getPiece(square, position);
    switch (piece) {
    | WhitePawn => pawn(White, square, position)
    | BlackPawn => pawn(Black, square, position)
    | WhiteKnight => knight(White, square, position)
    | BlackKnight => knight(Black, square, position)
    | WhiteBishop => bishop(White, square, position)
    | BlackBishop => bishop(Black, square, position)
    | WhiteRook => rook(White, square, position)
    | BlackRook => rook(Black, square, position)
    | WhiteQueen => queen(White, square, position)
    | BlackQueen => queen(Black, square, position)
    | WhiteKing => king(White, square, position)
    | BlackKing => king(Black, square, position)
    | NoPiece => []
    };
  };

  let getThreats = (player, position): SquareSet.t => {
    let isMe = X.isMe(player);
    position
    |> X.getAllPieces
    |> List.filter(((sq, piece)) => isMe(piece))
    |> List.map(((sq, piece)) => {
         switch (piece) {
         /* Only consider pawn attacks. Not normal moves or promitions. */
         | WhitePawn
         | BlackPawn => pawnAttacks(player, sq, position)
         /* Castling is not included in king moves, no need to special case. */
         | _ => forSquareFirstPass(sq, position)
         }
       })
    |> List.flatten
    |> SquareSet.of_list;
  };

  /*
   * Gets the next position. Assumes move is valid (but not necessarily legal.)
   */
  let nextPosition = (sq1, sq2, position: position): position => {
    let (r1, f1) = X.squareToRankAndFile(sq1);
    let (r2, f2) = X.squareToRankAndFile(sq2);
    let p1 = X.getPiece(sq1, position);
    let p2 = X.getPiece(sq2, position);
    let next =
      switch (p1, p2, position.enPassant) {
      /* Check en-passant. */
      | (WhitePawn | BlackPawn, _, Some(ep)) when ep == sq2 =>
        if (p1 == WhitePawn && r1 == 4 && r2 == 5) {
          let targetSquare = X.rankDownExn(sq2);
          let targetPiece = X.getPiece(targetSquare, position);
          if (targetPiece != BlackPawn) {
            raise(
              IllegalMove(
                sq1,
                sq2,
                "Invalid En Passant. No black pawn to capture.",
              ),
            );
          } else {
            position
            |> X.setPiece(targetSquare, NoPiece)
            |> X.setPiece(sq1, NoPiece)
            |> X.setPiece(sq2, WhitePawn);
          };
        } else if (p1 == BlackPawn && r1 == 3 && r2 == 2) {
          let targetSquare = X.rankUpExn(sq2);
          let targetPiece = X.getPiece(targetSquare, position);
          if (targetPiece != WhitePawn) {
            raise(
              IllegalMove(
                sq1,
                sq2,
                "Invalid En Passant. No white pawn to capture.",
              ),
            );
          } else {
            position
            |> X.setPiece(targetSquare, NoPiece)
            |> X.setPiece(sq1, NoPiece)
            |> X.setPiece(sq2, BlackPawn);
          };
        } else {
          raise(IllegalMove(sq1, sq2, "Invalid En Passant."));
        }
      /* TODO: Check castling. */
      | (WhiteKing, _, _) => position
      | (BlackKing, _, _) => position
      | _ => position |> X.setPiece(sq1, NoPiece) |> X.setPiece(sq2, p1)
      };
    next;
  };

  let forSquare = (square, position: fullPosition): list(square) => {
    let firstPass = forSquareFirstPass(square, position.p);
    let _ = firstPass;
    /* Filter out any moves that result in check. */
    [];
  };
};

module Timing = {
  type t = timing;

  let make = () => {
    timeLimit: None,
    timeLimitPerTurn: None,
    increment: None,
    timeControlMSAfterTurn: None,
  };

  let withTimeLimit = (~ms, timing) => {...timing, timeLimit: Some(ms)};
  let withTimeLimitPerTurn = (~ms, timing) => {
    ...timing,
    timeLimitPerTurn: Some(ms),
  };
  let withIncrement = (~ms, timing) => {...timing, increment: Some(ms)};
  let withTimeControl = (~ms, ~afterTurn, timing) => {
    ...timing,
    timeControlMSAfterTurn: Some((ms, afterTurn)),
  };
};

module Move = {
  type t = move;

  let make = (start, stop) => {
    start,
    stop,
    promotion: None,
    check: false,
    checkMate: false,
    castle: false,
    annotation: None,
  };

  let withPromotion = (promotion, move) => {
    ...move,
    promotion: Some(promotion),
  };
  let withCheck = move => {...move, check: true};
  let withCheckMate = move => {...move, checkMate: true};
  let withCastle = move => {...move, castle: true};

  module Annotations = {
    let setBlunder = move => {...move, annotation: Some(Blunder)};
    let setMistake = move => {...move, annotation: Some(Mistake)};
    let setDubious = move => {...move, annotation: Some(Dubious)};
    let setInteresting = move => {...move, annotation: Some(Interesting)};
    let setGood = move => {...move, annotation: Some(Good)};
    let setBrilliant = move => {...move, annotation: Some(Brilliant)};
  };
};

module TimedMove = {
  type t = timedMove;

  let make = (~elapsedMS, move) => {move, elapsedMS};

  let getMove = move => move.move;
};

/*
 * Some private utils needed to work with positions.
 */
module PositionUtils = {
  let build = (p: position): fullPosition => {
    let derived = {
      whiteThreats: Moves.getThreats(White, p),
      blackThreats: Moves.getThreats(Black, p),
    };
    {p, derived};
  };
};

module ConstPositions = {
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
    active: White,
    enPassant: None,
    whiteRights: [],
    blackRights: [],
    halfmoveClock: 0,
    moveCount: 1,
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
    whiteRights: [A1, H1],
    blackRights: [A8, H8],
  };
};

module Position = {
  type t = fullPosition;

  module Full = {
    let empty = PositionUtils.build(ConstPositions.empty);
    let start = PositionUtils.build(ConstPositions.start);
  };

  let make = () => Full.start;
  /* TODO: Implement. */
  let applyMove = (move, position) => position;
  let getPlayer = position => position.p.active;
  let getPiece = (square, position) => X.getPiece(square, position.p);
  /* TODO: Implement. */
  let getLegalMoves = (square, position) => [];
  /* TODO: Implement. */
  let getCheck = position => None;
  /* TODO: Implement. */
  let getCheckMate = position => None;
  /* TODO: Implement. */
  let isInsufficientMaterial = position => false;
  let getHalfmoveClock = position => position.p.halfmoveClock;
};

module Game = {
  type t = unit;

  let make = () => ();
  let withTiming = (timing, game) => game;
  let getPosition = game => Position.Full.start;
  let getPrevious = game => None;
  let getHistory = game => [];
  let applyMove = (move, game) => game;
  let getResult = game => None;
  let getOccurrenceCount = (position, game) => 0;
  let isThreeFoldRepetition = game => false;
};

module Debug = {
  let sortSquares = X.sort;
  let showSquare = X.squareToString;
  let showSquares = X.squaresToString;
};

module FEN = {};
module PGN = {};
