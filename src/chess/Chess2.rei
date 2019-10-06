module Types: {
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
};

open Types;

module Timing: {
  /**
   * The timing options for a particular game. This tracks the timing rules,
   * not the time remaining or used. Thos types of things should be tracked by
   * the game object.
   */
  type t;

  /**
   * Makes an empty timing object with no limit.
   */
  let make: unit => t;

  /**
   * The total amount of time each player has for all turns.
   */
  let withTimeLimit: (~ms: int, t) => t;

  /**
   * The amount of time each player has for each turn.
   */
  let withTimeLimitPerTurn: (~ms: int, t) => t;

  /**
   * The amount of time gained after each move.
   *
   * Does nothing if there is no time limit for the game.
   */
  let withIncrement: (~ms: int, t) => t;

  /**
   * The amount of time added to the remaining time after finishing the
   * specified turn. (e.g. gain 60 minutes after turn 40).
   *
   * Does nothing if there is no time limit for the game.
   */
  let withTimeControl: (~ms: int, ~afterTurn: int, t) => t;
};

module Move: {
  type t;

  let make: (square, square) => t;

  let withPromotion: (promotion, t) => t;

  let withCheck: t => t;

  let withCheckMate: t => t;

  let withCastle: t => t;

  /**
   * Extra annotations that can be added to moves.
   */
  module Annotations: {
    let setBlunder: t => t;
    let setMistake: t => t;
    let setDubious: t => t;
    let setInteresting: t => t;
    let setGood: t => t;
    let setBrilliant: t => t;
  };
};

module TimedMove: {
  type t;
  let make: (~elapsedMS: int, Move.t) => t;
  let getMove: t => Move.t;
};

module Position: {
  /**
   * Tracks the state of the current position. All legal moves should be able
   * to be determined from this. Note that the position must be able to
   * check for:
   *
   * - Castling rights
   * - En Passant
   * - Insufficient material
   * - 50-move rule
   */
  type t;

  /**
   * Makes a new starting position.
   */
  let make: unit => t;

  /**
   * Applies a move to the position.
   */
  let applyMove: (Move.t, t) => t;

  /**
   * Gets the active player that should make the next move.
   */
  let getPlayer: t => player;

  /**
   * Gets the piece at a particular square. This may be `NoPiece`.
   */
  let getPiece: (square, t) => piece;

  /**
   * Gets all legal moves.
   *
   * This should include all possible promotion variants, e.g: A8=Queen,
   * A8=Rook, A8=Bishop, and A8=Knight
   */
  let getLegalMoves: (square, t) => list(Move.t);

  /**
   * Gets the square in check or None.
   */
  let getCheck: t => option(square);

  /**
   * Gets the player in checkmate or None.
   */
  let getCheckMate: t => option(player);

  /**
   * Whether or not the game is a draw by insufficient material.
   */
  let isInsufficientMaterial: t => bool;

  /**
   * How many halfmoves since the last pawn move or capture.
   */
  let getHalfmoveClock: t => int;
};

module Game: {
  /**
   * Tracks an entire chess game from the starting position. It should be able
   * to track data about:
   *
   * - 3-fold repetion
   * - Timing data for moves (if the game is timed)
   * - Statuses like resignation, checkmate, timeout, etc.
   */
  type t;

  /**
   * Creates a new game.
   */
  let make: unit => t;

  /**
   * Adds timing to the game.
   */
  let withTiming: (Timing.t, t) => t;

  /**
   * Gets the current position of the game.
   */
  let getPosition: t => Position.t;

  /**
   * Gets the game position at the previous move.
   */
  let getPrevious: t => option((TimedMove.t, t));

  /**
   * Gets the entire history of the game.
   */
  let getHistory: t => list((TimedMove.t, t));

  /**
   * Applies a move to the game. Should include the amount of time elapsed
   * in ms since the previous move.
   *
   * Elapsed time should always be provided, but can be 0 for premoves or
   * when the timing doesn't matter.
   */
  let applyMove: (TimedMove.t, t) => t;

  /**
   * Gets the result of the game if it has been completed.
   */
  let getResult: t => option((result, resultReason));

  /**
   * Gets the number of times a position occurred in this game. Helpful
   * for determing if a move will result in a 3-fold repetition.
   *
   * A position is considered to have occurred before only if the exact
   * same set of legal moves is available. This includes ability to capture
   * en-passant and castling rights.
   */
  let getOccurrenceCount: (Position.t, t) => int;

  /**
   * Check if the active player can claim a draw by 3-fold repetition.
   *
   * See: `getOccurrenceCount` for determining if 3-fold is valid.
   */
  let isThreeFoldRepetition: t => bool;
};

/**
 * Helpful utilities for testing and debugging.
 */
module Debug: {
  let sortSquares: list(square) => list(square);
  let showSquare: square => string;
  let showSquares: list(square) => string;
};

/**
 * Forsyth-Edwards Notation is used to describe a position.
 *
 * - https://en.wikipedia.org/wiki/Forsyth%E2%80%93Edwards_Notation
 */
module FEN: {};

/**
 * Portable Game Notation is used to describe a game.
 *
 * - https://en.wikipedia.org/wiki/Portable_Game_Notation
 */
module PGN: {};
