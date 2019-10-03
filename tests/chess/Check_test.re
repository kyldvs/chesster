open ChessTypes;
open TestFramework;

describe("Tests if we are in check", ({test}) => {
  test("starting position", ({expect}) => {
    let position = Chess.setup([]);
    let inCheck = Chess.inCheck(position);
    expect.bool(inCheck).toBeFalse();
  });

  test("black knight on d3", ({expect}) => {
    let position = Chess.setup([(B8, NoPiece), (D3, BlackKnight)]);
    let inCheck = Chess.inCheck(position);
    expect.bool(inCheck).toBeTrue();
  });

  test("black bishop no blocker", ({expect}) => {
    let position =
      Chess.setup([
        (F8, NoPiece),
        (E7, NoPiece),
        (D2, NoPiece),
        (E5, WhitePawn),
        (B4, BlackBishop),
      ]);
    let inCheck = Chess.inCheck(position);
    expect.bool(inCheck).toBeTrue();
  });

  test("black bishop with blocker", ({expect}) => {
    let position = Chess.setup([(F8, NoPiece), (B4, BlackBishop)]);
    let inCheck = Chess.inCheck(position);
    expect.bool(inCheck).toBeFalse();
  });
});
