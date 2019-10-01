open Chess;
open Revery;
open Revery.UI;
open Revery.UI.Components;

module Square = {
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

  let createElement =
      (~square, ~piece: option(piece), ~children: list(unit), _) => {
    let color = isDark(square) ? black : white;

    let children =
      switch (piece) {
      | Some(piece) =>
        let src = getSrc(piece);
        let view =
          <View style=centered> <Image style=pieceStyle src /> </View>;
        [view];
      | None => []
      };

    <Container height=64 width=64 color> ...children </Container>;
  };
};

let boxShadow =
  Style.BoxShadow.make(
    ~xOffset=-8.,
    ~yOffset=-8.,
    ~blurRadius=20.,
    ~spreadRadius=0.,
    ~color=Colors.grey,
    (),
  );

let createElement = (~position, ~children, _) => {
  <BoxShadow boxShadow>
    <Container height=512 width=512>
      <Row>
        <Square square=A8 piece={position.a8} />
        <Square square=B8 piece={position.b8} />
        <Square square=C8 piece={position.c8} />
        <Square square=D8 piece={position.d8} />
        <Square square=E8 piece={position.e8} />
        <Square square=F8 piece={position.f8} />
        <Square square=G8 piece={position.g8} />
        <Square square=H8 piece={position.h8} />
      </Row>
      <Row>
        <Square square=A7 piece={position.a7} />
        <Square square=B7 piece={position.b7} />
        <Square square=C7 piece={position.c7} />
        <Square square=D7 piece={position.d7} />
        <Square square=E7 piece={position.e7} />
        <Square square=F7 piece={position.f7} />
        <Square square=G7 piece={position.g7} />
        <Square square=H7 piece={position.h7} />
      </Row>
      <Row>
        <Square square=A6 piece={position.a6} />
        <Square square=B6 piece={position.b6} />
        <Square square=C6 piece={position.c6} />
        <Square square=D6 piece={position.d6} />
        <Square square=E6 piece={position.e6} />
        <Square square=F6 piece={position.f6} />
        <Square square=G6 piece={position.g6} />
        <Square square=H6 piece={position.h6} />
      </Row>
      <Row>
        <Square square=A5 piece={position.a5} />
        <Square square=B5 piece={position.b5} />
        <Square square=C5 piece={position.c5} />
        <Square square=D5 piece={position.d5} />
        <Square square=E5 piece={position.e5} />
        <Square square=F5 piece={position.f5} />
        <Square square=G5 piece={position.g5} />
        <Square square=H5 piece={position.h5} />
      </Row>
      <Row>
        <Square square=A4 piece={position.a4} />
        <Square square=B4 piece={position.b4} />
        <Square square=C4 piece={position.c4} />
        <Square square=D4 piece={position.d4} />
        <Square square=E4 piece={position.e4} />
        <Square square=F4 piece={position.f4} />
        <Square square=G4 piece={position.g4} />
        <Square square=H4 piece={position.h4} />
      </Row>
      <Row>
        <Square square=A3 piece={position.a3} />
        <Square square=B3 piece={position.b3} />
        <Square square=C3 piece={position.c3} />
        <Square square=D3 piece={position.d3} />
        <Square square=E3 piece={position.e3} />
        <Square square=F3 piece={position.f3} />
        <Square square=G3 piece={position.g3} />
        <Square square=H3 piece={position.h3} />
      </Row>
      <Row>
        <Square square=A2 piece={position.a2} />
        <Square square=B2 piece={position.b2} />
        <Square square=C2 piece={position.c2} />
        <Square square=D2 piece={position.d2} />
        <Square square=E2 piece={position.e2} />
        <Square square=F2 piece={position.f2} />
        <Square square=G2 piece={position.g2} />
        <Square square=H2 piece={position.h2} />
      </Row>
      <Row>
        <Square square=A1 piece={position.a1} />
        <Square square=B1 piece={position.b1} />
        <Square square=C1 piece={position.c1} />
        <Square square=D1 piece={position.d1} />
        <Square square=E1 piece={position.e1} />
        <Square square=F1 piece={position.f1} />
        <Square square=G1 piece={position.g1} />
        <Square square=H1 piece={position.h1} />
      </Row>
    </Container>
  </BoxShadow>;
};
