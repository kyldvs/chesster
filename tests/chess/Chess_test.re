module Chess = Chess2;

open Chess;
open TestFramework;

describe("Tests legal moves", ({test}) => {
  test("t1", ({expect}) => {
    let inCheck = true;
    expect.bool(inCheck).toBeTrue();
  });

  test("black knight on d3", ({expect}) => {
    let inCheck = false;
    expect.bool(inCheck).toBeFalse();
  });
});
