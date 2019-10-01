open Chess;
open Revery;
open Revery.UI;
open Revery.UI.Components;

let isDark = square =>
  (squareToFile(square) + squareToRank(square)) mod 2 === 0;

let getSrc = (piece: piece) => {
  switch (piece) {
  | BlackPawn => "pdt.svg.png"
  | BlackKnight => "ndt.svg.png"
  | BlackBishop => "bdt.svg.png"
  | BlackRook => "rdt.svg.png"
  | BlackQueen => "qdt.svg.png"
  | BlackKing => "kdt.svg.png"
  | WhitePawn => "plt.svg.png"
  | WhiteKnight => "nlt.svg.png"
  | WhiteBishop => "blt.svg.png"
  | WhiteRook => "rlt.svg.png"
  | WhiteQueen => "qlt.svg.png"
  | WhiteKing => "klt.svg.png"
  };
};

let black = Color.hex("#AE734B");
let white = Color.hex("#F1D0A1");
let pieceStyle = Style.[width(64), height(64)];
let centered = Style.[justifyContent(`Center), alignItems(`Center)];
let boxShadow =
  Style.BoxShadow.make(
    ~xOffset=-8.,
    ~yOffset=-8.,
    ~blurRadius=20.,
    ~spreadRadius=0.,
    ~color=Colors.grey,
    (),
  );

let renderSquare = (square, piece: option(piece)) => {
  let color = isDark(square) ? black : white;

  let children =
    switch (piece) {
    | Some(piece) =>
      let src = getSrc(piece);
      let view = <View style=centered> <Image style=pieceStyle src /> </View>;
      [view];
    | None => []
    };

  <Container height=64 width=64 color> ...children </Container>;
};

module Square = {
  let createElement = (~square, ~children: list(piece), _) => {
    let piece =
      switch (children) {
      | [] => None
      | [x] => Some(x)
      /* TODO: What is the revery way to raise an exception? */
      | _ => failwith("Error: Squares cannot have multiple pieces.")
      };
    renderSquare(square, piece);
  };
};

let createElement = (~children, _) => {
  <BoxShadow boxShadow>
    <Container height=512 width=512>
      <Row>
        <Square square=A8> BlackRook </Square>
        <Square square=B8> BlackKnight </Square>
        <Square square=C8> BlackBishop </Square>
        <Square square=D8> BlackQueen </Square>
        <Square square=E8> BlackKing </Square>
        <Square square=F8> BlackBishop </Square>
        <Square square=G8> BlackKnight </Square>
        <Square square=H8> BlackRook </Square>
      </Row>
      <Row>
        <Square square=A7> BlackPawn </Square>
        <Square square=B7> BlackPawn </Square>
        <Square square=C7> BlackPawn </Square>
        <Square square=D7> BlackPawn </Square>
        <Square square=E7> BlackPawn </Square>
        <Square square=F7> BlackPawn </Square>
        <Square square=G7> BlackPawn </Square>
        <Square square=H7> BlackPawn </Square>
      </Row>
      <Row>
        <Square square=A6 />
        <Square square=B6 />
        <Square square=C6 />
        <Square square=D6 />
        <Square square=E6 />
        <Square square=F6 />
        <Square square=G6 />
        <Square square=H6 />
      </Row>
      <Row>
        <Square square=A5 />
        <Square square=B5 />
        <Square square=C5 />
        <Square square=D5 />
        <Square square=E5 />
        <Square square=F5 />
        <Square square=G5 />
        <Square square=H5 />
      </Row>
      <Row>
        <Square square=A4 />
        <Square square=B4 />
        <Square square=C4 />
        <Square square=D4 />
        <Square square=E4 />
        <Square square=F4 />
        <Square square=G4 />
        <Square square=H4 />
      </Row>
      <Row>
        <Square square=A3 />
        <Square square=B3 />
        <Square square=C3 />
        <Square square=D3 />
        <Square square=E3 />
        <Square square=F3 />
        <Square square=G3 />
        <Square square=H3 />
      </Row>
      <Row>
        <Square square=A2> WhitePawn </Square>
        <Square square=B2> WhitePawn </Square>
        <Square square=C2> WhitePawn </Square>
        <Square square=D2> WhitePawn </Square>
        <Square square=E2> WhitePawn </Square>
        <Square square=F2> WhitePawn </Square>
        <Square square=G2> WhitePawn </Square>
        <Square square=H2> WhitePawn </Square>
      </Row>
      <Row>
        <Square square=A1> WhiteRook </Square>
        <Square square=B1> WhiteKnight </Square>
        <Square square=C1> WhiteBishop </Square>
        <Square square=D1> WhiteQueen </Square>
        <Square square=E1> WhiteKing </Square>
        <Square square=F1> WhiteBishop </Square>
        <Square square=G1> WhiteKnight </Square>
        <Square square=H1> WhiteRook </Square>
      </Row>
    </Container>
  </BoxShadow>;
};
