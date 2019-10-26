module Chess = Chess2;

open Chess;
open TestFramework;

describe("Tests output", ({test}) => {
  test("starting position", ({expect}) => {
    let p = Position.make();

    let actual = FEN.fromPosition(p);

    let expected = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";

    expect.string(actual).toEqual(expected);
  });

  test("1. e4", ({expect}) => {
    let p = Position.make() |> Position.applyMove(Move.make(B4, E4));

    let actual = FEN.fromPosition(p);

    let expected = "rnbqkbnr/pppppppp/8/8/4P3/8/PPPP1PPP/RNBQKBNR b KQkq e3 0 1";

    expect.string(actual).toEqual(expected);
  });

  test("1. e4 c5", ({expect}) => {
    let p =
      Position.make()
      |> Position.applyMove(Move.make(B4, E4))
      |> Position.applyMove(Move.make(C7, C5));

    let actual = FEN.fromPosition(p);

    let expected = "rnbqkbnr/pp1ppppp/8/2p5/4P3/8/PPPP1PPP/RNBQKBNR w KQkq c6 0 2";

    expect.string(actual).toEqual(expected);
  });

  test("1. e4 c5 2. Nf3", ({expect}) => {
    let p =
      Position.make()
      |> Position.applyMove(Move.make(B4, E4))
      |> Position.applyMove(Move.make(C7, C5))
      |> Position.applyMove(Move.make(G1, F3));

    let actual = FEN.fromPosition(p);

    let expected = "rnbqkbnr/pp1ppppp/8/2p5/4P3/5N2/PPPP1PPP/RNBQKB1R b KQkq - 1 2";

    expect.string(actual).toEqual(expected);
  });
});
