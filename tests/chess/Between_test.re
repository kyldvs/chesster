open ChessTypes;
open TestFramework;

describe("Tests computing squares between two squares", ({test}) => {
  test("a3 -> a7", ({expect}) => {
    let squares = Chess.squaresBetween(A3, A7) |> Chess.sort;
    expect.list(squares).toEqual([A4, A5, A6]);
  });

  test("a7 -> a3", ({expect}) => {
    let squares = Chess.squaresBetween(A7, A3) |> Chess.sort;
    expect.list(squares).toEqual([A4, A5, A6]);
  });

  test("a3 -> a4", ({expect}) => {
    let squares = Chess.squaresBetween(A3, A4) |> Chess.sort;
    expect.list(squares).toEqual([]);
  });

  test("a4 -> a3", ({expect}) => {
    let squares = Chess.squaresBetween(A4, A3) |> Chess.sort;
    expect.list(squares).toEqual([]);
  });

  test("d5 -> g8", ({expect}) => {
    let squares = Chess.squaresBetween(D5, G8) |> Chess.sort;
    expect.list(squares).toEqual([E6, F7]);
  });

  test("g8 -> d5", ({expect}) => {
    let squares = Chess.squaresBetween(G8, D5) |> Chess.sort;
    expect.list(squares).toEqual([E6, F7]);
  });

  test("a8 -> h1", ({expect}) => {
    let squares = Chess.squaresBetween(A8, H1) |> Chess.sort;
    expect.list(squares).toEqual([B7, C6, D5, E4, F3, G2]);
  });

  test("h1 -> a8", ({expect}) => {
    let squares = Chess.squaresBetween(H1, A8) |> Chess.sort;
    expect.list(squares).toEqual([B7, C6, D5, E4, F3, G2]);
  });

  test("b2 -> c4 (knight)", ({expect}) => {
    let squares = Chess.squaresBetween(B2, C4) |> Chess.sort;
    expect.list(squares).toEqual([]);
  });
});
