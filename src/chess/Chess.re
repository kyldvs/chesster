open ChessTypes;

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

let setToPlay = (toPlay, position) => {...position, toPlay};

let setEnPassant = (enPassant, position) => {...position, enPassant};

let revokeWhiteShort = position => {...position, whiteShort: false};

let revokeWhiteLong = position => {...position, whiteLong: false};

let revokeBlackShort = position => {...position, blackShort: false};

let revokeBlackLong = position => {...position, blackLong: false};

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

let getWhitePieces = position => {
  position
  |> getAllPieces
  |> List.filter(((_, piece)) => isWhitePiece(piece));
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

let getBlackPieces = position => {
  position
  |> getAllPieces
  |> List.filter(((_, piece)) => isBlackPiece(piece));
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

/*
 * Squares the pawn can attack. Needs position to determine direction
 * and if En passant is a valid attack.
 *
 * Doesn't handle promotions.
 */
let pawnMoves = (square: square, position: position): list(square) => {
  let (r, f) = squareToRankAndFile(square);
  let pawn = getPiece(square, position);
  let maybePawnCapture = (r, f, isOpp) => {
    let squareOpt = rankAndFileToSquareOpt((r, f));
    switch (squareOpt) {
    | Some(square) =>
      if (isOpp(getPiece(square, position))) {
        Some(square);
      } else if (position.enPassant == Some(square)) {
        Some(square);
      } else {
        None;
      }
    | None => None
    };
  };

  /* Have to check what kind of pawn this is to determine direction. */
  switch (pawn) {
  | WhitePawn =>
    /* White moves up the ranks. */
    let moves = [
      rankAndFileToSquareOpt((r + 1, f)),
      r === 1 ? rankAndFileToSquareOpt((r + 2, f)) : None,
      /* Capture left. Checks En passant too. */
      maybePawnCapture(r + 1, f - 1, isBlackPiece),
      /* Capture right. Checks En passant too. */
      maybePawnCapture(r + 1, f + 1, isBlackPiece),
    ];
    Utils.compact(moves);
  | BlackPawn =>
    /* Black moves down the ranks. */
    let moves = [
      rankAndFileToSquareOpt((r - 1, f)),
      r === 6 ? rankAndFileToSquareOpt((r - 2, f)) : None,
      /* Capture left. Checks En passant too. */
      maybePawnCapture(r - 1, f - 1, isBlackPiece),
      /* Capture right. Checks En passant too. */
      maybePawnCapture(r - 1, f + 1, isBlackPiece),
    ];
    Utils.compact(moves);
  | _ => []
  };
};

/*
 * Squares the pawn can attack. Needs position to determine direction
 * and if En passant is a valid attack.
 */
let pawnAttacks = (square: square, position: position): list(square) => {
  pawnMoves(square, position)
  |> List.filter(move
       /* Attacks are diaganol, so filter moves where pawn stays on file. */
       => squareToFile(square) != squareToFile(move));
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

let findAll = (allPieces: list((square, piece)), piece) => {
  List.fold_left(
    (result, (sq, test)) => test == piece ? [sq, ...result] : result,
    [],
    allPieces,
  );
};

let buildPositionPieces = position => {
  let allPieces = getAllPieces(position);
  let findAll = findAll(allPieces);
  let white = {
    king: findAll(WhiteKing) |> List.hd,
    queen: findAll(WhiteQueen),
    rook: findAll(WhiteRook),
    bishop: findAll(WhiteBishop),
    knight: findAll(WhiteKnight),
    pawn: findAll(WhitePawn),
  };
  let black = {
    king: findAll(BlackKing) |> List.hd,
    queen: findAll(BlackQueen),
    rook: findAll(BlackRook),
    bishop: findAll(BlackBishop),
    knight: findAll(BlackKnight),
    pawn: findAll(BlackPawn),
  };
  {white, black};
};

let buildThreats = (position, start, moves) => {
  let getPiece = sq => getPiece(sq, position);
  let testingPiece = getPiece(start);

  let threats =
    List.filter(
      maybeThreatened => {
        let inBetween = squaresBetween(start, maybeThreatened);
        List.for_all(between => getPiece(between) == NoPiece, inBetween);
      },
      moves,
    );

  /* Can't threaten own pieces. */
  if (isWhitePiece(testingPiece)) {
    List.filter(sq => !isWhitePiece(getPiece(sq)), threats);
  } else if (isBlackPiece(testingPiece)) {
    List.filter(sq => !isBlackPiece(getPiece(sq)), threats);
  } else {
    [];
  };
};

let canAttack = (position, pieces, squareToCheck) => {
  let queenThreats = () =>
    pieces.queen
    |> List.map(sq => buildThreats(position, sq, queenMoves(sq)))
    |> List.concat;
  let rookThreats = () =>
    pieces.rook
    |> List.map(sq => buildThreats(position, sq, rookMoves(sq)))
    |> List.concat;
  let bishopThreats = () =>
    pieces.bishop
    |> List.map(sq => buildThreats(position, sq, bishopMoves(sq)))
    |> List.concat;
  let knightThreats = () =>
    pieces.knight
    |> List.map(sq => buildThreats(position, sq, knightMoves(sq)))
    |> List.concat;
  let pawnThreats = () =>
    pieces.pawn
    |> List.map(sq => buildThreats(position, sq, pawnAttacks(sq, position)))
    |> List.concat;
  let kingThreats = () =>
    buildThreats(position, pieces.king, kingMoves(pieces.king));

  let check = Utils.containsLazy(squareToCheck);

  check(queenThreats)
  || check(rookThreats)
  || check(bishopThreats)
  || check(knightThreats)
  || check(pawnThreats)
  || check(kingThreats);
};

let inCheck = position => {
  let pp = buildPositionPieces(position);
  /* The person to play is the only one that can be in check. */
  let (king, pieces) =
    switch (position.toPlay) {
    | White => (pp.white.king, pp.black)
    | Black => (pp.black.king, pp.white)
    };

  canAttack(position, pieces, king);
};

let setup = (~start=ChessPositions.start, ~toPlay=White, pairs) => {
  let position =
    List.fold_left(
      (pos, (sq, piece)) => setPiece(sq, piece, pos),
      start,
      pairs,
    );
  {...position, toPlay};
};

let modifiersToPiece = (player, modifiers) =>
  if (Utils.contains(PromoteToQueen, modifiers)) {
    player == White ? WhiteQueen : BlackQueen;
  } else if (Utils.contains(PromoteToRook, modifiers)) {
    player == White ? WhiteRook : BlackRook;
  } else if (Utils.contains(PromoteToBishop, modifiers)) {
    player == White ? WhiteBishop : BlackBishop;
  } else if (Utils.contains(PromoteToKnight, modifiers)) {
    player == White ? WhiteKnight : BlackKnight;
  } else {
    player == White ? WhiteQueen : BlackQueen;
  };

let applyMove = (position, move) => {
  let (piece, start, stop, modifiers) = move;
  let (startRank, startFile) = squareToRankAndFile(start);
  let (stopRank, stopFile) = squareToRankAndFile(stop);
  let actualPiece = getPiece(start, position);
  if (actualPiece != piece) {
    failwith("Unexpected mismatch of pieces when applying move.");
  };
  let toPlay = position.toPlay;
  if (toPlay == White) {
    let normal = () => {
      position
      |> setPiece(start, NoPiece)
      |> setPiece(stop, piece)
      |> setToPlay(Black)
      |> setEnPassant(None);
    };
    if (piece == WhitePawn && position.enPassant == Some(stop)) {
      /* Check en passant. */
      let position = normal() |> setPiece(rankDownExn(stop), NoPiece);
      position;
    } else if (piece == WhitePawn && stopRank === 7) {
      /* Check pawn promotion. */
      let piece = modifiersToPiece(White, modifiers);
      let position = normal() |> setPiece(stop, piece);
      position;
    } else if (piece == WhitePawn && startRank === 1 && stopRank === 3) {
      /* Check if next player can En passant. */
      let position = normal() |> setEnPassant(Some(rankUpExn(start)));
      position;
    } else if (piece == WhiteKing && start == E1 && (stop == G1 || stop == H1)) {
      /* Check for castling short. */
      if (!position.whiteShort) {
        failwith("White does not have short castling rights.");
      };
      let position =
        normal()
        |> setPiece(E1, NoPiece)
        |> setPiece(F1, WhiteRook)
        |> setPiece(G1, WhiteKing)
        |> setPiece(H1, NoPiece)
        |> revokeWhiteShort
        |> revokeWhiteLong;
      position;
    } else if (piece == WhiteKing
               && start == E1
               && (stop == A1 || stop == B1 || stop == C1)) {
      /* Check for castling long. */
      if (!position.whiteLong) {
        failwith("White does not have long castling rights.");
      };
      let position =
        normal()
        |> setPiece(A1, NoPiece)
        |> setPiece(B1, NoPiece)
        |> setPiece(C1, WhiteKing)
        |> setPiece(D1, WhiteRook)
        |> setPiece(E1, NoPiece)
        |> revokeWhiteShort
        |> revokeWhiteLong;
      position;
    } else if (piece == WhiteKing) {
      let position = normal() |> revokeWhiteShort |> revokeWhiteLong;
      position;
    } else if (piece == WhiteRook && start == A1) {
      let position = normal() |> revokeWhiteLong;
      position;
    } else if (piece == WhiteRook && start == H1) {
      let position = normal() |> revokeWhiteShort;
      position;
    } else {
      normal();
    };
  } else {
    let normal = () => {
      position
      |> setPiece(start, NoPiece)
      |> setPiece(stop, piece)
      |> setToPlay(White)
      |> setEnPassant(None);
    };
    if (piece == BlackPawn && position.enPassant == Some(stop)) {
      /* Check en passant. */
      let position = normal() |> setPiece(rankUpExn(stop), NoPiece);
      position;
    } else if (piece == BlackPawn && stopRank === 0) {
      /* Check pawn promotion. */
      let piece = modifiersToPiece(Black, modifiers);
      let position = normal() |> setPiece(stop, piece);
      position;
    } else if (piece == BlackPawn && startRank === 6 && stopRank === 5) {
      /* Check if next player can En passant. */
      let position = normal() |> setEnPassant(Some(rankDownExn(start)));
      position;
    } else if (piece == BlackKing && start == E8 && (stop == G8 || stop == H8)) {
      /* Check for castling short. */
      if (!position.blackShort) {
        failwith("Black does not have short castling rights.");
      };
      let position =
        normal()
        |> setPiece(E8, NoPiece)
        |> setPiece(F8, BlackRook)
        |> setPiece(G8, BlackKing)
        |> setPiece(H8, NoPiece)
        |> revokeBlackShort
        |> revokeBlackLong;
      position;
    } else if (piece == BlackKing
               && start == E8
               && (stop == A8 || stop == B8 || stop == C8)) {
      /* Check for castling long. */
      if (!position.blackLong) {
        failwith("Black does not have long castling rights.");
      };
      let position =
        normal()
        |> setPiece(A8, NoPiece)
        |> setPiece(B8, NoPiece)
        |> setPiece(C8, BlackKing)
        |> setPiece(D8, BlackRook)
        |> setPiece(E8, NoPiece)
        |> revokeWhiteShort
        |> revokeWhiteLong;
      position;
    } else if (piece == BlackKing) {
      let position = normal() |> revokeBlackShort |> revokeBlackLong;
      position;
    } else if (piece == BlackRook && start == A8) {
      let position = normal() |> revokeBlackLong;
      position;
    } else if (piece == BlackRook && start == H8) {
      let position = normal() |> revokeBlackShort;
      position;
    } else {
      normal();
    };
  };
};

let play = moves => {
  List.fold_left(
    (position, move) => applyMove(position, move),
    ChessPositions.start,
    moves,
  );
};
