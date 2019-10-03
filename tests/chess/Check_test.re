open ChessTypes;
open TestFramework;

describe("Tests if we are in check", ({test}) => {
  test("starting position", ({expect}) => {
    let position =
      Chess.play([
        (WhitePawn, E2, E4, []),
        (BlackKnight, B8, C6, []),
        (WhitePawn, E4, E5, []),
        (BlackKnight, C6, E5, []),
        (WhitePawn, A2, A3, []),
      ]);
    let inCheck = Chess.inCheck(position);
    expect.bool(inCheck).toBeFalse();
  });

  test("black knight on d3", ({expect}) => {
    let position =
      Chess.play([
        (WhitePawn, E2, E4, []),
        (BlackKnight, B8, C6, []),
        (WhitePawn, E4, E5, []),
        (BlackKnight, C6, E5, []),
        (WhitePawn, A2, A3, []),
        (BlackKnight, E5, D3, [Check]),
      ]);
    let inCheck = Chess.inCheck(position);
    expect.bool(inCheck).toBeTrue();
  });

  test("black bishop no blocker", ({expect}) => {
    let position =
      Chess.play([
        (WhitePawn, D2, D3, []),
        (BlackPawn, E7, E6, []),
        (WhitePawn, E2, E3, []),
        (BlackBishop, F8, B4, [Check]),
      ]);
    let inCheck = Chess.inCheck(position);
    expect.bool(inCheck).toBeTrue();
  });

  test("black bishop with blocker", ({expect}) => {
    let position =
      Chess.play([
        (WhitePawn, D2, D3, []),
        (BlackPawn, E7, E6, []),
        (WhiteKnight, B1, D2, []),
        (BlackBishop, F8, B4, []),
      ]);
    let inCheck = Chess.inCheck(position);
    expect.bool(inCheck).toBeFalse();
  });
});
