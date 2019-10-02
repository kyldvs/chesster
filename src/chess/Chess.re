open ChessTypes;

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

let knightMoves = (square: square): list(square) => {
  let (r, f) = squareToRankAndFile(square);
  let moves = [
    rankAndFileToSquareOpt((r - 1, f - 2)),
    rankAndFileToSquareOpt((r - 1, f + 2)),
    rankAndFileToSquareOpt((r + 1, f - 2)),
    rankAndFileToSquareOpt((r + 1, f + 2)),
    rankAndFileToSquareOpt((r - 2, f - 1)),
    rankAndFileToSquareOpt((r - 2, f + 1)),
    rankAndFileToSquareOpt((r + 2, f - 1)),
    rankAndFileToSquareOpt((r + 2, f + 1)),
  ];
  Utils.compact(moves);
};

let kingMoves = (square: square): list(square) => {
  let (r, f) = squareToRankAndFile(square);
  let moves = [
    rankAndFileToSquareOpt((r - 1, f - 1)),
    rankAndFileToSquareOpt((r - 1, f)),
    rankAndFileToSquareOpt((r - 1, f + 1)),
    rankAndFileToSquareOpt((r, f - 1)),
    rankAndFileToSquareOpt((r, f + 1)),
    rankAndFileToSquareOpt((r + 1, f - 1)),
    rankAndFileToSquareOpt((r + 1, f)),
    rankAndFileToSquareOpt((r + 1, f + 1)),
  ];
  Utils.compact(moves);
};

let rankMoves = (square: square): list(square) => {
  let (_, f) = squareToRankAndFile(square);
  let moves = [
    rankAndFileToSquareOpt((0, f)),
    rankAndFileToSquareOpt((1, f)),
    rankAndFileToSquareOpt((2, f)),
    rankAndFileToSquareOpt((3, f)),
    rankAndFileToSquareOpt((4, f)),
    rankAndFileToSquareOpt((5, f)),
    rankAndFileToSquareOpt((6, f)),
    rankAndFileToSquareOpt((7, f)),
  ];
  Utils.compact(moves);
};

let fileMoves = (square: square): list(square) => {
  let (r, _) = squareToRankAndFile(square);
  let moves = [
    rankAndFileToSquareOpt((r, 0)),
    rankAndFileToSquareOpt((r, 1)),
    rankAndFileToSquareOpt((r, 2)),
    rankAndFileToSquareOpt((r, 3)),
    rankAndFileToSquareOpt((r, 4)),
    rankAndFileToSquareOpt((r, 5)),
    rankAndFileToSquareOpt((r, 6)),
    rankAndFileToSquareOpt((r, 7)),
  ];
  Utils.compact(moves);
};

let rookMoves = (square: square): list(square) => {
  rankMoves(square) @ fileMoves(square);
};

let bishopMoves = (square: square): list(square) => {
  let (r, f) = squareToRankAndFile(square);
  let moves = [
    rankAndFileToSquareOpt((r - 7, f - 7)),
    rankAndFileToSquareOpt((r - 6, f - 6)),
    rankAndFileToSquareOpt((r - 5, f - 5)),
    rankAndFileToSquareOpt((r - 4, f - 4)),
    rankAndFileToSquareOpt((r - 3, f - 3)),
    rankAndFileToSquareOpt((r - 2, f - 2)),
    rankAndFileToSquareOpt((r - 1, f - 1)),
    rankAndFileToSquareOpt((r + 7, f - 7)),
    rankAndFileToSquareOpt((r + 6, f - 6)),
    rankAndFileToSquareOpt((r + 5, f - 5)),
    rankAndFileToSquareOpt((r + 4, f - 4)),
    rankAndFileToSquareOpt((r + 3, f - 3)),
    rankAndFileToSquareOpt((r + 2, f - 2)),
    rankAndFileToSquareOpt((r + 1, f - 1)),
    rankAndFileToSquareOpt((r - 7, f + 7)),
    rankAndFileToSquareOpt((r - 6, f + 6)),
    rankAndFileToSquareOpt((r - 5, f + 5)),
    rankAndFileToSquareOpt((r - 4, f + 4)),
    rankAndFileToSquareOpt((r - 3, f + 3)),
    rankAndFileToSquareOpt((r - 2, f + 2)),
    rankAndFileToSquareOpt((r - 1, f + 1)),
    rankAndFileToSquareOpt((r + 7, f + 7)),
    rankAndFileToSquareOpt((r + 6, f + 6)),
    rankAndFileToSquareOpt((r + 5, f + 5)),
    rankAndFileToSquareOpt((r + 4, f + 4)),
    rankAndFileToSquareOpt((r + 3, f + 3)),
    rankAndFileToSquareOpt((r + 2, f + 2)),
    rankAndFileToSquareOpt((r + 1, f + 1)),
  ];
  Utils.compact(moves);
};

let queenMoves = (square: square): list(square) => {
  rookMoves(square) @ bishopMoves(square);
};

/**
 * Doesn't consider pawn moves and castling.
 */
let squaresBetween = (square1: square, square2: square): list(square) => {
  let (r1, f1) = squareToRankAndFile(square1);
  let (r2, f2) = squareToRankAndFile(square2);
  let deltaR = r2 - r1;
  let deltaF = f2 - f1;

  if (r1 === r2) {
    /* Moving along the file. */
    Utils.seq(f1, f2)
    |> List.map(f => (r1, f))
    |> List.map(rankAndFileToSquareOpt)
    |> Utils.compact;
  } else if (f1 === f2) {
    /* Moving along the rank. */
    Utils.seq(r1, r2)
    |> List.map(r => (r, f1))
    |> List.map(rankAndFileToSquareOpt)
    |> Utils.compact;
  } else if (abs(deltaR) === abs(deltaF)) {
    /* Moving along the diagnol. */
    let rs = Utils.seq(r1, r2);
    let fs = Utils.seq(f1, f2);
    List.map2((r, f) => (r, f), rs, fs)
    |> List.map(rankAndFileToSquareOpt)
    |> Utils.compact;
  } else {
    /* Knight move, never needs to check squares between. */
    let squares = [];
    squares;
  };
};
