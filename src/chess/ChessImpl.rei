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
  type t;

  type promotion =
    | Queen
    | Rook
    | Bishop
    | Knight;

  let make: (square, square) => t;

  let withPromotion: (promotion, t) => t;
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
   */
  type t;

  /**
   * Makes a new starting position.
   */
  let make: unit => t;

  let applyMove: (Move.t, t) => t;

  let getPlayer: t => player;
  let getPiece: (square, t) => piece;
  let getLegalMoves: (square, t) => list(Move.t);

  let getCheck: t => option(square);
  let getCheckMate: t => option(player);
  let isInsufficientMaterial: t => bool;

  /**
   * Allows for more manual modification of a position. Not typically useful
   * for running a chess game.
   */
  module Manual: {
    let clear: t => t;

    let getEnPassant: t => option(square);
    let removeEnPassant: t => t;
    let setEnPassant: (square, t) => t;

    let hasWhiteShort: t => bool;
    let hasWhiteLong: t => bool;
    let hasBlackShort: t => bool;
    let hasBlackLong: t => bool;
    let removeWhiteShort: t => t;
    let removeWhiteLong: t => t;
    let removeBlackShort: t => t;
    let removeBlackLong: t => t;
    let addWhiteShort: t => t;
    let addWhiteLong: t => t;
    let addBlackShort: t => t;
    let addBlackLong: t => t;
  };
};

module Game: {
  /**
   * Tracks an entire chess game from the starting position. It should be able
   * to track data about:
   *
   * - Draws: 3-fold, 50-moves
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
   * Finish defining functions.
   */
  let todo: unit;
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
