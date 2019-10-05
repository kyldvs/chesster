open ChessTypes;

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
  type promotion =
    | Queen
    | Rook
    | Bishop
    | Knight;

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
  type result =
    | WhiteWon
    | BlackWon
    | Draw;

  type resultReason =
    | Timeout
    | Resignation
    | Checkmate
    | Agreement;

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
   * Applies a move to the game. Should include the amount of time elapsed
   * in ms since the previous move.
   *
   * Elapsed time should always be provided, but can be 0 for premoves or
   * when the timing doesn't matter.
   */
  let applyMove: (~elapsedMS: int, Move.t, t) => t;

  /**
   * Gets the result of the game if it has been completed.
   */
  let getResult: t => option(result);

  /**
   * Gets the result reason if the game has been completed.
   */
  let getResultReason: t => option(resultReason);
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
