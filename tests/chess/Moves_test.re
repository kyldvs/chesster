open ChessTypes;
open TestFramework;

describe("Tests valid moves", ({describe}) => {
  describe("Knight moves", ({test}) => {
    test("a1", ({expect}) => {
      let moves = Chess.knightMoves(A1) |> Chess.sort;
      expect.list(moves).toEqual([B3, C2]);
    });

    test("c4", ({expect}) => {
      let moves = Chess.knightMoves(C4) |> Chess.sort;
      expect.list(moves).toEqual([A3, A5, B2, B6, D2, D6, E3, E5]);
    });
  });

  describe("King moves", ({test}) => {
    test("a1", ({expect}) => {
      let moves = Chess.kingMoves(A1) |> Chess.sort;
      expect.list(moves).toEqual([A2, B1, B2]);
    });

    test("c4", ({expect}) => {
      let moves = Chess.kingMoves(C4) |> Chess.sort;
      expect.list(moves).toEqual([B3, B4, B5, C3, C5, D3, D4, D5]);
    });
  });
});
